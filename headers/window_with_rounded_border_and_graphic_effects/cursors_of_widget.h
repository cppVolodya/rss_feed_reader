// Copyright [2023] <Volodymyr Dorozhovets>"

#ifndef RSS_FEED_READER_HEADERS_CURSORS_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_CURSORS_OF_WIDGET_H_

#include <QCursor>
#include <QPoint>


using t_selected = bool;

class CursorsOfWidget
{
	using t_image = QString;
public:
	explicit CursorsOfWidget(bool system_cursor_is_selected = false) noexcept;

#pragma region SetDefaultSettings [functions]
	inline void SetDefaultSettings() noexcept;

	void SetDefaultOfImagesOfCursors  () noexcept;
	void SetDefaultOfHotSpotsOfCursors() noexcept;
#pragma endregion SetDefaultSettings [functions]

	void SelectSystemCursors(t_selected) noexcept;

	[[nodiscard]] inline t_selected SystemCursorsIsSelected() const noexcept;

#pragma region GetSpecificCursors [functions]
	[[nodiscard]] inline QCursor GetCursor(Qt::CursorShape) const noexcept;

	[[nodiscard]] inline QCursor GetCursorOfArrow  			 () const noexcept;
	[[nodiscard]] inline QCursor GetCursorOfSizeAll		     () const noexcept;
	[[nodiscard]] inline QCursor GetCursorOfSizeHorizontal   () const noexcept;
	[[nodiscard]] inline QCursor GetCursorOfSizeVertical     () const noexcept;
	[[nodiscard]] inline QCursor GetCursorOfSizeRightDiagonal() const noexcept;
	[[nodiscard]] inline QCursor GetCursorOfSizeLeftDiagonal () const noexcept;
#pragma endregion GetSpecificCursors [functions]
private:
	t_image m_current_cursor_image_of_arrow;
	t_image m_current_cursor_image_of_size_all;
	t_image m_current_cursor_image_of_size_horizontal;
	t_image m_current_cursor_image_of_size_vertical;
	t_image m_current_cursor_image_of_size_right_diagonal;
	t_image m_current_cursor_image_of_size_left_diagonal;

	QPoint m_current_hot_spot_of_cursor_of_arrow;
	QPoint m_current_hot_spot_of_cursor_of_size_all;
	QPoint m_current_hot_spot_of_cursor_of_size_horizontal;
	QPoint m_current_hot_spot_of_cursor_of_size_vertical;
	QPoint m_current_hot_spot_of_cursor_of_size_right_diagonal;
	QPoint m_current_hot_spot_of_cursor_of_size_left_diagonal;

	t_selected m_system_cursors_is_selected;
private:
	[[nodiscard]] QCursor ReleaseGetCursor(Qt::CursorShape) const noexcept;

#pragma region ReleaseGetSpecificCursors [functions]
	[[nodiscard]] 				QCursor ReleaseGetCursorOfArrow      () const noexcept;
	[[nodiscard]] inline 		QCursor ReleaseGetCustomCursorOfArrow() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfArrow() noexcept;

	[[nodiscard]] 				QCursor ReleaseGetCursorOfSizeAll	   () const noexcept;
	[[nodiscard]] inline 		QCursor ReleaseGetCustomCursorOfSizeAll() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeAll() noexcept;

	[[nodiscard]]			    QCursor ReleaseGetCursorOfSizeHorizontal   	  () const noexcept;
	[[nodiscard]] inline 	    QCursor ReleaseGetCustomCursorOfSizeHorizontal() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeHorizontal() noexcept;

	[[nodiscard]] 			    QCursor ReleaseGetCursorOfSizeVertical      () const noexcept;
	[[nodiscard]] inline 	    QCursor ReleaseGetCustomCursorOfSizeVertical() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeVertical() noexcept;

	[[nodiscard]] 			    QCursor ReleaseGetCursorOfSizeRightDiagonal		 () const noexcept;
	[[nodiscard]] inline 	    QCursor ReleaseGetCustomCursorOfSizeRightDiagonal() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeRightDiagonal() noexcept;

	[[nodiscard]] 			    QCursor ReleaseGetCursorOfSizeLeftDiagonal      () const noexcept;
	[[nodiscard]] inline 	    QCursor ReleaseGetCustomCursorOfSizeLeftDiagonal() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeLeftDiagonal() noexcept;
#pragma endregion ReleaseGetSpecificCursors [functions]
};

inline void CursorsOfWidget::SetDefaultSettings() noexcept
{
	this->SetDefaultOfImagesOfCursors  ();
	this->SetDefaultOfHotSpotsOfCursors();
}

[[nodiscard]] inline t_selected CursorsOfWidget::SystemCursorsIsSelected() const noexcept
{
	return this->m_system_cursors_is_selected;
}

[[nodiscard]] inline QCursor CursorsOfWidget::GetCursor(const Qt::CursorShape cursor_shape) const noexcept
{
	return this->ReleaseGetCursor(cursor_shape);
}

[[nodiscard]] inline QCursor CursorsOfWidget::GetCursorOfArrow() const noexcept
{
	return this->ReleaseGetCursorOfArrow();
}

[[nodiscard]] inline QCursor CursorsOfWidget::GetCursorOfSizeAll() const noexcept
{
	return this->ReleaseGetCursorOfSizeAll();
}

[[nodiscard]] inline QCursor CursorsOfWidget::GetCursorOfSizeHorizontal() const noexcept
{
	return this->ReleaseGetCursorOfSizeHorizontal();
}

[[nodiscard]] inline QCursor CursorsOfWidget::GetCursorOfSizeVertical() const noexcept
{
	return this->ReleaseGetCursorOfSizeVertical();
}

[[nodiscard]] inline QCursor CursorsOfWidget::GetCursorOfSizeRightDiagonal() const noexcept
{
	return this->ReleaseGetCursorOfSizeRightDiagonal();
}

[[nodiscard]] inline QCursor CursorsOfWidget::GetCursorOfSizeLeftDiagonal() const noexcept
{
	return this->ReleaseGetCursorOfSizeLeftDiagonal();
}

#endif  // RSS_FEED_READER_HEADERS_CURSORS_OF_WIDGET_H_
