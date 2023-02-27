// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef CHARACTERISTICS_OF_PLACEMENT_OF_POSITIONAL_ELEMENT_HPP
#define CHARACTERISTICS_OF_PLACEMENT_OF_POSITIONAL_ELEMENT_HPP

#include <algorithm>

#include "types_aliases.hpp"


namespace N_PainterOfRoundedBorderOfWidget
{
using N_TypesAliases::T_Position;


class CharacteristicsOfPlacementOfPositionalElement
{
public:
	explicit constexpr inline CharacteristicsOfPlacementOfPositionalElement(T_Position position_of_top    = 0.0,
																			T_Position position_of_bottom = 0.0,
																			T_Position position_of_left   = 0.0,
																			T_Position position_of_right  = 0.0) noexcept;

	[[nodiscard]] constexpr inline T_Position GetPositionOfTop   () const noexcept;
	[[nodiscard]] constexpr inline T_Position GetPositionOfBottom() const noexcept;
	[[nodiscard]] constexpr inline T_Position GetPositionOfLeft  () const noexcept;
	[[nodiscard]] constexpr inline T_Position GetPositionOfRight () const noexcept;

	inline void SetPositionOfTop   (T_Position) noexcept;
	inline void SetPositionOfBottom(T_Position) noexcept;
	inline void SetPositionOfLeft  (T_Position) noexcept;
	inline void SetPositionOfRight (T_Position) noexcept;

	[[nodiscard]] constexpr inline T_Position GetMaximumValue() const;
private:
	T_Position m_position_of_top;
	T_Position m_position_of_bottom;
	T_Position m_position_of_left;
	T_Position m_position_of_right;
};

constexpr inline CharacteristicsOfPlacementOfPositionalElement::CharacteristicsOfPlacementOfPositionalElement(const T_Position position_of_top,
																											  const T_Position position_of_bottom,
																											  const T_Position position_of_left,
																											  const T_Position position_of_right) noexcept
	: m_position_of_top   (position_of_top   ),
	  m_position_of_bottom(position_of_bottom),
	  m_position_of_left  (position_of_left  ),
	  m_position_of_right (position_of_right )
{
}

constexpr inline T_Position CharacteristicsOfPlacementOfPositionalElement::GetPositionOfTop() const noexcept
{
	return this->m_position_of_top;
}

constexpr inline T_Position CharacteristicsOfPlacementOfPositionalElement::GetPositionOfBottom() const noexcept
{
	return this->m_position_of_bottom;
}

constexpr inline T_Position CharacteristicsOfPlacementOfPositionalElement::GetPositionOfLeft() const noexcept
{
	return this->m_position_of_left;
}

constexpr inline T_Position CharacteristicsOfPlacementOfPositionalElement::GetPositionOfRight() const noexcept
{
	return this->m_position_of_right;
}

inline void CharacteristicsOfPlacementOfPositionalElement::SetPositionOfTop(const T_Position position_of_top) noexcept
{
	this->m_position_of_top = position_of_top;
}

inline void CharacteristicsOfPlacementOfPositionalElement::SetPositionOfBottom(const T_Position position_of_bottom) noexcept
{
	this->m_position_of_bottom = position_of_bottom;
}

inline void CharacteristicsOfPlacementOfPositionalElement::SetPositionOfLeft(const T_Position position_of_left) noexcept
{
	this->m_position_of_left = position_of_left;
}

inline void CharacteristicsOfPlacementOfPositionalElement::SetPositionOfRight(const T_Position position_of_right) noexcept
{
	this->m_position_of_right = position_of_right;
}

[[nodiscard]] constexpr inline T_Position CharacteristicsOfPlacementOfPositionalElement::GetMaximumValue() const
{
	return std::max({ this->GetPositionOfTop(), this->GetPositionOfBottom(), this->GetPositionOfLeft(), this->GetPositionOfRight() });
}
}  // namespace N_PainterOfRoundedBorderOfWidget

#endif  // CHARACTERISTICS_OF_PLACEMENT_OF_POSITIONAL_ELEMENT_HPP
