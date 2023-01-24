// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_HPP
#define PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_HPP

#include <QPainter>
#include <QPaintDevice>

#include <memory>

#include "abstract_layout_of_rounded_border_of_widget.hpp"


namespace N_PainterOfRoundedBorderOfWidget
{
using N_AbstractLayoutOfRoundedBorderOfWidget::AbstractLayoutOfRoundedBorderOfWidget;


enum class TypeLayoutOfRoundedBorderOfWidget
{
	EXTERNAL,
	INTERNAL,

	EXTERNAL_AND_INTERNAL,
};

class PainterOfRoundedBorderOfWidget : public QPainter
{
public:
	inline PainterOfRoundedBorderOfWidget() noexcept;

	explicit inline PainterOfRoundedBorderOfWidget(QPaintDevice *device,
												   TypeLayoutOfRoundedBorderOfWidget type_layout
												   = TypeLayoutOfRoundedBorderOfWidget::EXTERNAL_AND_INTERNAL);

	void Draw(const QRectF &);

	[[nodiscard]] constexpr inline QColor GetColor() const noexcept;

	[[nodiscard]] inline T_Roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] inline T_Roundness GetRoundnessOfY() const noexcept;

	[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget GetRoundness() const noexcept;

	[[nodiscard]] inline T_Thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfRight () const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfLeft  () const noexcept;

	[[nodiscard]] inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] inline T_Displacement GetDisplacementCoefficient() const noexcept;

	inline void SetColor(const QColor &) noexcept;

	inline void SetRoundnessOfX(T_Roundness) noexcept;
	inline void SetRoundnessOfY(T_Roundness) noexcept;

	inline void SetRoundness(const RoundnessOfRoundedBorderOfWidget &) noexcept;

	inline void SetThicknessOfTop   (T_Thickness) noexcept;
	inline void SetThicknessOfBottom(T_Thickness) noexcept;
	inline void SetThicknessOfRight (T_Thickness) noexcept;
	inline void SetThicknessOfLeft  (T_Thickness) noexcept;

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(T_Displacement) noexcept;

	inline void SetTypeOfLayout(TypeLayoutOfRoundedBorderOfWidget type_layout) noexcept;
private:
	std::unique_ptr<AbstractLayoutOfRoundedBorderOfWidget> m_layout;
	TypeLayoutOfRoundedBorderOfWidget m_layout_type;

	QColor m_color;
private:
	inline void Customize();

	inline void DrawAccordingToLayout();

	inline void ReleaseSetColor();

	void AllocateMemoryForLayout();
};

inline PainterOfRoundedBorderOfWidget::PainterOfRoundedBorderOfWidget() noexcept
	: m_layout_type(TypeLayoutOfRoundedBorderOfWidget::EXTERNAL_AND_INTERNAL)
{
	this->AllocateMemoryForLayout();
}

inline PainterOfRoundedBorderOfWidget::PainterOfRoundedBorderOfWidget(QPaintDevice *device,
																	  TypeLayoutOfRoundedBorderOfWidget type_layout)
	: QPainter(device),
	  m_layout_type(type_layout)
{
	this->AllocateMemoryForLayout();
}

[[nodiscard]] constexpr inline QColor PainterOfRoundedBorderOfWidget::GetColor() const noexcept
{
	return this->m_color;
}

[[nodiscard]] inline T_Roundness PainterOfRoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_layout->GetRoundnessOfX();
}

[[nodiscard]] inline T_Roundness PainterOfRoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_layout->GetRoundnessOfY();
}

[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget PainterOfRoundedBorderOfWidget::GetRoundness() const noexcept
{
	return this->m_layout->GetRoundness();
}

[[nodiscard]] inline T_Thickness PainterOfRoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_layout->GetThicknessOfTop();
}

[[nodiscard]] inline T_Thickness PainterOfRoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_layout->GetThicknessOfBottom();
}

[[nodiscard]] inline T_Thickness PainterOfRoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_layout->GetThicknessOfRight();
}

[[nodiscard]] inline T_Thickness PainterOfRoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_layout->GetThicknessOfLeft();
}

[[nodiscard]] inline ThicknessOfRoundedBorderOfWidget PainterOfRoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_layout->GetThickness();
}

[[nodiscard]] inline T_Displacement PainterOfRoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_layout->GetDisplacementCoefficient();
}

inline void PainterOfRoundedBorderOfWidget::SetColor(const QColor &color) noexcept
{
	this->m_color = color;
}

inline void PainterOfRoundedBorderOfWidget::SetRoundnessOfX(const T_Roundness roundness_of_x) noexcept
{
	this->m_layout->SetRoundnessOfX(roundness_of_x);
}

inline void PainterOfRoundedBorderOfWidget::SetRoundnessOfY(const T_Roundness roundness_of_y) noexcept
{
	this->m_layout->SetRoundnessOfY(roundness_of_y);
}

inline void PainterOfRoundedBorderOfWidget::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_layout->SetRoundness(roundness);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfTop(const T_Thickness thickness_of_top) noexcept
{
	this->m_layout->SetThicknessOfTop(thickness_of_top);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfBottom(const T_Thickness thickness_of_bottom) noexcept
{
	this->m_layout->SetThicknessOfBottom(thickness_of_bottom);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfRight(const T_Thickness thickness_of_right) noexcept
{
	this->m_layout->SetThicknessOfRight(thickness_of_right);
}

inline void PainterOfRoundedBorderOfWidget::SetThicknessOfLeft(const T_Thickness thickness_of_left) noexcept
{
	this->m_layout->SetThicknessOfLeft(thickness_of_left);
}

inline void PainterOfRoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_layout->SetThickness(thickness);
}

inline void PainterOfRoundedBorderOfWidget::SetDisplacementCoefficient(T_Displacement displacement_coefficient) noexcept
{
	this->m_layout->SetDisplacementCoefficient(displacement_coefficient);
}

inline void PainterOfRoundedBorderOfWidget::SetTypeOfLayout(const TypeLayoutOfRoundedBorderOfWidget type_layout) noexcept
{
	this->m_layout_type = type_layout;

	this->AllocateMemoryForLayout();
}
}  // namespace N_PainterOfRoundedBorderOfWidget

#endif  // PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_HPP
