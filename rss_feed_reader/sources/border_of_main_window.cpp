#include "border_of_main_window.h"


BorderOfMainWindow::BorderOfMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowFlag(Qt::FramelessWindowHint, true);
}
