#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_ROUNDED_BORDER_OF_WINDOW_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_ROUNDED_BORDER_OF_WINDOW_H_

#include <QWidget>

#include "characteristic_of_rounded_border_of_window.h"


class RoundedBorderOfWindow : public QWidget
{
public:
	explicit RoundedBorderOfWindow(QWidget *parent = nullptr);
protected:
	void paintEvent (QPaintEvent *) override;
private:
	CharacteristicOfRoundedBorderOfWindow m_characteristic;
};

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_ROUNDED_BORDER_OF_WINDOW_H_
