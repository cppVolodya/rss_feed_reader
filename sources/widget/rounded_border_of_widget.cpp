// Copyright [2023] <Volodymyr Dorozhovets>"

#include <QMessageBox>
#include <QApplication>

#include "rounded_border_of_widget.hpp"
#include "layout_of_external_rounded_border_of_widget.hpp"


namespace N_Widget
{
using N_PainterOfRoundedBorderOfWidget::TypeLayoutOfRoundedBorderOfWidget;


RoundedBorderOfWidget::RoundedBorderOfWidget(CursorsOfWidget &cursors, QWidget *parent)
	: m_cursors(cursors),
	  QWidget(parent),
	  m_left_mouse_button_is_pressed(false)
{
	this->SetDefaultSettings();
	this->SetDefaultCharacteristics();
}

void RoundedBorderOfWidget::SetDefaultSettings()
{
	this->setAttribute (Qt::WA_TranslucentBackground, true);

	this->setWindowFlag(Qt::Window, 			 true);
	this->setWindowFlag(Qt::FramelessWindowHint, true);

	this->setMouseTracking(true);
}

void RoundedBorderOfWidget::SetDefaultCharacteristics()
{
	this->m_painter_of_rounded_border.SetTypeOfLayout(TypeLayoutOfRoundedBorderOfWidget::EXTERNAL);

	this->resize(500, 500);

	this->SetColor(Qt::white);

	this->SetRoundness(RoundnessOfRoundedBorderOfWidget(10.0, 10.0));

	this->SetThickness(T_ThicknessOfRoundedBorderOfWidget(5.0, 5.0, 5.0, 5.0));

	this->SetBoundingThickness(T_ThicknessOfRoundedBorderOfWidget(8.0, 8.0, 8.0, 8.0));
};

void RoundedBorderOfWidget::paintEvent(QPaintEvent *paint_event)
{
	this->DrawOfRoundedBorder();

	this->m_changing_cursor_and_size_of_widget.CustomizeLayoutOfSizeBorder(this->rect().toRectF());

	QWidget::paintEvent(paint_event);
}

void RoundedBorderOfWidget::mouseMoveEvent(QMouseEvent *mouse_event)
{
	this->SetNewCursorIfMousePositionLocatedOnLayoutOfSizeBorder(mouse_event->position());
	this->SetNewGeometryIfPressAndMoveMouseOnLayoutOfSizeBorder (mouse_event);

	QWidget::mouseMoveEvent(mouse_event);
}

void RoundedBorderOfWidget::mousePressEvent(QMouseEvent *mouse_event)
{
	this->SetValueIfLeftMouseButtonIsPressed(true, mouse_event);

	this->m_changing_cursor_and_size_of_widget.SetMousePosition(mouse_event->globalPosition());

	QWidget::mouseMoveEvent(mouse_event);
}

void RoundedBorderOfWidget::mouseReleaseEvent(QMouseEvent *mouse_event)
{
	this->SetValueIfLeftMouseButtonIsPressed(false, mouse_event);

	QWidget::mouseReleaseEvent(mouse_event);
}

void RoundedBorderOfWidget::DrawOfRoundedBorder()
{
	QMessageBox::StandardButton button_pressed;

	if(!this->m_painter_of_rounded_border.begin(this))
	{
		qDebug() << "Error starting to draw a rounded border!";
		button_pressed = QMessageBox::critical(this, "Rss Feed Reader",
												     "Error starting to draw a rounded border!",
												     QMessageBox::Ok);
	}

	this->m_painter_of_rounded_border.Draw(this->rect().toRectF());

	if(!this->m_painter_of_rounded_border.end())
	{
		qDebug() << "Error completing drawing rounded border!";
		button_pressed = QMessageBox::critical(this, "Rss Feed Reader",
													 "Error completing drawing rounded border!",
													 QMessageBox::Ok);
	}

	if(button_pressed == QMessageBox::Ok)
	{
		QApplication::exit(EXIT_FAILURE);
	}
}

void RoundedBorderOfWidget::SetNewCursorIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &mouse_position)
{
	if (!this->m_left_mouse_button_is_pressed)
	{
		CursorShape new_cursor_shape =
			this->m_changing_cursor_and_size_of_widget.GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(mouse_position);

		this->setCursor(this->m_cursors.GetCursor(new_cursor_shape));
	}
}

void RoundedBorderOfWidget::SetNewGeometryIfPressAndMoveMouseOnLayoutOfSizeBorder(const QMouseEvent *mouse_event)
{
	if (this->m_left_mouse_button_is_pressed)
	{
		QRectF new_geometry =
			this->m_changing_cursor_and_size_of_widget.GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(mouse_event->globalPosition(),
																	  this->geometry().toRectF());

		this->setGeometry(new_geometry.toRect());
	}
}

inline void RoundedBorderOfWidget::SetValueIfLeftMouseButtonIsPressed(const bool value, const QMouseEvent *mouse_event)
{
	if(mouse_event->button() == Qt::LeftButton)
	{
		this->m_left_mouse_button_is_pressed = value;
	}
}
}  // namespace N_Widget
