// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_HPP
#define SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_HPP

#include <QRectF>

#include "characteristics_of_placement_of_positional_element.hpp"


namespace N_PainterOfRoundedBorderOfWidget
{
using N_TypesAliases::T_Thickness;
using N_TypesAliases::T_ThicknessOfRoundedBorderOfWidget;


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

	[[nodiscard]] constexpr inline T_ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] constexpr inline T_ThicknessOfRoundedBorderOfWidget GetBoundingThickness() const noexcept;

	[[nodiscard]] constexpr inline QSizeF GetSize() const noexcept;

	inline void SetExternalRectangle(const QRectF &) noexcept;
	inline void SetInternalRectangle(const QRectF &) noexcept;

	inline void SetThicknessOfTop   (T_Thickness) noexcept;
	inline void SetThicknessOfBottom(T_Thickness) noexcept;
	inline void SetThicknessOfLeft  (T_Thickness) noexcept;
	inline void SetThicknessOfRight (T_Thickness) noexcept;

	inline void SetThickness(const T_ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetBoundingThickness(const T_ThicknessOfRoundedBorderOfWidget &) noexcept;
private:
	QRectF m_external_rectangle;
	QRectF m_internal_rectangle;

	T_ThicknessOfRoundedBorderOfWidget m_thickness;

	T_ThicknessOfRoundedBorderOfWidget m_bounding_thickness;
private:
	void ReleaseCustomizeGeometry(const QRectF &) noexcept;

	inline void SetGeometry(QRectF) noexcept;

#pragma region ReleaseSetThickness [functions]
	static void ReleaseSetThickness(QRectF &, const T_ThicknessOfRoundedBorderOfWidget &) noexcept;

	static inline void ReleaseSetThicknessOfTop   (QRectF &, T_Thickness) noexcept;
	static inline void ReleaseSetThicknessOfBottom(QRectF &, T_Thickness) noexcept;
	static inline void ReleaseSetThicknessOfLeft  (QRectF &, T_Thickness) noexcept;
	static inline void ReleaseSetThicknessOfRight (QRectF &, T_Thickness) noexcept;
#pragma endregion ReleaseSetThickness [functions]

	static void ReleaseSetBoundingThickness(QRectF &, const T_ThicknessOfRoundedBorderOfWidget &) noexcept;
};

constexpr inline ShapeOfRoundedBorderOfWidget::ShapeOfRoundedBorderOfWidget() noexcept
	: m_bounding_thickness(0.0, 0.0, 0.0, 0.0)
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
	return this->m_thickness.GetPositionOfTop();
}

[[nodiscard]] constexpr inline T_Thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_thickness.GetPositionOfBottom();
}

[[nodiscard]] constexpr inline T_Thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_thickness.GetPositionOfLeft();
}

[[nodiscard]] constexpr inline T_Thickness ShapeOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_thickness.GetPositionOfRight();
}

[[nodiscard]] constexpr inline T_ThicknessOfRoundedBorderOfWidget ShapeOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_thickness;
}

[[nodiscard]] constexpr inline T_ThicknessOfRoundedBorderOfWidget ShapeOfRoundedBorderOfWidget::GetBoundingThickness() const noexcept
{
	return this->m_bounding_thickness;
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
	this->m_thickness.SetPositionOfTop(thickness_of_top);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfBottom(const T_Thickness thickness_of_bottom) noexcept
{
	this->m_thickness.SetPositionOfBottom(thickness_of_bottom);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfLeft(const T_Thickness thickness_of_left) noexcept
{
	this->m_thickness.SetPositionOfLeft(thickness_of_left);
}

inline void ShapeOfRoundedBorderOfWidget::SetThicknessOfRight(const T_Thickness thickness_of_right) noexcept
{
	this->m_thickness.SetPositionOfRight(thickness_of_right);
}

inline void ShapeOfRoundedBorderOfWidget::SetThickness(const T_ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_thickness = thickness;
}

inline void ShapeOfRoundedBorderOfWidget::SetBoundingThickness(const T_ThicknessOfRoundedBorderOfWidget &bounding_thickness) noexcept
{
	this->m_bounding_thickness = bounding_thickness;
}
}  // namespace N_PainterOfRoundedBorderOfWidget

#endif  // SHAPE_OF_ROUNDED_BORDER_OF_WIDGET_HPP
