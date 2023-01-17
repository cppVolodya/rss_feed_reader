#ifndef RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QtGlobal>


using thickness = qreal;

class ThicknessOfRoundedBorderOfWidget
{
public:
	explicit constexpr inline ThicknessOfRoundedBorderOfWidget(thickness thickness_of_top    = 1.0, 		   // top
													 		   thickness thickness_of_bottom = 1.0, 		   // bottom
													 		   thickness thickness_of_left   = 1.0, 		   // right
													 		   thickness thickness_of_right  = 1.0) noexcept;  // left

#pragma region GetThickness [functions]
	[[nodiscard]] constexpr inline thickness GetThicknessOfTop   () const noexcept;  // top
	[[nodiscard]] constexpr inline thickness GetThicknessOfBottom() const noexcept;  // bottom
	[[nodiscard]] constexpr inline thickness GetThicknessOfRight () const noexcept;  // right
	[[nodiscard]] constexpr inline thickness GetThicknessOfLeft  () const noexcept;  // left
#pragma endregion GetThickness [functions]

#pragma region SetThickness [functions]
	inline void SetThicknessOfTop   (thickness) noexcept;  // top
	inline void SetThicknessOfBottom(thickness) noexcept;  // bottom
	inline void SetThicknessOfLeft  (thickness) noexcept;  // right
	inline void SetThicknessOfRight (thickness) noexcept;  // left
#pragma endregion SetThickness [functions]
private:
#pragma region Thickness [members]
	thickness m_thickness_of_top;     // top
	thickness m_thickness_of_bottom;  // bottom
	thickness m_thickness_of_left;    // right
	thickness m_thickness_of_right;   // left
#pragma endregion Thickness [members]
};

constexpr inline ThicknessOfRoundedBorderOfWidget::ThicknessOfRoundedBorderOfWidget(const thickness thickness_of_top, 		      // top
																		 			const thickness thickness_of_bottom, 		  // bottom
																		 			const thickness thickness_of_left, 		      // right
																		 			const thickness thickness_of_right) noexcept  // left
	: m_thickness_of_top   (thickness_of_top   ),  // top
	  m_thickness_of_bottom(thickness_of_bottom),  // bottom
	  m_thickness_of_left  (thickness_of_left  ),  // right
	  m_thickness_of_right (thickness_of_right )   // left
{
}

constexpr inline thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept  // top
{
	return this->m_thickness_of_top;
}

constexpr inline thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept  // bottom
{
	return this->m_thickness_of_bottom;
}

constexpr inline thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept  // right
{
	return this->m_thickness_of_left;
}

constexpr inline thickness ThicknessOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept  // left
{
	return this->m_thickness_of_right;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfTop(const thickness thickness_of_top) noexcept  // top
{
	this->m_thickness_of_top = thickness_of_top;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfBottom(const thickness thickness_of_bottom) noexcept  // bottom
{
	this->m_thickness_of_bottom = thickness_of_bottom;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfLeft(const thickness thickness_of_left) noexcept  // right
{
	this->m_thickness_of_left = thickness_of_left;
}

inline void ThicknessOfRoundedBorderOfWidget::SetThicknessOfRight(const thickness thickness_of_right) noexcept  // left
{
	this->m_thickness_of_right = thickness_of_right;
}

#endif  // RSS_FEED_READER_HEADERS_THICKNESS_OF_ROUNDED_BORDER_OF_WIDGET_H_
