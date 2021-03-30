#include "juego.h"

//%%%%%%%%%%%%%%%%%%% Constructores - destructores %%%%%%%%%%%%%%%%%%%

Juego::Juego(Jugador *_jugador1, Jugador *_jugador2)
{
    jugador1 = _jugador1;
    jugador2 = _jugador2;
}

Juego::~Juego() {}


//%%%%%%%%%%%%%%%%%%% Public functions %%%%%%%%%%%%%%%%%%%

void Juego::crear_nuevo_juego(Juego ** juego) {
    Jugador *p1, *p2;
    QPoint pos1, pos2, tam;

    tam = QPoint(10, 70);
    pos1 = QPoint(15, (ALTO_VENTANA-tam.y())/2);
    pos2 = QPoint(ANCHO_VENTANA-15, (ALTO_VENTANA-tam.y())/2);

    p1 = new Jugador(pos1, tam);
    p2 = new Jugador(pos2, tam);

    *juego = new Juego(p1, p2);
}



void Juego::imprimir_elementos(QPixmap * pixmap) {
    jugador1->actualizarImagen(pixmap);
    jugador2->actualizarImagen(pixmap);
}



void Juego::moverJugador(int nroJugador, int direccion) {
    if (nroJugador == 1) {
        if (direccion == DIR_ARRIBA) {
            jugador1->moverArriba();
        } else {
            jugador1->moverAbajo();
        }
    } else {
        if (direccion == DIR_ARRIBA) {
            jugador2->moverArriba();
        } else {
            jugador2->moverAbajo();
        }
    }
}


//%%%%%%%%%%%%%%%%%%% Private functions %%%%%%%%%%%%%%%%%%%


void borrarElemViejos() {

}


