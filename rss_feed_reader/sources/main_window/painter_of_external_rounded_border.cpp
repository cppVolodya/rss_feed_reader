#include "painter_of_external_rounded_border.h"


PainterOfExternalRoundedBorder::PainterOfExternalRoundedBorder(QPaintDevice *parent,
															   const QRect &geometry_of_window,
															   const CharacteristicOfRoundedBorderOfWindow &characteristic)
	: PainterOfRoundedBorder(parent, geometry_of_window, characteristic)
{
}

void PainterOfExternalRoundedBorder::SetRoundnessOfBorderOnLayout(const RoundnessOfRoundedBorderOfWindow &roundness)
{
	this->layout.addRoundedRect(this->border.m_external_rectangle, roundness.GetRoundnessOfX(), roundness.GetRoundnessOfY());
	this->layout.addRect(this->border.m_internal_rectangle);
}
