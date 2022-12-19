#include "layout_of_external_rounded_border_of_widget.h"


void LayoutOfExternalRoundedBorderOfWidget::ReleaseSetRoundness()
{
	this->addRect(this->m_shape.GetInternalRectangle());
	this->addRoundedRect(this->m_shape.GetExternalRectangle(), this->GetRoundnessOfX(), this->GetRoundnessOfY());
}
