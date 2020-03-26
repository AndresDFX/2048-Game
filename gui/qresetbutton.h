/**
  * @file qresetbutton.h
  * @version 1.0
  * @date 25/03/2020
  *
*/

#ifndef QRESETBUTTON_H
#define QRESETBUTTON_H

#include <QLabel>

/**
 * @brief Clase de la interfaz grafica que crea el boton que permite resetar el juego e iniciar una nueva ronda
 */
class QResetButton : public QLabel
{
    Q_OBJECT
public:
    QResetButton( QWidget* parent = 0);

signals:
    void clicked();

public slots:

protected:
    /**
     * @brief Manejador de eventos para el mouse al presionar el boton de resetear el juego
     * @param event Recibe el evento del mouse dentro de las opciones permitidas en el juego
     */
    void mousePressEvent(QMouseEvent* event);

};

#endif // QRESETBUTTON_H
