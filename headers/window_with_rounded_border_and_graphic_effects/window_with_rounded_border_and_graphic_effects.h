#ifndef RSS_FEED_READER_HEADERS_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS_H_
#define RSS_FEED_READER_HEADERS_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS_H_

/*
 * The class called WindowWithRoundedBorderAndGraphicEffects represents a window that will be stacked from two windows.
 * The first window will be responsible for the frame, and the second window will be the central part.
 * My task is to get a window at the exit that will have a rounded border and a central part with an acrylic or blur effect. Why such difficulty?.
 * The reason is that on Windows 10 I was able to make a rounded window through the WinAPI or
 * through QPainter (that is, remove the system border and through a method called paintEvent using QPainter: draw a frame),
 * but if I then make an acrylic or blur effect for it (that is, for a window with a ready-made rounded border) of this window,
 * square (ordinary or system) borders remained in the corners.
 * That is, the problem is to use a rounded window together with an acrylic or blur effect, which is why I decided to use two windows to solve the problem.
*/

#include "central_part_of_window_with_graphic_effects.h"
#include "rounded_border_of_window.h"


class WindowWithRoundedBorderAndGraphicEffects : public CentralPartOfWindowWithGraphicEffects
{
public:
	explicit WindowWithRoundedBorderAndGraphicEffects(QWidget *parent = nullptr);
private:
	RoundedBorderOfWindow *m_rounded_border_of_window;
};

#endif  // RSS_FEED_READER_HEADERS_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS_H_
