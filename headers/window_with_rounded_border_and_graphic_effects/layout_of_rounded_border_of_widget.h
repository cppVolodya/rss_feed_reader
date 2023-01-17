#ifndef RSS_FEED_READER_HEADERS_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QPainterPath>

#include "shape_of_rounded_border_of_widget.h"
#include "roundness_of_rounded_border_of_widget.h"


class LayoutOfRoundedBorderOfWidget : public QPainterPath
{
public:
	LayoutOfRoundedBorderOfWidget() = default;

	virtual ~LayoutOfRoundedBorderOfWidget() = default;

	LayoutOfRoundedBorderOfWidget(const LayoutOfRoundedBorderOfWidget &) = default;
	LayoutOfRoundedBorderOfWidget(LayoutOfRoundedBorderOfWidget &&) 	 = default;

	LayoutOfRoundedBorderOfWidget& operator=(const LayoutOfRoundedBorderOfWidget &) = default;
	LayoutOfRoundedBorderOfWidget& operator=(LayoutOfRoundedBorderOfWidget &&) 	    = default;

	inline void Customize(const QRectF &);

#pragma region GetRoundness [functions]
	[[nodiscard]] constexpr inline roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] constexpr inline roundness GetRoundnessOfY() const noexcept;
#pragma endregion GetRoundness [functions]

#pragma region GetThickness [functions]
	[[nodiscard]] constexpr inline thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfRight () const noexcept;
	[[nodiscard]] constexpr inline thickness GetThicknessOfLeft  () const noexcept;
#pragma endregion GetThickness [functions]

	[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] constexpr inline RoundnessOfRoundedBorderOfWidget GetRoundness() const noexcept;

	[[nodiscard]] constexpr inline displacement GetDisplacementCoefficient() const noexcept;

	[[nodiscard]] constexpr inline QSizeF GetSize() const noexcept;

#pragma region SetRoundness [functions]
	inline void SetRoundnessOfX(roundness) noexcept;
	inline void SetRoundnessOfY(roundness) noexcept;
#pragma endregion SetRoundness [functions]

#pragma region SetThickness [functions]
	inline void SetThicknessOfTop   (thickness) noexcept;
	inline void SetThicknessOfBottom(thickness) noexcept;
	inline void SetThicknessOfRight (thickness) noexcept;
	inline void SetThicknessOfLeft  (thickness) noexcept;
#pragma endregion SetThickness [functions]

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetRoundness(const RoundnessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(displacement) noexcept;
protected:
	ShapeOfRoundedBorderOfWidget m_shape;

	RoundnessOfRoundedBorderOfWidget m_roundness;
protected:
	virtual void ReleaseSetRoundness() = 0;
private:
	void ReleaseCustomize(const QRectF &);

	inline void UpdateData(const QRectF &);

	inline void AddShape();
};

inline void LayoutOfRoundedBorderOfWidget::Customize(const QRectF &geometry_of_window)
{
	this->ReleaseCustomize(geometry_of_window);
}

#pragma region GetRoundness [functions]
[[nodiscard]] constexpr inline roundness LayoutOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_roundness.GetRoundnessOfX();
}

[[nodiscard]] constexpr inline roundness LayoutOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_roundness.GetRoundnessOfY();
}
#pragma endregion GetRoundness [functions]

#pragma region GetThickness [functions]
[[nodiscard]] constexpr inline thickness LayoutOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_shape.GetThicknessOfTop();
}

[[nodiscard]] constexpr inline thickness LayoutOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_shape.GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline thickness LayoutOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_shape.GetThicknessOfRight();
}

[[nodiscard]] constexpr inline thickness LayoutOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_shape.GetThicknessOfLeft();
}
#pragma endregion GetThickness [functions]

[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget LayoutOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_shape.GetThickness();
}

[[nodiscard]] constexpr inline RoundnessOfRoundedBorderOfWidget LayoutOfRoundedBorderOfWidget::GetRoundness() const noexcept
{
	return this->m_roundness;
}

[[nodiscard]] constexpr inline displacement LayoutOfRoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_shape.GetDisplacementCoefficient();
}

[[nodiscard]] constexpr inline QSizeF LayoutOfRoundedBorderOfWidget::GetSize() const noexcept
{
	return this->m_shape.GetSize();
}

#pragma region SetRoundness [functions]
inline void LayoutOfRoundedBorderOfWidget::SetRoundnessOfX(const roundness roundness_of_x) noexcept
{
	this->m_roundness.SetRoundnessOfX(roundness_of_x);
}

inline void LayoutOfRoundedBorderOfWidget::SetRoundnessOfY(const roundness roundness_of_y) noexcept
{
	this->m_roundness.SetRoundnessOfY(roundness_of_y);
}
#pragma endregion SetRoundness [functions]

#pragma region SetThickness [functions]
inline void LayoutOfRoundedBorderOfWidget::SetThicknessOfTop(const thickness thickness_of_top) noexcept
{
	this->m_shape.SetThicknessOfTop(thickness_of_top);
}

inline void LayoutOfRoundedBorderOfWidget::SetThicknessOfBottom(const thickness thickness_of_bottom) noexcept
{
	this->m_shape.SetThicknessOfBottom(thickness_of_bottom);
}

inline void LayoutOfRoundedBorderOfWidget::SetThicknessOfRight(const thickness thickness_of_right) noexcept
{
	this->m_shape.SetThicknessOfRight(thickness_of_right);
}

inline void LayoutOfRoundedBorderOfWidget::SetThicknessOfLeft(const thickness thickness_of_left) noexcept
{
	this->m_shape.SetThicknessOfLeft(thickness_of_left);
}
#pragma endregion SetThickness [functions]

inline void LayoutOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_shape.SetThickness(thickness);
}

inline void LayoutOfRoundedBorderOfWidget::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_roundness = roundness;
}

inline void LayoutOfRoundedBorderOfWidget::SetDisplacementCoefficient(displacement displacement_coefficient) noexcept
{
	this->m_shape.SetDisplacementCoefficient(displacement_coefficient);
}

#endif  // RSS_FEED_READER_HEADERS_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_H_
