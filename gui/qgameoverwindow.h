/**
  * @file qgameoverwindow.h
  * @version 1.0
  * @date 25/03/2020
  *
*/


#ifndef QGAMEOVERWINDOW_H
#define QGAMEOVERWINDOW_H

#include <QWidget>

class QResetButton;

/**
 * @brief Clase que representa la ventana de "Game Over" cuando el jugador pierde
 */

class QGameOverWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QGameOverWindow(QWidget *parent = 0);
    QResetButton* getResetBtn() const;

signals:

public slots:

private:
    QResetButton* reset;

};

#endif // QGAMEOVERWINDOW_H
