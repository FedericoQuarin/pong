#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QPoint>
#include <QPainter>
//#include "ventanajuego.h"

#define DIR_ARRIBA 1
#define DIR_ABAJO 2
#define ANCHO_VENTANA 800
#define ALTO_VENTANA 600
#define DESPLAZAMIENTO 5


class Jugador : public QObject
{
    Q_OBJECT

private:
    QPoint pos, tam, anteriorPos;

public:
    Jugador();
    Jugador(QPoint _pos, QPoint _tam);

    void actualizarImagen(QPixmap * pixmap);

    void moverArriba();
    void moverAbajo();
};

#endif // JUGADOR_H
