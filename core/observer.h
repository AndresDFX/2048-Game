/**
  * @file observer.h
  * @version 1.0
  * @date 25/03/2020
  *
*/

#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief Clase que notifica los cambios realizados en el juego, para actualizar el tablero, juego, baldosas con los nuevos valores
 */
class Observer
{
public:
    Observer();
    virtual void notify() = 0;
};

#endif // OBSERVER_H
