// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef CHANGING_SIZE_OF_WIDGET_HPP
#define CHANGING_SIZE_OF_WIDGET_HPP

#include <QCursor>
#include <QPointF>
#include <QRectF>

#include "types_aliases_of_widget.hpp"
#include "layout_of_external_and_internal_rounded_border_of_widget.hpp"


namespace N_Widget
{
using N_AbstractLayoutOfRoundedBorderOfWidget::LayoutOfExternalAndInternalRoundedBorderOfWidget;

using N_PainterOfRoundedBorderOfWidget::RoundnessOfRoundedBorderOfWidget;
using N_PainterOfRoundedBorderOfWidget::ThicknessOfRoundedBorderOfWidget;

using N_PainterOfRoundedBorderOfWidget::T_Thickness;


class ChangingSizeOfWidget
{
public:
	inline ChangingSizeOfWidget() noexcept;

	inline void SetDefaultCharacteristics() noexcept;

	inline void CustomizeLayoutOfSizeBorder(const QRectF &);

	Qt::CursorShape GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &);

	QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &,
																	     const QRectF  &) noexcept;

	[[nodiscard]] inline QPointF GetMousePosition() const noexcept;

	inline void SetMousePosition(const QPointF &) noexcept;
private:
	struct Characteristic;

	enum class StateOfWidgetResize;
private:
	LayoutOfExternalAndInternalRoundedBorderOfWidget m_layout_of_size_border;

	StateOfWidgetResize m_state_of_widget_resize;

	QPointF m_old_mouse_position;
private:
	void SetCharacteristic(Characteristic &, const QPointF &) noexcept;

#pragma region GetNewCursorShapeIfMousePositionLocatedOnCertainParts [functions]
	Qt::CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder  (const Characteristic &);
	Qt::CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder	(const Characteristic &);
	Qt::CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	Qt::CursorShape GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder   (const Characteristic &) noexcept;
	Qt::CursorShape GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	Qt::CursorShape GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &) noexcept;
	Qt::CursorShape GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder (const Characteristic &) noexcept;

	Qt::CursorShape GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(const Characteristic &);
	Qt::CursorShape GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(const Characteristic &);

	Qt::CursorShape GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(const Characteristic &);
	Qt::CursorShape GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder  (const Characteristic &);
#pragma endregion GetNewCursorShapeIfMousePositionLocatedOnCertainParts [functions]

#pragma region VerifyOfMousePositionLocatedOnCertainParts [functions]
	inline static T_Success VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder  (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder   (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	inline static T_Success VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder	 (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	inline static T_Success VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder      (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder	   (const Characteristic &) noexcept;
	inline static T_Success VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	[[nodiscard]] inline T_Success VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder	  (const Characteristic &) const;
	[[nodiscard]] inline T_Success VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(const Characteristic &) const;
#pragma endregion VerifyOfMousePositionLocatedOnCertainParts [functions]

#pragma region GetNewGeometryOfWidgetIfPressAndMoveMouseOnCertainParts [functions]
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopPartLayoutOfSizeBorder	 (const QPointF &, const QRectF &) noexcept;
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomPartLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;

	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnRightPartLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnLeftPartLayoutOfSizeBorder	(const QPointF &, const QRectF &) noexcept;

	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopRightPartLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopLeftLayoutOfSizeBorder	   (const QPointF &, const QRectF &) noexcept;

	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomRightPartLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomLeftPartLayoutOfSizeBorder (const QPointF &, const QRectF &) noexcept;
#pragma endregion GetNewGeometryOfWidgetIfPressAndMoveMouseOnCertainParts [functions]
};

struct ChangingSizeOfWidget::Characteristic
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

enum class ChangingSizeOfWidget::StateOfWidgetResize
{
	TOP,
	BOTTOM,

	LEFT,
	RIGHT,

	TOP_LEFT,
	TOP_RIGHT,

	BOTTOM_LEFT,
	BOTTOM_RIGHT,

	IDLE
};

inline ChangingSizeOfWidget::ChangingSizeOfWidget() noexcept
	: m_state_of_widget_resize(StateOfWidgetResize::IDLE)
{
	SetDefaultCharacteristics();
}

inline void ChangingSizeOfWidget::SetDefaultCharacteristics() noexcept
{
	this->m_layout_of_size_border.SetRoundness(RoundnessOfRoundedBorderOfWidget(10.0, 10.0		  ));
	this->m_layout_of_size_border.SetThickness(ThicknessOfRoundedBorderOfWidget(8.0, 8.0, 8.0, 8.0));
}

inline void ChangingSizeOfWidget::CustomizeLayoutOfSizeBorder(const QRectF &geometry_of_widget)
{
	this->m_layout_of_size_border.Customize(geometry_of_widget);
}

[[nodiscard]] inline QPointF ChangingSizeOfWidget::GetMousePosition() const noexcept
{
	return this->m_old_mouse_position;
}

inline void ChangingSizeOfWidget::SetMousePosition(const QPointF &mouse_position) noexcept
{
	this->m_old_mouse_position = mouse_position;
}
}  // namespace N_Widget

#endif  // CHANGING_SIZE_OF_WIDGET_HPP
