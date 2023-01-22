// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef RSS_FEED_READER_HEADERS_CHANGING_SIZE_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_CHANGING_SIZE_OF_WIDGET_H_

#include <QCursor>
#include <QPointF>
#include <QRectF>

#include "layout_of_external_and_internal_rounded_border_of_widget.hpp"


class ChangingSizeOfWidget
{
public:
	inline ChangingSizeOfWidget() noexcept;

	inline void CustomizeLayoutOfSizeBorder(const QRectF &);

	Qt::CursorShape GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &);

	QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;

	inline void SetDefaultSettings() noexcept;

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
	inline static bool VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder  (const Characteristic &) noexcept;
	inline static bool VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder   (const Characteristic &) noexcept;
	inline static bool VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	inline static bool VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder	 (const Characteristic &) noexcept;
	inline static bool VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	inline static bool VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder      (const Characteristic &) noexcept;
	inline static bool VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder	      (const Characteristic &) noexcept;
	inline static bool VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(const Characteristic &) noexcept;

	[[nodiscard]] inline bool VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder		 (const Characteristic &) const;
	[[nodiscard]] inline bool VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(const Characteristic &) const;
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
	qreal m_position_x_of_mouse;
	qreal m_position_y_of_mouse;

	qreal m_width;
	qreal m_height;

	qreal m_thickness;

	qreal m_displacement_coefficient;

	qreal m_distance_of_x_for_cursor_of_size_diagonal;
	qreal m_distance_of_y_for_cursor_of_size_diagonal;
};

enum class ChangingSizeOfWidget::StateOfWidgetResize
{
	TOP,
	BOTTOM,

	RIGHT,
	LEFT,

	TOP_RIGHT,
	TOP_LEFT,

	BOTTOM_RIGHT,
	BOTTOM_LEFT,

	IDLE
};

inline ChangingSizeOfWidget::ChangingSizeOfWidget() noexcept
	: m_state_of_widget_resize(StateOfWidgetResize::IDLE)
{
	SetDefaultSettings();
}

inline void ChangingSizeOfWidget::CustomizeLayoutOfSizeBorder(const QRectF &geometry_of_widget)
{
	this->m_layout_of_size_border.Customize(geometry_of_widget);
}

inline void ChangingSizeOfWidget::SetDefaultSettings() noexcept
{
	this->m_layout_of_size_border.SetRoundness(RoundnessOfRoundedBorderOfWidget(10.0, 10.0		  ));
	this->m_layout_of_size_border.SetThickness(ThicknessOfRoundedBorderOfWidget(8.0, 8.0, 8.0, 8.0));
}

inline void ChangingSizeOfWidget::SetMousePosition(const QPointF &mouse_position) noexcept
{
	this->m_old_mouse_position = mouse_position;
}

#endif  // RSS_FEED_READER_HEADERS_CHANGING_SIZE_OF_WIDGET_H_
