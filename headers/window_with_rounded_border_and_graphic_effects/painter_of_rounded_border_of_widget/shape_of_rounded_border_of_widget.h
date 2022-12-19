#ifndef RSS_FEED_READER_HEADERS_SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QRectF>

#include "thickness_of_rounded_border_of_widget.h"


class ShapeOfRoundedBorderOfWidget
{
public:
	void CustomizeGeometry(const QRectF &) noexcept;

	[[nodiscard]] constexpr inline QRectF GetExternalRectangle() const noexcept;
	[[nodiscard]] constexpr inline QRectF GetInternalRectangle() const noexcept;

	[[nodiscard]] constexpr inline thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfLeft  () const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfRight () const noexcept;

	inline void SetThicknessOfTop   (thickness) noexcept;
	inline void SetThicknessOfBottom(thickness) noexcept;
	inline void SetThicknessOfLeft  (thickness) noexcept;
	inline void SetThicknessOfRight (thickness) noexcept;
private:
	QRectF m_external_rectangle;
	QRectF m_internal_rectangle;

	ThicknessOfRoundedBorderOfWidget m_thickness;
private:
	void SetGeometry(const QRectF &) noexcept;

	void ReleaseSetThickness() noexcept;

	inline void ReleaseSetThicknessOfTop   () noexcept;
	inline void ReleaseSetThicknessOfBottom() noexcept;
	inline void ReleaseSetThicknessOfLeft  () noexcept;
	inline void ReleaseSetThicknessOfRight () noexcept;
};

constexpr inline QRectF ShapeOfRoundedBorderOfWidget::GetExternalRectangle() const noexcept
{
	return m_external_rectangle;
}

constexpr inline QRectF ShapeOfRoundedBorderOfWidget::GetInternalRectangle() const noexcept
{
	return m_internal_rectangle;
}

constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_thickness.GetThicknessOfTop();
}

constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_thickness.GetThicknessOfBottom();
}

constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_thickness.GetThicknessOfLeft();
}

constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_thickness.GetThicknessOfRight();
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfTop(const thickness thickness_of_top) noexcept
{
	this->m_thickness.SetThicknessOfTop(thickness_of_top);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfBottom(const thickness thickness_of_bottom) noexcept
{
	this->m_thickness.SetThicknessOfBottom(thickness_of_bottom);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfLeft(const thickness thickness_of_left) noexcept
{
	this->m_thickness.SetThicknessOfLeft(thickness_of_left);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfRight(const thickness thickness_of_right) noexcept
{
	this->m_thickness.SetThicknessOfRight(thickness_of_right);
}

#endif  // RSS_FEED_READER_HEADERS_SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_H_
