#include "painter_of_rounded_border_of_widget.h"


void PainterOfRoundedBorderOfWidget::Draw(const QRectF &geometry_of_window)
{
	this->m_color = Qt::white;  // TEST

	this->Customize();
	this->m_layout->Customize(geometry_of_window);
	this->DrawAccordingToLayout();
}

inline void PainterOfRoundedBorderOfWidget::Customize()
{
	this->setRenderHint(QPainter::Antialiasing);
	this->setPen(Qt::transparent);
}

inline void PainterOfRoundedBorderOfWidget::DrawAccordingToLayout()
{
	this->ReleaseSetColor();
	this->drawPath(*this->m_layout);
}

inline void PainterOfRoundedBorderOfWidget::ReleaseSetColor()
{
	this->setBrush(this->GetColor());
}
