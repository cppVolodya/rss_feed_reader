#include "central_part_of_window_with_graphic_effects.h"


CentralPartOfWindowWithGraphicEffects::CentralPartOfWindowWithGraphicEffects(QWidget *parent)
	: QWidget(parent, Qt::Window)
{
	this->setWindowFlag(Qt::FramelessWindowHint, true);
}
