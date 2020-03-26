#include "qgameoverwindow.h"
#include "qresetbutton.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>

QGameOverWindow::QGameOverWindow(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("QGameOverWindow { background: rgb(237,224,200); }");
    setFixedSize(425,205);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // etiqueta sobre la ventana game over
    QLabel* gameover = new QLabel("Perdiste!", this);
    gameover->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40pt; font: bold;} ");  

    // Botón de reinicio
    reset = new QResetButton(this);
    reset->setFixedHeight(50);
    reset->setFixedWidth(100);

    // agrega el juego sobre la etiqueta a la ventana
    layout->insertWidget(0,gameover,0,Qt::AlignCenter);

    // agrega el botón de reinicio a la ventana
    layout->insertWidget(1,reset,0,Qt::AlignCenter);
}

QResetButton* QGameOverWindow::getResetBtn() const
{
    return reset;
}
