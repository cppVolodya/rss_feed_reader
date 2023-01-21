// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QtGlobal>


using t_thickness = qreal;

class ThicknessOfRoundedBorderOfWidget
{
public:
	explicit constexpr inline ThicknessOfRoundedBorderOfWidget(t_thickness thickness_of_top    = 1.0,
													 		   t_thickness thickness_of_bottom = 1.0,
													 		   t_thickness thickness_of_left   = 1.0,
													 		   t_thickness thickness_of_right  = 1.0) noexcept;

	[[nodiscard]] constexpr inline t_thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfRight () const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfLeft  () const noexcept;

	inline void SetThicknessOfTop   (t_thickness) noexcept;
	inline void SetThicknessOfBottom(t_thickness) noexcept;
	inline void SetThicknessOfLeft  (t_thickness) noexcept;
	inline void SetThicknessOfRight (t_thickness) noexcept;
private:
	t_thickness m_thickness_of_top;
	t_thickness m_thickness_of_bottom;
	t_thickness m_thickness_of_left;
	t_thickness m_thickness_of_right;
};

constexpr inline ThicknessOfRoundedBorderOfWidget::ThicknessOfRoundedBorderOfWidget(const t_thickness thickness_of_top,
																		 			const t_thickness thickness_of_bottom,
																		 			const t_thickness thickness_of_left,
																		 			const t_thickness thickness_of_right) noexcept
	: m_thickness_of_top   (thickness_of_top   ),
	  m_thickness_of_bottom(thickness_of_bottom),
	  m_thickness_of_left  (thickness_of_left  ),
	  m_thickness_of_right (thickness_of_right )
{
}

constexpr inline t_thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_thickness_of_top;
}

constexpr inline t_thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_thickness_of_bottom;
}

constexpr inline t_thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_thickness_of_left;
}

constexpr inline t_thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_thickness_of_right;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfTop(const t_thickness thickness_of_top) noexcept
{
	this->m_thickness_of_top = thickness_of_top;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfBottom(const t_thickness thickness_of_bottom) noexcept
{
	this->m_thickness_of_bottom = thickness_of_bottom;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfLeft(const t_thickness thickness_of_left) noexcept
{
	this->m_thickness_of_left = thickness_of_left;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfRight(const t_thickness thickness_of_right) noexcept
{
	this->m_thickness_of_right = thickness_of_right;
}

#endif  // RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
