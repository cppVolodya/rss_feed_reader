#ifndef RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QtGlobal>


using roundness = qreal;

class RoundnessOfRoundedBorderOfWidget
{
public:
	explicit constexpr inline RoundnessOfRoundedBorderOfWidget(roundness roundness_of_x = 1.0,            // x
													 		   roundness roundness_of_y = 1.0) noexcept;  // y

#pragma region GetRoundness [functions]
	[[nodiscard]] constexpr inline roundness GetRoundnessOfX() const noexcept;  // x
	[[nodiscard]] constexpr inline roundness GetRoundnessOfY() const noexcept;  // y
#pragma endregion GetRoundness [functions]

#pragma region SetRoundness [functions]
	inline void SetRoundnessOfX(roundness) noexcept;  // x
	inline void SetRoundnessOfY(roundness) noexcept;  // y
#pragma endregion SetRoundness [functions]
private:
#pragma region Roundness [members]
	roundness m_roundness_of_x;  // x
	roundness m_roundness_of_y;  // y
#pragma endregion Roundness [members]
};

constexpr inline RoundnessOfRoundedBorderOfWidget::RoundnessOfRoundedBorderOfWidget (const roundness roundness_of_x,           // x
																		  			 const roundness roundness_of_y) noexcept  // y
	: m_roundness_of_x(roundness_of_x),  // x
	  m_roundness_of_y(roundness_of_y)   // y
{
}

constexpr inline roundness RoundnessOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept  // x
{
	return this->m_roundness_of_x;
}

constexpr inline roundness RoundnessOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept  // y
{
	return this->m_roundness_of_y;
}

inline void RoundnessOfRoundedBorderOfWidget::SetRoundnessOfX(const roundness roundness_of_x) noexcept  // x
{
	this->m_roundness_of_x = roundness_of_x;
}

inline void RoundnessOfRoundedBorderOfWidget::SetRoundnessOfY(const roundness roundness_of_y) noexcept  // y
{
	this->m_roundness_of_y = roundness_of_y;
}

#endif   // RSS_FEED_READER_HEADERS_ROUNDNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
