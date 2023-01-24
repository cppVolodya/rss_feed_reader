// Copyright [2023] <Volodymyr Dorozhovets>"

#include <QApplication>

#include "main_window.hpp"


int main(int argc, char *argv[])  // NOLINT(clion-misra-cpp2008-3-1-3)
{
    QApplication application(argc, argv);  // NOLINT(pvs-studio-V808)

    N_MainWindow::MainWindow main_window;
    main_window.show();

    return QApplication::exec();
}
