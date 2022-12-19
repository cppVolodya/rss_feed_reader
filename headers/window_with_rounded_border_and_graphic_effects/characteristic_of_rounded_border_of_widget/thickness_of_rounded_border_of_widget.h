#ifndef RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QtGlobal>


using thickness = qreal;

class ThicknessOfRoundedBorderOfWidget
{
public:
	explicit inline ThicknessOfRoundedBorderOfWidget(thickness thickness_of_top    = 1.0,
													 thickness thickness_of_bottom = 1.0,
													 thickness thickness_of_left   = 1.0,
													 thickness thickness_of_right  = 1.0) noexcept;

	[[nodiscard]] constexpr inline thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfLeft  () const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfRight () const noexcept;

	inline void SetThicknessOfTop   (thickness) noexcept;
	inline void SetThicknessOfBottom(thickness) noexcept;
	inline void SetThicknessOfLeft  (thickness) noexcept;
	inline void SetThicknessOfRight (thickness) noexcept;
private:
	thickness m_thickness_of_top;
	thickness m_thickness_of_bottom;
	thickness m_thickness_of_left;
	thickness m_thickness_of_right;
};

inline ThicknessOfRoundedBorderOfWidget::ThicknessOfRoundedBorderOfWidget (const thickness thickness_of_top,
																		   const thickness thickness_of_bottom,
																		   const thickness thickness_of_left,
																		   const thickness thickness_of_right) noexcept
	: m_thickness_of_top   (thickness_of_top   ),
	  m_thickness_of_bottom(thickness_of_bottom),
	  m_thickness_of_left  (thickness_of_left  ),
	  m_thickness_of_right (thickness_of_right )
{
}

constexpr inline thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_thickness_of_top;
}

constexpr inline thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_thickness_of_bottom;
}

constexpr inline thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_thickness_of_left;
}

constexpr inline thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_thickness_of_right;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfTop(const thickness thickness_of_top) noexcept
{
	this->m_thickness_of_top = thickness_of_top;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfBottom(const thickness thickness_of_bottom) noexcept
{
	this->m_thickness_of_bottom = thickness_of_bottom;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfLeft(const thickness thickness_of_left) noexcept
{
	this->m_thickness_of_left = thickness_of_left;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfRight(const thickness thickness_of_right) noexcept
{
	this->m_thickness_of_right = thickness_of_right;
}

#endif  // RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
