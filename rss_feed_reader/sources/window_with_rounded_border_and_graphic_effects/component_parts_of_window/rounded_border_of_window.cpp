#include "rounded_border_of_window.h"
#include "layout_of_external_rounded_border_of_widget.h"


RoundedBorderOfWindow::RoundedBorderOfWindow(QWidget *parent)
	: QWidget(parent, Qt::Window)
{
	this->setAttribute (Qt::WA_TranslucentBackground, true);
	this->setWindowFlag(Qt::FramelessWindowHint,      true);
	this->setMouseTracking(true);

	m_painter_of_rounded_border.SetLayout(new LayoutOfExternalRoundedBorderOfWidget);

	this->setFixedSize(700, 700);  // TEST
}

void RoundedBorderOfWindow::paintEvent(QPaintEvent *paint_event)
{
	this->DrawOfRoundedBorder();

	QWidget::paintEvent(paint_event);
}

void RoundedBorderOfWindow::DrawOfRoundedBorder()
{
	this->m_painter_of_rounded_border.begin(this);
	this->m_painter_of_rounded_border.Draw(this->rect().toRectF());
	this->m_painter_of_rounded_border.end();
}
