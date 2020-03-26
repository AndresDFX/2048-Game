/**
  * @file board.h
  * @version 1.0
  * @date 25/03/2020
  *
*/

#ifndef BOARD_H
#define BOARD_H

#include "core/subject.h"
#include <QVector>
#include <QString>

class Tile;

/**
 * @brief Representacion las direcciones de los movimientos realizados por el jugador
 */
enum Direction { UP, DOWN, LEFT, RIGHT };

/**
 * @brief Clase que representa e implementa todos los metodos necesarios para que realizar acciones dentro de un tablero
 */
class Board : public Subject
{
public:

    Board(int dimension);
    Board(const Board& other);
    ~Board();

    /**
     * @brief Metodo que coloca el tablero en un estado inicial vacio a excepcion de dos fichas
     */
    void reset();

    /**
     * @brief Metodo que retorna un elemento del tablero
     * @param i Fila del tablero
     * @param j Columna del tablero
     * @return El elemento del tablero (baldosa)
     */
    Tile* getTile(int i, int j);

    /**
     * @brief Metodo que retorna el valor de la variable almacena el tamaño de la baldosa
     * @return La variable que contiene el valor entero de la dimension de la baldosa
     */
    int getDimension() const { return dimension; }

    /**
     * @brief Metodo que administra y ejecuta el movimiento deacuerdo a la tecla presionado por el jugador
     * @param direction Variable que contiene el movimiento realizado por el jugador
     */
    void move(Direction direction);

    /**
     * @brief Metodo que determina si el tablero esta lleno
     * @return La variable booleano que determina si se puede seguir haciendo movimientos por el jugador
     */
    bool full() const;

    /**
     * @brief  Metodo que retorna el valor de la variable que verifica si en el ultimo movimiento del jugador hubo una colision de baldosas
     * @return La variable que contiene el valor booleano de las colisiones
     */
    int getPointsScoredLastRound() const { return pointsScoredLastRound; }

    /**
     * @brief  Metodo que retorna el valor de la variable que verifica si en el ultimo movimiento del jugador hubo una colision de baldosas
     * @return La variable que contiene el valor booleano de las colisiones
     */
    bool isTileCollisionLastRound() const { return tileCollisionLastRound; }

    /**
     * @brief Metodo que verifica si es posible moverse dentro del tablero
     * @return Un valor booleano true si es posible mover o false si no es posible
     */
    bool movePossible() const;

    /**
     * @brief Metodo que inicializa el tablero vacio
     */
    void init();

    /**
     * @brief Metodo que genera una posición libre y aleatoria en el tablero
     * @return La lista que determina el valor de la posicion libre en el tablero
     */
    QVector<int> freePosition();

    /**
     * @brief Metodo que registra los cambios en el tablero
     * @param other Variable que representa el estado actual del  tablero
     * @return Verdadero si el estado actual del tablero es diferente del argumento other
     */
    bool changed(Board& other) const;

    /**
     * @brief Metodo que determina si la baldosa se encuentra dentro del tabler
     * @param i Fila del tablero
     * @param j Columna del tablero
     * @return La variable booleana true si esta dentro del tablero, false si la baldosa no esta en el tablero
     */
    bool inbounds(int i, int j);

    /**
     * @brief Metodo que realiza el cambio de estado dado movimiento horizontal de una baldosa
     * @param i Fila del tablero
     * @param j Columna del tablero
     * @param dir Variable que almacena el tipo de movimiento a realizar (LEFT, RIGHT)
     */
    void moveHorizontally(int i, int j, Direction dir);

    /**
     * @brief Metodo que realiza el cambio de estado dado movimiento vertical de una baldosa
     * @param i Fila del tablero
     * @param j Columna del tablero
     * @param dir Variable que almacena el tipo de movimiento a realizar (UP, DOWN)
     */
    void moveVertically(int i, int j, Direction dir);

    /**
     * @brief Metodo que maneja las colisiones de baldosas y actualiza el tablero
     * @param i Fila del tablero
     * @param j Columna del tablero
     */
    void handleCollision(int i, int j);

    /**
     * @brief Metodo que reinicializa todos los parametros para que el usuario realice el proximo movimiento
     */
    void prepareForNextMove();

private:
    QVector<QVector<Tile*> > board;
    int dimension;
    int pointsScoredLastRound;
    bool tileCollisionLastRound;
};

#endif // BOARD_H
