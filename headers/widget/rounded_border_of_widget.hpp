// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef ROUNDED_BORDER_OF_WIDGET_HPP
#define ROUNDED_BORDER_OF_WIDGET_HPP

#include <QWidget>
#include <QMouseEvent>

#include "types_aliases.hpp"
#include "painter_of_rounded_border_of_widget.hpp"
#include "cursors_of_widget.hpp"
#include "changing_size_and_cursor_of_widget.hpp"
#include "graphics_shadow_effect_of_widget.hpp"


namespace N_Widget
{
using N_PainterOfRoundedBorderOfWidget::PainterOfRoundedBorderOfWidget;
using N_PainterOfRoundedBorderOfWidget::RoundnessOfRoundedBorderOfWidget;

using N_ChangingSizeAndCursorOfWidget::ChangingSizeAndCursorOfWidget;

using N_TypesAliases::T_Roundness;
using N_TypesAliases::T_Thickness;
using N_TypesAliases::T_Pressed;
using N_TypesAliases::T_ThicknessOfRoundedBorderOfWidget;


class RoundedBorderOfWidget : public QWidget
{
public:
	explicit RoundedBorderOfWidget(CursorsOfWidget &, QWidget *parent = nullptr);

	void SetDefaultSettings();
	void SetDefaultCharacteristic();

	[[nodiscard]] inline QColor GetColor() const noexcept;

	[[nodiscard]] inline T_Roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] inline T_Roundness GetRoundnessOfY() const noexcept;

	[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget GetRoundness() const noexcept;

	[[nodiscard]] inline T_Thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfLeft  () const noexcept;
	[[nodiscard]] inline T_Thickness GetThicknessOfRight () const noexcept;

	[[nodiscard]] inline T_ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] inline T_ThicknessOfRoundedBorderOfWidget GetBoundingThickness() const noexcept;

	inline void SetColor(const QColor &) noexcept;

	inline void SetRoundnessOfX(T_Roundness) noexcept;
	inline void SetRoundnessOfY(T_Roundness) noexcept;

	inline void SetRoundness(const RoundnessOfRoundedBorderOfWidget &) noexcept;

	inline void SetThicknessOfTop   (T_Thickness) noexcept;
	inline void SetThicknessOfBottom(T_Thickness) noexcept;
	inline void SetThicknessOfLeft  (T_Thickness) noexcept;
	inline void SetThicknessOfRight (T_Thickness) noexcept;

	inline void SetThickness(const T_ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetBoundingThickness(const T_ThicknessOfRoundedBorderOfWidget &) noexcept;
protected:
	void paintEvent(QPaintEvent *) override;

	void mouseMoveEvent   (QMouseEvent *) override;
	void mousePressEvent  (QMouseEvent *) override;
	void mouseReleaseEvent(QMouseEvent *) override;
private:
	PainterOfRoundedBorderOfWidget m_painter_of_rounded_border;

	ChangingSizeAndCursorOfWidget m_changing_cursor_and_size;

	CursorsOfWidget &m_cursors;

	T_Pressed m_left_mouse_button_is_pressed;

	GraphicsShadowEffectOfWidget m_graphics_shadow_effect;
private:
	void DrawOfRoundedBorder();

	void SetNewCursorIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &);

	void SetNewGeometryIfPressAndMoveMouseOnLayoutOfSizeBorder(const QMouseEvent *);

	inline void SetValueIfLeftMouseButtonIsPressed(T_Pressed, const QMouseEvent *);
};

[[nodiscard]] inline QColor RoundedBorderOfWidget::GetColor() const noexcept
{
	return this->m_painter_of_rounded_border.GetColor();
}

[[nodiscard]] inline T_Roundness RoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundnessOfX();
}

[[nodiscard]] inline T_Roundness RoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundnessOfY();
}

[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget RoundedBorderOfWidget::GetRoundness() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundness();
}

[[nodiscard]] inline T_Thickness RoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfTop();
}

[[nodiscard]] inline T_Thickness RoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfBottom();
}

[[nodiscard]] inline T_Thickness RoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfLeft();
}

[[nodiscard]] inline T_Thickness RoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfRight();
}

[[nodiscard]] inline T_ThicknessOfRoundedBorderOfWidget RoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_painter_of_rounded_border.GetThickness();
}

[[nodiscard]] inline T_ThicknessOfRoundedBorderOfWidget RoundedBorderOfWidget::GetBoundingThickness() const noexcept
{
	return this->m_painter_of_rounded_border.GetBoundingThickness();
}

inline void RoundedBorderOfWidget::SetColor(const QColor &color) noexcept
{
	this->m_painter_of_rounded_border.SetColor(color);
}

inline void RoundedBorderOfWidget::SetRoundnessOfX(const T_Roundness roundness_of_x) noexcept
{
	this->m_painter_of_rounded_border.SetRoundnessOfX(roundness_of_x);
}

inline void RoundedBorderOfWidget::SetRoundnessOfY(const T_Roundness roundness_of_y) noexcept
{
	this->m_painter_of_rounded_border.SetRoundnessOfY(roundness_of_y);
}

inline void RoundedBorderOfWidget::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_painter_of_rounded_border.SetRoundness(roundness);
}

inline void RoundedBorderOfWidget::SetThicknessOfTop(const T_Thickness thickness_of_top) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfTop(thickness_of_top);
}

inline void RoundedBorderOfWidget::SetThicknessOfBottom(const T_Thickness thickness_of_bottom) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfBottom(thickness_of_bottom);
}

inline void RoundedBorderOfWidget::SetThicknessOfLeft(const T_Thickness thickness_of_left) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfLeft(thickness_of_left);
}

inline void RoundedBorderOfWidget::SetThicknessOfRight(const T_Thickness thickness_of_right) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfRight(thickness_of_right);
}

inline void RoundedBorderOfWidget::SetThickness(const T_ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_painter_of_rounded_border.SetThickness(thickness);
}

inline void RoundedBorderOfWidget::SetBoundingThickness(const T_ThicknessOfRoundedBorderOfWidget &bounding_thickness) noexcept
{
	this->m_painter_of_rounded_border.SetBoundingThickness(bounding_thickness);
}
}  // namespace N_Widget

#endif  // ROUNDED_BORDER_OF_WIDGET_HPP
