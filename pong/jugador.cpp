#include "jugador.h"

//%%%%%%%%%%%%%%%%%%% Constructores - destructores %%%%%%%%%%%%%%%%%%%

Jugador::Jugador()
{

}

Jugador::Jugador(QPoint _pos, QPoint _tam) {
    pos = _pos;
    anteriorPos.setX(pos.x());
    anteriorPos.setY(pos.y());
    tam = _tam;
}


//%%%%%%%%%%%%%%%%%%% Public functions %%%%%%%%%%%%%%%%%%%

void Jugador::actualizarImagen(QPixmap * pixmap) {
    QPainter pintor(pixmap);

    pintor.setBrush(Qt::black);
    pintor.drawRect(anteriorPos.x(), anteriorPos.y(), tam.x(), tam.y());

    pintor.setBrush(Qt::white);
    pintor.drawRect(pos.x(), pos.y(), tam.x(), tam.y());

    anteriorPos.setY(pos.y());
}

void Jugador::moverArriba() {
    if (pos.y() - DESPLAZAMIENTO > 0) {
        pos.setY(pos.y() - DESPLAZAMIENTO);
    }
}

void Jugador::moverAbajo() {
    if (pos.y() + tam.y() + DESPLAZAMIENTO < ALTO_VENTANA) {
        pos.setY(pos.y() + DESPLAZAMIENTO);
    }
}
