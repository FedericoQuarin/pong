#include "jugador.h"

//%%%%%%%%%%%%%%%%%%% Constructores - destructores %%%%%%%%%%%%%%%%%%%

Jugador::Jugador()
{

}

Jugador::Jugador(QPoint _pos, QPoint _tam) {
    pos = _pos;
    tam = _tam;
}


//%%%%%%%%%%%%%%%%%%% Public functions %%%%%%%%%%%%%%%%%%%

void Jugador::pintarse(QPixmap * pixmap) {
    QPainter pintor(pixmap);

    pintor.setBrush(Qt::white);
    pintor.drawRect(pos.x(), pos.y(), tam.x(), tam.y());
}
