#include "main_window.h"


MainWindow::MainWindow(QWidget *parent)
	: WindowWithRoundedBorderAndGraphicEffect(parent)
{
	this->setWindowIcon(QIcon(":/resources/rss_feed_reader_window_icon.ico"));
}
