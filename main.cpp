#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "gui/mainwindow.h"
#include "core/board.h"
#include "gui/qgameboard.h"
#include "gui/qgameoverwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));
    QGameBoard board;
    board.show();

    return a.exec();
}
