// Copyright [2023] <Volodymyr Dorozhovets>"

#include "changing_cursor_of_widget.hpp"


namespace N_ChangingSizeAndCursorOfWidget
{
CursorShape ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &mouse_position)
{
	Characteristic characteristics{};
	this->SetCharacteristic(characteristics, mouse_position);

	CursorShape new_cursor_shape =
		this->GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(characteristics);

	if (new_cursor_shape == CursorShape::ArrowCursor)
	{
		new_cursor_shape = this->GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(characteristics);
	}

	if (new_cursor_shape == CursorShape::ArrowCursor)
	{
		new_cursor_shape = ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(characteristics);
	}

	return new_cursor_shape;
}

void ChangingCursorOfWidget::SetCharacteristic(Characteristic &characteristics, const QPointF &mouse_position) noexcept
{
	characteristics.m_position_x_of_mouse = mouse_position.x();
	characteristics.m_position_y_of_mouse = mouse_position.y();

	characteristics.m_width  = this->m_layout_of_size_border.GetSize().width();
	characteristics.m_height = this->m_layout_of_size_border.GetSize().height();

	characteristics.m_thickness = this->m_layout_of_size_border.GetThicknessOfLeft();

	characteristics.m_bounding_distance = this->m_layout_of_size_border.GetBoundingThickness().GetMaximumValue();

	constexpr qreal minimum_distance_for_cursor_of_size_diagonal = 10.0;

	characteristics.m_distance_of_x_for_cursor_of_size_diagonal =
		(this->m_layout_of_size_border.GetRoundnessOfX() > minimum_distance_for_cursor_of_size_diagonal)
		? this->m_layout_of_size_border.GetRoundnessOfX()
		: minimum_distance_for_cursor_of_size_diagonal;

	characteristics.m_distance_of_y_for_cursor_of_size_diagonal =
		(this->m_layout_of_size_border.GetRoundnessOfY() > minimum_distance_for_cursor_of_size_diagonal)
		? this->m_layout_of_size_border.GetRoundnessOfY()
		: minimum_distance_for_cursor_of_size_diagonal;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape =
			ChangingCursorOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(characteristics);

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(characteristics);
		}

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(characteristics);
		}
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape =
			ChangingCursorOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(characteristics);

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(characteristics);
		}

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = this->GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder(characteristics);
		}
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = ChangingCursorOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder(characteristics);

		if (new_cursor_shape == CursorShape::ArrowCursor)
		{
			new_cursor_shape = ChangingCursorOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(characteristics);
		}
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = CursorShape::SizeLeftHorizontalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = CursorShape::SizeTopLeftDiagonalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = CursorShape::SizeBottomLeftDiagonalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = CursorShape::SizeRightHorizontalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = CursorShape::SizeTopRightDiagonalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(const Characteristic &characteristics)
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (this->VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = CursorShape::SizeBottomRightDiagonalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = CursorShape::SizeTopVerticalCursor;
	}

	return new_cursor_shape;
}

CursorShape ChangingCursorOfWidget::GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	CursorShape new_cursor_shape = CursorShape::ArrowCursor;

	if (ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(characteristics))
	{
		new_cursor_shape = CursorShape::SizeBottomVerticalCursor;
	}

	return new_cursor_shape;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return (characteristics.m_width - characteristics.m_distance_of_x_for_cursor_of_size_diagonal) <= characteristics.m_position_x_of_mouse &&
		    characteristics.m_position_x_of_mouse 											       <= characteristics.m_width;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_bounding_distance   <= characteristics.m_position_x_of_mouse &&
		   characteristics.m_position_x_of_mouse <= characteristics.m_distance_of_x_for_cursor_of_size_diagonal;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_distance_of_x_for_cursor_of_size_diagonal <= characteristics.m_position_x_of_mouse &&
		   characteristics.m_position_x_of_mouse 					   <= (characteristics.m_width - characteristics.m_distance_of_x_for_cursor_of_size_diagonal);
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_bounding_distance   <= characteristics.m_position_y_of_mouse &&
		   characteristics.m_position_y_of_mouse <= characteristics.m_thickness;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return (characteristics.m_height - characteristics.m_thickness) <= characteristics.m_position_y_of_mouse &&
		    characteristics.m_position_y_of_mouse 					<= characteristics.m_height;
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return (characteristics.m_width - characteristics.m_thickness) <= characteristics.m_position_x_of_mouse &&
		    VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(characteristics);
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_position_x_of_mouse <= characteristics.m_thickness &&
		   VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(characteristics);
}

inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) noexcept
{
	return characteristics.m_distance_of_y_for_cursor_of_size_diagonal <= characteristics.m_position_y_of_mouse &&
		   characteristics.m_position_y_of_mouse 					   <= (characteristics.m_height - characteristics.m_distance_of_y_for_cursor_of_size_diagonal);
}

[[nodiscard]] inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) const
{
	QPointF mouse_position{ characteristics.m_position_x_of_mouse, characteristics.m_position_y_of_mouse };

	return (characteristics.m_bounding_distance   <= characteristics.m_position_y_of_mouse &&
			characteristics.m_position_y_of_mouse <= characteristics.m_distance_of_y_for_cursor_of_size_diagonal) &&
			this->m_layout_of_size_border.contains(mouse_position);
}

[[nodiscard]] inline bool ChangingCursorOfWidget::VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(const Characteristic &characteristics) const
{
	QPointF mouse_position{ characteristics.m_position_x_of_mouse, characteristics.m_position_y_of_mouse };

	return this->m_layout_of_size_border.contains(mouse_position);
}
}  // namespace N_ChangingSizeAndCursorOfWidget
