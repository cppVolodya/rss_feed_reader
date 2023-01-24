// Copyright [2023] <Volodymyr Dorozhovets>"

#include <QApplication>

#include "changing_size_of_widget.hpp"


namespace N_Widget
{
Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &mouse_position)
{
	Characteristic characteristics{};
	this->SetCharacteristic(characteristics, mouse_position);

	Qt::CursorShape new_cursor_shape =
		this->GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(characteristics);

	if (new_cursor_shape == Qt::CursorShape::ArrowCursor)
	{
		new_cursor_shape = this->GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(characteristics);
	}

	if (new_cursor_shape == Qt::CursorShape::ArrowCursor)
	{
		new_cursor_shape = this->GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(characteristics);
	}

	if (new_cursor_shape == Qt::CursorShape::ArrowCursor)
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::IDLE;
	}

	return new_cursor_shape;
}

QRectF ChangingSizeOfWidget::GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &new_mouse_position,
																					 	   const QRectF  &geometry_of_widget) noexcept
{
	QRectF new_geometry_of_widget;
	QPointF displacement_of_mouse_position = new_mouse_position - this->m_old_mouse_position;

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
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape =
			this->GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(characteristics);

		if (new_cursor_shape == Qt::CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(characteristics);
		}

		if (new_cursor_shape == Qt::CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(characteristics);
		}
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape =
			this->GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(characteristics);

		if (new_cursor_shape == Qt::CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(characteristics);
		}

		if (new_cursor_shape == Qt::CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder(characteristics);
		}
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = this->GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder(characteristics);

		if (new_cursor_shape == Qt::CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(characteristics);
		}
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::LEFT;

		new_cursor_shape = Qt::CursorShape::SizeHorCursor;
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP_LEFT;

		new_cursor_shape = Qt::CursorShape::SizeFDiagCursor;
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM_LEFT;

		new_cursor_shape = Qt::CursorShape::SizeBDiagCursor;
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::RIGHT;

		new_cursor_shape = Qt::CursorShape::SizeHorCursor;
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP_RIGHT;

		new_cursor_shape = Qt::CursorShape::SizeBDiagCursor;
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM_RIGHT;

		new_cursor_shape = Qt::CursorShape::SizeFDiagCursor;
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP;

		new_cursor_shape = Qt::CursorShape::SizeVerCursor;
	}

	return new_cursor_shape;
}

Qt::CursorShape ChangingSizeOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	Qt::CursorShape new_cursor_shape = Qt::CursorShape::ArrowCursor;

	if (ChangingSizeOfWidget::VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(characteristics))
	{
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM;

		new_cursor_shape = Qt::CursorShape::SizeVerCursor;
	}

	return new_cursor_shape;
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
}  // namespace N_Widget
