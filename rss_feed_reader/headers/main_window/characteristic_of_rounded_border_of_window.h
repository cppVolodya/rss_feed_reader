#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_CHARACTERISTIC_OF_ROUNDED_BORDER_OF_WINDOW_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_CHARACTERISTIC_OF_ROUNDED_BORDER_OF_WINDOW_H_

#include <QColor>

#include "roundness_of_rounded_border_of_window.h"
#include "thickness_of_rounded_border_of_window.h"


class CharacteristicOfRoundedBorderOfWindow
{
public:
	explicit CharacteristicOfRoundedBorderOfWindow(const RoundnessOfRoundedBorderOfWindow &roundness = RoundnessOfRoundedBorderOfWindow(),
												   const ThicknessOfRoundedBorderOfWindow &thickness = ThicknessOfRoundedBorderOfWindow(),
												   const QColor 						  &color 	 = QColor						   ());

	[[nodiscard]] inline RoundnessOfRoundedBorderOfWindow GetRoundness() const;
	[[nodiscard]] inline ThicknessOfRoundedBorderOfWindow GetThickness() const;
	[[nodiscard]] inline QColor 						  GetColor    () const;

	inline void SetRoundness(const RoundnessOfRoundedBorderOfWindow &);
	inline void SetThickness(const ThicknessOfRoundedBorderOfWindow &);
	inline void SetColor    (const QColor							&);
private:
	RoundnessOfRoundedBorderOfWindow m_roundness;
	ThicknessOfRoundedBorderOfWindow m_thickness;
	QColor 								 m_color;
};

inline RoundnessOfRoundedBorderOfWindow CharacteristicOfRoundedBorderOfWindow::GetRoundness() const
{
	return this->m_roundness;
}

inline ThicknessOfRoundedBorderOfWindow CharacteristicOfRoundedBorderOfWindow::GetThickness() const
{
	return this->m_thickness;
}

inline QColor CharacteristicOfRoundedBorderOfWindow::GetColor() const
{
	return this->m_color;
}

inline void CharacteristicOfRoundedBorderOfWindow::SetRoundness(const RoundnessOfRoundedBorderOfWindow &roundness)
{
	this->m_roundness = roundness;
}

inline void CharacteristicOfRoundedBorderOfWindow::SetThickness(const ThicknessOfRoundedBorderOfWindow &thickness)
{
	this->m_thickness = thickness;
}

inline void CharacteristicOfRoundedBorderOfWindow::SetColor(const QColor &color)
{
	this->m_color = color;
}

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_CHARACTERISTIC_OF_ROUNDED_BORDER_OF_WINDOW_H_
