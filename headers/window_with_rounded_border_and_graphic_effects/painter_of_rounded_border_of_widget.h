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

	[[nodiscard]] constexpr inline t_roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] constexpr inline t_roundness GetRoundnessOfY() const noexcept;

	[[nodiscard]] constexpr inline t_thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfRight () const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfLeft  () const noexcept;

	[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] constexpr inline RoundnessOfRoundedBorderOfWidget GetRoundness() const noexcept;

	[[nodiscard]] constexpr inline t_displacement GetDisplacementCoefficient() const noexcept;

	inline void SetColor(const QColor &) noexcept;

	inline void SetRoundnessOfX(t_roundness) noexcept;
	inline void SetRoundnessOfY(t_roundness) noexcept;

	inline void SetThicknessOfTop   (t_thickness) noexcept;
	inline void SetThicknessOfBottom(t_thickness) noexcept;
	inline void SetThicknessOfRight (t_thickness) noexcept;
	inline void SetThicknessOfLeft  (t_thickness) noexcept;

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetRoundness(const RoundnessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(t_displacement) noexcept;

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

[[nodiscard]] constexpr inline t_roundness PainterOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_layout->GetRoundnessOfX();
}

[[nodiscard]] constexpr inline t_roundness PainterOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_layout->GetRoundnessOfY();
}

[[nodiscard]] constexpr inline t_thickness PainterOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_layout->GetThicknessOfTop();
}

[[nodiscard]] constexpr inline t_thickness PainterOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_layout->GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline t_thickness PainterOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_layout->GetThicknessOfRight();
}

[[nodiscard]] constexpr inline t_thickness PainterOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_layout->GetThicknessOfLeft();
}

[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget PainterOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_layout->GetThickness();
}

[[nodiscard]] constexpr inline RoundnessOfRoundedBorderOfWidget PainterOfRoundedBorderOfWidget::GetRoundness() const noexcept
{
	return this->m_layout->GetRoundness();
}

[[nodiscard]] constexpr inline t_displacement PainterOfRoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_layout->GetDisplacementCoefficient();
}

inline void PainterOfRoundedBorderOfWidget::SetColor(const QColor &color) noexcept
{
	this->m_color = color;
}

inline void PainterOfRoundedBorderOfWidget::SetRoundnessOfX(const t_roundness roundness_of_x) noexcept
{
	this->m_layout->SetRoundnessOfX(roundness_of_x);
}

inline void PainterOfRoundedBorderOfWidget::SetRoundnessOfY(const t_roundness roundness_of_y) noexcept
{
	this->m_layout->SetRoundnessOfY(roundness_of_y);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfTop(const t_thickness thickness_of_top) noexcept
{
	this->m_layout->SetThicknessOfTop(thickness_of_top);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfBottom(const t_thickness thickness_of_bottom) noexcept
{
	this->m_layout->SetThicknessOfBottom(thickness_of_bottom);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfRight(const t_thickness thickness_of_right) noexcept
{
	this->m_layout->SetThicknessOfRight(thickness_of_right);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfLeft(const t_thickness thickness_of_left) noexcept
{
	this->m_layout->SetThicknessOfLeft(thickness_of_left);
}

inline void PainterOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_layout->SetThickness(thickness);
}

inline void PainterOfRoundedBorderOfWidget::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_layout->SetRoundness(roundness);
}

inline void PainterOfRoundedBorderOfWidget::SetDisplacementCoefficient(t_displacement displacement_coefficient) noexcept
{
	this->m_layout->SetDisplacementCoefficient(displacement_coefficient);
}

inline void PainterOfRoundedBorderOfWidget::SetLayout(LayoutOfRoundedBorderOfWidget *layout) noexcept
{
	delete this->m_layout;

	this->m_layout = layout;
}

#endif  // RSS_FEED_READER_HEADERS_PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_H_
