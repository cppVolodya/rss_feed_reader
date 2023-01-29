// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef PAINTER_OF_SAVE_AND_RESTORE_HPP
#define PAINTER_OF_SAVE_AND_RESTORE_HPP

#include <QPainter>


namespace N_PainterOfRoundedBorderOfWidget
{
class PainterOfSaveAndRestore final
{
public:
	explicit inline PainterOfSaveAndRestore(QPainter &);

#pragma region RuleOfZero
	PainterOfSaveAndRestore(const PainterOfSaveAndRestore &) = delete;
	PainterOfSaveAndRestore(PainterOfSaveAndRestore &&)		 = delete;

	PainterOfSaveAndRestore& operator=(const PainterOfSaveAndRestore &) = delete;
	PainterOfSaveAndRestore& operator=(PainterOfSaveAndRestore &&)		= delete;

	inline ~PainterOfSaveAndRestore();
#pragma endregion RuleOfZero
private:
	QPainter &m_painter;
};

inline PainterOfSaveAndRestore::PainterOfSaveAndRestore(QPainter &painter)
	: m_painter(painter)
{
	m_painter.save();
}

inline PainterOfSaveAndRestore::~PainterOfSaveAndRestore()
{
	m_painter.restore();
}
}  // namespace N_PainterOfRoundedBorderOfWidget

#endif  // PAINTER_OF_SAVE_AND_RESTORE_HPP
