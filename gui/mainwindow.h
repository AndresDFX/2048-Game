/**
  * @file mainwindow.h
  * @version 1.0
  * @date 25/03/2020
  *
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gui/qgameboard.h"

#include <QMainWindow>


/**
 * @namespace Espacio de nombre para representar el uso de la clase en cuestion MainWindow
 */
namespace Ui {
class MainWindow;
}

/**
 * @brief Clase que representa la ventana principal asociando un juego dentro del tablero
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGameBoard *gameBoard;

};

#endif // MAINWINDOW_H
