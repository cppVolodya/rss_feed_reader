#include "painter_of_rounded_border_of_widget.h"


PainterOfRoundedBorderOfWidget::PainterOfRoundedBorderOfWidget(PainterOfRoundedBorderOfWidget &&painter) noexcept
	: m_layout(painter.m_layout)
{
	painter.m_layout = nullptr;
}

PainterOfRoundedBorderOfWidget& PainterOfRoundedBorderOfWidget::operator=(PainterOfRoundedBorderOfWidget &&painter) noexcept
{
	if (this == &painter)
	{
		return *this;
	}

	delete this->m_layout;

	this->m_layout = painter.m_layout;
	painter.m_layout = nullptr;

	return *this;
}

void PainterOfRoundedBorderOfWidget::Draw(const QRectF &geometry_of_window)
{
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
	this->drawPath(*(this->m_layout));
}

inline void PainterOfRoundedBorderOfWidget::ReleaseSetColor()
{
	this->setBrush(this->GetColor());
}
