// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef LAYOUT_OF_EXTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP
#define LAYOUT_OF_EXTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP

#include "abstract_layout_of_rounded_border_of_widget.hpp"


class LayoutOfExternalRoundedBorderOfWidget : public AbstractLayoutOfRoundedBorderOfWidget
{
public:
	~LayoutOfExternalRoundedBorderOfWidget() override = default;
private:
	inline void ReleaseSetRoundness() final;
};

inline void LayoutOfExternalRoundedBorderOfWidget::ReleaseSetRoundness()
{
	this->addRect(this->m_shape.GetInternalRectangle());
	this->addRoundedRect(this->m_shape.GetExternalRectangle(), this->GetRoundnessOfX(), this->GetRoundnessOfY());
}

#endif  // LAYOUT_OF_EXTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP
