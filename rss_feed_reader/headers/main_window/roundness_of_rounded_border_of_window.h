#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_ROUNDNESS_OF_ROUNDED_BORDER_OF_WINDOW_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_ROUNDNESS_OF_ROUNDED_BORDER_OF_WINDOW_H_

#include <QtGlobal>


using roundness = qreal;

class RoundnessOfRoundedBorderOfWindow
{
public:
	explicit RoundnessOfRoundedBorderOfWindow(roundness roundness_of_x = 1.0,
											  roundness roundness_of_y = 1.0);

	[[nodiscard]] inline roundness GetRoundnessOfX() const;
	[[nodiscard]] inline roundness GetRoundnessOfY() const;

	inline void SetRoundnessOfx(roundness);
	inline void SetRoundnessOfy(roundness);
private:
	qreal m_roundness_of_x;
	qreal m_roundness_of_y;
};

inline qreal RoundnessOfRoundedBorderOfWindow::GetRoundnessOfX() const
{
	return this->m_roundness_of_x;
}

inline qreal RoundnessOfRoundedBorderOfWindow::GetRoundnessOfY() const
{
	return this->m_roundness_of_y;
}

inline void RoundnessOfRoundedBorderOfWindow::SetRoundnessOfx(const qreal roundness_of_x)
{
	this->m_roundness_of_x = roundness_of_x;
}

inline void RoundnessOfRoundedBorderOfWindow::SetRoundnessOfy(const qreal roundness_of_y)
{
	this->m_roundness_of_y = roundness_of_y;
}

#endif   // RSS_FEED_READER_HEADERS_MAIN_WINDOW_ROUNDNESS_OF_ROUNDED_BORDER_OF_WINDOW_H_
