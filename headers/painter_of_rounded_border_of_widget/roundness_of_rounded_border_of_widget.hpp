// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_HPP
#define ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_HPP

#include "types_aliases_of_painter_of_rounded_border_of_widget.hpp"


namespace N_PainterOfRoundedBorderOfWidget
{
class RoundnessOfRoundedBorderOfWidget
{
public:
	explicit constexpr inline RoundnessOfRoundedBorderOfWidget(T_Roundness roundness_of_x = 0.0,
													 		   T_Roundness roundness_of_y = 0.0) noexcept;

	[[nodiscard]] constexpr inline T_Roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] constexpr inline T_Roundness GetRoundnessOfY() const noexcept;

	inline void SetRoundnessOfX(T_Roundness) noexcept;
	inline void SetRoundnessOfY(T_Roundness) noexcept;
private:
	T_Roundness m_roundness_of_x;
	T_Roundness m_roundness_of_y;
};

constexpr inline RoundnessOfRoundedBorderOfWidget::RoundnessOfRoundedBorderOfWidget(const T_Roundness roundness_of_x,
																					const T_Roundness roundness_of_y) noexcept
	: m_roundness_of_x(roundness_of_x),
	  m_roundness_of_y(roundness_of_y)
{
}

constexpr inline T_Roundness RoundnessOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_roundness_of_x;
}

constexpr inline T_Roundness RoundnessOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_roundness_of_y;
}

inline void RoundnessOfRoundedBorderOfWidget::SetRoundnessOfX(const T_Roundness roundness_of_x) noexcept
{
	this->m_roundness_of_x = roundness_of_x;
}

inline void RoundnessOfRoundedBorderOfWidget::SetRoundnessOfY(const T_Roundness roundness_of_y) noexcept
{
	this->m_roundness_of_y = roundness_of_y;
}
}  // namespace N_PainterOfRoundedBorderOfWidget

#endif   // ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_HPP
