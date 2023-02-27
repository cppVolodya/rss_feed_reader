// Copyright [2023] <Volodymyr Dorozhovets>"

#include "shape_of_rounded_border_of_widget.hpp"


namespace N_PainterOfRoundedBorderOfWidget
{
void ShapeOfRoundedBorderOfWidget::ReleaseCustomizeGeometry(const QRectF &geometry) noexcept
{
	this->SetGeometry(geometry);
	ShapeOfRoundedBorderOfWidget::ReleaseSetThickness(this->m_internal_rectangle, this->m_thickness);
}

inline void ShapeOfRoundedBorderOfWidget::SetGeometry(QRectF geometry) noexcept
{
	ShapeOfRoundedBorderOfWidget::ReleaseSetBoundingThickness(geometry, this->GetBoundingThickness());

	this->SetExternalRectangle(geometry);
	this->SetInternalRectangle(geometry);
}

void ShapeOfRoundedBorderOfWidget::ReleaseSetThickness(QRectF &geometry,
													   const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfTop   (geometry, thickness.GetPositionOfTop   ());
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfBottom(geometry, thickness.GetPositionOfBottom());
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfLeft  (geometry, thickness.GetPositionOfLeft  ());
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfRight (geometry, thickness.GetPositionOfRight ());
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfTop(QRectF &geometry,
																   const T_Thickness thickness_of_top) noexcept
{
	geometry.setY(geometry.y() + thickness_of_top);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfBottom(QRectF &geometry,
																      const T_Thickness thickness_of_bottom) noexcept
{
	geometry.setHeight(geometry.height() - thickness_of_bottom);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfLeft(QRectF &geometry,
																	const T_Thickness thickness_of_left) noexcept
{
	geometry.setX(geometry.x() + thickness_of_left);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfRight(QRectF &geometry,
																	 const T_Thickness thickness_of_right) noexcept
{
	geometry.setWidth(geometry.width() - thickness_of_right);
}

void ShapeOfRoundedBorderOfWidget::ReleaseSetBoundingThickness(QRectF &geometry,
															   const ThicknessOfRoundedBorderOfWidget& bounding_thickness) noexcept
{
	ShapeOfRoundedBorderOfWidget::ReleaseSetThickness(geometry, bounding_thickness);
}
}  // namespace N_PainterOfRoundedBorderOfWidget
