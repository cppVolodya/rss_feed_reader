#ifndef RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_MAIN_WINDOW_H_
#define RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_MAIN_WINDOW_H_

#include <QMainWindow>

#include "border_of_main_window.h"


class RoundedBorderOfMainWindow : public BorderOfMainWindow
{
public:
	explicit RoundedBorderOfMainWindow(QWidget *parent = nullptr);
};


#endif  // RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_MAIN_WINDOW_H_
