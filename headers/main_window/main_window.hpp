// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "widget.hpp"


namespace N_MainWindow
{
using N_Widget::Widget;


class MainWindow : public Widget
{
public:
	explicit MainWindow(QWidget *parent = nullptr);
};
}  // namespace N_MainWindow

#endif  // MAIN_WINDOW_HPP
