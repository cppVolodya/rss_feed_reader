// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_
#define RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_

#include <QWidget>
#include <QMouseEvent>

#include "painter_of_rounded_border_of_widget.hpp"
#include "cursors_of_widget.hpp"
#include "changing_size_of_widget.hpp"


using t_pressed = bool;

class RoundedBorderOfWidget : public QWidget
{
public:
	explicit RoundedBorderOfWidget(QWidget *parent = nullptr);

	void SetDefaultSettings();

	[[nodiscard]] constexpr inline QColor GetColor() const noexcept;

	[[nodiscard]] constexpr inline t_roundness GetRoundnessOfX() const noexcept;
	[[nodiscard]] constexpr inline t_roundness GetRoundnessOfY() const noexcept;

	[[nodiscard]] constexpr inline RoundnessOfRoundedBorderOfWidget GetRoundness() const noexcept;

	[[nodiscard]] constexpr inline t_thickness GetThicknessOfTop   () const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfBottom() const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfRight () const noexcept;
	[[nodiscard]] constexpr inline t_thickness GetThicknessOfLeft  () const noexcept;

	[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] constexpr inline t_displacement GetDisplacementCoefficient() const noexcept;

	inline void SetColor(const QColor &) noexcept;

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
	void paintEvent(QPaintEvent *) override;

	void mouseMoveEvent   (QMouseEvent *) override;
	void mousePressEvent  (QMouseEvent *) override;
	void mouseReleaseEvent(QMouseEvent *) override;
private:
	PainterOfRoundedBorderOfWidget m_painter_of_rounded_border;

	ChangingSizeOfWidget m_changing_size_of_widget;

	CursorsOfWidget m_cursors;

	t_pressed m_left_mouse_button_is_pressed;
private:
	void DrawOfRoundedBorder();

	inline void CustomizeChangingSizeOfWidget();

	void SetNewCursorIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &);

	void SetNewGeometryIfPressAndMoveMouseOnLayoutOfSizeBorder(QMouseEvent *);

	inline void SetValueIfLeftMouseButtonIsPressed(t_pressed, QMouseEvent *);
};

[[nodiscard]] constexpr inline QColor RoundedBorderOfWidget::GetColor() const noexcept
{
	return this->m_painter_of_rounded_border.GetColor();
}

[[nodiscard]] constexpr inline t_roundness RoundedBorderOfWidget::GetRoundnessOfX() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundnessOfX();
}

[[nodiscard]] constexpr inline t_roundness RoundedBorderOfWidget::GetRoundnessOfY() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundnessOfY();
}

[[nodiscard]] constexpr inline RoundnessOfRoundedBorderOfWidget RoundedBorderOfWidget::GetRoundness() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundness();
}

[[nodiscard]] constexpr inline t_thickness RoundedBorderOfWidget::GetThicknessOfTop() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfTop();
}

[[nodiscard]] constexpr inline t_thickness RoundedBorderOfWidget::GetThicknessOfBottom() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline t_thickness RoundedBorderOfWidget::GetThicknessOfRight() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfRight();
}

[[nodiscard]] constexpr inline t_thickness RoundedBorderOfWidget::GetThicknessOfLeft() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfLeft();
}

[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget RoundedBorderOfWidget::GetThickness() const noexcept
{
	return this->m_painter_of_rounded_border.GetThickness();
}

[[nodiscard]] constexpr inline t_displacement RoundedBorderOfWidget::GetDisplacementCoefficient() const noexcept
{
	return this->m_painter_of_rounded_border.GetDisplacementCoefficient();
}

inline void RoundedBorderOfWidget::SetColor(const QColor &color) noexcept
{
	this->m_painter_of_rounded_border.SetColor(color);
}

inline void RoundedBorderOfWidget::SetRoundnessOfX(const t_roundness roundness_of_x) noexcept
{
	this->m_painter_of_rounded_border.SetRoundnessOfX(roundness_of_x);
}

inline void RoundedBorderOfWidget::SetRoundnessOfY(const t_roundness roundness_of_y) noexcept
{
	this->m_painter_of_rounded_border.SetRoundnessOfY(roundness_of_y);
}

inline void RoundedBorderOfWidget::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_painter_of_rounded_border.SetRoundness(roundness);
}

inline void RoundedBorderOfWidget::SetThicknessOfTop(const t_thickness thickness_of_top) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfTop(thickness_of_top);
}

inline void RoundedBorderOfWidget::SetThicknessOfBottom(const t_thickness thickness_of_bottom) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfBottom(thickness_of_bottom);
}

inline void RoundedBorderOfWidget::SetThicknessOfRight(const t_thickness thickness_of_right) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfRight(thickness_of_right);
}

inline void RoundedBorderOfWidget::SetThicknessOfLeft(const t_thickness thickness_of_left) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfLeft(thickness_of_left);
}

inline void RoundedBorderOfWidget::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_painter_of_rounded_border.SetThickness(thickness);
}

inline void RoundedBorderOfWidget::SetDisplacementCoefficient(t_displacement displacement_coefficient) noexcept
{
	this->m_painter_of_rounded_border.SetDisplacementCoefficient(displacement_coefficient);
}

#endif  // RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_