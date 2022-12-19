#ifndef RSS_FEED_READER_HEADERS_LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_H_

#include "layout_of_rounded_border_of_widget.h"


class LayoutOfInternalRoundedBorderOfWidget : public LayoutOfRoundedBorderOfWidget
{
public:
	~LayoutOfInternalRoundedBorderOfWidget() override = default;
private:
	void ReleaseSetRoundness() override;
};

#endif  // RSS_FEED_READER_HEADERS_LAYOUT_OF_INTERNAL_ROUNDED_BORDER_OF_WIDGET_H_
