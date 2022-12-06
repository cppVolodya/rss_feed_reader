#include "rounded_border_of_window.h"
#include "painter_of_external_rounded_border.h"


RoundedBorderOfWindow::RoundedBorderOfWindow(QWidget *parent)
	: QWidget(parent, Qt::Window)
{
	this->setAttribute (Qt::WA_TranslucentBackground, true);
	this->setWindowFlag(Qt::FramelessWindowHint,      true);
	this->setMouseTracking(true);

	this->setFixedSize(500, 500);  // TEST

	m_characteristic = CharacteristicOfRoundedBorderOfWindow(RoundnessOfRoundedBorderOfWindow(10, 10),
															 ThicknessOfRoundedBorderOfWindow(30, 5, 5, 5),
															 QColor(Qt::white));  // TEST
}

void RoundedBorderOfWindow::paintEvent(QPaintEvent *paint_event)
{
	PainterOfExternalRoundedBorder painter_of_rounded_border(this, this->rect(), m_characteristic);
	painter_of_rounded_border.Draw();

	QWidget::paintEvent(paint_event);
}
