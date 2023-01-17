#ifndef RSS_FEED_READER_HEADERS_PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QPainter>
#include <QPaintDevice>

#include "layout_of_rounded_border_of_widget.h"


class PainterOfRoundedBorderOfWidget : public QPainter
{
public:
	explicit inline PainterOfRoundedBorderOfWidget(LayoutOfRoundedBorderOfWidget* layout = nullptr) noexcept;

	inline ~PainterOfRoundedBorderOfWidget() noexcept;

	PainterOfRoundedBorderOfWidget(const PainterOfRoundedBorderOfWidget &) = delete;
	PainterOfRoundedBorderOfWidget(PainterOfRoundedBorderOfWidget &&) noexcept;

	PainterOfRoundedBorderOfWidget& operator=(const PainterOfRoundedBorderOfWidget &) = delete;
	PainterOfRoundedBorderOfWidget& operator=(PainterOfRoundedBorderOfWidget &&) noexcept;

	void Draw(const QRectF &);

	[[nodiscard]] constexpr inline QColor GetColor() const noexcept;

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

	inline void SetColor(const QColor &) noexcept;

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

	inline void SetLayout(LayoutOfRoundedBorderOfWidget *layout) noexcept;
private:
	LayoutOfRoundedBorderOfWidget *m_layout;

	QColor m_color;
private:
	inline void Customize();

	inline void DrawAccordingToLayout();

	inline void ReleaseSetColor();
};

inline PainterOfRoundedBorderOfWidget::PainterOfRoundedBorderOfWidget(LayoutOfRoundedBorderOfWidget* layout) noexcept
	: m_layout(layout)
{
}

inline PainterOfRoundedBorderOfWidget::~PainterOfRoundedBorderOfWidget() noexcept
{
	delete this->m_layout;
}

[[nodiscard]] constexpr inline QColor PainterOfRoundedBorderOfWidget::GetColor() const noexcept
{
	return this->m_color;
}

#pragma region GetRoundness [functions]
[[nodiscard]] constexpr inline roundness PainterOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_layout->GetRoundnessOfX();
}

[[nodiscard]] constexpr inline roundness PainterOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_layout->GetRoundnessOfY();
}
#pragma endregion GetRoundness [functions]

#pragma region GetThickness [functions]
[[nodiscard]] constexpr inline thickness PainterOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_layout->GetThicknessOfTop();
}

[[nodiscard]] constexpr inline thickness PainterOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_layout->GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline thickness PainterOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_layout->GetThicknessOfRight();
}

[[nodiscard]] constexpr inline thickness PainterOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_layout->GetThicknessOfLeft();
}
#pragma endregion GetThickness [functions]

[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget PainterOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_layout->GetThickness();
}

[[nodiscard]] constexpr inline RoundnessOfRoundedBorderOfWidget PainterOfRoundedBorderOfWidget::GetRoundness() const noexcept
{
	return this->m_layout->GetRoundness();
}

[[nodiscard]] constexpr inline displacement PainterOfRoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_layout->GetDisplacementCoefficient();
}

inline void PainterOfRoundedBorderOfWidget::SetColor(const QColor &color) noexcept
{
	this->m_color = color;
}

#pragma region SetRoundness [functions]
inline void PainterOfRoundedBorderOfWidget::SetRoundnessOfX(const roundness roundness_of_x) noexcept
{
	this->m_layout->SetRoundnessOfX(roundness_of_x);
}

inline void PainterOfRoundedBorderOfWidget::SetRoundnessOfY(const roundness roundness_of_y) noexcept
{
	this->m_layout->SetRoundnessOfY(roundness_of_y);
}
#pragma endregion SetRoundness [functions]

#pragma region SetThickness [functions]
inline void PainterOfRoundedBorderOfWidget::SetThicknessOfTop(const thickness thickness_of_top) noexcept
{
	this->m_layout->SetThicknessOfTop(thickness_of_top);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfBottom(const thickness thickness_of_bottom) noexcept
{
	this->m_layout->SetThicknessOfBottom(thickness_of_bottom);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfRight(const thickness thickness_of_right) noexcept
{
	this->m_layout->SetThicknessOfRight(thickness_of_right);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfLeft(const thickness thickness_of_left) noexcept
{
	this->m_layout->SetThicknessOfLeft(thickness_of_left);
}
#pragma endregion SetThickness [functions]

inline void PainterOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_layout->SetThickness(thickness);
}

inline void PainterOfRoundedBorderOfWidget::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_layout->SetRoundness(roundness);
}

inline void PainterOfRoundedBorderOfWidget::SetDisplacementCoefficient(displacement displacement_coefficient) noexcept
{
	this->m_layout->SetDisplacementCoefficient(displacement_coefficient);
}

inline void PainterOfRoundedBorderOfWidget::SetLayout(LayoutOfRoundedBorderOfWidget *layout) noexcept
{
	delete this->m_layout;

	this->m_layout = layout;
}

#endif  // RSS_FEED_READER_HEADERS_PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_H_
