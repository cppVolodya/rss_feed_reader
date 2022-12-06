#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_THICKNESS_OF_ROUNDED_BORDER_OF_WINDOW_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_THICKNESS_OF_ROUNDED_BORDER_OF_WINDOW_H_

#include <QtGlobal>


using thickness = qint32;

class ThicknessOfRoundedBorderOfWindow
{
public:
	explicit ThicknessOfRoundedBorderOfWindow(thickness thickness_of_top    = 1,
											  thickness thickness_of_bottom = 1,
											  thickness thickness_of_left   = 1,
											  thickness thickness_of_right  = 1);

	[[nodiscard]] inline thickness GetThicknessOfTop   () const;
	[[nodiscard]] inline thickness GetThicknessOfBottom() const;
	[[nodiscard]] inline thickness GetThicknessOfLeft  () const;
	[[nodiscard]] inline thickness GetThicknessOfRight () const;

	inline void SetThicknessOfTop   (thickness);
	inline void SetThicknessOfBottom(thickness);
	inline void SetThicknessOfLeft  (thickness);
	inline void SetThicknessOfRight (thickness);
private:
	qint32 m_thickness_of_top;
	qint32 m_thickness_of_bottom;
	qint32 m_thickness_of_left;
	qint32 m_thickness_of_right;
};

inline qint32 ThicknessOfRoundedBorderOfWindow::GetThicknessOfTop() const
{
	return this->m_thickness_of_top;
}

inline qint32 ThicknessOfRoundedBorderOfWindow::GetThicknessOfBottom() const
{
	return this->m_thickness_of_bottom;
}

inline qint32 ThicknessOfRoundedBorderOfWindow::GetThicknessOfLeft() const
{
	return this->m_thickness_of_left;
}

inline qint32 ThicknessOfRoundedBorderOfWindow::GetThicknessOfRight() const
{
	return this->m_thickness_of_right;
}

inline void ThicknessOfRoundedBorderOfWindow::SetThicknessOfTop(const qint32 thickness_of_top)
{
	this->m_thickness_of_top = thickness_of_top;
}

inline void ThicknessOfRoundedBorderOfWindow::SetThicknessOfBottom(const qint32 thickness_of_bottom)
{
	this->m_thickness_of_bottom = thickness_of_bottom;
}

inline void ThicknessOfRoundedBorderOfWindow::SetThicknessOfLeft(const qint32 thickness_of_left)
{
	this->m_thickness_of_left = thickness_of_left;
}

inline void ThicknessOfRoundedBorderOfWindow::SetThicknessOfRight(const qint32 thickness_of_right)
{
	this->m_thickness_of_right = thickness_of_right;
}

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_THICKNESS_OF_ROUNDED_BORDER_OF_WINDOW_H_
