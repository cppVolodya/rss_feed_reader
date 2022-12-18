#include "layout_of_internal_rounded_border_of_widget.h"


void LayoutOfInternalRoundedBorderOfWidget::ReleaseSetRoundness()
{
	this->addRoundedRect(this->m_shape.GetInternalRectangle(), this->GetRoundnessOfX(), this->GetRoundnessOfY());
	this->addRect(this->m_shape.GetExternalRectangle());
}
