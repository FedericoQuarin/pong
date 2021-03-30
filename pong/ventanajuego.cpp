#include "ventanajuego.h"
#include "ui_ventanajuego.h"

//%%%%%%%%%%%%%%%%%%% Constructores - destructor %%%%%%%%%%%%%%%%%%%

VentanaJuego::VentanaJuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaJuego)

{
    ui->setupUi(this);

    connect(&temp, SIGNAL(timeout()), this, SLOT(actualizarPantalla()));
    temp.start(100);
}

VentanaJuego::VentanaJuego(QMainWindow * _mainWindow, QWidget *parent) :
    VentanaJuego(parent)
{

    //ui->setupUi(this);

    mainWindow = _mainWindow;

    //init pixmap y pintar cancha
    QPixmap pixmapAux(ui->label->size());

    pixmap = pixmapAux;

    init_pixmap();

    tlTeclas = 0;

    //connect(&temp, SIGNAL(timeout()), this, SLOT(actualizarPantalla()));
    //temp.start(100);

    this->installEventFilter(this);

}

VentanaJuego::~VentanaJuego()
{
    delete ui;
}

//%%%%%%%%%%%%%%%%%%% other public functions %%%%%%%%%%%%%%%%%%%

void VentanaJuego::start() {
    init_pixmap();

    Juego::crear_nuevo_juego(&juego);



}

//%%%%%%%%%%%%%%%%%%% private slots %%%%%%%%%%%%%%%%%%%

void VentanaJuego::actualizarPantalla() {
    if (this->isVisible()) {
        for (int i=0; i<tlTeclas; i++) {
            switch (teclas[i]) {
            case Qt::Key_W:
                juego->moverJugador(1, DIR_ARRIBA);
                break;
            case Qt::Key_S:
                juego->moverJugador(1, DIR_ABAJO);
                break;
            case Qt::Key_I:
                juego->moverJugador(2, DIR_ARRIBA);
                break;
            case Qt::Key_K:
                juego->moverJugador(2, DIR_ABAJO);
                break;
            default:
                break;
            }
        }

        juego->imprimir_elementos(&pixmap);

        ui->label->setPixmap(pixmap);
    }
}


//%%%%%%%%%%%%%%%%%%% private functions %%%%%%%%%%%%%%%%%%%

void VentanaJuego::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);

    /*if (event->key() == Qt::Key_Up) {
        this->close();
    }*/
    switch (event->key()) {
    case Qt::Key_Escape:
        this->close();
        break;
    case Qt::Key_W:
        if (!this->teclaYaPresionada(Qt::Key_W)) {
            teclas[tlTeclas] = Qt::Key_W;
            tlTeclas++;
        }
        break;
    case Qt::Key_S:
        if (!this->teclaYaPresionada(Qt::Key_S)) {
            teclas[tlTeclas] = Qt::Key_S;
            tlTeclas++;
        }
        break;
    case Qt::Key_I:
        if (!this->teclaYaPresionada(Qt::Key_I)) {
            teclas[tlTeclas] = Qt::Key_I;
            tlTeclas++;
        }
        break;
    case Qt::Key_K:
        if (!this->teclaYaPresionada(Qt::Key_K)) {
            teclas[tlTeclas] = Qt::Key_K;
            tlTeclas++;
        }
        break;

    }

    //ui->pts_p1->setValue(ui->pts_p1->value()+1);


}

bool VentanaJuego::eventFilter(QObject *object, QEvent *ev)
{
      if (ev->type() == QEvent::KeyRelease)
      {
           QKeyEvent* keyEvent = (QKeyEvent*)ev;
               switch (keyEvent->key()) {
               case Qt::Key_W:
                   this->eliminarTecla(Qt::Key_W);
                   break;
               case Qt::Key_S:
                   this->eliminarTecla(Qt::Key_S);
                   break;
               case Qt::Key_I:
                   this->eliminarTecla(Qt::Key_I);
                   break;
               case Qt::Key_K:
                   this->eliminarTecla(Qt::Key_K);
                   break;
               }


           ui->pts_p1->setValue(ui->pts_p1->value()+1);
    }

    return false;
}

/*void VentanaJuego::keyReleaseEvent(QKeyEvent *event) {
    QWidget::keyReleaseEvent(event);

    switch (event->key()) {
    case Qt::Key_W:
        this->eliminarTecla(Qt::Key_W);
        break;
    case Qt::Key_S:
        this->eliminarTecla(Qt::Key_S);
        break;
    case Qt::Key_I:
        this->eliminarTecla(Qt::Key_I);
        break;
    case Qt::Key_K:
        this->eliminarTecla(Qt::Key_K);
        break;
    }

    ui->pts_p1->setValue(ui->pts_p1->value()+1);

}*/

void VentanaJuego::closeEvent(QCloseEvent *event) {
    clean_pixmap();

    mainWindow->setEnabled(true);
    mainWindow->show();
    QWidget::closeEvent(event);
}

void VentanaJuego::init_pixmap() {
    QPainter pintor(&pixmap);
    QPen pen;

    //pintor.setBrush(Qt::white);

    pen.setBrush(Qt::white);
    pen.setStyle(Qt::DashLine);
    pen.setWidth(4);

    pintor.setPen(pen);
    pintor.drawLine(400, 25, 400, 575);

    ui->label->setPixmap(pixmap);
}

void VentanaJuego::clean_pixmap() {
    QPainter pintor(&pixmap);

    pintor.setBrush(Qt::black);

    pintor.drawRect(0, 0, 800, 600);

    ui->label->setPixmap(pixmap);
}

bool VentanaJuego::teclaYaPresionada(Qt::Key teclaBuscada) {
    for (int i=0; i<this->tlTeclas; i++) {
        if (teclaBuscada == this->teclas[i]) return true;
    }
    return false;
}

void VentanaJuego::eliminarTecla(Qt::Key teclaAEliminar) {
    bool encontrada = false;
    int i=0;

    while (i < this->tlTeclas && !encontrada) {
        if (this->teclas[i] == teclaAEliminar) encontrada = true;
        else i++;
    }

    for (int j=i+1; j<this->tlTeclas; j++) {
        this->teclas[i] = this->teclas[j];
        i++;
    }

    this->tlTeclas--;
}

