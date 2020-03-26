#include "core/game.h"
#include "core/tile.h"

using namespace std;

ABB Game::treeScore = NULL;
ABB Game::treeMoves = NULL;
int Game::counter = 0;

Game::Game(int dimension)
{
    score = 0;
    board = new Board(dimension);
    restart();
}

Game::~Game()
{

    delete board;
}


void Game::move(Direction dir)
{

    try {       
        // hacer el movimiento
        board->move(dir);

        // actualización de puntaje
        if (board->isTileCollisionLastRound())
            score += board->getPointsScoredLastRound();

        // si no hay más movimiento posible, entonces se acabó el juego
        if (!board->movePossible())
            gameOver = true;

        saveMoveTree();
        notifyObservers();
    }catch(...) {
        cout << "Ha ocurrido un error inesperado..." << endl;
    }
}

void Game::restart()
{
    try {

        saveScoreTree(score);
        treeMoves=NULL;
        board->reset();
        gameOver = false;
        score = 0;

    }catch(...) {
        cout << "Ha ocurrido un error inesperado..." << endl;
    }


}

void Game::saveScoreTree(int score){

    // creado Arbol
    tree treeMethods;

    treeMethods.insert(treeScore,score);
    cout << "\n Mostrando ABB de Score \n\n";
    treeMethods.lookTree( treeScore, 0);

    cout << "\n Recorrido del ABB";
    cout << "\n\n Pre Orden  :  ";  treeMethods.preOrder(treeScore);

    cout << endl << endl;

}

void Game::saveMoveTree(){

    try {
        // creado Arbol
        tree treeMethods;
        counter++;
        treeMethods.insert(treeMoves,counter);
        cout << "El usuario realizo hasta el momento "<< treeMethods.countNodes(treeMoves)<<" movimientos \n "<<endl;
        cout << endl << endl;

    }catch(...) {
        cout << "Ha ocurrido un error inesperado..." << endl;
    }

}




