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
        // do the move
        board->move(dir);

        // update score
        if (board->isTileCollisionLastRound())
            score += board->getPointsScoredLastRound();

        // if there is no more move possible, then it's game over
        if (!board->movePossible())
            gameOver = true;

        writePlain("Se movio la ficha",2);
        saveMoveTree();
        notifyObservers();
    }catch(...) {
        cout << "Ha ocurrido un error inesperado..." << endl;
    }
}

void Game::restart()
{
    try {
        writePlain(to_string(score),1);
        saveScoreTree(score);
        treeMoves=NULL;
        board->reset();
        gameOver = false;
        score = 0;

    }catch(...) {
        cout << "Ha ocurrido un error inesperado..." << endl;
    }


}


void Game::writePlain(string text,int n){

    try {
        ofstream out_file;
        time_t current_time;
        struct tm * time_info;
        char timeString[9];

        time(&current_time);
        time_info = localtime(&current_time);

        strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

        // Escribir el archivo
        if(n==1 && text!="0"){
            out_file.open("..\\2048-Game\\Score.txt", ios::app); // ios::app es lo paralello a "a" que significa append agregar al final del archivo
            out_file << "Score: "<<text << " - "<< "Fecha: " <<timeString<< endl; // agregamos al buffer del stream
            out_file.close();  // flush el buffer y cerramos. flush el buffer basicamente hace write en el archivo.
        }
        if(n==2){
            out_file.open("..\\2048-Game\\Moves.txt", ios::app);
            out_file << "Move: "<<text << " - "<< "Fecha: " <<timeString<< endl;
            out_file.close();

        }

    }catch(...) {
        cout << "Ha ocurrido un error inesperado..." << endl;
    }




}

//Guarda los scores de un jugador durante todos los intentos
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


//Aumenta el  valor de 1 por cada movimiento del usuario en un intento
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




