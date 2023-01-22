// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QtGlobal>


using t_roundness = qreal;

class RoundnessOfRoundedBorderOfWidget
{
public:
	explicit constexpr inline RoundnessOfRoundedBorderOfWidget(t_roundness roundness_of_x = 1.0,
													 		   t_roundness roundness_of_y = 1.0) noexcept;

	[[nodiscard]] constexpr inline t_roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] constexpr inline t_roundness GetRoundnessOfY() const noexcept;

	inline void SetRoundnessOfX(t_roundness) noexcept;
	inline void SetRoundnessOfY(t_roundness) noexcept;
private:
	t_roundness m_roundness_of_x;
	t_roundness m_roundness_of_y;
};

constexpr inline RoundnessOfRoundedBorderOfWidget::RoundnessOfRoundedBorderOfWidget (const t_roundness roundness_of_x,
																		  			 const t_roundness roundness_of_y) noexcept
	: m_roundness_of_x(roundness_of_x),
	  m_roundness_of_y(roundness_of_y)
{
}

constexpr inline t_roundness RoundnessOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_roundness_of_x;
}

constexpr inline t_roundness RoundnessOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_roundness_of_y;
}

inline void RoundnessOfRoundedBorderOfWidget::SetRoundnessOfX(const t_roundness roundness_of_x) noexcept
{
	this->m_roundness_of_x = roundness_of_x;
}

inline void RoundnessOfRoundedBorderOfWidget::SetRoundnessOfY(const t_roundness roundness_of_y) noexcept
{
	this->m_roundness_of_y = roundness_of_y;
}

#endif   // RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
