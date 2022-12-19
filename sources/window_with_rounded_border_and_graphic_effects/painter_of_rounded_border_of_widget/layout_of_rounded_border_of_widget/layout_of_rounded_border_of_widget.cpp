#include "layout_of_rounded_border_of_widget.h"


void LayoutOfRoundedBorderOfWidget::UpdateData(const QRectF &geometry_of_window) noexcept
{
	this->clear();
	this->m_shape.CustomizeGeometry(geometry_of_window);
}

void LayoutOfRoundedBorderOfWidget::AddShape() noexcept
{
	this->ReleaseSetRoundness();
}


