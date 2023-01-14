#include "rounded_border_of_window.h"
#include "layout_of_external_rounded_border_of_widget.h"


#pragma region DefaultCharacteristic [members]
const QSizeF  						    RoundedBorderOfWindow::C_S_DEFAULT_SIZE	    { 500.0, 500.0 	      };
const QColor  						    RoundedBorderOfWindow::C_S_DEFAULT_COLOR	{ Qt::white 		  };
const RoundnessOfRoundedBorderOfWidget  RoundedBorderOfWindow::C_S_DEFAULT_ROUNDNESS{ 10.0, 10.0 		  };
const ThicknessOfRoundedBorderOfWidget  RoundedBorderOfWindow::C_S_DEFAULT_THICKNESS{ 30.0, 5.0, 5.0, 5.0 };
#pragma endregion DefaultCharacteristic [members]

RoundedBorderOfWindow::RoundedBorderOfWindow(QWidget *parent)
	: QWidget(parent, Qt::Window),
	  m_left_mouse_button_is_pressed(false)
{
	this->setAttribute (Qt::WA_TranslucentBackground, true);
	this->setWindowFlag(Qt::FramelessWindowHint,      true);

	this->setMouseTracking(true);

	this->SetDefaultSettings();
}

void RoundedBorderOfWindow::SetDefaultSettings()
{
	this->m_painter_of_rounded_border.SetLayout(new LayoutOfExternalRoundedBorderOfWidget());

	this->resize					(C_S_DEFAULT_SIZE.toSize()		     );
	this->SetColor					(C_S_DEFAULT_COLOR				     );
	this->SetRoundness				(C_S_DEFAULT_ROUNDNESS			     );
	this->SetThickness			    (C_S_DEFAULT_THICKNESS			     );
	this->SetDisplacementCoefficient(C_S_DEFAULT_DISPLACEMENT_COEFFICIENT);
}

void RoundedBorderOfWindow::paintEvent(QPaintEvent *paint_event)
{
	this->DrawOfRoundedBorder();

	this->CustomizeChangingSizeOfWidget();

	QWidget::paintEvent(paint_event);
}

#pragma region EventsOfMouse [functions]
void RoundedBorderOfWindow::mouseMoveEvent(QMouseEvent *mouse_event)
{
	this->SetNewCursorIfMousePositionLocatedOnLayoutOfSizeBorder(mouse_event->position());
	this->SetNewGeometryIfPressAndMoveMouseOnLayoutOfSizeBorder (mouse_event);

	QWidget::mouseMoveEvent(mouse_event);
}

void RoundedBorderOfWindow::mousePressEvent(QMouseEvent *mouse_event)
{
	this->SetValueIfLeftMouseButtonIsPressed(true, mouse_event);

	this->m_changing_size_of_widget.SetMousePosition(mouse_event->globalPosition());

	QWidget::mouseMoveEvent(mouse_event);
}

void RoundedBorderOfWindow::mouseReleaseEvent(QMouseEvent *mouse_event)
{
	this->SetValueIfLeftMouseButtonIsPressed(false, mouse_event);

	QWidget::mouseReleaseEvent(mouse_event);
}
#pragma endregion EventsOfMouse [functions]

void RoundedBorderOfWindow::DrawOfRoundedBorder()
{
	this->m_painter_of_rounded_border.begin(this);
	this->m_painter_of_rounded_border.Draw(this->rect().toRectF());
	this->m_painter_of_rounded_border.end();
}

inline void RoundedBorderOfWindow::CustomizeChangingSizeOfWidget()
{
	this->m_changing_size_of_widget.GetLayout().Customize(this->rect().toRectF());
}

void RoundedBorderOfWindow::SetNewCursorIfMousePositionLocatedOnLayoutOfSizeBorder(const QPointF &mouse_position)
{
	if (!this->m_left_mouse_button_is_pressed)
	{
		Qt::CursorShape new_cursor_shape = this->m_changing_size_of_widget.GetNewCursorShapeIfMousePositionLocatedOnLayoutOfSizeBorder(mouse_position);
		this->setCursor(this->m_cursors.GetCursor(new_cursor_shape));
	}
}

void RoundedBorderOfWindow::SetNewGeometryIfPressAndMoveMouseOnLayoutOfSizeBorder(QMouseEvent *mouse_event)
{
	if (this->m_left_mouse_button_is_pressed)
	{
		QRectF new_geometry = this->m_changing_size_of_widget.GetNewGeometryOfWidgetIfPressAndMoveMouseOnLayoutOfSizeBorder(mouse_event->globalPosition(), this->geometry().toRectF());
		this->setGeometry(new_geometry.toRect());
	}
}

inline void RoundedBorderOfWindow::SetValueIfLeftMouseButtonIsPressed(const bool value, QMouseEvent *mouse_event)
{
	if(mouse_event->button() == Qt::LeftButton)
	{
		this->m_left_mouse_button_is_pressed = value;
	}
}
