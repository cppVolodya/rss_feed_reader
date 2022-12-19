#ifndef RSS_FEED_READER_HEADERS_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QPainterPath>

#include "shape_of_rounded_border_of_widget.h"
#include "roundness_of_rounded_border_of_widget.h"


class LayoutOfRoundedBorderOfWidget : public QPainterPath
{
public:
	inline LayoutOfRoundedBorderOfWidget() noexcept;
	virtual ~LayoutOfRoundedBorderOfWidget() = default;

	inline void Customize(const QRectF &) noexcept;

	[[nodiscard]] constexpr inline roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] constexpr inline roundness GetRoundnessOfY() const noexcept;

	inline void SetRoundnessOfX(roundness) noexcept;
	inline void SetRoundnessOfY(roundness) noexcept;
protected:
	ShapeOfRoundedBorderOfWidget     m_shape;
	RoundnessOfRoundedBorderOfWidget m_roundness;
protected:
	virtual void ReleaseSetRoundness() = 0;
private:
	void UpdateData(const QRectF &) noexcept;
	void AddShape() noexcept;
};

inline LayoutOfRoundedBorderOfWidget::LayoutOfRoundedBorderOfWidget() noexcept
{
	this->setFillRule(Qt::OddEvenFill);

	this->m_roundness = RoundnessOfRoundedBorderOfWidget(15, 15);  // TEST
}

inline void LayoutOfRoundedBorderOfWidget::Customize(const QRectF &geometry_of_window) noexcept
{
	this->UpdateData(geometry_of_window);
	this->AddShape();
}

constexpr inline roundness LayoutOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_roundness.GetRoundnessOfX();
}

constexpr inline roundness LayoutOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_roundness.GetRoundnessOfY();
}

inline void LayoutOfRoundedBorderOfWidget::SetRoundnessOfX(const roundness roundness_of_x) noexcept
{
	this->m_roundness.SetRoundnessOfX(roundness_of_x);
}

inline void LayoutOfRoundedBorderOfWidget::SetRoundnessOfY(const roundness roundness_of_y) noexcept
{
	this->m_roundness.SetRoundnessOfY(roundness_of_y);
}

#endif  // RSS_FEED_READER_HEADERS_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_H_
