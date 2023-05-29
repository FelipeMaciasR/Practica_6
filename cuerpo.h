#ifndef CUERPO_H
#define CUERPO_H

#define EX 300
#define EY 600

#define G 1
#define DT 1

#include <QGraphicsItem>
#include <QPainter>
#include <cmath>
#include <iostream>
#include <QDebug>

using namespace std;


class Cuerpo : public QGraphicsItem
{
public:
    Cuerpo();
    Cuerpo(float _x, float _y, float _masa, float _rad, float _vx, float _vy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float x;
    float y;
    float vx;
    float vy;
    float radio;
    float masa;
    float ax=0;
    float ay=0;
    void aceleracion(const Cuerpo& c);
    void velocidades();
    void posiciones();
    float getX() const;
    void setX(float newX);
    float getY() const;
    void setY(float newY);
    float getVx() const;
    void setVx(float newVx);
    float getVy() const;
    void setVy(float newVy);
    float getRadio() const;
    void setRadio(float newRadio);
    float getMasa() const;
    void setMasa(float newMasa);
};

#endif // CUERPO_H
