// Copyright [2023] <Volodymyr Dorozhovets>"

#include "widget.hpp"


namespace N_Widget
{
Widget::Widget(QWidget *parent)
	: CentralPartOfWidget(parent)
{
	this->m_rounded_border_of_widget = new RoundedBorderOfWidget(this);  // NOLINT(pvs-studio-V2511, clion-misra-cpp2008-18-4-1)
	this->m_rounded_border_of_widget->show();
}
}  // namespace N_Widget
