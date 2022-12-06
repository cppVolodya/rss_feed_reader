#ifndef RSS_FEED_READER_HEADERS_MAIN_WINDOW_PAINTER_OF_ROUNDED_BORDER_H_
#define RSS_FEED_READER_HEADERS_MAIN_WINDOW_PAINTER_OF_ROUNDED_BORDER_H_

#include <QPainter>
#include <QPaintDevice>
#include <QPainterPath>

#include "characteristic_of_rounded_border_of_window.h"


class PainterOfRoundedBorder : public QPainter
{
public:
	explicit PainterOfRoundedBorder(QPaintDevice *parent = nullptr,
									const QRect &geometry_of_window = QRect(),
									const CharacteristicOfRoundedBorderOfWindow &characteristic = CharacteristicOfRoundedBorderOfWindow());

	void Draw();

	[[nodiscard]] inline RoundnessOfRoundedBorderOfWindow GetRoundness() const;
	[[nodiscard]] inline ThicknessOfRoundedBorderOfWindow GetThickness() const;
	[[nodiscard]] inline QColor 						  GetColor    () const;
protected:
	class Border
	{
	public:
		QRect m_external_rectangle;
		QRect m_internal_rectangle;
	};
protected:
	const CharacteristicOfRoundedBorderOfWindow &m_characteristic;
	const QRect 								&m_geometry_of_window;

	QPainterPath layout;
	Border 		 border;
private:
	void CustomizeLayout();
	inline void DrawAccordingToLayout();

	void CustomizeBorder();

	void         SetThicknessOfBorderOnLayout(const ThicknessOfRoundedBorderOfWindow &);
	virtual void SetRoundnessOfBorderOnLayout(const RoundnessOfRoundedBorderOfWindow &) = 0;
	inline  void SetColorOfBorderOnLayout    (const QColor 								 &);

	inline void SetThicknessOfTopBorderOnLayout   (qint32);
	inline void SetThicknessOfBottomBorderOnLayout(qint32);
	inline void SetThicknessOfLeftBorderOnLayout  (qint32);
	inline void SetThicknessOfRightBorderOnLayout (qint32);
};

inline RoundnessOfRoundedBorderOfWindow PainterOfRoundedBorder::GetRoundness() const
{
	return this->m_characteristic.GetRoundness();
}

inline ThicknessOfRoundedBorderOfWindow PainterOfRoundedBorder::GetThickness() const
{
	return this->m_characteristic.GetThickness();
}

inline QColor PainterOfRoundedBorder::GetColor() const
{
	return this->m_characteristic.GetColor();
}

#endif  // RSS_FEED_READER_HEADERS_MAIN_WINDOW_PAINTER_OF_ROUNDED_BORDER_H_
