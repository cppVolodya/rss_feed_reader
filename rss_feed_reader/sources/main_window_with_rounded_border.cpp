#include "main_window_with_rounded_border.h"


MainWindowWithRoundedBorder::MainWindowWithRoundedBorder(QWidget *parent)
	: QMainWindow(parent)
{
	central_widget = new MainWindowIsBorderless    (this);
	rounded_bord   = new RoundedBorderForMainWindow(this);
}
