// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef GRAPHICS_SHADOW_EFFECT_OF_WIDGET_HPP
#define GRAPHICS_SHADOW_EFFECT_OF_WIDGET_HPP

#include <QGraphicsEffect>
#include <QPainter>

#include "types_aliases.hpp"
#include "characteristic_of_placement_of_positional_element.hpp"


namespace N_Widget
{
using N_PainterOfRoundedBorderOfWidget::CharacteristicOfPlacementOfPositionalElement;

using N_TypesAliases::T_BlurRadius;


class GraphicsShadowEffectOfWidget : public QGraphicsEffect
{
public:
	explicit inline GraphicsShadowEffectOfWidget(QObject 							      			 *parent      				  = nullptr,
												 const QColor 							  			 &color 	  				  = QColor(),
												 const CharacteristicOfPlacementOfPositionalElement &characteristic_of_placement = CharacteristicOfPlacementOfPositionalElement(2.0, 2.0, 2.0, 2.0),
												 T_BlurRadius 						   	  			  blur_radius 				  = 10.0);

	[[nodiscard]] inline QColor 	  								   GetColor	 				   () const noexcept;
	[[nodiscard]] inline CharacteristicOfPlacementOfPositionalElement GetCharacteristicOfPlacement() const noexcept;
	[[nodiscard]] inline T_BlurRadius 								   GetBlurRadius			   () const noexcept;

	inline void SetColor	 				(const QColor &						 			  	  ) noexcept;
	inline void SetCharacteristicOfPlacement(const CharacteristicOfPlacementOfPositionalElement &) noexcept;
	inline void SetBlurRadius				(T_BlurRadius  						 			  	  ) noexcept;
protected:
	void draw(QPainter *) override;

	[[nodiscard]] QRectF boundingRectFor(const QRectF &) const override;
private:
	QColor m_color;

	CharacteristicOfPlacementOfPositionalElement m_characteristic_of_placement;

	T_BlurRadius m_blur_radius;
private:
	[[nodiscard]] QRectF GetGeometry(const QRectF &) const;

	QPixmap GetPixelMapOfSource(QPoint &);

	QImage GetImageWithSetPlacementCharacteristic(const QPixmap &);
	[[nodiscard]] QSizeF GetNewSize(const QPixmap &pixel_map_of_source) const noexcept;
	void DrawOnImageWithSetPlacementCharacteristic(QImage &, const QPixmap &) const;

	inline void SetBlurRadiusOnImage(QImage &) const;
	void DrawOnImageWithSetBlurRadius(QImage &, QImage &) const;

	void SetColorOnImage(QImage &) const;

	static inline void DrawCurrentEffect(QPainter *painter, const QPoint &, const QImage  &);
	static inline void DrawCurrentSource(QPainter *painter, const QPoint &, const QPixmap &);
};

inline GraphicsShadowEffectOfWidget::GraphicsShadowEffectOfWidget(QObject 	   							  	    	  *parent,
																  const QColor								    	  &color,
																  const CharacteristicOfPlacementOfPositionalElement &characteristic_of_placement,
																  const T_BlurRadius 								   blur_radius)
	: QGraphicsEffect			   (parent	 				   ),
	  m_color		 			   (color		 			   ),
	  m_characteristic_of_placement(characteristic_of_placement),
	  m_blur_radius  			   (blur_radius				   )
{
}

[[nodiscard]] inline QColor GraphicsShadowEffectOfWidget::GetColor() const noexcept
{
	return this->m_color;
}

[[nodiscard]] inline CharacteristicOfPlacementOfPositionalElement GraphicsShadowEffectOfWidget::GetCharacteristicOfPlacement() const noexcept
{
	return this->m_characteristic_of_placement;
}

[[nodiscard]] inline T_BlurRadius GraphicsShadowEffectOfWidget::GetBlurRadius() const noexcept
{
	return this->m_blur_radius;
}

inline void GraphicsShadowEffectOfWidget::SetColor(const QColor	&color) noexcept
{
	this->m_color = color;
}

inline void GraphicsShadowEffectOfWidget::SetCharacteristicOfPlacement(const CharacteristicOfPlacementOfPositionalElement &characteristic_of_placement) noexcept
{
	this->m_characteristic_of_placement = characteristic_of_placement;
	this->updateBoundingRect();
}

inline void GraphicsShadowEffectOfWidget::SetBlurRadius(const T_BlurRadius blurRadius) noexcept
{
	this->m_blur_radius = blurRadius;
	this->updateBoundingRect();
}
}  // namespace N_Widget

#endif  // GRAPHICS_SHADOW_EFFECT_OF_WIDGET_HPP
