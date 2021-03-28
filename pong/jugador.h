#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QPoint>
#include <QPainter>

class Jugador : public QObject
{
    Q_OBJECT

private:
    QPoint pos, tam;

public:
    Jugador();
    Jugador(QPoint _pos, QPoint _tam);

    void pintarse(QPixmap * pixmap);
};

#endif // JUGADOR_H
