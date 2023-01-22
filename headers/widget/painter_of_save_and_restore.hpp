// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef RSS_FEED_READER_HEADERS_PAINTER_OF_SAVE_AND_RESTORE_H
#define RSS_FEED_READER_HEADERS_PAINTER_OF_SAVE_AND_RESTORE_H

#include <QPainter>


class PainterOfSaveAndRestore final
{
public:
	explicit inline PainterOfSaveAndRestore(QPainter *);

#pragma region RuleOfZero
	PainterOfSaveAndRestore(const PainterOfSaveAndRestore &) = delete;
	PainterOfSaveAndRestore(PainterOfSaveAndRestore &&)		 = delete;

	PainterOfSaveAndRestore& operator=(const PainterOfSaveAndRestore &) = delete;
	PainterOfSaveAndRestore& operator=(PainterOfSaveAndRestore &&)		= delete;
#pragma endregion RuleOfZero

	inline ~PainterOfSaveAndRestore();
private:
	QPainter *m_painter;
};

inline PainterOfSaveAndRestore::PainterOfSaveAndRestore(QPainter *painter)
	: m_painter(painter)
{
	m_painter->save();
}

inline PainterOfSaveAndRestore::~PainterOfSaveAndRestore()
{
	m_painter->restore();
}

#endif  // RSS_FEED_READER_HEADERS_PAINTER_OF_SAVE_AND_RESTORE_H
