// Copyright [2023] <Volodymyr Dorozhovets>"

#include <QApplication>

#include "cursors_of_widget.hpp"


namespace N_Widget
{
CursorsOfWidget::CursorsOfWidget(bool system_cursor_is_selected) noexcept
	: m_system_cursors_is_selected(system_cursor_is_selected)
{
	this->SetDefaultSettings();
}

void CursorsOfWidget::SetDefaultOfImagesOfCursors() noexcept
{
	this->m_current_pixmap_of_cursor_of_arrow				= QPixmap(":/resources/cursor_image_of_arrow.png"			   );
	this->m_current_pixmap_of_cursor_of_size_all			= QPixmap(":/resources/cursor_image_of_size_all.png"		   );
	this->m_current_pixmap_of_cursor_of_size_horizontal	    = QPixmap(":/resources/cursor_image_of_size_horizontal.png"    );
	this->m_current_pixmap_of_cursor_of_size_vertical		= QPixmap(":/resources/cursor_image_of_size_vertical.png"	   );
	this->m_current_pixmap_of_cursor_of_size_right_diagonal = QPixmap(":/resources/cursor_image_of_size_right_diagonal.png");
	this->m_current_pixmap_of_cursor_of_size_left_diagonal  = QPixmap(":/resources/cursor_image_of_size_left_diagonal.png" );
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
	QCursor cursor = Qt::CursorShape::ArrowCursor;

	switch (cursor_shape)
	{
	case Qt::CursorShape::ArrowCursor:
		cursor = this->GetCursorOfArrow();
		break;
	case Qt::CursorShape::SizeAllCursor:
		cursor = this->GetCursorOfSizeAll();
		break;
	case Qt::CursorShape::SizeVerCursor:
		cursor = this->GetCursorOfSizeVertical();
		break;
	case Qt::CursorShape::SizeHorCursor:
		cursor = this->GetCursorOfSizeHorizontal();
		break;
	case Qt::CursorShape::SizeBDiagCursor:
		cursor = this->GetCursorOfSizeRightDiagonal();
		break;
	case Qt::CursorShape::SizeFDiagCursor:
		cursor = this->GetCursorOfSizeLeftDiagonal();
		break;
	default:  // NOLINT(clion-misra-cpp2008-6-4-5)
		qDebug() << "A different cursor shape is selected!";
		QApplication::exit(EXIT_FAILURE);
		break;
	}

	return cursor;
}

[[nodiscard]] QCursor CursorsOfWidget::ReleaseGetCursorOfArrow() const noexcept
{
	QCursor cursor;

	if (this->SystemCursorsIsSelected())
	{
		cursor = CursorsOfWidget::ReleaseGetSystemCursorOfArrow();
	}
	else
	{
		cursor = this->ReleaseGetCustomCursorOfArrow();
	}

	return cursor;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfArrow() const noexcept
{
	QCursor cursor_of_arrow(this->m_current_pixmap_of_cursor_of_arrow,
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
	QCursor cursor;

	if (this->SystemCursorsIsSelected())
	{
		cursor = CursorsOfWidget::ReleaseGetSystemCursorOfSizeAll();
	}
	else
	{
		cursor = this->ReleaseGetCustomCursorOfSizeAll();
	}

	return cursor;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeAll() const noexcept
{
	QCursor cursor_of_size_all(this->m_current_pixmap_of_cursor_of_size_all,
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
	QCursor cursor;

	if (this->SystemCursorsIsSelected())
	{
		cursor = CursorsOfWidget::ReleaseGetSystemCursorOfSizeHorizontal();
	}
	else
	{
		cursor = this->ReleaseGetCustomCursorOfSizeHorizontal();
	}

	return cursor;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeHorizontal() const noexcept
{
	QCursor cursor_of_size_horizontal(this->m_current_pixmap_of_cursor_of_size_horizontal,
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
	QCursor cursor;

	if (this->SystemCursorsIsSelected())
	{
		cursor = CursorsOfWidget::ReleaseGetSystemCursorOfSizeVertical();
	}
	else
	{
		cursor = this->ReleaseGetCustomCursorOfSizeVertical();
	}

	return cursor;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeVertical() const noexcept
{
	QCursor cursor_of_size_vertical(this->m_current_pixmap_of_cursor_of_size_vertical,
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
	QCursor cursor;

	if (this->SystemCursorsIsSelected())
	{
		cursor = CursorsOfWidget::ReleaseGetSystemCursorOfSizeRightDiagonal();
	}
	else
	{
		cursor = this->ReleaseGetCustomCursorOfSizeRightDiagonal();
	}

	return cursor;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeRightDiagonal() const noexcept
{
	QCursor cursor_of_size_right_diagonal(this->m_current_pixmap_of_cursor_of_size_right_diagonal,
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
	QCursor cursor;

	if (this->SystemCursorsIsSelected())
	{
		cursor = CursorsOfWidget::ReleaseGetSystemCursorOfSizeLeftDiagonal();
	}
	else
	{
		cursor = this->ReleaseGetCustomCursorOfSizeLeftDiagonal();
	}

	return cursor;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetCustomCursorOfSizeLeftDiagonal() const noexcept
{
	QCursor cursor_image_of_left_diagonal(this->m_current_pixmap_of_cursor_of_size_left_diagonal,
										  this->m_current_hot_spot_of_cursor_of_size_left_diagonal.x(),
										  this->m_current_hot_spot_of_cursor_of_size_left_diagonal.y());

	return cursor_image_of_left_diagonal;
}

[[nodiscard]] inline QCursor CursorsOfWidget::ReleaseGetSystemCursorOfSizeLeftDiagonal() noexcept
{
	QCursor cursor_of_arrow(Qt::SizeFDiagCursor);

	return cursor_of_arrow;
}
}  // namespace N_Widget
