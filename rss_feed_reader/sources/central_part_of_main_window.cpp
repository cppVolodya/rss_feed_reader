#include "central_part_of_main_window.h"


CentralPartOfMainWindow::CentralPartOfMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowFlag(Qt::FramelessWindowHint, true);
}
