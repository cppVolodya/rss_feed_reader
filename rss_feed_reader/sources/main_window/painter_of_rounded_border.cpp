#include "painter_of_rounded_border.h"


PainterOfRoundedBorder::PainterOfRoundedBorder(QPaintDevice *parent,
											   const QRect 								   &geometry_of_window,
											   const CharacteristicOfRoundedBorderOfWindow &characteristic)
	: QPainter(parent),
	  m_geometry_of_window(geometry_of_window),
	  m_characteristic    (characteristic    )
{
	this->setRenderHint(QPainter::Antialiasing);
	this->setPen(Qt::transparent);

	this->layout.setFillRule(Qt::OddEvenFill);
}

void PainterOfRoundedBorder::Draw()
{
	this->layout.clear();
	this->CustomizeLayout();
	this->DrawAccordingToLayout();
}

void PainterOfRoundedBorder::CustomizeLayout()
{
	this->CustomizeBorder();

	this->SetThicknessOfBorderOnLayout(this->GetThickness());
	this->SetRoundnessOfBorderOnLayout(this->GetRoundness());
	this->SetColorOfBorderOnLayout    (this->GetColor    ());
}

inline void PainterOfRoundedBorder::DrawAccordingToLayout()
{
	this->drawPath(layout);
}

void PainterOfRoundedBorder::CustomizeBorder()
{
	this->border.m_external_rectangle = m_geometry_of_window;
	this->border.m_internal_rectangle = m_geometry_of_window;
}

void PainterOfRoundedBorder::SetThicknessOfBorderOnLayout(const ThicknessOfRoundedBorderOfWindow &thickness)
{
	this->SetThicknessOfTopBorderOnLayout   (thickness.GetThicknessOfTop   ());
	this->SetThicknessOfBottomBorderOnLayout(thickness.GetThicknessOfBottom());
	this->SetThicknessOfLeftBorderOnLayout  (thickness.GetThicknessOfLeft  ());
	this->SetThicknessOfRightBorderOnLayout (thickness.GetThicknessOfRight ());
}

inline void PainterOfRoundedBorder::SetThicknessOfTopBorderOnLayout(const qint32 thickness_of_top)
{
	this->border.m_internal_rectangle.setY(this->border.m_internal_rectangle.y() + thickness_of_top);
}

inline void PainterOfRoundedBorder::SetThicknessOfBottomBorderOnLayout(const qint32 thickness_of_bottom)
{
	this->border.m_internal_rectangle.setHeight(this->border.m_internal_rectangle.height() - thickness_of_bottom);
}

inline void PainterOfRoundedBorder::SetThicknessOfLeftBorderOnLayout(const qint32 thickness_of_left)
{
	this->border.m_internal_rectangle.setX(this->border.m_internal_rectangle.x() + thickness_of_left);
}

inline void PainterOfRoundedBorder::SetThicknessOfRightBorderOnLayout(const qint32 thickness_of_right)
{
	this->border.m_internal_rectangle.setWidth (this->border.m_internal_rectangle.width() - thickness_of_right);
}

inline void PainterOfRoundedBorder::SetColorOfBorderOnLayout(const QColor &color)
{
	this->setBrush(color);
}
