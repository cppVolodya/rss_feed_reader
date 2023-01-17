#ifndef RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QtGlobal>


using roundness = qreal;

class RoundnessOfRoundedBorderOfWidget
{
public:
	explicit constexpr inline RoundnessOfRoundedBorderOfWidget(roundness roundness_of_x = 1.0,
													 		   roundness roundness_of_y = 1.0) noexcept;

#pragma region GetRoundness [functions]
	[[nodiscard]] constexpr inline roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] constexpr inline roundness GetRoundnessOfY() const noexcept;
#pragma endregion GetRoundness [functions]

#pragma region SetRoundness [functions]
	inline void SetRoundnessOfX(roundness) noexcept;
	inline void SetRoundnessOfY(roundness) noexcept;
#pragma endregion SetRoundness [functions]
private:
#pragma region Roundness [members]
	roundness m_roundness_of_x;
	roundness m_roundness_of_y;
#pragma endregion Roundness [members]
};

constexpr inline RoundnessOfRoundedBorderOfWidget::RoundnessOfRoundedBorderOfWidget (const roundness roundness_of_x,
																		  			 const roundness roundness_of_y) noexcept
	: m_roundness_of_x(roundness_of_x),
	  m_roundness_of_y(roundness_of_y)
{
}

constexpr inline roundness RoundnessOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_roundness_of_x;
}

constexpr inline roundness RoundnessOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_roundness_of_y;
}

inline void RoundnessOfRoundedBorderOfWidget::SetRoundnessOfX(const roundness roundness_of_x) noexcept
{
	this->m_roundness_of_x = roundness_of_x;
}

inline void RoundnessOfRoundedBorderOfWidget::SetRoundnessOfY(const roundness roundness_of_y) noexcept
{
	this->m_roundness_of_y = roundness_of_y;
}

#endif   // RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
