/**
  * @file qgameboard.h
  * @version 1.0
  * @date 25/03/2020
  *
*/


#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include "core/observer.h"
#include "qgameoverwindow.h"


#include <QVector>
#include <QWidget>

class QResetButton;
class Game;
class QKeyEvent;
class QTile;
class QGridLayout;
class QVBoxLayout;
class QLabel;

/**
 * @brief Clase que asocia el juego dentro del tablero con los propios componentes de QT
 */

class QGameBoard : public QWidget, public Observer
{
    Q_OBJECT
public:
    explicit QGameBoard(QWidget *parent = 0);
    ~QGameBoard();
    void notify();

    /**
     * @brief Metodo que dibuja todos los componentes dentro de un tablero en un Layout
     */
    void drawBoard();

private:

    Game* game;

    // representación gui del tablero
    QVector<QVector<QTile*> > gui_board;

    // diseño principal
    QVBoxLayout *mainLayout;

    // diseño de cuadrícula del tablero
    QGridLayout *boardLayout;

    // puntaje widget
    QLabel *score;

    // juego sobre widget
    QGameOverWindow gameOverWindow;

    // Widget ganador
    QLabel *youwin;


protected:
    /**
     * @brief Manejador de eventos para el teclado
     * @param event Recibe el evento del teclado dentro de las opciones permitidas en el juego
     */
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:
    void resetGame();

};

#endif // QGAMEBOARD_H
