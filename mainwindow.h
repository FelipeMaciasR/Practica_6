#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QTimer>
#include <cuerpo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // puntero de mi escena
    QGraphicsScene *scene;

    // temporizador para el pulso
    QTimer *timer;

    //limites
    QGraphicsLineItem *l1;
    QGraphicsLineItem *l2;
    QGraphicsLineItem *l3;
    QGraphicsLineItem *l4;

    Cuerpo* cuerpo1;
    Cuerpo* cuerpo2;
    Cuerpo* cuerpo3;

    Cuerpo* cuerpoB1;
    Cuerpo* cuerpoB2;
    Cuerpo* cuerpoB3;
    Cuerpo* cuerpoB4;
    Cuerpo* cuerpoB5;


public slots:
    void Actualizar();

};
#endif // MAINWINDOW_H
