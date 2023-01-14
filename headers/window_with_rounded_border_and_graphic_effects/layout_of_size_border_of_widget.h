#ifndef RSS_FEED_READER_HEADERS_LAYOUT_OF_SIZE_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_LAYOUT_OF_SIZE_BORDER_OF_WIDGET_H_

#include "layout_of_rounded_border_of_widget.h"


class LayoutOfSizeBorderOfWidget : public LayoutOfRoundedBorderOfWidget
{
public:
	~LayoutOfSizeBorderOfWidget() override = default;
private:
	inline void ReleaseSetRoundness() final;
};

inline void LayoutOfSizeBorderOfWidget::ReleaseSetRoundness()
{
	this->addRoundedRect(this->m_shape.GetInternalRectangle(), this->GetRoundnessOfX(), this->GetRoundnessOfY());
	this->addRoundedRect(this->m_shape.GetExternalRectangle(), this->GetRoundnessOfX(), this->GetRoundnessOfY());
}

#endif  // RSS_FEED_READER_HEADERS_LAYOUT_OF_SIZE_BORDER_OF_WIDGET_H_
