#ifndef RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_
#define RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_

#include <QWidget>
#include <QMouseEvent>

#include "painter_of_rounded_border_of_widget.h"
#include "cursors_of_widget.h"
#include "changing_size_of_widget.h"


using pressed = bool;

class RoundedBorderOfWindow : public QWidget
{
public:
#pragma region DefaultCharacteristic [members]
	const 	  static QSizeF  						  C_S_DEFAULT_SIZE;
	const 	  static QColor  						  C_S_DEFAULT_COLOR;
	const 	  static RoundnessOfRoundedBorderOfWidget C_S_DEFAULT_ROUNDNESS;
	const     static ThicknessOfRoundedBorderOfWidget C_S_DEFAULT_THICKNESS;
	constexpr static displacement 					  C_S_DEFAULT_DISPLACEMENT_COEFFICIENT{ 8.0 };
#pragma endregion DefaultCharacteristic [members]
public:
	explicit RoundedBorderOfWindow(QWidget *parent = nullptr);

	void SetDefaultSettings();

	[[nodiscard]] constexpr inline QColor GetColor() const noexcept;

#pragma region GetRoundness [functions]
	[[nodiscard]] constexpr inline roundness GetRoundnessOfX() const noexcept;  // x
	[[nodiscard]] constexpr inline roundness GetRoundnessOfY() const noexcept;  // y
#pragma endregion GetRoundness [functions]

#pragma region GetThickness [functions]
	[[nodiscard]] constexpr inline thickness GetThicknessOfTop   () const noexcept;  // top
	[[nodiscard]] constexpr inline thickness GetThicknessOfBottom() const noexcept;  // bottom
	[[nodiscard]] constexpr inline thickness GetThicknessOfRight () const noexcept;  // right
	[[nodiscard]] constexpr inline thickness GetThicknessOfLeft  () const noexcept;  // left
#pragma endregion GetThickness [functions]

	[[nodiscard]] inline ThicknessOfRoundedBorderOfWidget GetThickness() const noexcept;

	[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget GetRoundness() const noexcept;

	[[nodiscard]] inline displacement GetDisplacementCoefficient() const noexcept;

	inline void SetColor(const QColor &) noexcept;

#pragma region SetRoundness [functions]
	inline void SetRoundnessOfX(roundness) noexcept;  // x
	inline void SetRoundnessOfY(roundness) noexcept;  // y
#pragma endregion SetRoundness [functions]

#pragma region SetThickness [functions]
	inline void SetThicknessOfTop   (thickness) noexcept;  // top
	inline void SetThicknessOfBottom(thickness) noexcept;  // bottom
	inline void SetThicknessOfRight (thickness) noexcept;  // right
	inline void SetThicknessOfLeft  (thickness) noexcept;  // left
#pragma endregion SetThickness [functions]

	inline void SetThickness(const ThicknessOfRoundedBorderOfWidget &) noexcept;

	inline void SetRoundness(const RoundnessOfRoundedBorderOfWidget &) noexcept;

	inline void SetDisplacementCoefficient(displacement) noexcept;
protected:
	void paintEvent(QPaintEvent *) override;

#pragma region EventsOfMouse [functions]
	void mouseMoveEvent   (QMouseEvent *) override;
	void mousePressEvent  (QMouseEvent *) override;
	void mouseReleaseEvent(QMouseEvent *) override;
#pragma endregion EventsOfMouse [functions]
private:
	PainterOfRoundedBorderOfWidget m_painter_of_rounded_border;

	ChangingSizeOfWidget m_changing_size_of_widget;

	CursorsOfWidget m_cursors;

	pressed m_left_mouse_button_is_pressed;
private:
	void DrawOfRoundedBorder();

	inline void CustomizeChangingSizeOfWidget();

	void SetNewCursorIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &);

	void SetNewGeometryIfPressAndMoveMouseOnLayoutOfSizeBorder(QMouseEvent *);

	inline void SetValueIfLeftMouseButtonIsPressed(pressed, QMouseEvent *);
};

[[nodiscard]] constexpr inline QColor RoundedBorderOfWindow::GetColor() const noexcept
{
	return this->m_painter_of_rounded_border.GetColor();
}

#pragma region GetRoundness [functions]
[[nodiscard]] constexpr inline roundness RoundedBorderOfWindow::GetRoundnessOfX() const noexcept  // x
{
	return this->m_painter_of_rounded_border.GetRoundnessOfX();
}

[[nodiscard]] constexpr inline roundness RoundedBorderOfWindow::GetRoundnessOfY() const noexcept  // y
{
	return this->m_painter_of_rounded_border.GetRoundnessOfY();
}
#pragma endregion GetRoundness [functions]

#pragma region GetThickness [functions]
[[nodiscard]] constexpr inline thickness RoundedBorderOfWindow::GetThicknessOfTop() const noexcept  // top
{
	return this->m_painter_of_rounded_border.GetThicknessOfTop();
}

[[nodiscard]] constexpr inline thickness RoundedBorderOfWindow::GetThicknessOfBottom() const noexcept  // bottom
{
	return this->m_painter_of_rounded_border.GetThicknessOfBottom();
}

[[nodiscard]] constexpr inline thickness RoundedBorderOfWindow::GetThicknessOfRight() const noexcept  // right
{
	return this->m_painter_of_rounded_border.GetThicknessOfRight();
}

[[nodiscard]] constexpr inline thickness RoundedBorderOfWindow::GetThicknessOfLeft() const noexcept  // left
{
	return this->m_painter_of_rounded_border.GetThicknessOfLeft();
}
#pragma endregion GetThickness [functions]

[[nodiscard]] inline ThicknessOfRoundedBorderOfWidget RoundedBorderOfWindow::GetThickness() const noexcept
{
	return this->m_painter_of_rounded_border.GetThickness();
}

[[nodiscard]] inline RoundnessOfRoundedBorderOfWidget RoundedBorderOfWindow::GetRoundness() const noexcept
{
	return this->m_painter_of_rounded_border.GetRoundness();
}

[[nodiscard]] inline displacement RoundedBorderOfWindow::GetDisplacementCoefficient() const noexcept
{
	return this->m_painter_of_rounded_border.GetDisplacementCoefficient();
}

inline void RoundedBorderOfWindow::SetColor(const QColor &color) noexcept
{
	this->m_painter_of_rounded_border.SetColor(color);
}

#pragma region SetRoundness [functions]
inline void RoundedBorderOfWindow::SetRoundnessOfX(const roundness roundness_of_x) noexcept  // x
{
	this->m_painter_of_rounded_border.SetRoundnessOfX(roundness_of_x);
}

inline void RoundedBorderOfWindow::SetRoundnessOfY(const roundness roundness_of_y) noexcept  // y
{
	this->m_painter_of_rounded_border.SetRoundnessOfY(roundness_of_y);
}
#pragma endregion SetRoundness [functions]

#pragma region SetThickness [functions]
inline void RoundedBorderOfWindow::SetThicknessOfTop(const thickness thickness_of_top) noexcept  // top
{
	this->m_painter_of_rounded_border.SetThicknessOfTop(thickness_of_top);
}

inline void RoundedBorderOfWindow::SetThicknessOfBottom(const thickness thickness_of_bottom) noexcept  // bottom
{
	this->m_painter_of_rounded_border.SetThicknessOfBottom(thickness_of_bottom);
}

inline void RoundedBorderOfWindow::SetThicknessOfRight(const thickness thickness_of_right) noexcept  // right
{
	this->m_painter_of_rounded_border.SetThicknessOfRight(thickness_of_right);
}

inline void RoundedBorderOfWindow::SetThicknessOfLeft(const thickness thickness_of_left) noexcept  // left
{
	this->m_painter_of_rounded_border.SetThicknessOfLeft(thickness_of_left);
}
#pragma endregion SetThickness [functions]

inline void RoundedBorderOfWindow::SetThickness(const ThicknessOfRoundedBorderOfWidget &thickness) noexcept
{
	this->m_painter_of_rounded_border.SetThickness(thickness);
}

inline void RoundedBorderOfWindow::SetRoundness(const RoundnessOfRoundedBorderOfWidget &roundness) noexcept
{
	this->m_painter_of_rounded_border.SetRoundness(roundness);
}

inline void RoundedBorderOfWindow::SetDisplacementCoefficient(displacement displacement_coefficient) noexcept
{
	this->m_painter_of_rounded_border.SetDisplacementCoefficient(displacement_coefficient);
}

#endif  // RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_