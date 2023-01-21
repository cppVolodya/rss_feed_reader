// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef RSS_FEED_READER_HEADERS_LAYOUT_OF_EXTERNAL_AND_INTERNAL_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_LAYOUT_OF_EXTERNAL_AND_INTERNAL_ROUNDED_BORDER_OF_WIDGET_H_

#include "layout_of_rounded_border_of_widget.h"


class LayoutOfExternalAndInternalRoundedBorderOfWidget : public LayoutOfRoundedBorderOfWidget
{
public:
	~LayoutOfExternalAndInternalRoundedBorderOfWidget() override = default;
private:
	inline void ReleaseSetRoundness() final;
};

inline void LayoutOfExternalAndInternalRoundedBorderOfWidget::ReleaseSetRoundness()
{
	this->addRoundedRect(this->m_shape.GetInternalRectangle(), this->GetRoundnessOfX(), this->GetRoundnessOfY());
	this->addRoundedRect(this->m_shape.GetExternalRectangle(), this->GetRoundnessOfX(), this->GetRoundnessOfY());
}

#endif  // RSS_FEED_READER_HEADERS_LAYOUT_OF_EXTERNAL_AND_INTERNAL_ROUNDED_BORDER_OF_WIDGET_H_
