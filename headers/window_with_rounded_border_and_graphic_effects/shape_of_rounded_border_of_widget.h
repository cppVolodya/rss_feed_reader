#ifndef RSS_FEED_READER_HEADERS_SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QRectF>

#include "thickness_of_rounded_border_of_widget.h"


using displacement = qreal;

class ShapeOfRoundedBorderOfWidget
{
public:
	constexpr inline ShapeOfRoundedBorderOfWidget() noexcept;

	inline void CustomizeGeometry(const QRectF &) noexcept;

	[[nodiscard]] constexpr inline QRectF GetExternalRectangle() const noexcept;
	[[nodiscard]] constexpr inline QRectF GetInternalRectangle() const noexcept;

	[[nodiscard]] constexpr inline thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfLeft  () const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfRight () const noexcept;

	[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] constexpr inline displacement GetDisplacementCoefficient() const noexcept;

	[[nodiscard]] constexpr inline QSizeF GetSize() const noexcept;

	inline void SetThicknessOfTop   (thickness) noexcept;
	inline void SetThicknessOfBottom(thickness) noexcept;
	inline void SetThicknessOfLeft  (thickness) noexcept;
	inline void SetThicknessOfRight (thickness) noexcept;

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(displacement) noexcept;
private:
	QRectF m_external_rectangle;
	QRectF m_internal_rectangle;

	ThicknessOfRoundedBorderOfWidget m_thickness;

	displacement m_displacement_coefficient;
private:
	void ReleaseCustomizeGeometry(const QRectF &) noexcept;

	inline void SetGeometry(QRectF) noexcept;

	void ReleaseSetDisplacementCoefficient(QRectF &) const noexcept;

#pragma region ReleaseSetThickness [functions]
	void ReleaseSetThickness() noexcept;

	inline void ReleaseSetThicknessOfTop   () noexcept;
	inline void ReleaseSetThicknessOfBottom() noexcept;
	inline void ReleaseSetThicknessOfLeft  () noexcept;
	inline void ReleaseSetThicknessOfRight () noexcept;
#pragma endregion ReleaseSetThickness [functions]
};

constexpr inline ShapeOfRoundedBorderOfWidget::ShapeOfRoundedBorderOfWidget() noexcept
	: m_displacement_coefficient(0.0)
{
}

inline void ShapeOfRoundedBorderOfWidget::CustomizeGeometry(const QRectF &geometry_of_widget) noexcept
{
	this->ReleaseCustomizeGeometry(geometry_of_widget);
}

[[nodiscard]] constexpr inline QRectF ShapeOfRoundedBorderOfWidget::GetExternalRectangle() const noexcept
{
	return m_external_rectangle;
}

[[nodiscard]] constexpr inline QRectF ShapeOfRoundedBorderOfWidget::GetInternalRectangle() const noexcept
{
	return m_internal_rectangle;
}

[[nodiscard]] constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_thickness.GetThicknessOfTop();
}

[[nodiscard]] constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_thickness.GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_thickness.GetThicknessOfLeft();
}

[[nodiscard]] constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_thickness.GetThicknessOfRight();
}

[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget ShapeOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_thickness;
}

[[nodiscard]] constexpr inline displacement ShapeOfRoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_displacement_coefficient;
}

[[nodiscard]] constexpr inline QSizeF ShapeOfRoundedBorderOfWidget::GetSize() const noexcept
{
	return this->m_external_rectangle.size();
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

inline void ShapeOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_thickness = thickness;
}

inline void ShapeOfRoundedBorderOfWidget::SetDisplacementCoefficient(displacement displacement_coefficient) noexcept
{
	this->m_displacement_coefficient = displacement_coefficient;
}

#endif  // RSS_FEED_READER_HEADERS_SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_H_
