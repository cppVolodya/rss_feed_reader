// Copyright [2023] <Volodymyr Dorozhovets>"

#include "graphics_shadow_effect_of_widget.hpp"
#include "painter_of_save_and_restore_transform.hpp"

QT_BEGIN_NAMESPACE
extern Q_WIDGETS_EXPORT void qt_blurImage(QPainter *painter,  // NOLINT(pvs-studio-V3549), NOLINT(pvs-studio-V2575)
										  QImage   &blur_image,
										  qreal     blur_radius,
										  bool 	    quality,
										  bool 	    alphaOnly,
										  int 	    transposed = 0);
QT_END_NAMESPACE


namespace N_Widget
{
using N_PainterOfRoundedBorderOfWidget::PainterOfSaveAndRestoreTransform;


void GraphicsShadowEffectOfWidget::draw(QPainter *painter)
{
	QPoint offset_of_pixel_map_of_source;
	const QPixmap pixel_map_of_source = this->GetPixelMapOfSource(offset_of_pixel_map_of_source);

	if (!pixel_map_of_source.isNull())
	{
	PainterOfSaveAndRestoreTransform painter_saver(*painter);

	QImage image = this->GetImageWithSetPlacementCharacteristic(pixel_map_of_source);
	this->SetBlurRadiusOnImage(image);
	this->SetColorOnImage(image);

	GraphicsShadowEffectOfWidget::DrawCurrentEffect(painter, offset_of_pixel_map_of_source, image			   );
	GraphicsShadowEffectOfWidget::DrawCurrentSource(painter, offset_of_pixel_map_of_source, pixel_map_of_source);
	}
}

QRectF GraphicsShadowEffectOfWidget::boundingRectFor(const QRectF &geometry_of_widget) const
{
	QRectF geometry_of_graphic_shadow_effect = this->GetGeometry(geometry_of_widget);

	QRectF bounding_rectangle = geometry_of_widget.united(geometry_of_graphic_shadow_effect);

	return bounding_rectangle;
}

[[nodiscard]] QRectF GraphicsShadowEffectOfWidget::GetGeometry(const QRectF &geometry_of_widget) const
{
	const CharacteristicsOfPlacementOfPositionalElement &characteristic_of_placement = this->GetCharacteristicOfPlacement();
	qreal position_of_top    = characteristic_of_placement.GetPositionOfTop   () + this->GetBlurRadius();
	qreal position_of_bottom = characteristic_of_placement.GetPositionOfBottom() + this->GetBlurRadius();
	qreal position_of_left   = characteristic_of_placement.GetPositionOfLeft  () + this->GetBlurRadius();
	qreal position_of_right  = characteristic_of_placement.GetPositionOfRight () + this->GetBlurRadius();

	QRectF geometry_of_graphic_shadow_effect = geometry_of_widget.adjusted(-position_of_top,   -position_of_left,
																		    position_of_bottom, position_of_right);

	return geometry_of_graphic_shadow_effect;
}

QPixmap GraphicsShadowEffectOfWidget::GetPixelMapOfSource(QPoint &offset_of_pixel_map)
{
    constexpr Qt::CoordinateSystem coordinate_system = Qt::DeviceCoordinates;

    constexpr QGraphicsEffect::PixmapPadMode padded_mode = QGraphicsEffect::PadToEffectiveBoundingRect;

    QPixmap pixel_map = this->sourcePixmap(coordinate_system,
                                           &offset_of_pixel_map,
										   padded_mode);

    return pixel_map;
}

QImage GraphicsShadowEffectOfWidget::GetImageWithSetPlacementCharacteristic(const QPixmap &pixel_map_of_source)
{
	QSizeF new_size = this->GetNewSize(pixel_map_of_source);

	QImage image(new_size.toSize(), QImage::Format_ARGB32_Premultiplied);
	image.fill(0);

	QPixmap new_scaled = pixel_map_of_source.scaled(new_size.toSize());
	this->DrawOnImageWithSetPlacementCharacteristic(image, new_scaled);

	return image;
}

[[nodiscard]] QSizeF GraphicsShadowEffectOfWidget::GetNewSize(const QPixmap &pixel_map_of_source) const noexcept
{
	QSizeF new_size;

	const CharacteristicsOfPlacementOfPositionalElement &characteristic_of_placement = this->GetCharacteristicOfPlacement();

	new_size.setWidth(static_cast<qreal>(pixel_map_of_source.size().width()) +
		characteristic_of_placement.GetPositionOfRight() + this->GetCharacteristicOfPlacement().GetPositionOfLeft());

	new_size.setHeight(static_cast<qreal>(pixel_map_of_source.size().height()) +
		characteristic_of_placement.GetPositionOfBottom() + this->GetCharacteristicOfPlacement().GetPositionOfTop());

	return new_size;
}

void GraphicsShadowEffectOfWidget::DrawOnImageWithSetPlacementCharacteristic(QImage &image_with_set_placement_characteristic,
																			 const QPixmap &new_scaled) const
{
	QPainter painter(&image_with_set_placement_characteristic);
	painter.setCompositionMode(QPainter::CompositionMode_Source);

	painter.drawPixmap(QPointF(-GetCharacteristicOfPlacement().GetPositionOfLeft(),
							   -GetCharacteristicOfPlacement().GetPositionOfTop ()), new_scaled);

	painter.end();
}

inline void GraphicsShadowEffectOfWidget::SetBlurRadiusOnImage(QImage &old_image) const
{
	QImage new_image(old_image.size(), QImage::Format_ARGB32_Premultiplied);
	new_image.fill(0);

	this->DrawOnImageWithSetBlurRadius(new_image, old_image);

	old_image = new_image;
}

void GraphicsShadowEffectOfWidget::DrawOnImageWithSetBlurRadius(QImage &new_image, QImage &old_image) const
{
	bool quality    = true;
	bool alpha_only = true;

	QPainter painter(&new_image);
	qt_blurImage(&painter, old_image, this->GetBlurRadius(), quality, alpha_only);
	painter.end();
}

void GraphicsShadowEffectOfWidget::SetColorOnImage(QImage &image) const
{
	QPainter painter(&image);
	painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	painter.fillRect(image.rect(), this->GetColor());
	painter.end();
}

inline void GraphicsShadowEffectOfWidget::DrawCurrentEffect(QPainter *painter,
													 		const QPoint &offset_of_pixel_map_of_source,
													 		const QImage &image)
{
	painter->drawImage(offset_of_pixel_map_of_source, image);
}

inline void GraphicsShadowEffectOfWidget::DrawCurrentSource(QPainter *painter,
													 		const QPoint &offset_of_pixel_map_of_source,
													 		const QPixmap &pixel_map_of_source)
{
	painter->drawPixmap(offset_of_pixel_map_of_source, pixel_map_of_source);
}
}  // namespace N_Widget
