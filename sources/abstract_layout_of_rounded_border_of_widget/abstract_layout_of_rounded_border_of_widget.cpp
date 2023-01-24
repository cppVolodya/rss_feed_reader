// Copyright [2023] <Volodymyr Dorozhovets>"

#include "abstract_layout_of_rounded_border_of_widget.hpp"


void AbstractLayoutOfRoundedBorderOfWidget::ReleaseCustomize(const QRectF &geometry_of_window)
{
	this->UpdateData(geometry_of_window);
	this->AddShape();
}

inline void AbstractLayoutOfRoundedBorderOfWidget::UpdateData(const QRectF &geometry_of_window)
{
	this->clear();
	this->m_shape.CustomizeGeometry(geometry_of_window);
}

inline void AbstractLayoutOfRoundedBorderOfWidget::AddShape()
{
	this->ReleaseSetRoundness();
}


