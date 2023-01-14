#ifndef RSS_FEED_READER_HEADERS_CURSORS_OF_WIDGET_H_
#define RSS_FEED_READER_HEADERS_CURSORS_OF_WIDGET_H_

#include <QCursor>
#include <QPoint>


class CursorsOfWidget
{
	using Image    = QString;
	using selected = bool;
public:
#pragma region DefaultImagesOfCursors [members]
	const static Image C_S_DEFAULT_CURSOR_IMAGE_OF_ARROW;  			     // cursor of arrow
	const static Image C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_ALL;  			 // cursor of size all
	const static Image C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_HORIZONTAL;      // cursor of size horizontal
	const static Image C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_VERTICAL;  		 // cursor of size vertical
	const static Image C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_RIGHT_DIAGONAL;  // cursor of size right diagonal
	const static Image C_S_DEFAULT_CURSOR_IMAGE_OF_SIZE_LEFT_DIAGONAL;   // cursor of size left diagonal
#pragma endregion DefaultImagesOfCursors [members]

#pragma region DefaultHotSpotsOfCursors [members]
	const static QPoint C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_ARROW;  				// cursor of arrow
	const static QPoint C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_ALL;  			// cursor of size all
	const static QPoint C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_HORIZONTAL;      // cursor of size horizontal
	const static QPoint C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_VERTICAL;  		// cursor of size vertical
	const static QPoint C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_RIGHT_DIAGONAL;  // cursor of size right diagonal
	const static QPoint C_S_DEFAULT_HOT_SPOT_OF_CURSOR_OF_SIZE_LEFT_DIAGONAL;   // cursor of size left diagonal
#pragma endregion DefaultHotSpotsOfCursors [members]
public:
	explicit CursorsOfWidget(bool system_cursor_is_selected = false) noexcept;

#pragma region SetDefaultSettings [functions]
	inline void SetDefaultSettings() noexcept;

	void SetDefaultOfImagesOfCursors  () noexcept;
	void SetDefaultOfHotSpotsOfCursors() noexcept;
#pragma endregion DefaultHotSpotsOfCursors [functions]

	void SetSystemCursor(selected) noexcept;

	[[nodiscard]] inline QCursor GetCursor(Qt::CursorShape) const noexcept;

#pragma region GetSpecificCursors [functions]
	[[nodiscard]] inline QCursor GetCursorOfArrow  			 () const noexcept;  // cursor of arrow
	[[nodiscard]] inline QCursor GetCursorOfSizeAll		     () const noexcept;  // cursor of size all
	[[nodiscard]] inline QCursor GetCursorOfSizeHorizontal   () const noexcept;  // cursor of size horizontal
	[[nodiscard]] inline QCursor GetCursorOfSizeVertical     () const noexcept;  // cursor of size vertical
	[[nodiscard]] inline QCursor GetCursorOfSizeRightDiagonal() const noexcept;  // cursor of size right diagonal
	[[nodiscard]] inline QCursor GetCursorOfSizeLeftDiagonal () const noexcept;  // cursor of size left diagonal
#pragma endregion GetSpecificCursors [functions]
private:
#pragma region CurrentImagesOfCursors [members]
	Image m_current_cursor_image_of_arrow;  			  // cursor of arrow
	Image m_current_cursor_image_of_size_all; 		 	  // cursor of size all
	Image m_current_cursor_image_of_size_horizontal;  	  // cursor of size horizontal
	Image m_current_cursor_image_of_size_vertical;  	  // cursor of size vertical
	Image m_current_cursor_image_of_size_right_diagonal;  // cursor of size right diagonal
	Image m_current_cursor_image_of_size_left_diagonal;   // cursor of size left diagonal
#pragma endregion CurrentImagesOfCursors [members]

#pragma region CurrentHotSpotsOfCursors [members]
	QPoint m_current_hot_spot_of_cursor_of_arrow;				 // cursor of arrow
	QPoint m_current_hot_spot_of_cursor_of_size_all;			 // cursor of size all
	QPoint m_current_hot_spot_of_cursor_of_size_horizontal;		 // cursor of size horizontal
	QPoint m_current_hot_spot_of_cursor_of_size_vertical;		 // cursor of size vertical
	QPoint m_current_hot_spot_of_cursor_of_size_right_diagonal;  // cursor of size right diagonal
	QPoint m_current_hot_spot_of_cursor_of_size_left_diagonal;   // cursor of size left diagonal
#pragma endregion CurrentHotSpotsOfCursors [members]

	selected m_system_cursor_is_selected;
private:
	[[nodiscard]] QCursor ReleaseGetCursor(Qt::CursorShape) const noexcept;

#pragma region ReleaseGetSpecificCursors [functions]
#pragma region ReleaseGetCursorOfArrow [functions]
	[[nodiscard]] 				QCursor ReleaseGetCursorOfArrow      () const noexcept;
	[[nodiscard]] inline 		QCursor ReleaseGetCustomCursorOfArrow() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfArrow() noexcept;
#pragma endregion ReleaseGetCursorOfArrow [functions]

#pragma region ReleaseGetCursorOfSizeAll [functions]
	[[nodiscard]] 				QCursor ReleaseGetCursorOfSizeAll	   () const noexcept;
	[[nodiscard]] inline 		QCursor ReleaseGetCustomCursorOfSizeAll() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeAll() noexcept;
#pragma endregion ReleaseGetCursorOfSizeAll [functions]

#pragma region ReleaseGetCursorOfSizeHorizontal [functions]
	[[nodiscard]]			    QCursor ReleaseGetCursorOfSizeHorizontal   	  () const noexcept;
	[[nodiscard]] inline 	    QCursor ReleaseGetCustomCursorOfSizeHorizontal() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeHorizontal() noexcept;
#pragma endregion ReleaseGetCursorOfSizeHorizontal [functions]

#pragma region ReleaseGetCursorOfSizeVertical [functions]
	[[nodiscard]] 			    QCursor ReleaseGetCursorOfSizeVertical      () const noexcept;
	[[nodiscard]] inline 	    QCursor ReleaseGetCustomCursorOfSizeVertical() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeVertical() noexcept;
#pragma endregion ReleaseGetCursorOfSizeVertical [functions]

#pragma region ReleaseGetCursorOfSizeRightDiagonal [functions]
	[[nodiscard]] 			    QCursor ReleaseGetCursorOfSizeRightDiagonal		 () const noexcept;
	[[nodiscard]] inline 	    QCursor ReleaseGetCustomCursorOfSizeRightDiagonal() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeRightDiagonal() noexcept;
#pragma endregion ReleaseGetCursorOfSizeRightDiagonal [functions]

#pragma region ReleaseGetCursorOfSizeLeftDiagonal [functions]
	[[nodiscard]] 			    QCursor ReleaseGetCursorOfSizeLeftDiagonal      () const noexcept;
	[[nodiscard]] inline 	    QCursor ReleaseGetCustomCursorOfSizeLeftDiagonal() const noexcept;
	[[nodiscard]] static inline QCursor ReleaseGetSystemCursorOfSizeLeftDiagonal() noexcept;
#pragma endregion ReleaseGetCursorOfSizeLeftDiagonal [functions]
#pragma endregion ReleaseGetSpecificCursors [functions]
};

#pragma region SetDefaultSettings [functions]
inline void CursorsOfWidget::SetDefaultSettings() noexcept
{
	this->SetDefaultOfImagesOfCursors  ();
	this->SetDefaultOfHotSpotsOfCursors();
}
#pragma endregion DefaultHotSpotsOfCursors [functions]

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
