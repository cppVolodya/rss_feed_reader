// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef WIDGET_HPP
#define WIDGET_HPP

/*
 * The class called Widget represents a window that will be stacked from two windows.
 * The first window will be responsible for the frame, and the second window will be the central part.
 * My task is to get a window at the exit that will have a rounded border and a central part with an acrylic or blur effect. Why such difficulty?.
 * The reason is that on Windows 10 I was able to make a rounded window through the WinAPI or
 * through QPainter (that is, remove the system border and through a method called paintEvent using QPainter: draw a frame),
 * but if I then make an acrylic or blur effect for it (that is, for a window with a ready-made rounded border) of this window,
 * square (ordinary or system) borders remained in the corners.
 * That is, the problem is to use a rounded window together with an acrylic or blur effect, which is why I decided to use two windows to solve the problem.
*/

#include "central_part_of_widget.hpp"
#include "rounded_border_of_widget.hpp"


class Widget : public CentralPartOfWidget
{
public:
	explicit Widget(QWidget *parent = nullptr);
private:
	RoundedBorderOfWidget *m_rounded_border_of_widget;  // NOLINT(pvs-studio-V122)
};

#endif  // WIDGET_HPP
