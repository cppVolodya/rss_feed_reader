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

#pragma region GetRectangles [functions]
	[[nodiscard]] constexpr inline QRectF GetExternalRectangle() const noexcept;  // external
	[[nodiscard]] constexpr inline QRectF GetInternalRectangle() const noexcept;  // internal
#pragma endregion GetRectangles [functions]

#pragma region GetThickness [functions]
	[[nodiscard]] constexpr inline thickness GetThicknessOfTop   () const noexcept;  // top
	[[nodiscard]] constexpr inline thickness GetThicknessOfBottom() const noexcept;  // bottom
	[[nodiscard]] constexpr inline thickness GetThicknessOfLeft  () const noexcept;  // left
	[[nodiscard]] constexpr inline thickness GetThicknessOfRight () const noexcept;  // right
#pragma endregion GetThickness [functions]

	[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] constexpr inline displacement GetDisplacementCoefficient() const noexcept;

	[[nodiscard]] constexpr inline QSizeF GetSize() const noexcept;

#pragma region SetThickness [functions]
	inline void SetThicknessOfTop   (thickness) noexcept;  // top
	inline void SetThicknessOfBottom(thickness) noexcept;  // bottom
	inline void SetThicknessOfLeft  (thickness) noexcept;  // left
	inline void SetThicknessOfRight (thickness) noexcept;  // right
#pragma endregion SetThickness [functions]

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(displacement) noexcept;
private:
#pragma region Rectangles [members]
	QRectF m_external_rectangle;  // external
	QRectF m_internal_rectangle;  // internal
#pragma endregion Rectangles [members]

	ThicknessOfRoundedBorderOfWidget m_thickness;

	displacement m_displacement_coefficient;
private:
	void ReleaseCustomizeGeometry(const QRectF &) noexcept;

	inline void SetGeometry(QRectF) noexcept;

	void ReleaseSetDisplacementCoefficient(QRectF &) const noexcept;

#pragma region ReleaseSetThickness [functions]
	void ReleaseSetThickness() noexcept;

	inline void ReleaseSetThicknessOfTop   () noexcept;  // top
	inline void ReleaseSetThicknessOfBottom() noexcept;  // bottom
	inline void ReleaseSetThicknessOfLeft  () noexcept;  // left
	inline void ReleaseSetThicknessOfRight () noexcept;  // right
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

#pragma region GetRectangles [functions]
[[nodiscard]] constexpr inline QRectF ShapeOfRoundedBorderOfWidget::GetExternalRectangle() const noexcept  // external
{
	return m_external_rectangle;
}

[[nodiscard]] constexpr inline QRectF ShapeOfRoundedBorderOfWidget::GetInternalRectangle() const noexcept  // internal
{
	return m_internal_rectangle;
}
#pragma endregion GetRectangles [functions]

#pragma region GetThickness [functions]
[[nodiscard]] constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept  // top
{
	return this->m_thickness.GetThicknessOfTop();
}

[[nodiscard]] constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept  // bottom
{
	return this->m_thickness.GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept  // left
{
	return this->m_thickness.GetThicknessOfLeft();
}

[[nodiscard]] constexpr inline thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept  // right
{
	return this->m_thickness.GetThicknessOfRight();
}
#pragma endregion GetThickness [functions]

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

#pragma region SetThickness [functions]
inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfTop(const thickness thickness_of_top) noexcept  // top
{
	this->m_thickness.SetThicknessOfTop(thickness_of_top);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfBottom(const thickness thickness_of_bottom) noexcept  // bottom
{
	this->m_thickness.SetThicknessOfBottom(thickness_of_bottom);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfLeft(const thickness thickness_of_left) noexcept  // left
{
	this->m_thickness.SetThicknessOfLeft(thickness_of_left);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfRight(const thickness thickness_of_right) noexcept  // right
{
	this->m_thickness.SetThicknessOfRight(thickness_of_right);
}
#pragma endregion SetThickness [functions]

inline void ShapeOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_thickness = thickness;
}

inline void ShapeOfRoundedBorderOfWidget::SetDisplacementCoefficient(displacement displacement_coefficient) noexcept
{
	this->m_displacement_coefficient = displacement_coefficient;
}

#endif  // RSS_FEED_READER_HEADERS_SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_H_
