// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef CHANGING_SIZE_AND_CURSOR_OF_WIDGET_HPP
#define CHANGING_SIZE_AND_CURSOR_OF_WIDGET_HPP

#include "changing_cursor_of_widget.hpp"
#include "changing_size_of_widget.hpp"


namespace N_ChangingSizeAndCursorOfWidget
{
class ChangingSizeAndCursorOfWidget
{
public:
	inline ChangingSizeAndCursorOfWidget() noexcept;

	inline CursorShape GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &);

	inline QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &,
																				const QRectF  &) noexcept;

	inline void SetMousePosition(const QPointF &) noexcept;

	inline void CustomizeLayoutOfSizeBorder(const QRectF &);
private:
	ChangingSizeOfWidget   m_changing_size_of_widget;
	ChangingCursorOfWidget m_changing_cursor_of_widget;

	CursorShape m_cursor_shape;
private:
	CursorShape ReleaseGetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &);

	QRectF ReleaseGetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &,
																				const QRectF  &) noexcept;
};

inline ChangingSizeAndCursorOfWidget::ChangingSizeAndCursorOfWidget() noexcept
	: m_changing_cursor_of_widget(this->m_changing_size_of_widget.GetLayoutOfSizeBorder()),
	  m_cursor_shape(CursorShape::ArrowCursor)
{
}

inline CursorShape ChangingSizeAndCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &mouse_position)
{
	return this->ReleaseGetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(mouse_position);
}

inline QRectF ChangingSizeAndCursorOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &mouse_position,
																										   const QRectF  &geometry_of_widget) noexcept
{
	return this->ReleaseGetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(mouse_position, geometry_of_widget);
}

inline void ChangingSizeAndCursorOfWidget::SetMousePosition(const QPointF &mouse_position) noexcept
{
	this->m_changing_size_of_widget.SetMousePosition(mouse_position);
}

inline void ChangingSizeAndCursorOfWidget::CustomizeLayoutOfSizeBorder(const QRectF &geometry_of_widget)
{
	this->m_changing_size_of_widget.CustomizeLayoutOfSizeBorder(geometry_of_widget);
}
}  // namespace N_ChangingSizeAndCursorOfWidget

#endif  // CHANGING_SIZE_AND_CURSOR_OF_WIDGET_HPP
