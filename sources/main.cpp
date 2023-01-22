// Copyright [2023] <Volodymyr Dorozhovets>"

#include <QApplication>

#include "main_window.hpp"


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    MainWindow main_window;
    main_window.show();

    return QApplication::exec();
}
