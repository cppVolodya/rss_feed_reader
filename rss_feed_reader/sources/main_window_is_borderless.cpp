#include "main_window_is_borderless.h"


MainWindowIsBorderless::MainWindowIsBorderless(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowFlag(Qt::FramelessWindowHint, true);
}
