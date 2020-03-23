#ifndef BOARD_H
#define BOARD_H

#include "core/subject.h"

#include <QVector>
#include <QString>

class Tile;

enum Direction { UP, DOWN, LEFT, RIGHT };

class Board : public Subject
{
public:

    Board(int dimension);
    Board(const Board& other);
    // destruir tablero
    ~Board();
    // coloca el tablero en estado inicial (todo está vacío, excepto dos 2 fichas)
    void reset();
    Tile* getTile(int i, int j);
    int getDimension() const { return dimension; }
    void move(Direction direction);
    bool full() const;
    int getPointsScoredLastRound() const { return pointsScoredLastRound; }
    bool isTileCollisionLastRound() const { return tileCollisionLastRound; }
    // verifica si todavía hay un movimiento posible
    bool movePossible() const;

private:
    QVector<QVector<Tile*> > board;
    int dimension;

    // crea un tablero vacío
    void init();

    // genera una posición libre y aleatoria en el tablero
    QVector<int> freePosition();


    // devuelve verdadero si el estado actual del tablero es diferente del argumento
    bool changed(Board& other) const;

    bool inbounds(int i, int j);

    // cambia de estado (tileCollision & pointsScoredLastRound)
    void moveHorizontally(int i, int j, Direction dir);
    void moveVertically(int i, int j, Direction dir);
    void handleCollision(int i, int j);

    // Reinicializar para el proximo movimiento
    void prepareForNextMove();

    int pointsScoredLastRound;
    bool tileCollisionLastRound;
};

#endif // BOARD_H
