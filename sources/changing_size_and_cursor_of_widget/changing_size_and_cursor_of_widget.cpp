// Copyright [2023] <Volodymyr Dorozhovets>"

#include "changing_size_and_cursor_of_widget.hpp"


namespace N_ChangingSizeAndCursorOfWidget
{
CursorShape ChangingSizeAndCursorOfWidget::ReleaseGetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &mouse_position)
{
	this->m_cursor_shape = this->m_changing_cursor_of_widget.GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(mouse_position);

	return this->m_cursor_shape;
}

QRectF ChangingSizeAndCursorOfWidget::ReleaseGetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &mouse_position,
																										   const QRectF  &geometry_of_widget) noexcept
{
	this->m_changing_size_of_widget.SetStateOfWidgetResize(this->m_cursor_shape);

	return this->m_changing_size_of_widget.GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(mouse_position, geometry_of_widget);
}
}  // namespace N_ChangingSizeAndCursorOfWidget
