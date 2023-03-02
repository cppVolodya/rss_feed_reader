// Copyright [2023] <Volodymyr Dorozhovets>"

#include "changing_cursor_of_widget.hpp"


namespace N_ChangingSizeAndCursorOfWidget
{
CursorShape ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &mouse_position)
{
	Characteristic characteristic{};
	this->SetCharacteristic(characteristic, mouse_position);

	CursorShape new_cursor_shape =
		this->GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(characteristic);

	if (new_cursor_shape == CursorShape::ArrowCursor)
	{
		new_cursor_shape = this->GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(characteristic);
	}

	if (new_cursor_shape == CursorShape::ArrowCursor)
	{
		new_cursor_shape = ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(characteristic);
	}

	return new_cursor_shape;
}

void ChangingCursorOfWidget::SetCharacteristic(Characteristic &characteristic, const QPointF &mouse_position) noexcept
{
	characteristic.m_position_x_of_mouse = mouse_position.x();
	characteristic.m_position_y_of_mouse = mouse_position.y();

	characteristic.m_width  = this->m_layout_of_size_border.GetSize().width();
	characteristic.m_height = this->m_layout_of_size_border.GetSize().height();

	characteristic.m_thickness = this->m_layout_of_size_border.GetThicknessOfLeft();

	characteristic.m_bounding_distance = this->m_layout_of_size_border.GetBoundingThickness().GetMaximumValue();

	constexpr qreal minimum_distance_for_cursor_of_size_diagonal = 10.0;

	characteristic.m_distance_of_x_for_cursor_of_size_diagonal =
		(this->m_layout_of_size_border.GetRoundnessOfX() > minimum_distance_for_cursor_of_size_diagonal)
		? this->m_layout_of_size_border.GetRoundnessOfX()
		: minimum_distance_for_cursor_of_size_diagonal;

	characteristic.m_distance_of_y_for_cursor_of_size_diagonal =
		(this->m_layout_of_size_border.GetRoundnessOfY() > minimum_distance_for_cursor_of_size_diagonal)
		? this->m_layout_of_size_border.GetRoundnessOfY()
		: minimum_distance_for_cursor_of_size_diagonal;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(const Characteristic &characteristic)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape =
			ChangingCursorOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(characteristic);

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(characteristic);
		}

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(characteristic);
		}
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(const Characteristic &characteristic)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape =
			ChangingCursorOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(characteristic);

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(characteristic);
		}

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder(characteristic);
		}
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = ChangingCursorOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder(characteristic);

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = ChangingCursorOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(characteristic);
		}
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = CursorShape::SizeLeftHorizontalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(const Characteristic &characteristic)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = CursorShape::SizeTopLeftDiagonalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder(const Characteristic &characteristic)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = CursorShape::SizeBottomLeftDiagonalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = CursorShape::SizeRightHorizontalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(const Characteristic &characteristic)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = CursorShape::SizeTopRightDiagonalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(const Characteristic &characteristic)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = CursorShape::SizeBottomRightDiagonalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = CursorShape::SizeTopVerticalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(characteristic))
	{
		new_cursor_shape = CursorShape::SizeBottomVerticalCursor;
	}

	return new_cursor_shape;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	return (characteristic.m_width - characteristic.m_distance_of_x_for_cursor_of_size_diagonal) <= characteristic.m_position_x_of_mouse &&
		    characteristic.m_position_x_of_mouse 											       <= characteristic.m_width;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	return characteristic.m_bounding_distance   <= characteristic.m_position_x_of_mouse &&
		   characteristic.m_position_x_of_mouse <= characteristic.m_distance_of_x_for_cursor_of_size_diagonal;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	return characteristic.m_distance_of_x_for_cursor_of_size_diagonal <= characteristic.m_position_x_of_mouse &&
		   characteristic.m_position_x_of_mouse 					   <= (characteristic.m_width - characteristic.m_distance_of_x_for_cursor_of_size_diagonal);
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	return characteristic.m_bounding_distance   <= characteristic.m_position_y_of_mouse &&
		   characteristic.m_position_y_of_mouse <= characteristic.m_thickness;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	return (characteristic.m_height - characteristic.m_thickness) <= characteristic.m_position_y_of_mouse &&
		    characteristic.m_position_y_of_mouse 					<= characteristic.m_height;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	return (characteristic.m_width - characteristic.m_thickness) <= characteristic.m_position_x_of_mouse &&
		    VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(characteristic);
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	return characteristic.m_position_x_of_mouse <= characteristic.m_thickness &&
		   VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(characteristic);
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(const Characteristic &characteristic) noexcept
{
	return characteristic.m_distance_of_y_for_cursor_of_size_diagonal <= characteristic.m_position_y_of_mouse &&
		   characteristic.m_position_y_of_mouse 					   <= (characteristic.m_height - characteristic.m_distance_of_y_for_cursor_of_size_diagonal);
}

[[nodiscard]] inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(const Characteristic &characteristic) const
{
	QPointF mouse_position{ characteristic.m_position_x_of_mouse, characteristic.m_position_y_of_mouse };

	return (characteristic.m_bounding_distance   <= characteristic.m_position_y_of_mouse &&
			characteristic.m_position_y_of_mouse <= characteristic.m_distance_of_y_for_cursor_of_size_diagonal) &&
			this->m_layout_of_size_border.contains(mouse_position);
}

[[nodiscard]] inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(const Characteristic &characteristic) const
{
	QPointF mouse_position{ characteristic.m_position_x_of_mouse, characteristic.m_position_y_of_mouse };

	return this->m_layout_of_size_border.contains(mouse_position);
}
}  // namespace N_ChangingSizeAndCursorOfWidget
