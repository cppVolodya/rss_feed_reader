// Copyright [2023] <Volodymyr Dorozhovets>"

#include "widget.h"


Widget::Widget(QWidget *parent)
	: CentralPartOfWidget(parent)
{
	this->m_rounded_border_of_widget = new RoundedBorderOfWidget(this);
	this->m_rounded_border_of_widget->show();
}
