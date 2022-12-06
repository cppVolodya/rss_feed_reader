#include "window_with_rounded_border_and_graphic_effect.h"


WindowWithRoundedBorderAndGraphicEffect::WindowWithRoundedBorderAndGraphicEffect(QWidget *parent)
	: CentralPartOfWindowWithGraphicEffect(parent)
{
	this->m_rounded_bord = new RoundedBorderOfWindow(this);
	this->m_rounded_bord->show();

	this->setFixedSize(100, 100);  // TEST
}
