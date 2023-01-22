// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_
#define HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_

#include "widget.hpp"


class MainWindow : public Widget
{
public:
	explicit MainWindow(QWidget *parent = nullptr);
};

#endif  // HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_
