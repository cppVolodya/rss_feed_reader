// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef TYPES_ALIASES_HPP
#define TYPES_ALIASES_HPP

#include <QtGlobal>

namespace N_PainterOfRoundedBorderOfWidget
{
class CharacteristicOfPlacementOfPositionalElement;
}

namespace N_TypesAliases
{
using N_PainterOfRoundedBorderOfWidget::CharacteristicOfPlacementOfPositionalElement;


using T_Success  = bool;
using T_Selected = bool;
using T_Pressed  = bool;

using T_BlurRadius = qreal;
using T_Position   = qreal;
using T_Roundness  = qreal;
using T_Distance   = qreal;

using T_Thickness = T_Position;

using T_ThicknessOfRoundedBorderOfWidget = CharacteristicOfPlacementOfPositionalElement;
}  // namespace N_TypesAliases

#endif  // TYPES_ALIASES_HPP
