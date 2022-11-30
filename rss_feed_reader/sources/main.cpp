#include <QApplication>

#include "main_window.h"


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    MainWindow main_window;
    main_window.Show();

    return application.exec();
}
