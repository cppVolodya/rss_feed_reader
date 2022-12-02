#include "rounded_border_of_main_window.h"


RoundedBorderOfMainWindow::RoundedBorderOfMainWindow(QWidget *parent)
	: BorderOfMainWindow(parent)
{
	this->setWindowFlag(Qt::FramelessWindowHint, true);
}
