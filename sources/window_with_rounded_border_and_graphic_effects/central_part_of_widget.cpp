// Copyright [2023] <Volodymyr Dorozhovets>"

#include "central_part_of_widget.h"


CentralPartOfWidget::CentralPartOfWidget(QWidget *parent)
	: QWidget(parent, Qt::Widget)
{
	this->setWindowFlag(Qt::FramelessWindowHint, true);
}
