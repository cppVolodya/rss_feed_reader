#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_WITH_ROUNDED_BORDER_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_WITH_ROUNDED_BORDER_H_

#include <QMainWindow>

#include "main_window_is_borderless.h"
#include "rounded_border_for_main_window.h"


class MainWindowWithRoundedBorder : public QMainWindow
{
private:
	MainWindowIsBorderless     *central_widget;
	RoundedBorderForMainWindow *rounded_bord;

public:
	explicit MainWindowWithRoundedBorder(QWidget *);
};

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_WITH_ROUNDED_BORDER_H_
