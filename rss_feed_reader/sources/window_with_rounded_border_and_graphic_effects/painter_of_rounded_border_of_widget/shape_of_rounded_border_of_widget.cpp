#include "shape_of_rounded_border_of_widget.h"


void ShapeOfRoundedBorderOfWidget::CustomizeGeometry(const QRectF &geometry_of_widget) noexcept
{
	this->SetGeometry(geometry_of_widget);
	this->ReleaseSetThickness();
}

void ShapeOfRoundedBorderOfWidget::SetGeometry(const QRectF &geometry_of_widget) noexcept
{
	this->m_external_rectangle = geometry_of_widget;
	this->m_internal_rectangle = geometry_of_widget;
}

void ShapeOfRoundedBorderOfWidget::ReleaseSetThickness() noexcept
{
	this->m_thickness = ThicknessOfRoundedBorderOfWidget(30.0, 5.0, 5.0, 5.0);  // TEST

	this->ReleaseSetThicknessOfTop   ();
	this->ReleaseSetThicknessOfBottom();
	this->ReleaseSetThicknessOfLeft  ();
	this->ReleaseSetThicknessOfRight ();
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfTop() noexcept
{
	const qreal thickness_of_top = this->GetThicknessOfTop();
	this->m_internal_rectangle.setY(this->m_internal_rectangle.y() + thickness_of_top);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfBottom() noexcept
{
	const qreal thickness_of_bottom = this->GetThicknessOfBottom();
	this->m_internal_rectangle.setHeight(this->m_internal_rectangle.height() - thickness_of_bottom);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfLeft() noexcept
{
	const qreal thickness_of_left = this->GetThicknessOfLeft();
	this->m_internal_rectangle.setX(this->m_internal_rectangle.x() + thickness_of_left);
}

inline void ShapeOfRoundedBorderOfWidget::ReleaseSetThicknessOfRight() noexcept
{
	const qreal thickness_of_right = this->GetThicknessOfRight();
	this->m_internal_rectangle.setWidth (this->m_internal_rectangle.width() - thickness_of_right);
}
