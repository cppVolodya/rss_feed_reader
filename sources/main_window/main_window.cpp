// Copyright [2023] <Volodymyr Dorozhovets>"

#include "main_window.hpp"


namespace N_MainWindow
{
MainWindow::MainWindow(QWidget *parent)
	: Widget(parent)
{
	this->setWindowIcon(QIcon(":/resources/window_image_of_rss_feed_reader.ico"));
}
}  // namespace N_MainWindow
