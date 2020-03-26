/**
  * @file game.h
  * @version 1.0
  * @date 25/03/2020
  *
*/

#ifndef GAME_H
#define GAME_H

#include "core/subject.h"
#include "core/board.h"
#include "core/tree.h"
#include <iostream>
#include <fstream>
#include <ctime>

class Board;

/**
 * @brief Clase que representa e implementa todos los metodos necesarios para que un jugador realice acciones sobre un tablero
 */
class Game : public Subject
{


public:
    Game(int dimension);
    ~Game();

    /**
     * @brief treeScore Representa el arbol Binario de Busqueda donde se almacenaran de forma ordenada todos los puntajes de un jugador
     */
    static ABB treeScore;

    /**
     * @brief treeMoves Representa el arbol Binario de Busqueda donde se almacenara cada moviemiento del jugador para posteriormente contar los nodos del arbol
     */
    static ABB treeMoves;

    /**
     * @brief counter Variable que almacena la cantidad de movimientos de un jugador para imprimirlos por pantalla
     */
    static int counter;

    /**
     * @brief Metodo que restaura todas las variables del juego (y el tablero) para iniciar una nueva ronda
     */
    void restart();

    /**
     * @brief Metodo que determina si el jugador perdio porque no hay ningun movimiento posible de las baldosas
     * @return La variable booleana que retorna
     */
    bool isGameOver() const { return gameOver; }

    /**
     * @brief Metodo que obtiene el tablero de juego
     * @return La variable del tablero dadas todas las condiciones y acciones realizadas por el jugador
     */
    Board* getGameBoard() const { return board; }

    /**
     * @brief Metodo que dada una direccion verifica si es posible realizar el movimiento y actualiza las constantes del juego
     * @param dir La variable que almacena la direccion de la accion del teclado realizada por el jugador (UP, DOWN, LEFT, RIGHT)
     */
    void move(Direction dir);

    /**
     * @brief Metodo que obtiene el score dada las colisiones de baldosas validas
     * @return La variable del score que almacena el valor del QTile
     */
    int getScore() const { return score; }

    /**
     * @brief Metodo que guarda los scores de un jugador durante todos los intentos en un Arbol Binario de Busqueda y lo muestra por pantalla
     * @param score Variable que almacena el valor del score de una ronda especifica
     */
    void saveScoreTree(int score);

    /**
     * @brief Metodo que guarda con un valor 1, cada movimiento del jugador durante todos los intentos en un Arbol Binario de Busqueda y lo muestra por pantalla
     */
    void saveMoveTree();


private:
    Board* board;
    bool gameOver;
    int score;

};

#endif // GAME_H
