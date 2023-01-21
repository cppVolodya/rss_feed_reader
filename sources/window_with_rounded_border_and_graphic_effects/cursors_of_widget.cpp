// Copyright [2023] <Volodymyr Dorozhovets>"

#include <qdebug.h>

#include "cursors_of_widget.h"


CursorsOfWidget::CursorsOfWidget(bool system_cursor_is_selected) noexcept
	: m_system_cursors_is_selected(system_cursor_is_selected)
{
	this->SetDefaultSettings();
}

void CursorsOfWidget::SetDefaultOfImagesOfCursors() noexcept
{
	this->m_current_cursor_image_of_arrow				= ":/resources/cursor_image_of_arrow.png";
	this->m_current_cursor_image_of_size_all			= ":/resources/cursor_image_of_size_all.png";
	this->m_current_cursor_image_of_size_horizontal	    = ":/resources/cursor_image_of_size_horizontal.png";
	this->m_current_cursor_image_of_size_vertical		= ":/resources/cursor_image_of_size_vertical.png";
	this->m_current_cursor_image_of_size_right_diagonal = ":/resources/cursor_image_of_size_right_diagonal.png";
	this->m_current_cursor_image_of_size_left_diagonal  = ":/resources/cursor_image_of_size_left_diagonal.png";
}

void CursorsOfWidget::SetDefaultOfHotSpotsOfCursors() noexcept
{
	this->m_current_hot_spot_of_cursor_of_arrow 			  = QPoint( 5,  2 );
	this->m_current_hot_spot_of_cursor_of_size_all 			  = QPoint(-1, -1 );
	this->m_current_hot_spot_of_cursor_of_size_horizontal 	  = QPoint(-1, -1 );
	this->m_current_hot_spot_of_cursor_of_size_vertical 	  = QPoint(-1, -1 );
	this->m_current_hot_spot_of_cursor_of_size_right_diagonal = QPoint(-1, -1 );
	this->m_current_hot_spot_of_cursor_of_size_left_diagonal  = QPoint(-1, -1 );
}

void CursorsOfWidget::SelectSystemCursors(const bool system_cursor_is_selected) noexcept
{
	this->m_system_cursors_is_selected = system_cursor_is_selected;
}

[[nodiscard]] QCursor CursorsOfWidget::ReleaseGetCursor(const Qt::CursorShape cursor_shape) const noexcept
{
	switch (cursor_shape)
	{
	case Qt::CursorShape::ArrowCursor:
		return this->GetCursorOfArrow();
	case Qt::CursorShape::SizeAllCursor:
		return this->GetCursorOfSizeAll();
	case Qt::CursorShape::SizeVerCursor:
		return this->GetCursorOfSizeVertical();
	case Qt::CursorShape::SizeHorCursor:
		return this->GetCursorOfSizeHorizontal();
	case Qt::CursorShape::SizeBDiagCursor:
		return this->GetCursorOfSizeRightDiagonal();
	case Qt::CursorShape::SizeFDiagCursor:
		return this->GetCursorOfSizeLeftDiagonal();
	default:
		qDebug() << "A different cursor shape is selected!";
		return { Qt::ArrowCursor };
	}
}

[[nodiscard]] QCursor CursorsOfWidget::ReleaseGetCursorOfArrow() const noexcept
{
	if (this->SystemCursorsIsSelected())
	{
		return CursorsOfWidget::ReleaseGetSystemCursorOfArrow();
	}

	return this->ReleaseGetCustomCursorOfArrow();
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfArrow() const noexcept
{
	QCursor cursor_of_arrow(this->m_current_cursor_image_of_arrow,
							this->m_current_hot_spot_of_cursor_of_arrow.x(),
							this->m_current_hot_spot_of_cursor_of_arrow.y());

	return cursor_of_arrow;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetSystemCursorOfArrow() noexcept
{
	QCursor cursor_of_arrow(Qt::ArrowCursor);

	return cursor_of_arrow;
}

[[nodiscard]] QCursor CursorsOfWidget::ReleaseGetCursorOfSizeAll() const noexcept
{
	if (this->SystemCursorsIsSelected())
	{
		return ReleaseGetSystemCursorOfSizeAll();
	}

	return ReleaseGetCustomCursorOfSizeAll();
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeAll() const noexcept
{
	QCursor cursor_of_size_all(this->m_current_cursor_image_of_size_all,
							   this->m_current_hot_spot_of_cursor_of_size_all.x(),
							   this->m_current_hot_spot_of_cursor_of_size_all.y());

	return cursor_of_size_all;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetSystemCursorOfSizeAll() noexcept
{
	QCursor cursor_of_arrow(Qt::SizeAllCursor);

	return cursor_of_arrow;
}

[[nodiscard]] QCursor CursorsOfWidget::ReleaseGetCursorOfSizeHorizontal() const noexcept
{
	if (this->SystemCursorsIsSelected())
	{
		return CursorsOfWidget::ReleaseGetSystemCursorOfSizeHorizontal();
	}

	return this->ReleaseGetCustomCursorOfSizeHorizontal();
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeHorizontal() const noexcept
{
	QCursor cursor_of_size_horizontal(this->m_current_cursor_image_of_size_horizontal,
									  this->m_current_hot_spot_of_cursor_of_size_horizontal.x(),
									  this->m_current_hot_spot_of_cursor_of_size_horizontal.y());

	return cursor_of_size_horizontal;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetSystemCursorOfSizeHorizontal() noexcept
{
	QCursor cursor_of_arrow(Qt::SizeHorCursor);

	return cursor_of_arrow;
}

[[nodiscard]] QCursor CursorsOfWidget::ReleaseGetCursorOfSizeVertical() const noexcept
{
	if (this->SystemCursorsIsSelected())
	{
		return CursorsOfWidget::ReleaseGetSystemCursorOfSizeVertical();
	}

	return this->ReleaseGetCustomCursorOfSizeVertical();
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeVertical() const noexcept
{
	QCursor cursor_of_size_vertical(this->m_current_cursor_image_of_size_vertical,
									this->m_current_hot_spot_of_cursor_of_size_vertical.x(),
									this->m_current_hot_spot_of_cursor_of_size_vertical.y());

	return cursor_of_size_vertical;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetSystemCursorOfSizeVertical() noexcept
{
	QCursor cursor_of_arrow(Qt::SizeVerCursor);
	return cursor_of_arrow;
}

[[nodiscard]] QCursor CursorsOfWidget::ReleaseGetCursorOfSizeRightDiagonal() const noexcept
{
	if (this->SystemCursorsIsSelected())
	{
		return CursorsOfWidget::ReleaseGetSystemCursorOfSizeRightDiagonal();
	}

	return this->ReleaseGetCustomCursorOfSizeRightDiagonal();
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeRightDiagonal() const noexcept
{
	QCursor cursor_of_size_right_diagonal(this->m_current_cursor_image_of_size_right_diagonal,
										  this->m_current_hot_spot_of_cursor_of_size_right_diagonal.x(),
										  this->m_current_hot_spot_of_cursor_of_size_right_diagonal.y());

	return cursor_of_size_right_diagonal;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetSystemCursorOfSizeRightDiagonal() noexcept
{
	QCursor cursor_of_arrow(Qt::SizeBDiagCursor);
	return cursor_of_arrow;
}

[[nodiscard]] QCursor CursorsOfWidget::ReleaseGetCursorOfSizeLeftDiagonal () const noexcept
{
	if (this->SystemCursorsIsSelected())
	{
		return CursorsOfWidget::ReleaseGetSystemCursorOfSizeLeftDiagonal();
	}

	return this->ReleaseGetCustomCursorOfSizeLeftDiagonal();
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeLeftDiagonal() const noexcept
{
	QCursor cursor_image_of_left_diagonal(this->m_current_cursor_image_of_size_left_diagonal,
										  this->m_current_hot_spot_of_cursor_of_size_left_diagonal.x(),
										  this->m_current_hot_spot_of_cursor_of_size_left_diagonal.y());

	return cursor_image_of_left_diagonal;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetSystemCursorOfSizeLeftDiagonal() noexcept
{
	QCursor cursor_of_arrow(Qt::SizeFDiagCursor);

	return cursor_of_arrow;
}
