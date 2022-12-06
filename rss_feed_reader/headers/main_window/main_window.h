#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_

#include "window_with_rounded_border_and_graphic_effect.h"


class MainWindow : public WindowWithRoundedBorderAndGraphicEffect
{
public:
	explicit MainWindow(QWidget *parent = nullptr);
};

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_
