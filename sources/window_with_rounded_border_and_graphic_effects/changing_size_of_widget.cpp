#include <qdebug.h>

#include "changing_size_of_widget.h"


Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &mouse_position)
{
	Characteristic characteristics{};
	this->SetCharacteristic(characteristics, mouse_position);

	if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(characteristics);
			cursor_shape != Qt::CursorShape::ArrowCursor)
	{
		return cursor_shape;
	}

	if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(characteristics);
			cursor_shape != Qt::CursorShape::ArrowCursor)
	{
		return cursor_shape;
	}

	if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(characteristics);
			cursor_shape != Qt::CursorShape::ArrowCursor)
	{
		return cursor_shape;
	}

	this->m_state_of_widget_resize = StateOfWidgetResize::IDLE_RESIZE;

	return Qt::CursorShape::ArrowCursor;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &new_mouse_position,
																					 	   const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget;
	QPointF displacement_of_mouse_position = new_mouse_position - this->m_old_mouse_position;

	switch (this->m_state_of_widget_resize)
	{
	case StateOfWidgetResize::TOP_RESIZE:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopPartLayoutOfSizeBorder(displacement_of_mouse_position,
																									  geometry_of_widget);

		break;
	case StateOfWidgetResize::BOTTOM_RESIZE:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomPartLayoutOfSizeBorder(displacement_of_mouse_position,
																										 geometry_of_widget);

		break;
	case StateOfWidgetResize::RIGHT_RESIZE:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnRightPartLayoutOfSizeBorder(displacement_of_mouse_position,
																										geometry_of_widget);

		break;
	case StateOfWidgetResize::LEFT_RESIZE:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnLeftPartLayoutOfSizeBorder(displacement_of_mouse_position,
																									   geometry_of_widget);

		break;
	case StateOfWidgetResize::TOP_RIGHT_RESIZE:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopRightPartLayoutOfSizeBorder(displacement_of_mouse_position,
																										   geometry_of_widget);

		break;
	case StateOfWidgetResize::TOP_LEFT_RESIZE:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopLeftLayoutOfSizeBorder(displacement_of_mouse_position,
																									  geometry_of_widget);

		break;
	case StateOfWidgetResize::BOTTOM_RIGHT_RESIZE:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomRightPartLayoutOfSizeBorder(displacement_of_mouse_position,
																											  geometry_of_widget);

		break;
	case StateOfWidgetResize::BOTTOM_LEFT_RESIZE:
		new_geometry_of_widget = GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomLeftPartLayoutOfSizeBorder(displacement_of_mouse_position,
																										     geometry_of_widget);

		break;
	case StateOfWidgetResize::IDLE_RESIZE:
		new_geometry_of_widget = geometry_of_widget;
		break;
	default:
		qDebug() << "A different widget resizing state is selected!";
		new_geometry_of_widget = geometry_of_widget;
	}

	this->SetMousePosition(new_mouse_position);

	return new_geometry_of_widget;
}

void ChangingSizeOfWidget::SetCharacteristic(Characteristic &characteristics, const QPointF &mouse_position) noexcept
{
	characteristics.m_position_x_of_mouse = mouse_position.x();
	characteristics.m_position_y_of_mouse = mouse_position.y();

	characteristics.m_width  = this->m_layout_of_size_border.GetSize().width();
	characteristics.m_height = this->m_layout_of_size_border.GetSize().height();

	characteristics.m_thickness = this->m_layout_of_size_border.GetThicknessOfLeft();

	characteristics.m_displacement_coefficient = this->m_layout_of_size_border.GetDisplacementCoefficient();

	constexpr qreal minimum_distance_for_cursor_of_size_diagonal{ 10.0 };

	characteristics.m_distance_of_x_for_cursor_of_size_diagonal =
		(this->m_layout_of_size_border.GetRoundnessOfX() > minimum_distance_for_cursor_of_size_diagonal)
		? this->m_layout_of_size_border.GetRoundnessOfX()
		: minimum_distance_for_cursor_of_size_diagonal;

	characteristics.m_distance_of_y_for_cursor_of_size_diagonal =
		(this->m_layout_of_size_border.GetRoundnessOfY() > minimum_distance_for_cursor_of_size_diagonal)
		? this->m_layout_of_size_border.GetRoundnessOfY()
		: minimum_distance_for_cursor_of_size_diagonal;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(characteristics))
	{
		if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(characteristics);
				cursor_shape != Qt::CursorShape::ArrowCursor)
		{
			return cursor_shape;
		}

		if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(characteristics);
				cursor_shape != Qt::CursorShape::ArrowCursor)
		{
			return cursor_shape;
		}

		if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(characteristics);
				cursor_shape != Qt::CursorShape::ArrowCursor)
		{
			return cursor_shape;
		}
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(characteristics))
	{
		if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(characteristics);
				cursor_shape != Qt::CursorShape::ArrowCursor)
		{
			return cursor_shape;
		}

		if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(characteristics);
				cursor_shape != Qt::CursorShape::ArrowCursor)
		{
			return cursor_shape;
		}

		if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder(characteristics);
				cursor_shape != Qt::CursorShape::ArrowCursor)
		{
			return cursor_shape;
		}
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(characteristics))
	{
		if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder(characteristics);
				cursor_shape != Qt::CursorShape::ArrowCursor)
		{
			return cursor_shape;
		}

		if (Qt::CursorShape cursor_shape = this->GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(characteristics);
				cursor_shape != Qt::CursorShape::ArrowCursor)
		{
			return cursor_shape;
		}
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::LEFT_RESIZE;

		return Qt::CursorShape::SizeHorCursor;
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	if (this->VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP_LEFT_RESIZE;

		return Qt::CursorShape::SizeFDiagCursor;
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	if (this->VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM_LEFT_RESIZE;

		return Qt::CursorShape::SizeBDiagCursor;
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::RIGHT_RESIZE;

		return Qt::CursorShape::SizeHorCursor;
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	if (this->VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP_RIGHT_RESIZE;

		return Qt::CursorShape::SizeBDiagCursor;
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	if (this->VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM_RIGHT_RESIZE;

		return Qt::CursorShape::SizeFDiagCursor;
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP_RESIZE;

		return Qt::CursorShape::SizeVerCursor;
	}

	return Qt::CursorShape::ArrowCursor;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM_RESIZE;

		return Qt::CursorShape::SizeVerCursor;
	}

	return Qt::CursorShape::ArrowCursor;
}

inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return (characteristics.m_width - characteristics.m_distance_of_x_for_cursor_of_size_diagonal) <= characteristics.m_position_x_of_mouse &&
		    characteristics.m_position_x_of_mouse 											       <= characteristics.m_width;
}

inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_displacement_coefficient <= characteristics.m_position_x_of_mouse &&
		   characteristics.m_position_x_of_mouse      <= characteristics.m_distance_of_x_for_cursor_of_size_diagonal;
}

inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_distance_of_x_for_cursor_of_size_diagonal <= characteristics.m_position_x_of_mouse &&
		   characteristics.m_position_x_of_mouse 					   <= (characteristics.m_width - characteristics.m_distance_of_x_for_cursor_of_size_diagonal);
}

inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_displacement_coefficient <= characteristics.m_position_y_of_mouse &&
		   characteristics.m_position_y_of_mouse 	  <= characteristics.m_thickness;
}

inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return (characteristics.m_height - characteristics.m_thickness) <= characteristics.m_position_y_of_mouse &&
		    characteristics.m_position_y_of_mouse 					<= characteristics.m_height;
}

inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return (characteristics.m_width - characteristics.m_thickness) <= characteristics.m_position_x_of_mouse &&
			VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(characteristics);
}

inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_position_x_of_mouse <= characteristics.m_thickness &&
		   VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(characteristics);
}

inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_distance_of_y_for_cursor_of_size_diagonal <= characteristics.m_position_y_of_mouse &&
	       characteristics.m_position_y_of_mouse 					   <= (characteristics.m_height - characteristics.m_distance_of_y_for_cursor_of_size_diagonal);
}

[[nodiscard]] inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) const
{
	QPointF mouse_position{ characteristics.m_position_x_of_mouse, characteristics.m_position_y_of_mouse };

	return (characteristics.m_displacement_coefficient <= characteristics.m_position_y_of_mouse &&
			characteristics.m_position_y_of_mouse      <= characteristics.m_distance_of_y_for_cursor_of_size_diagonal) &&
				this->m_layout_of_size_border.contains(mouse_position);
}

[[nodiscard]] inline bool ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) const
{
	QPointF mouse_position{ characteristics.m_position_x_of_mouse, characteristics.m_position_y_of_mouse };

	return this->m_layout_of_size_border.contains(mouse_position);
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
