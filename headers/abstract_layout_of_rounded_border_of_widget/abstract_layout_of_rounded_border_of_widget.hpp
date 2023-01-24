// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef ABSTRACT_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_HPP
#define ABSTRACT_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_HPP

#include <QPainterPath>

#include "shape_of_rounded_border_of_widget.hpp"
#include "roundness_of_rounded_border_of_widget.hpp"


namespace N_AbstractLayoutOfRoundedBorderOfWidget
{
using N_PainterOfRoundedBorderOfWidget::ShapeOfRoundedBorderOfWidget;
using N_PainterOfRoundedBorderOfWidget::ThicknessOfRoundedBorderOfWidget;
using N_PainterOfRoundedBorderOfWidget::RoundnessOfRoundedBorderOfWidget;

using N_PainterOfRoundedBorderOfWidget::T_Roundness;
using N_PainterOfRoundedBorderOfWidget::T_Thickness;
using N_PainterOfRoundedBorderOfWidget::T_Displacement;


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

	[[nodiscard]] inline T_Roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] inline T_Roundness GetRoundnessOfY() const noexcept;

	[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget GetRoundness() const noexcept;

	[[nodiscard]] inline T_Thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfRight () const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfLeft  () const noexcept;

	[[nodiscard]] inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] inline T_Displacement GetDisplacementCoefficient() const noexcept;

	[[nodiscard]] inline QSizeF GetSize() const noexcept;

	inline void SetRoundnessOfX(T_Roundness) noexcept;
	inline void SetRoundnessOfY(T_Roundness) noexcept;

	inline void SetRoundness(const RoundnessOfRoundedBorderOfWidget &) noexcept;

	inline void SetThicknessOfTop   (T_Thickness) noexcept;
	inline void SetThicknessOfBottom(T_Thickness) noexcept;
	inline void SetThicknessOfRight (T_Thickness) noexcept;
	inline void SetThicknessOfLeft  (T_Thickness) noexcept;

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(T_Displacement) noexcept;
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

[[nodiscard]] inline T_Roundness AbstractLayoutOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_roundness.GetRoundnessOfX();
}

[[nodiscard]] inline T_Roundness AbstractLayoutOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_roundness.GetRoundnessOfY();
}

[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget AbstractLayoutOfRoundedBorderOfWidget::GetRoundness() const noexcept
{
	return this->m_roundness;
}

[[nodiscard]] inline T_Thickness AbstractLayoutOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_shape.GetThicknessOfTop();
}

[[nodiscard]] inline T_Thickness AbstractLayoutOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_shape.GetThicknessOfBottom();
}

[[nodiscard]] inline T_Thickness AbstractLayoutOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_shape.GetThicknessOfRight();
}

[[nodiscard]] inline T_Thickness AbstractLayoutOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_shape.GetThicknessOfLeft();
}

[[nodiscard]] inline ThicknessOfRoundedBorderOfWidget AbstractLayoutOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_shape.GetThickness();
}

[[nodiscard]] inline T_Displacement AbstractLayoutOfRoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_shape.GetDisplacementCoefficient();
}

[[nodiscard]] inline QSizeF AbstractLayoutOfRoundedBorderOfWidget::GetSize() const noexcept
{
	return this->m_shape.GetSize();
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetRoundnessOfX(const T_Roundness roundness_of_x) noexcept
{
	this->m_roundness.SetRoundnessOfX(roundness_of_x);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetRoundnessOfY(const T_Roundness roundness_of_y) noexcept
{
	this->m_roundness.SetRoundnessOfY(roundness_of_y);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_roundness = roundness;
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThicknessOfTop(const T_Thickness thickness_of_top) noexcept
{
	this->m_shape.SetThicknessOfTop(thickness_of_top);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThicknessOfBottom(const T_Thickness thickness_of_bottom) noexcept
{
	this->m_shape.SetThicknessOfBottom(thickness_of_bottom);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThicknessOfRight(const T_Thickness thickness_of_right) noexcept
{
	this->m_shape.SetThicknessOfRight(thickness_of_right);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThicknessOfLeft(const T_Thickness thickness_of_left) noexcept
{
	this->m_shape.SetThicknessOfLeft(thickness_of_left);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_shape.SetThickness(thickness);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::SetDisplacementCoefficient(T_Displacement displacement_coefficient) noexcept
{
	this->m_shape.SetDisplacementCoefficient(displacement_coefficient);
}
}  // namespace N_AbstractLayoutOfRoundedBorderOfWidget

#endif  // ABSTRACT_LAYOUT_OF_ROUNDED_BORDER_OF_WIDGET_HPP
