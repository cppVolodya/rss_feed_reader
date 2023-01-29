// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP
#define LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP

#include "abstract_layout_of_rounded_border_of_widget.hpp"


namespace N_AbstractLayoutOfRoundedBorderOfWidget
{
class LayoutOfInternalRoundedBorderOfWidget : public AbstractLayoutOfRoundedBorderOfWidget
{
public:
	~LayoutOfInternalRoundedBorderOfWidget() override = default;
private:
	inline  void ReleaseSetRoundness() final;
};

inline void LayoutOfInternalRoundedBorderOfWidget::ReleaseSetRoundness()
{
	this->addRoundedRect(this->m_shape.GetInternalRectangle(),
						 this->GetRoundnessOfX(),
						 this->GetRoundnessOfY());

	this->addRect(this->m_shape.GetExternalRectangle());
}
}  // namespace N_AbstractLayoutOfRoundedBorderOfWidget

#endif  // LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_HPP
