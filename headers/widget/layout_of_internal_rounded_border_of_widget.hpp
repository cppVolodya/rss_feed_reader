// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP
#define LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP

#include "layout_of_rounded_border_of_widget.hpp"


class LayoutOfInternalRoundedBorderOfWidget : public LayoutOfRoundedBorderOfWidget
{
public:
	~LayoutOfInternalRoundedBorderOfWidget() override = default;
private:
	inline  void ReleaseSetRoundness() final;
};

inline void LayoutOfInternalRoundedBorderOfWidget::ReleaseSetRoundness()
{
	this->addRoundedRect(this->m_shape.GetInternalRectangle(), this->GetRoundnessOfX(), this->GetRoundnessOfY());
	this->addRect(this->m_shape.GetExternalRectangle());
}

#endif  // LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP
