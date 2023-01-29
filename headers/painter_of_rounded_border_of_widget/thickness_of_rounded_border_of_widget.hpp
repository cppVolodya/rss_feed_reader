// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_HPP
#define THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_HPP

#include "types_aliases_of_painter_of_rounded_border_of_widget.hpp"


namespace N_PainterOfRoundedBorderOfWidget
{
class ThicknessOfRoundedBorderOfWidget
{
public:
	explicit constexpr inline ThicknessOfRoundedBorderOfWidget(T_Thickness thickness_of_top    = 2.0,
													 		   T_Thickness thickness_of_bottom = 2.0,
													 		   T_Thickness thickness_of_left   = 2.0,
													 		   T_Thickness thickness_of_right  = 2.0) noexcept;

	[[nodiscard]] constexpr inline T_Thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline T_Thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline T_Thickness GetThicknessOfLeft  () const noexcept;
	[[nodiscard]] constexpr inline T_Thickness GetThicknessOfRight () const noexcept;

	inline void SetThicknessOfTop   (T_Thickness) noexcept;
	inline void SetThicknessOfBottom(T_Thickness) noexcept;
	inline void SetThicknessOfLeft  (T_Thickness) noexcept;
	inline void SetThicknessOfRight (T_Thickness) noexcept;
private:
	T_Thickness m_thickness_of_top;
	T_Thickness m_thickness_of_bottom;
	T_Thickness m_thickness_of_left;
	T_Thickness m_thickness_of_right;
};

constexpr inline ThicknessOfRoundedBorderOfWidget::ThicknessOfRoundedBorderOfWidget(const T_Thickness thickness_of_top,
																					const T_Thickness thickness_of_bottom,
																					const T_Thickness thickness_of_left,
																					const T_Thickness thickness_of_right) noexcept
	: m_thickness_of_top   (thickness_of_top   ),
	  m_thickness_of_bottom(thickness_of_bottom),
	  m_thickness_of_left  (thickness_of_left  ),
	  m_thickness_of_right (thickness_of_right )
{
}

constexpr inline T_Thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_thickness_of_top;
}

constexpr inline T_Thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_thickness_of_bottom;
}

constexpr inline T_Thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_thickness_of_left;
}

constexpr inline T_Thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_thickness_of_right;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfTop(const T_Thickness thickness_of_top) noexcept
{
	this->m_thickness_of_top = thickness_of_top;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfBottom(const T_Thickness thickness_of_bottom) noexcept
{
	this->m_thickness_of_bottom = thickness_of_bottom;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfLeft(const T_Thickness thickness_of_left) noexcept
{
	this->m_thickness_of_left = thickness_of_left;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfRight(const T_Thickness thickness_of_right) noexcept
{
	this->m_thickness_of_right = thickness_of_right;
}
}  // namespace N_PainterOfRoundedBorderOfWidget

#endif  // THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_HPP
