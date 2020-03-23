#include "gui/qgameboard.h"
#include "core/board.h"
#include "core/game.h"
#include "gui/qtile.h"
#include "core/tile.h"
#include "gui/qresetbutton.h"
#include <iostream>
#include <fstream>

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>

#include <QDebug>

using namespace std;

QGameBoard::~QGameBoard()
{
    delete game;
}

QGameBoard::QGameBoard(QWidget *parent) :
    QWidget(parent)
{

    // establecer tamaño predeterminado
    resize(650,450);

    // crea el diseño principal
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // se creará en drawBoard ()
    boardLayout = NULL;


    // crea el juego y se regístrate un observador
    game = new Game(4);
    game->registerObserver(this);


    // crea el tablero gui y lo dibuja
    gui_board.resize(game->getGameBoard()->getDimension());
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i)
        gui_board[i].resize(game->getGameBoard()->getDimension());
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i)
        for (int j = 0; j < game->getGameBoard()->getDimension(); ++j)
            gui_board[i][j] = NULL;
    drawBoard();


    // crea el widget de puntuación y lo agréga al tablero
    score = new QLabel(QString("PUNTAJE: %1").arg(game->getScore()));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);


    // estilo para el tablero
    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
}

void QGameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        game->move(UP);
        break;
    case Qt::Key_Left:
        game->move(LEFT);
        break;
    case Qt::Key_Right:
        game->move(RIGHT);
        break;
    case Qt::Key_Down:
        game->move(DOWN);
        break;
    }
}

void QGameBoard::notify()
{
    if (game->isGameOver())
        gameOverWindow.show();

    if (game->getScore()==2048)
        score->setText(QString("Su puntaje es 2048, Felicitaciones! Siga jugando para aumentar su puntaje.\t\t PUNTAJE: %1").arg(game->getScore()));
    else
        score->setText(QString("PUNTAJE: %1").arg(game->getScore()));

    drawBoard();
}


void QGameBoard::drawBoard()
{
    delete boardLayout;
    boardLayout = new QGridLayout();
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i) {

        for (int j = 0; j < game->getGameBoard()->getDimension(); ++j) {
            delete gui_board[i][j];
            gui_board[i][j] = new QTile(game->getGameBoard()->getTile(i,j));
            boardLayout->addWidget(gui_board[i][j], i, j);
            gui_board[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}


void QGameBoard::resetGame()
{
    game->restart();
    drawBoard();
    score->setText(QString("PUNTAJE: %1").arg(game->getScore()));
    gameOverWindow.hide();
}



