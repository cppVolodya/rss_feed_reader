// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "widget.hpp"


class MainWindow : public Widget
{
public:
	explicit MainWindow(QWidget *parent = nullptr);
};

#endif  // MAIN_WINDOW_HPP
