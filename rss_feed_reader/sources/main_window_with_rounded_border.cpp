#include "main_window_with_rounded_border.h"


MainWindowWithRoundedBorder::MainWindowWithRoundedBorder(QWidget *parent)
	: QMainWindow(parent)
{
	/* --------------------------------------------------------------------- */
	// hide the parent window because it is not part of the main window
	// child windows are part of the main window
	this->setAttribute (Qt::WA_TranslucentBackground, true);
	this->setWindowFlag(Qt::FramelessWindowHint,      true);
	/* --------------------------------------------------------------------- */


	m_central_widget = new CentralPartOfMainWindow  (this);
	m_rounded_bord   = new RoundedBorderOfMainWindow(this);
}

void MainWindowWithRoundedBorder::Show()
{
	/* --------------------------------------------------------------------- */
	// show the program icon in the operating system taskbar
	this->show();
	/* --------------------------------------------------------------------- */


	m_central_widget->show();
	m_rounded_bord  ->show();
}
