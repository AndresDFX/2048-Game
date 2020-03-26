/**
  * @file tile.h
  * @version 1.0
  * @date 25/03/2020
  *
*/

#ifndef TILE_H
#define TILE_H

#define EXP_MULTIPLIER 2

/**
 * @brief Clase que representa una baldosa dentro de un tablero
*/
class Tile
{
public:
    /**
     * @brief Constructor vacio que genera una nueva baldosa
     */
    Tile() { value = 2; upgratedThisMove = false; }

    /**
     * @brief Constructor que actualiza el valor de una baldosa dada otra baldosa
     * @param other Variable que almancena la baldosa a cambiar por la ingresada
     */
    Tile(const Tile& other) { this->value = other.value; }

    /**
     * @brief Constructor que actualiza el valor de una baldosa
     * @param value Variable que almancena el cambio de valor una baldosa
     */
    Tile(int value) { this->value = value; }

    /**
     * @brief Metodo que obtiene el valor de la baldosa
     * @return Variable que almacena el valor entero de una baldosa
     */
    int getValue() { return value; }

    /**
     * @brief Metodo que actualiza el valor de generacion de una baldosa multiplicandolo por la constante de clase
     */
    void upgrade() { value *= EXP_MULTIPLIER; }

    /**
     * @brief Metodo que actualiza el movimiento de una baldosa dada las acciones de un jugador en el tablero
     * @param updated Variable que almacena el estado de la baldosa
     */
    void setUpgratedThisMove(bool updated) { this->upgratedThisMove = updated; }

    /**
     * @brief Metodo que obtiene el estado de una baldosa dadas el movimiento de una baldosa dada las acciones de un jugador en el tablero
     */
    bool getUpgratedThisMove() const { return this->upgratedThisMove; }

private:
    int value;
    bool upgratedThisMove;
};

#endif // TILE_H
