#include "cuerpo.h"

Cuerpo::Cuerpo()
{

}
Cuerpo::Cuerpo(float _x, float _y, float _masa, float _rad, float _vx, float _vy)
{
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
    radio = _rad;
    masa = _masa;
    setPos((x/EX), (-y/EY));
}

QRectF Cuerpo::boundingRect() const
{
    return QRect(-radio, -radio, radio*2, radio*2);
}

void Cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

void Cuerpo::aceleracion(const Cuerpo &c)
{

    this->ax=(G*c.getMasa()/(pow(c.getX()-this->x,2)+pow(c.getY()-this->y,2)))*cos(atan((c.getY()-this->y)/(c.getX()-this->x)));
    this->ay=(G*c.getMasa()/(pow(c.getX()-this->x,2)+pow(c.getY()-this->y,2)))*sin(atan((c.getY()-this->y)/(c.getX()-this->x)));
    //qDebug()<<ax<<ay;
}

void Cuerpo::velocidades()
// calcula las velocidades
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);
    //qDebug()<<vx<<vy;
}

void Cuerpo::posiciones()
// calcula y Actualiza las posiciones
{
    x = x + (vx * DT) + (0.5 * ax * pow(DT,2));
    y = y + (vy * DT) + (0.5 * ay * pow(DT,2));

    //ajustando los cuadrantes
    setPos((x/EX), (-y/EY));

    qDebug()<<x<<y;
}

float Cuerpo::getMasa() const
{
    return masa;
}

void Cuerpo::setMasa(float newMasa)
{
    masa = newMasa;
}

float Cuerpo::getRadio() const
{
    return radio;
}

void Cuerpo::setRadio(float newRadio)
{
    radio = newRadio;
}

float Cuerpo::getVy() const
{
    return vy;
}

void Cuerpo::setVy(float newVy)
{
    vy = newVy;
}

float Cuerpo::getVx() const
{
    return vx;
}

void Cuerpo::setVx(float newVx)
{
    vx = newVx;
}

float Cuerpo::getY() const
{
    return y;
}

void Cuerpo::setY(float newY)
{
    y = newY;
}

float Cuerpo::getX() const
{
    return x;
}

void Cuerpo::setX(float newX)
{
    x = newX;
}
