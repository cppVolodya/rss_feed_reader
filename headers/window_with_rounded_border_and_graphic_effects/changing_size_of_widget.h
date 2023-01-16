#ifndef RSS_FEED_READER_HEADERS_CHANGING_SIZE_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_CHANGING_SIZE_OF_WIDGET_H_

#include <QCursor>
#include <QPointF>
#include <QRectF>

#include "layout_of_external_and_internal_rounded_border_of_widget.h"


using distance = qreal;

class ChangingSizeOfWidget
{
public:
	const static RoundnessOfRoundedBorderOfWidget C_S_DEFAULT_ROUNDNESS_OF_LAYOUT_OF_SIZE_BORDER;  // roundness
	const static ThicknessOfRoundedBorderOfWidget C_S_DEFAULT_THICKNESS_OF_LAYOUT_OF_SIZE_BORDER;  // thickness

	constexpr static distance C_S_MINIMUM_DISTANCE_FOR_CURSOR_OF_SIZE_DIAGONAL{ 10.0 };  // minimum distance
public:
	inline ChangingSizeOfWidget() noexcept;

	[[nodiscard]] inline LayoutOfExternalAndInternalRoundedBorderOfWidget& GetLayout() noexcept;

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

#pragma region GetNewCursorShapeIfMousePositionLocatedOnEntireParts [functions]
	Qt::CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder  (const Characteristic &);  // right part

	Qt::CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder	(const Characteristic &);  // left part

	Qt::CursorShape GetNewCursorShapeIfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &) noexcept;  // central part
#pragma endregion GetNewCursorShapeIfMousePositionLocatedOnEntireParts [functions]

#pragma region GetNewCursorShapeIfMousePositionLocatedOnCertainParts [functions]
	Qt::CursorShape GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnTopPartLayoutOfSizeBorder   (const Characteristic &) noexcept;  // top part
	Qt::CursorShape GetNewCursorShapeOfSizeVerticalIfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &) noexcept;  // bottom part

	Qt::CursorShape GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnRightPartLayoutOfSizeBorder(const Characteristic &) noexcept;  // right part
	Qt::CursorShape GetNewCursorShapeOfSizeHorizontalIfMousePositionLocatedOnLeftPartLayoutOfSizeBorder (const Characteristic &) noexcept;  // left part

	Qt::CursorShape GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnTopRightPartLayoutOfSizeBorder(const Characteristic &);  // top right part
	Qt::CursorShape GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnTopLeftPartLayoutOfSizeBorder(const Characteristic &);  // top left part

	Qt::CursorShape GetNewCursorShapeOfSizeRightDiagonalIfMousePositionLocatedOnBottomRightPartLayoutOfSizeBorder(const Characteristic &);  // bottom right part
	Qt::CursorShape GetNewCursorShapeOfSizeLeftDiagonalIfMousePositionLocatedOnBottomLeftPartLayoutOfSizeBorder  (const Characteristic &);  // bottom left part
#pragma endregion GetNewCursorShapeIfMousePositionLocatedOnCertainParts [functions]

#pragma region VerifyOfMousePositionLocatedOnEntireParts [functions]
	inline static bool VerifyOfMousePositionLocatedOnEntireRightPartLayoutOfSizeBorder  (const Characteristic &) noexcept;  // right part

	inline static bool VerifyOfMousePositionLocatedOnEntireLeftPartLayoutOfSizeBorder   (const Characteristic &) noexcept;  // left part

	inline static bool VerifyOfMousePositionLocatedOnEntireCentralPartLayoutOfSizeBorder(const Characteristic &) noexcept;  // central part
#pragma endregion VerifyOfMousePositionLocatedOnEntireParts [functions]

#pragma region VerifyOfMousePositionLocatedOnCertainParts [functions]
	inline static bool VerifyOfMousePositionLocatedOnTopPartLayoutOfSizeBorder	 (const Characteristic &) noexcept;  // top part
	inline static bool VerifyOfMousePositionLocatedOnBottomPartLayoutOfSizeBorder(const Characteristic &) noexcept;  // bottom part

	inline static bool VerifyOfMousePositionLocatedOnRightPartLayoutOfSizeBorder      (const Characteristic &) noexcept;  // right part
	inline static bool VerifyOfMousePositionLocatedOnLeftPartLayoutOfSizeBorder	      (const Characteristic &) noexcept;  // left part
	inline static bool VerifyOfMousePositionLocatedOnRightOrLeftPartLayoutOfSizeBorder(const Characteristic &) noexcept;  // right or left part

	[[nodiscard]] inline bool VerifyOfMousePositionLocatedOnTopRightOrTopLeftPartLayoutOfSizeBorder(const Characteristic &) const;  // top right or top left part

	[[nodiscard]] inline bool VerifyOfMousePositionLocatedOnBottomRightOrBottomLeftPartLayoutOfSizeBorder(const Characteristic &) const;  // bottom right or bottom left part
#pragma endregion VerifyOfMousePositionLocatedOnCertainParts [functions]

#pragma region GetNewGeometryOfWidgetIfPressAndMoveMouseOnCertainParts [functions]
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopPartLayoutOfSizeBorder	 (const QPointF &, const QRectF &) noexcept;  // top part
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomPartLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;  // bottom part

	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnRightPartLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;  // right part
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnLeftPartLayoutOfSizeBorder	(const QPointF &, const QRectF &) noexcept;  // left part

	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopRightPartLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;  // top right part
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnTopLeftLayoutOfSizeBorder	   (const QPointF &, const QRectF &) noexcept;  // top left part

	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomRightPartLayoutOfSizeBorder(const QPointF &, const QRectF &) noexcept;  // bottom right part
	static QRectF GetNewGeometryOfWidgetIfPressAndMoveMouseOnBottomLeftPartLayoutOfSizeBorder (const QPointF &, const QRectF &) noexcept;  // bottom left part
#pragma endregion GetNewGeometryOfWidgetIfPressAndMoveMouseOnCertainParts [functions]
};

#pragma region AdditionalInternalDataForChangingSizeOfWidget [data]
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
	TOP_RESIZE,
	BOTTOM_RESIZE,

	RIGHT_RESIZE,
	LEFT_RESIZE,

	TOP_RIGHT_RESIZE,
	TOP_LEFT_RESIZE,

	BOTTOM_RIGHT_RESIZE,
	BOTTOM_LEFT_RESIZE,

	IDLE_RESIZE
};
#pragma endregion AdditionalInternalDataForChangingSizeOfWidget [data]

inline ChangingSizeOfWidget::ChangingSizeOfWidget() noexcept
	: m_state_of_widget_resize(StateOfWidgetResize::IDLE_RESIZE)
{
	SetDefaultSettings();
}

[[nodiscard]] inline LayoutOfExternalAndInternalRoundedBorderOfWidget& ChangingSizeOfWidget::GetLayout() noexcept
{
	return this->m_layout_of_size_border;
}

inline void ChangingSizeOfWidget::SetDefaultSettings() noexcept
{
	this->m_layout_of_size_border.SetRoundness(C_S_DEFAULT_ROUNDNESS_OF_LAYOUT_OF_SIZE_BORDER);
	this->m_layout_of_size_border.SetThickness(C_S_DEFAULT_THICKNESS_OF_LAYOUT_OF_SIZE_BORDER);
}

inline void ChangingSizeOfWidget::SetMousePosition(const QPointF &mouse_position) noexcept
{
	this->m_old_mouse_position = mouse_position;
}

#endif  // RSS_FEED_READER_HEADERS_CHANGING_SIZE_OF_WIDGET_H_
