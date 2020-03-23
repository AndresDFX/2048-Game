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

class QGameBoard : public QWidget, public Observer
{
    Q_OBJECT
public:
    explicit QGameBoard(QWidget *parent = 0);
    ~QGameBoard();
    void notify();

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

    void drawBoard();


protected:
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:
    void resetGame();

};

#endif // QGAMEBOARD_H
