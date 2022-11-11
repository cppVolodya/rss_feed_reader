#include "main_window.h"
#include "ui_main_window.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	this->setWindowIcon( QIcon(":/resources/rss_feed_reader_window_icon.ico") );
}

MainWindow::~MainWindow()
{
    delete ui;
}
