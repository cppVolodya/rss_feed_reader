#ifndef RSS_FEED_READER_HEADERS_PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_H_

#include <QPainter>
#include <QPaintDevice>

#include "layout_of_rounded_border_of_widget.h"


class PainterOfRoundedBorderOfWidget : public QPainter
{
public:
	explicit inline PainterOfRoundedBorderOfWidget(LayoutOfRoundedBorderOfWidget *layout = nullptr) noexcept;
	inline ~PainterOfRoundedBorderOfWidget() noexcept;

	void Draw(const QRectF &);

	[[nodiscard]] constexpr inline QColor GetColor() const noexcept;

	inline void SetLayout(LayoutOfRoundedBorderOfWidget *) noexcept;
private:
	LayoutOfRoundedBorderOfWidget* m_layout;

	QColor m_color;
private:
	inline void Customize();

	inline void DrawAccordingToLayout();

	inline void ReleaseSetColor();
};

inline PainterOfRoundedBorderOfWidget::PainterOfRoundedBorderOfWidget(LayoutOfRoundedBorderOfWidget *layout) noexcept
	: 	  m_layout(layout)
{
}

inline PainterOfRoundedBorderOfWidget::~PainterOfRoundedBorderOfWidget() noexcept
{
	delete m_layout;
}

constexpr inline QColor PainterOfRoundedBorderOfWidget::GetColor() const noexcept
{
	return this->m_color;
}

inline void PainterOfRoundedBorderOfWidget::SetLayout(LayoutOfRoundedBorderOfWidget *layout) noexcept
{
	this->m_layout = layout;
}

#endif  // RSS_FEED_READER_HEADERS_PAINTER_OF_ROUNDED_BORDER_OF_WIDGET_H_
