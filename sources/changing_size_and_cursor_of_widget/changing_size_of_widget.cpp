// Copyright [2023] <Volodymyr Dorozhovets>"

#include <QApplication>

#include "changing_size_of_widget.hpp"


namespace N_ChangingSizeAndCursorOfWidget
{
QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &new_mouse_position,
																						  const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget;
	QPointF displacement_of_mouse_position = new_mouse_position - this->GetMousePosition();

	switch (this->m_state_of_widget_resize)
	{
	case StateOfWidgetResize::TOP:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopPartLayoutOfSizeBorder(displacement_of_mouse_position,
																									  geometry_of_widget);
		break;
	case StateOfWidgetResize::BOTTOM:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomPartLayoutOfSizeBorder(displacement_of_mouse_position,
																										 geometry_of_widget);
		break;
	case StateOfWidgetResize::LEFT:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnLeftPartLayoutOfSizeBorder(displacement_of_mouse_position,
																									   geometry_of_widget);
		break;
	case StateOfWidgetResize::RIGHT:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnRightPartLayoutOfSizeBorder(displacement_of_mouse_position,
																										geometry_of_widget);
		break;
	case StateOfWidgetResize::TOP_LEFT:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopLeftLayoutOfSizeBorder(displacement_of_mouse_position,
																									  geometry_of_widget);
		break;
	case StateOfWidgetResize::TOP_RIGHT:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopRightPartLayoutOfSizeBorder(displacement_of_mouse_position,
																										   geometry_of_widget);
		break;
	case StateOfWidgetResize::BOTTOM_LEFT:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomLeftPartLayoutOfSizeBorder(displacement_of_mouse_position,
																											 geometry_of_widget);
		break;
	case StateOfWidgetResize::BOTTOM_RIGHT:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomRightPartLayoutOfSizeBorder(displacement_of_mouse_position,
																											  geometry_of_widget);
		break;
	case StateOfWidgetResize::IDLE:
		new_geometry_of_widget = geometry_of_widget;
		break;
	default:  // NOLINT(clion-misra-cpp2008-6-4-5)
		qDebug() << "A different widget resizing state is selected!";
		QApplication::exit(EXIT_FAILURE);
		break;
	}

	this->SetMousePosition(new_mouse_position);

	return new_geometry_of_widget;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopPartLayoutOfSizeBorder(const QPointF &displacement_of_mouse_position,
																								  const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget = geometry_of_widget;
	new_geometry_of_widget.setTop(new_geometry_of_widget.top() + displacement_of_mouse_position.y());

	return new_geometry_of_widget;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomPartLayoutOfSizeBorder(const QPointF &displacement_of_mouse_position,
																									 const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget = geometry_of_widget;
	new_geometry_of_widget.setBottom(new_geometry_of_widget.bottom() + displacement_of_mouse_position.y());

	return new_geometry_of_widget;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnRightPartLayoutOfSizeBorder(const QPointF &displacement_of_mouse_position,
																									const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget = geometry_of_widget;
	new_geometry_of_widget.setRight(new_geometry_of_widget.right() + displacement_of_mouse_position.x());

	return new_geometry_of_widget;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnLeftPartLayoutOfSizeBorder(const QPointF &displacement_of_mouse_position,
																								   const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget = geometry_of_widget;
	new_geometry_of_widget.setLeft(new_geometry_of_widget.left() + displacement_of_mouse_position.x());

	return new_geometry_of_widget;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopRightPartLayoutOfSizeBorder(const QPointF &displacement_of_mouse_position,
																									   const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget = geometry_of_widget;
	new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopPartLayoutOfSizeBorder  (displacement_of_mouse_position,
																								    new_geometry_of_widget);

	new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnRightPartLayoutOfSizeBorder(displacement_of_mouse_position,
																								    new_geometry_of_widget);

	return new_geometry_of_widget;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopLeftLayoutOfSizeBorder(const QPointF &displacement_of_mouse_position,
																								  const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget = geometry_of_widget;
	new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopPartLayoutOfSizeBorder (displacement_of_mouse_position,
																								   new_geometry_of_widget);

	new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnLeftPartLayoutOfSizeBorder(displacement_of_mouse_position,
																								   new_geometry_of_widget);

	return new_geometry_of_widget;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomRightPartLayoutOfSizeBorder(const QPointF &displacement_of_mouse_position,
																										  const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget = geometry_of_widget;
	new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomPartLayoutOfSizeBorder(displacement_of_mouse_position,
																									 new_geometry_of_widget);

	new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnRightPartLayoutOfSizeBorder (displacement_of_mouse_position,
																									 new_geometry_of_widget);

	return new_geometry_of_widget;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomLeftPartLayoutOfSizeBorder(const QPointF &displacement_of_mouse_position,
																										 const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget = geometry_of_widget;
	new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomPartLayoutOfSizeBorder(displacement_of_mouse_position,
																									 new_geometry_of_widget);

	new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnLeftPartLayoutOfSizeBorder  (displacement_of_mouse_position,
																									 new_geometry_of_widget);

	return new_geometry_of_widget;
}
}  // namespace N_ChangingSizeAndCursorOfWidget
