#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_PAINTER_OF_INTERNAL_ROUNDED_BORDER_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_PAINTER_OF_INTERNAL_ROUNDED_BORDER_H_

#include "painter_of_rounded_border.h"


class PainterOfInternalRoundedBorder : public PainterOfRoundedBorder
{
public:
	explicit PainterOfInternalRoundedBorder(QPaintDevice *parent = nullptr,
										    const QRect &geometry_of_window = QRect(),
										    const CharacteristicOfRoundedBorderOfWindow &characteristic = CharacteristicOfRoundedBorderOfWindow());
private:
	void SetRoundnessOfBorderOnLayout(const RoundnessOfRoundedBorderOfWindow &) override;
};

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_PAINTER_OF_INTERNAL_ROUNDED_BORDER_H_
