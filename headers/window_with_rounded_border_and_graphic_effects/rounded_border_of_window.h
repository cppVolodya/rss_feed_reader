#ifndef RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_
#define RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_

#include <QWidget>
#include <QMouseEvent>

#include "painter_of_rounded_border_of_widget.h"
#include "cursors_of_widget.h"
#include "changing_size_of_widget.h"


using t_pressed = bool;

class RoundedBorderOfWindow : public QWidget
{
public:
	const 	  static QSizeF  						  C_S_DEFAULT_SIZE;
	const 	  static QColor  						  C_S_DEFAULT_COLOR;
	const 	  static RoundnessOfRoundedBorderOfWidget C_S_DEFAULT_ROUNDNESS;
	const     static ThicknessOfRoundedBorderOfWidget C_S_DEFAULT_THICKNESS;
	constexpr static t_displacement 				  C_S_DEFAULT_DISPLACEMENT_COEFFICIENT{ 8.0 };
public:
	explicit RoundedBorderOfWindow(QWidget *parent = nullptr);

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

[[nodiscard]] constexpr inline QColor RoundedBorderOfWindow::GetColor() const noexcept
{
	return this->m_painter_of_rounded_border.GetColor();
}

[[nodiscard]] constexpr inline t_roundness RoundedBorderOfWindow::GetRoundnessOfX() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundnessOfX();
}

[[nodiscard]] constexpr inline t_roundness RoundedBorderOfWindow::GetRoundnessOfY() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundnessOfY();
}

[[nodiscard]] constexpr inline RoundnessOfRoundedBorderOfWidget RoundedBorderOfWindow::GetRoundness() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundness();
}

[[nodiscard]] constexpr inline t_thickness RoundedBorderOfWindow::GetThicknessOfTop() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfTop();
}

[[nodiscard]] constexpr inline t_thickness RoundedBorderOfWindow::GetThicknessOfBottom() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline t_thickness RoundedBorderOfWindow::GetThicknessOfRight() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfRight();
}

[[nodiscard]] constexpr inline t_thickness RoundedBorderOfWindow::GetThicknessOfLeft() const noexcept
{
	return this->m_painter_of_rounded_border.GetThicknessOfLeft();
}

[[nodiscard]] constexpr inline ThicknessOfRoundedBorderOfWidget RoundedBorderOfWindow::GetThickness() const noexcept
{
	return this->m_painter_of_rounded_border.GetThickness();
}

[[nodiscard]] constexpr inline t_displacement RoundedBorderOfWindow::GetDisplacementCoefficient() const noexcept
{
	return this->m_painter_of_rounded_border.GetDisplacementCoefficient();
}

inline void RoundedBorderOfWindow::SetColor(const QColor &color) noexcept
{
	this->m_painter_of_rounded_border.SetColor(color);
}

inline void RoundedBorderOfWindow::SetRoundnessOfX(const t_roundness roundness_of_x) noexcept
{
	this->m_painter_of_rounded_border.SetRoundnessOfX(roundness_of_x);
}

inline void RoundedBorderOfWindow::SetRoundnessOfY(const t_roundness roundness_of_y) noexcept
{
	this->m_painter_of_rounded_border.SetRoundnessOfY(roundness_of_y);
}

inline void RoundedBorderOfWindow::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_painter_of_rounded_border.SetRoundness(roundness);
}

inline void RoundedBorderOfWindow::SetThicknessOfTop(const t_thickness thickness_of_top) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfTop(thickness_of_top);
}

inline void RoundedBorderOfWindow::SetThicknessOfBottom(const t_thickness thickness_of_bottom) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfBottom(thickness_of_bottom);
}

inline void RoundedBorderOfWindow::SetThicknessOfRight(const t_thickness thickness_of_right) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfRight(thickness_of_right);
}

inline void RoundedBorderOfWindow::SetThicknessOfLeft(const t_thickness thickness_of_left) noexcept
{
	this->m_painter_of_rounded_border.SetThicknessOfLeft(thickness_of_left);
}

inline void RoundedBorderOfWindow::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_painter_of_rounded_border.SetThickness(thickness);
}

inline void RoundedBorderOfWindow::SetDisplacementCoefficient(t_displacement displacement_coefficient) noexcept
{
	this->m_painter_of_rounded_border.SetDisplacementCoefficient(displacement_coefficient);
}

#endif  // RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_
