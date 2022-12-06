#include "painter_of_internal_rounded_border.h"


PainterOfInternalRoundedBorder::PainterOfInternalRoundedBorder(QPaintDevice *parent,
															   const QRect &geometry_of_window,
															   const CharacteristicOfRoundedBorderOfWindow &characteristic)
	: PainterOfRoundedBorder(parent, geometry_of_window, characteristic)
{
}

void PainterOfInternalRoundedBorder::SetRoundnessOfBorderOnLayout(const RoundnessOfRoundedBorderOfWindow &roundness)
{
	this->layout.addRect(this->border.m_external_rectangle);
	this->layout.addRoundedRect(this->border.m_internal_rectangle, roundness.GetRoundnessOfX(), roundness.GetRoundnessOfY());
}
