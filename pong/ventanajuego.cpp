#include "ventanajuego.h"
#include "ui_ventanajuego.h"

//%%%%%%%%%%%%%%%%%%% Constructores - destructor %%%%%%%%%%%%%%%%%%%

VentanaJuego::VentanaJuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaJuego),
    pixmap()

{
    ui->setupUi(this);

    connect(&temp, SIGNAL(timeout()), this, SLOT(actualizarPantalla()));
    temp.start(1000);

}

VentanaJuego::VentanaJuego(QMainWindow * _mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaJuego)
{
    ui->setupUi(this);

    mainWindow = _mainWindow;

    //init pixmap y pintar cancha
    QPixmap pixmapAux(ui->label->size());

    pixmap = pixmapAux;

    init_pixmap();

    connect(&temp, SIGNAL(timeout()), this, SLOT(actualizarPantalla()));
    temp.start(100);
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
        //ui->pts_p1->setValue(5);

        juego->imprimir_elementos(&pixmap);

        ui->label->setPixmap(pixmap);
    }
}


//%%%%%%%%%%%%%%%%%%% private functions %%%%%%%%%%%%%%%%%%%

void VentanaJuego::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);

    if (event->key() == Qt::Key_Escape) {
        this->close();
    }
    else {
        //ui->label->setText(ui->label->text() + event->text());
    }
}

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

