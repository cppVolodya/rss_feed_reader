// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef CHANGING_SIZE_OF_WIDGET_HPP
#define CHANGING_SIZE_OF_WIDGET_HPP

#include <QPointF>
#include <QRectF>
#include <QApplication>

#include "types_aliases_of_changing_size_and_cursor_of_widget.hpp"
#include "layout_of_external_and_internal_rounded_border_of_widget.hpp"
#include "cursors_of_widget.hpp"


namespace N_ChangingSizeAndCursorOfWidget
{
using N_AbstractLayoutOfRoundedBorderOfWidget::LayoutOfExternalAndInternalRoundedBorderOfWidget;

using N_PainterOfRoundedBorderOfWidget::RoundnessOfRoundedBorderOfWidget;
using N_PainterOfRoundedBorderOfWidget::ThicknessOfRoundedBorderOfWidget;

using N_Widget::CursorShape;


class ChangingSizeOfWidget
{
public:
	inline ChangingSizeOfWidget() noexcept;

	inline void SetDefaultCharacteristics() noexcept;

	inline void CustomizeLayoutOfSizeBorder(const QRectF &);

	QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &,
																	     const QRectF  &) noexcept;

	[[nodiscard]] inline QPointF GetMousePosition() const noexcept;

	[[nodiscard]] inline const LayoutOfExternalAndInternalRoundedBorderOfWidget& GetLayoutOfSizeBorder() const noexcept;

	inline void SetMousePosition(const QPointF &) noexcept;

	inline void SetStateOfWidgetResize(CursorShape) noexcept;
private:
	enum class StateOfWidgetResize;
private:
	LayoutOfExternalAndInternalRoundedBorderOfWidget m_layout_of_size_border;

	StateOfWidgetResize m_state_of_widget_resize;

	QPointF m_old_mouse_position;
private:
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

[[nodiscard]] inline const LayoutOfExternalAndInternalRoundedBorderOfWidget& ChangingSizeOfWidget::GetLayoutOfSizeBorder() const noexcept
{
	return this->m_layout_of_size_border;
}

inline void ChangingSizeOfWidget::SetMousePosition(const QPointF &mouse_position) noexcept
{
	this->m_old_mouse_position = mouse_position;
}

inline void ChangingSizeOfWidget::SetStateOfWidgetResize(const CursorShape cursor_shape) noexcept
{
	switch(cursor_shape)
	{
	case CursorShape::ArrowCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::IDLE;
		break;
	case CursorShape::SizeTopVerticalCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP;
		break;
	case CursorShape::SizeBottomVerticalCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM;
		break;
	case CursorShape::SizeLeftHorizontalCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::LEFT;
		break;
	case CursorShape::SizeRightHorizontalCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::RIGHT;
		break;
	case CursorShape::SizeTopLeftDiagonalCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP_LEFT;
		break;
	case CursorShape::SizeTopRightDiagonalCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::TOP_RIGHT;
		break;
	case CursorShape::SizeBottomLeftDiagonalCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM_LEFT;
		break;
	case CursorShape::SizeBottomRightDiagonalCursor:
		this->m_state_of_widget_resize = StateOfWidgetResize::BOTTOM_RIGHT;
		break;
	default:  // NOLINT(clion-misra-cpp2008-6-4-5)
		qDebug() << "Cursor shape not recognized for setting widget resizing state!";
		QApplication::exit(EXIT_FAILURE);
		break;
	}
}
}  // namespace N_ChangingSizeAndCursorOfWidget

#endif  // CHANGING_SIZE_OF_WIDGET_HPP
