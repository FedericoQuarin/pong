#ifndef JUEGO_H
#define JUEGO_H

#include <QObject>
#include <QPainter>
#include "jugador.h"
#include "pelota.h"
//#include "ventanajuego.h"



class Juego : public QObject
{
    Q_OBJECT

private:
    Jugador *jugador1, *jugador2;
    Pelota * pelota;

    void borrarElemViejos();

public:
    Juego(Jugador *_jugador1, Jugador *_jugador2);

    ~Juego();


    static void crear_nuevo_juego(Juego ** juego);

    void imprimir_elementos(QPixmap * pixmap);

    void moverJugador(int nroJugador, int direccion);
};

#endif // JUEGO_H
