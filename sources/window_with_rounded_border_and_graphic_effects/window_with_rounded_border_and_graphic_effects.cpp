// Copyright [2023] <Volodymyr Dorozhovets>"

#include "window_with_rounded_border_and_graphic_effects.h"


WindowWithRoundedBorderAndGraphicEffects::WindowWithRoundedBorderAndGraphicEffects(QWidget *parent)
	: CentralPartOfWindowWithGraphicEffects(parent)
{
	this->m_rounded_border_of_window = new RoundedBorderOfWindow(this);
	this->m_rounded_border_of_window->show();
}
