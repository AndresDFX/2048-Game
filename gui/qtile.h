/**
  * @file qtile.h
  * @version 1.0
  * @date 25/03/2020
  *
*/


#ifndef QTILE_H
#define QTILE_H

#include <QLabel>


class Tile;
/**
 * @brief Clase de la interfaz grafica que representa una baldosa
 */
class QTile : public QLabel
{
    Q_OBJECT
public:
    QTile(const QString & text);
    QTile(Tile* tile);

    /**
     * @brief Metodo que dibuja la baldosa dado su valor (2,4,8,16,32,64,128,256,512,1024 y 2048)
     */
    void draw();
private:
    Tile* tile;

signals:

public slots:

};

#endif // QTILE_H
