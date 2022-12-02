#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_WITH_ROUNDED_BORDER_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_WITH_ROUNDED_BORDER_H_

#include <QMainWindow>

#include "central_part_of_main_window.h"
#include "rounded_border_of_main_window.h"


class MainWindowWithRoundedBorder : public QMainWindow
{
private:
	CentralPartOfMainWindow   *m_central_widget;
	RoundedBorderOfMainWindow *m_rounded_bord;

public:
	explicit MainWindowWithRoundedBorder(QWidget *parent = nullptr);

	void Show();  // show child windows
};

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_WITH_ROUNDED_BORDER_H_
