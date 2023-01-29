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
	ShapeOfRoundedBorderOfWidget::ReleaseSetDisplacementCoefficient(geometry, this->GetDisplacementCoefficient());

	this->SetExternalRectangle(geometry);
	this->SetInternalRectangle(geometry);
}

void ShapeOfRoundedBorderOfWidget::ReleaseSetThickness(QRectF &geometry,
													   const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfTop   (geometry, thickness.GetThicknessOfTop	  ());
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfBottom(geometry, thickness.GetThicknessOfBottom());
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfLeft  (geometry, thickness.GetThicknessOfLeft  ());
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfRight (geometry, thickness.GetThicknessOfRight ());
}

void ShapeOfRoundedBorderOfWidget::ReleaseSetThickness(QRectF &geometry,
													   const T_Thickness thickness) noexcept
{
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfTop   (geometry, thickness);
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfBottom(geometry, thickness);
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfLeft  (geometry, thickness);
	ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfRight (geometry, thickness);
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

void ShapeOfRoundedBorderOfWidget::ReleaseSetDisplacementCoefficient(QRectF &geometry,
																	 const T_Displacement displacement) noexcept
{
	ShapeOfRoundedBorderOfWidget::ReleaseSetThickness(geometry, displacement);
}
}  // namespace N_PainterOfRoundedBorderOfWidget
