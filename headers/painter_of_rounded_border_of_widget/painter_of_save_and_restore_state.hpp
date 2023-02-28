// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef PAINTER_OF_SAVE_AND_RESTORE_STATE_HPP
#define PAINTER_OF_SAVE_AND_RESTORE_STATE_HPP

#include <QPainter>


namespace N_PainterOfRoundedBorderOfWidget
{
class PainterOfSaveAndRestoreState final
{
public:
	explicit inline PainterOfSaveAndRestoreState(QPainter &);

#pragma region RuleOfZero
	PainterOfSaveAndRestoreState(const PainterOfSaveAndRestoreState &) = delete;
	PainterOfSaveAndRestoreState(PainterOfSaveAndRestoreState &&)	   = delete;

	PainterOfSaveAndRestoreState& operator=(const PainterOfSaveAndRestoreState &) = delete;
	PainterOfSaveAndRestoreState& operator=(PainterOfSaveAndRestoreState &&)	  = delete;

	inline ~PainterOfSaveAndRestoreState();
#pragma endregion RuleOfZero
private:
	QPainter &m_painter;
};

inline PainterOfSaveAndRestoreState::PainterOfSaveAndRestoreState(QPainter &painter)
	: m_painter(painter)
{
	this->m_painter.save();
}

inline PainterOfSaveAndRestoreState::~PainterOfSaveAndRestoreState()
{
	this->m_painter.restore();
}
}  // namespace N_PainterOfRoundedBorderOfWidget

#endif  // PAINTER_OF_SAVE_AND_RESTORE_STATE_HPP
