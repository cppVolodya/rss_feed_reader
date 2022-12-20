#include "main_window.h"


MainWindow::MainWindow(QWidget *parent)
	: WindowWithRoundedBorderAndGraphicEffects(parent)
{
	this->setWindowIcon(QIcon(":/resources/window_icon_of_rss_feed_reader.ico"));
}
