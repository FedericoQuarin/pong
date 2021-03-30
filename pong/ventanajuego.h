#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QWidget>
#include <QKeyEvent>
#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "juego.h"

#define MAX_TECLAS 10


namespace Ui {
class VentanaJuego;
}

class VentanaJuego : public QWidget
{
    Q_OBJECT

public:
    VentanaJuego(QWidget *parent = nullptr);
    VentanaJuego(QMainWindow * _mainWindow, QWidget *parent = nullptr);
    ~VentanaJuego();

    void start();

private slots:
    void actualizarPantalla();

private:
    Ui::VentanaJuego *ui;
    QMainWindow * mainWindow;
    QTimer temp;

    Juego * juego;
    QPixmap pixmap;
    Qt::Key teclas[MAX_TECLAS];
    int tlTeclas;

    void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);
    bool eventFilter(QObject *object, QEvent *ev);
    void closeEvent(QCloseEvent *event);
    void init_pixmap();
    void clean_pixmap();
    bool teclaYaPresionada(Qt::Key teclaBuscada);
    void eliminarTecla(Qt::Key teclaAEliminar);
};

#endif // VENTANAJUEGO_H
