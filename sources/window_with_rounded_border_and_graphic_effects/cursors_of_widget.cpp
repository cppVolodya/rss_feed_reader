#include <qdebug.h>

#include "cursors_of_widget.h"


const QString CursorsOfWidget::C_S_DEFAULT_CURSOR_IMAGE_OF_ARROW		      { ":/resources/cursor_image_of_arrow.png" 			  };
const QString CursorsOfWidget::C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_ALL			  { ":/resources/cursor_image_of_size_all.png" 			  };
const QString CursorsOfWidget::C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_HORIZONTAL    { ":/resources/cursor_image_of_size_horizontal.png"     };
const QString CursorsOfWidget::C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_VERTICAL	  { ":/resources/cursor_image_of_size_vertical.png"       };
const QString CursorsOfWidget::C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_RIGHT_DIAGONAL{ ":/resources/cursor_image_of_size_right_diagonal.png" };
const QString CursorsOfWidget::C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_LEFT_DIAGONAL { ":/resources/cursor_image_of_size_left_diagonal.png"  };

const QPoint CursorsOfWidget::C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_ARROW			   {  5,  2 };
const QPoint CursorsOfWidget::C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_ALL		   { -1, -1 };
const QPoint CursorsOfWidget::C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_HORIZONTAL	   { -1, -1 };
const QPoint CursorsOfWidget::C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_VERTICAL	   { -1, -1 };
const QPoint CursorsOfWidget::C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_RIGHT_DIAGONAL{ -1, -1 };
const QPoint CursorsOfWidget::C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_LEFT_DIAGONAL { -1, -1 };

CursorsOfWidget::CursorsOfWidget(bool system_cursor_is_selected) noexcept
	: m_system_cursors_is_selected(system_cursor_is_selected)
{
	this->SetDefaultSettings();
}

void CursorsOfWidget::SetDefaultOfImagesOfCursors() noexcept
{
	this->m_current_cursor_image_of_arrow				= C_S_DEFAULT_CURSOR_IMAGE_OF_ARROW;
	this->m_current_cursor_image_of_size_all			= C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_ALL;
	this->m_current_cursor_image_of_size_horizontal	    = C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_HORIZONTAL;
	this->m_current_cursor_image_of_size_vertical		= C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_VERTICAL;
	this->m_current_cursor_image_of_size_right_diagonal = C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_RIGHT_DIAGONAL;
	this->m_current_cursor_image_of_size_left_diagonal  = C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_LEFT_DIAGONAL;
}

void CursorsOfWidget::SetDefaultOfHotSpotsOfCursors() noexcept
{
	this->m_current_hot_spot_of_cursor_of_arrow 			  = C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_ARROW;
	this->m_current_hot_spot_of_cursor_of_size_all 			  = C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_ALL;
	this->m_current_hot_spot_of_cursor_of_size_horizontal 	  = C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_HORIZONTAL;
	this->m_current_hot_spot_of_cursor_of_size_vertical 	  = C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_VERTICAL;
	this->m_current_hot_spot_of_cursor_of_size_right_diagonal = C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_RIGHT_DIAGONAL;
	this->m_current_hot_spot_of_cursor_of_size_left_diagonal  = C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_LEFT_DIAGONAL;
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
