/**
  * @file subject.h
  * @version 1.0
  * @date 25/03/2020
  *
*/

#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

using namespace std;

class Observer;

/**
 * @brief Clase sujeto que se utiliza para manejar los diferentes observadores
 */
class Subject
{
public:
    Subject();

    /**
     * @brief Metodo que notifica los observadores dentro de un contexto
     */
    void notifyObservers();

    /**
     * @brief Metodo que registra los multiples observadores de clase dentro de una lista
     * @param observer Variable que almacena los diferentes observadores de clase
     */
    void registerObserver(Observer* observer);

private:
    vector<Observer*> observers;
};

#endif // SUBJECT_H
