#include "characteristic_of_rounded_border_of_window.h"


CharacteristicOfRoundedBorderOfWindow::CharacteristicOfRoundedBorderOfWindow (const RoundnessOfRoundedBorderOfWindow &roundness,
																			  const ThicknessOfRoundedBorderOfWindow &thickness,
																			  const QColor 							 &color)
	 : m_roundness(roundness),
	   m_thickness(thickness),
	   m_color    (color    )
{
}
