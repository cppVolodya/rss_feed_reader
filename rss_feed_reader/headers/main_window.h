#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_H_

#include "main_window_with_rounded_border.h"


class MainWindow : public MainWindowWithRoundedBorder
{
public:
	explicit MainWindow(QWidget *parent = nullptr);
};

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_H_
