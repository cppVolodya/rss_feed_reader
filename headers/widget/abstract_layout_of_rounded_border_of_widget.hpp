// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef ABSTRACT_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_HPP
#define ABSTRACT_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_HPP

#include <QPainterPath>

#include "shape_of_rounded_border_of_widget.hpp"
#include "roundness_of_rounded_border_of_widget.hpp"


class AbstractLayoutOfRoundedBorderOfWidget : public QPainterPath
{
public:
	AbstractLayoutOfRoundedBorderOfWidget() = default;

#pragma region RuleOfZero
	AbstractLayoutOfRoundedBorderOfWidget(const AbstractLayoutOfRoundedBorderOfWidget &) = default;
	AbstractLayoutOfRoundedBorderOfWidget(AbstractLayoutOfRoundedBorderOfWidget &&) 	 = default;

	AbstractLayoutOfRoundedBorderOfWidget& operator=(const AbstractLayoutOfRoundedBorderOfWidget &) = default;
	AbstractLayoutOfRoundedBorderOfWidget& operator=(AbstractLayoutOfRoundedBorderOfWidget &&) 	    = default;

	virtual ~AbstractLayoutOfRoundedBorderOfWidget() = default;
#pragma endregion RuleOfZero

	inline void Customize(const QRectF &);

	[[nodiscard]] inline t_roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] inline t_roundness GetRoundnessOfY() const noexcept;

	[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget GetRoundness() const noexcept;

	[[nodiscard]] inline t_thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] inline t_thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] inline t_thickness GetThicknessOfRight () const noexcept;
	[[nodiscard]] inline t_thickness GetThicknessOfLeft  () const noexcept;

	[[nodiscard]] inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] inline t_displacement GetDisplacementCoefficient() const noexcept;

	[[nodiscard]] inline QSizeF GetSize() const noexcept;

	inline void SetRoundnessOfX(t_roundness) noexcept;
	inline void SetRoundnessOfY(t_roundness) noexcept;

	inline void SetRoundness(const RoundnessOfRoundedBorderOfWidget &) noexcept;

	inline void SetThicknessOfTop   (t_thickness) noexcept;
	inline void SetThicknessOfBottom(t_thickness) noexcept;
	inline void SetThicknessOfRight (t_thickness) noexcept;
	inline void SetThicknessOfLeft  (t_thickness) noexcept;

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(t_displacement) noexcept;
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

inline void AbstractLayoutOfRoundedBorderOfWidget::Customize(const QRectF &geometry_of_window)
{
	this->ReleaseCustomize(geometry_of_window);
}

[[nodiscard]] inline t_roundness AbstractLayoutOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_roundness.GetRoundnessOfX();
}

[[nodiscard]] inline t_roundness AbstractLayoutOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_roundness.GetRoundnessOfY();
}

[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget AbstractLayoutOfRoundedBorderOfWidget::GetRoundness() const noexcept
{
	return this->m_roundness;
}

[[nodiscard]] inline t_thickness AbstractLayoutOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_shape.GetThicknessOfTop();
}

[[nodiscard]] inline t_thickness AbstractLayoutOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_shape.GetThicknessOfBottom();
}

[[nodiscard]] inline t_thickness AbstractLayoutOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_shape.GetThicknessOfRight();
}

[[nodiscard]] inline t_thickness AbstractLayoutOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_shape.GetThicknessOfLeft();
}

[[nodiscard]] inline ThicknessOfRoundedBorderOfWidget AbstractLayoutOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_shape.GetThickness();
}

[[nodiscard]] inline t_displacement AbstractLayoutOfRoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_shape.GetDisplacementCoefficient();
}

[[nodiscard]] inline QSizeF AbstractLayoutOfRoundedBorderOfWidget::GetSize() const noexcept
{
	return this->m_shape.GetSize();
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetRoundnessOfX(const t_roundness roundness_of_x) noexcept
{
	this->m_roundness.SetRoundnessOfX(roundness_of_x);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetRoundnessOfY(const t_roundness roundness_of_y) noexcept
{
	this->m_roundness.SetRoundnessOfY(roundness_of_y);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_roundness = roundness;
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThicknessOfTop(const t_thickness thickness_of_top) noexcept
{
	this->m_shape.SetThicknessOfTop(thickness_of_top);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThicknessOfBottom(const t_thickness thickness_of_bottom) noexcept
{
	this->m_shape.SetThicknessOfBottom(thickness_of_bottom);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThicknessOfRight(const t_thickness thickness_of_right) noexcept
{
	this->m_shape.SetThicknessOfRight(thickness_of_right);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThicknessOfLeft(const t_thickness thickness_of_left) noexcept
{
	this->m_shape.SetThicknessOfLeft(thickness_of_left);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_shape.SetThickness(thickness);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetDisplacementCoefficient(t_displacement displacement_coefficient) noexcept
{
	this->m_shape.SetDisplacementCoefficient(displacement_coefficient);
}

#endif  // ABSTRACT_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_HPP
