// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_HPP
#define SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_HPP

#include <QRectF>

#include "types_aliases_of_painter_of_rounded_border_of_widget.hpp"
#include "thickness_of_rounded_border_of_widget.hpp"


namespace N_PainterOfRoundedBorderOfWidget
{
class ShapeOfRoundedBorderOfWidget
{
public:
	constexpr inline ShapeOfRoundedBorderOfWidget() noexcept;

	inline void CustomizeGeometry(const QRectF &) noexcept;

	[[nodiscard]] constexpr inline QRectF GetExternalRectangle() const noexcept;
	[[nodiscard]] constexpr inline QRectF GetInternalRectangle() const noexcept;

	[[nodiscard]] constexpr inline T_Thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline T_Thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline T_Thickness GetThicknessOfLeft  () const noexcept;
	[[nodiscard]] constexpr inline T_Thickness GetThicknessOfRight () const noexcept;

	[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] constexpr inline T_Displacement GetDisplacementCoefficient() const noexcept;

	[[nodiscard]] constexpr inline QSizeF GetSize() const noexcept;

	inline void SetExternalRectangle(const QRectF &) noexcept;
	inline void SetInternalRectangle(const QRectF &) noexcept;

	inline void SetThicknessOfTop   (T_Thickness) noexcept;
	inline void SetThicknessOfBottom(T_Thickness) noexcept;
	inline void SetThicknessOfLeft  (T_Thickness) noexcept;
	inline void SetThicknessOfRight (T_Thickness) noexcept;

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(T_Displacement) noexcept;
private:
	QRectF m_external_rectangle;
	QRectF m_internal_rectangle;

	ThicknessOfRoundedBorderOfWidget m_thickness;

	T_Displacement m_displacement_coefficient;
private:
	void ReleaseCustomizeGeometry(const QRectF &) noexcept;

	inline void SetGeometry(QRectF) noexcept;

#pragma region ReleaseSetThickness [functions]
	static void ReleaseSetThickness(QRectF &, const ThicknessOfRoundedBorderOfWidget &) noexcept;
	static void ReleaseSetThickness(QRectF &, T_Thickness						      ) noexcept;

	static inline void ReleaseSetThicknessOfTop   (QRectF &, T_Thickness) noexcept;
	static inline void ReleaseSetThicknessOfBottom(QRectF &, T_Thickness) noexcept;
	static inline void ReleaseSetThicknessOfLeft  (QRectF &, T_Thickness) noexcept;
	static inline void ReleaseSetThicknessOfRight (QRectF &, T_Thickness) noexcept;
#pragma endregion ReleaseSetThickness [functions]

	static void ReleaseSetDisplacementCoefficient(QRectF &, T_Displacement) noexcept;
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
	return this->m_external_rectangle;
}

[[nodiscard]] constexpr inline QRectF ShapeOfRoundedBorderOfWidget::GetInternalRectangle() const noexcept
{
	return this->m_internal_rectangle;
}

[[nodiscard]] constexpr inline T_Thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_thickness.GetThicknessOfTop();
}

[[nodiscard]] constexpr inline T_Thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_thickness.GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline T_Thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_thickness.GetThicknessOfLeft();
}

[[nodiscard]] constexpr inline T_Thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_thickness.GetThicknessOfRight();
}

[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget ShapeOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_thickness;
}

[[nodiscard]] constexpr inline T_Displacement ShapeOfRoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_displacement_coefficient;
}

[[nodiscard]] constexpr inline QSizeF ShapeOfRoundedBorderOfWidget::GetSize() const noexcept
{
	return this->m_external_rectangle.size();
}

inline void ShapeOfRoundedBorderOfWidget::SetExternalRectangle(const QRectF & external_rectangle) noexcept
{
	this->m_external_rectangle = external_rectangle;
}

inline void ShapeOfRoundedBorderOfWidget::SetInternalRectangle(const QRectF & internal_rectangle) noexcept
{
	this->m_internal_rectangle = internal_rectangle;
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfTop(const T_Thickness thickness_of_top) noexcept
{
	this->m_thickness.SetThicknessOfTop(thickness_of_top);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfBottom(const T_Thickness thickness_of_bottom) noexcept
{
	this->m_thickness.SetThicknessOfBottom(thickness_of_bottom);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfLeft(const T_Thickness thickness_of_left) noexcept
{
	this->m_thickness.SetThicknessOfLeft(thickness_of_left);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfRight(const T_Thickness thickness_of_right) noexcept
{
	this->m_thickness.SetThicknessOfRight(thickness_of_right);
}

inline void ShapeOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_thickness = thickness;
}

inline void ShapeOfRoundedBorderOfWidget::SetDisplacementCoefficient(T_Displacement displacement_coefficient) noexcept
{
	this->m_displacement_coefficient = displacement_coefficient;
}
}  // namespace N_PainterOfRoundedBorderOfWidget

#endif  // SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_HPP
