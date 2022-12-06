#include "central_part_of_window_with_graphic_effect.h"


CentralPartOfWindowWithGraphicEffect::CentralPartOfWindowWithGraphicEffect(QWidget *parent)
	: QWidget(parent)
{
	this->setWindowFlag(Qt::FramelessWindowHint, true);
}
