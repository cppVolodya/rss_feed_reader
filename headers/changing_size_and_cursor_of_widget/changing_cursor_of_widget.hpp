// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef CHANGING_CURSOR_OF_WIDGET_HPP
#define CHANGING_CURSOR_OF_WIDGET_HPP

#include <QPointF>

#include "types_aliases_of_changing_size_and_cursor_of_widget.hpp"
#include "layout_of_external_and_internal_rounded_border_of_widget.hpp"
#include "cursors_of_widget.hpp"


namespace N_ChangingSizeAndCursorOfWidget
{
using N_AbstractLayoutOfRoundedBorderOfWidget::LayoutOfExternalAndInternalRoundedBorderOfWidget;

using N_Widget::CursorShape;

using N_PainterOfRoundedBorderOfWidget::T_Thickness;


class ChangingCursorOfWidget
{
public:
	explicit inline ChangingCursorOfWidget(const LayoutOfExternalAndInternalRoundedBorderOfWidget &) noexcept;

	CursorShape GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &);
private:
	struct Characteristic;
private:
	const LayoutOfExternalAndInternalRoundedBorderOfWidget& m_layout_of_size_border;
private:
	void SetCharacteristic(Characteristic &, const QPointF &) noexcept;

#pragma region GetNewCursorShapeIfMousePositionLocatedOnCertainParts [functions]
	CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder  (const Characteristic &);
	CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder	(const Characteristic &);
	static CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	static CursorShape GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder   (const Characteristic &) noexcept;
	static CursorShape GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	static CursorShape GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &) noexcept;
	static CursorShape GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder (const Characteristic &) noexcept;

	CursorShape GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(const Characteristic &);
	CursorShape GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(const Characteristic &);

	CursorShape GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(const Characteristic &);
	CursorShape GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder  (const Characteristic &);
#pragma endregion GetNewCursorShapeIfMousePositionLocatedOnCertainParts [functions]

#pragma region VerifyOfMousePositionLocatedOnCertainParts [functions]
	inline static T_Success VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder  (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder   (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	inline static T_Success VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder	  (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	inline static T_Success VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder      (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder	   (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	[[nodiscard]] inline T_Success VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder	  (const Characteristic &) const;
	[[nodiscard]] inline T_Success VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(const Characteristic &) const;
#pragma endregion VerifyOfMousePositionLocatedOnCertainParts [functions]
};

struct ChangingCursorOfWidget::Characteristic
{
public:
	T_Position m_position_x_of_mouse;
	T_Position m_position_y_of_mouse;

	T_Distance m_width;
	T_Distance m_height;

	T_Thickness m_thickness;

	T_Distance m_bounding_distance;

	T_Distance m_distance_of_x_for_cursor_of_size_diagonal;
	T_Distance m_distance_of_y_for_cursor_of_size_diagonal;
};

inline ChangingCursorOfWidget::ChangingCursorOfWidget(const LayoutOfExternalAndInternalRoundedBorderOfWidget &layout_of_size_border) noexcept
	: m_layout_of_size_border(layout_of_size_border)
{
}
}  // namespace N_ChangingSizeAndCursorOfWidget

#endif  // CHANGING_CURSOR_OF_WIDGET_HPP
