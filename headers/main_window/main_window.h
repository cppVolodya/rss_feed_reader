// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_
#define HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_

#include "window_with_rounded_border_and_graphic_effects.h"


class MainWindow : public WindowWithRoundedBorderAndGraphicEffects
{
public:
	explicit MainWindow(QWidget *parent = nullptr);
};

#endif  // HEADERS_MAIN_WINDOW_MAIN_WINDOW_H_
