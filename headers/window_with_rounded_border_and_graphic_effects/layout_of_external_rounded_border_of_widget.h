#ifndef RSS_FEED_READER_HEADERS_LAYOUT_OF_ETERNAL_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_LAYOUT_OF_ETERNAL_ROUNDED_BORDER_OF_WIDGET_H_

#include "layout_of_rounded_border_of_widget.h"


class LayoutOfExternalRoundedBorderOfWidget : public LayoutOfRoundedBorderOfWidget
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

#endif  // RSS_FEED_READER_HEADERS_LAYOUT_OF_ETERNAL_ROUNDED_BORDER_OF_WIDGET_H_
