#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // se agrega la escena
    scene = new QGraphicsScene(-500, -250, 1000, 500);
    ui->graphicsView->setScene(scene);

    /*ui->graphicsView->setRenderHint(QPainter::Antialiasing);*/

    // limites de la escena
    l1 = new QGraphicsLineItem(-500,-250,500,-250);
    l2 = new QGraphicsLineItem(-500,250,500,250);
    l3 = new QGraphicsLineItem(-500,-250,-500,250);
    l4 = new QGraphicsLineItem(500,-250,500,250);

    //SISTEMA 1
    /*
    cuerpo1 = new Cuerpo(0, -7000, 70, 120, 2, 0);
    cuerpo2 = new Cuerpo(0, 0, 70000, 300, 0, 0);
    cuerpo3 = new Cuerpo(4000, 5000, 25, 100, -1.6, 1.2);

    scene->addItem(cuerpo1);
    scene->addItem(cuerpo2);
    scene->addItem(cuerpo3);
    */

    //SISTEMA 2

    cuerpoB1 = new Cuerpo(0, 0, 50000, 200, 0, 0);
    cuerpoB2 = new Cuerpo(-5000, 0, 70, 70, 0, -2);
    cuerpoB3 = new Cuerpo(5000, 0, 70, 70, 0, 2);
    cuerpoB4 = new Cuerpo(0, -5000, 70, 70, 2, 0);
    cuerpoB5 = new Cuerpo(0, 5000, 70, 70, -2, 0);

    scene->addItem(cuerpoB1);
    scene->addItem(cuerpoB2);
    scene->addItem(cuerpoB3);
    scene->addItem(cuerpoB4);
    scene->addItem(cuerpoB5);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Actualizar()));
    timer->start(1000);
}

void MainWindow::Actualizar()
//Actualiza las velocidades y posiciones del cuerpo
{
    //SISTEMA 1
    /*
    cuerpo1->aceleracion(*cuerpo2);
    cuerpo1->aceleracion(*cuerpo3);
    cuerpo2->aceleracion(*cuerpo1);
    cuerpo2->aceleracion(*cuerpo3);
    cuerpo3->aceleracion(*cuerpo1);
    cuerpo3->aceleracion(*cuerpo2);

    cuerpo1->velocidades();
    cuerpo2->velocidades();
    cuerpo3->velocidades();

    cuerpo1->posiciones();
    cuerpo2->posiciones();
    cuerpo3->posiciones();
    */

    //SISTEMA 2

    cuerpoB1->aceleracion(*cuerpoB2);
    cuerpoB1->aceleracion(*cuerpoB3);
    cuerpoB1->aceleracion(*cuerpoB4);
    cuerpoB1->aceleracion(*cuerpoB5);

    cuerpoB2->aceleracion(*cuerpoB1);
    cuerpoB2->aceleracion(*cuerpoB3);
    cuerpoB2->aceleracion(*cuerpoB4);
    cuerpoB2->aceleracion(*cuerpoB5);

    cuerpoB3->aceleracion(*cuerpoB1);
    cuerpoB3->aceleracion(*cuerpoB2);
    cuerpoB3->aceleracion(*cuerpoB4);
    cuerpoB3->aceleracion(*cuerpoB5);

    cuerpoB4->aceleracion(*cuerpoB1);
    cuerpoB4->aceleracion(*cuerpoB2);
    cuerpoB4->aceleracion(*cuerpoB3);
    cuerpoB4->aceleracion(*cuerpoB5);

    cuerpoB5->aceleracion(*cuerpoB1);
    cuerpoB5->aceleracion(*cuerpoB2);
    cuerpoB5->aceleracion(*cuerpoB3);
    cuerpoB5->aceleracion(*cuerpoB4);

    cuerpoB1->velocidades();
    cuerpoB2->velocidades();
    cuerpoB3->velocidades();
    cuerpoB4->velocidades();
    cuerpoB5->velocidades();

    cuerpoB1->posiciones();
    cuerpoB2->posiciones();
    cuerpoB3->posiciones();
    cuerpoB4->posiciones();
    cuerpoB5->posiciones();

}

MainWindow::~MainWindow()
{
    delete ui;
}

