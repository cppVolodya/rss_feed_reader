// Copyright [2023] <Volodymyr Dorozhovets>"

#include "central_part_of_widget.hpp"


namespace N_Widget
{
CentralPartOfWidget::CentralPartOfWidget(QWidget *parent)
	: QWidget(parent)
{
	this->setWindowFlag(Qt::Window, 			 true);
	this->setWindowFlag(Qt::FramelessWindowHint, true);
}
}  // namespace N_Widget
