#ifndef GAME_H
#define GAME_H



#include "core/subject.h"
#include "core/board.h"
#include "core/tree.h"
#include <iostream>
#include <fstream>
#include <ctime>

class Board;

class Game : public Subject
{


public:
    Game(int dimension);
    ~Game();
    static ABB treeScore;
    static ABB treeMoves;
    static int counter;
    void restart();
    bool isGameOver() const { return gameOver; }
    Board* getGameBoard() const { return board; }
    void move(Direction dir);

    // devuelve verdadero si el juego está en estado ganador,
    // (es decir, hay un mosaico que tiene el valor definido en WINNING_VALUE)
    bool won() const;
    int getScore() const { return score; }

    void writePlain(string text, int n);
    void saveScoreTree(int score);
    void saveMoveTree();


private:
    Board* board;
    bool gameOver;
    int score;




};

#endif // GAME_H
