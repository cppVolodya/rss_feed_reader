#include "shape_of_rounded_border_of_widget.h"


void ShapeOfRoundedBorderOfWidget::ReleaseCustomizeGeometry(const QRectF &geometry_of_widget) noexcept
{
	this->SetGeometry(geometry_of_widget);
	this->ReleaseSetThickness();
}

inline void ShapeOfRoundedBorderOfWidget::SetGeometry(QRectF geometry_of_widget) noexcept
{
	this->ReleaseSetDisplacementCoefficient(geometry_of_widget);

	this->m_external_rectangle = geometry_of_widget;  // external
	this->m_internal_rectangle = geometry_of_widget;  // internal
}

void ShapeOfRoundedBorderOfWidget::ReleaseSetDisplacementCoefficient(QRectF &geometry_of_widget) const noexcept
{
	geometry_of_widget.setY     (geometry_of_widget.y     () + this->m_displacement_coefficient);  // top
	geometry_of_widget.setHeight(geometry_of_widget.height() - this->m_displacement_coefficient);  // bottom
	geometry_of_widget.setX     (geometry_of_widget.x     () + this->m_displacement_coefficient);  // left
	geometry_of_widget.setWidth (geometry_of_widget.width () - this->m_displacement_coefficient);  // right
}

#pragma region ReleaseSetThickness [functions]
void ShapeOfRoundedBorderOfWidget::ReleaseSetThickness() noexcept
{
	this->ReleaseSetThicknessOfTop   ();  // top
	this->ReleaseSetThicknessOfBottom();  // bottom
	this->ReleaseSetThicknessOfLeft  ();  // left
	this->ReleaseSetThicknessOfRight ();  // right
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfTop() noexcept  // top
{
	const qreal thickness_of_top = this->GetThicknessOfTop();
	this->m_internal_rectangle.setY(this->m_internal_rectangle.y() + thickness_of_top);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfBottom() noexcept  // bottom
{
	const qreal thickness_of_bottom = this->GetThicknessOfBottom();
	this->m_internal_rectangle.setHeight(this->m_internal_rectangle.height() - thickness_of_bottom);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfLeft() noexcept  // left
{
	const qreal thickness_of_left = this->GetThicknessOfLeft();
	this->m_internal_rectangle.setX(this->m_internal_rectangle.x() + thickness_of_left);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfRight() noexcept  // right
{
	const qreal thickness_of_right = this->GetThicknessOfRight();
	this->m_internal_rectangle.setWidth (this->m_internal_rectangle.width() - thickness_of_right);
}
#pragma endregion ReleaseSetThickness [functions]
