#include "gui/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent) 
{
    gameBoard = new QGameBoard(this);
    setCentralWidget(gameBoard);
}

MainWindow::~MainWindow()
{

}
