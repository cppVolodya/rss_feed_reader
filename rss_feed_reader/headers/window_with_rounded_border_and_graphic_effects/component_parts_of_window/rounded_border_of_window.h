#ifndef RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_
#define RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_

#include <QWidget>

#include "painter_of_rounded_border_of_widget.h"


class RoundedBorderOfWindow : public QWidget
{
public:
	explicit RoundedBorderOfWindow(QWidget *parent = nullptr);
protected:
	void paintEvent(QPaintEvent *) override;
private:
	PainterOfRoundedBorderOfWidget m_painter_of_rounded_border;
private:
	void DrawOfRoundedBorder();
};

#endif  // RSS_FEED_READER_HEADERS_ROUNDED_BORDER_OF_WINDOW_H_
