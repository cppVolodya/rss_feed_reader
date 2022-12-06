#include "thickness_of_rounded_border_of_window.h"


ThicknessOfRoundedBorderOfWindow::ThicknessOfRoundedBorderOfWindow (const qint32 thickness_of_top,
																	const qint32 thickness_of_bottom,
																	const qint32 thickness_of_left,
																	const qint32 thickness_of_right)
	: m_thickness_of_top   (thickness_of_top   ),
	  m_thickness_of_bottom(thickness_of_bottom),
	  m_thickness_of_left  (thickness_of_left  ),
	  m_thickness_of_right (thickness_of_right )
{
}
