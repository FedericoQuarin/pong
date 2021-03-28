#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QWidget>
#include <QKeyEvent>
#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "juego.h"

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

    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);
    void init_pixmap();
    void clean_pixmap();
};

#endif // VENTANAJUEGO_H
