#include "drawwidget.h"
#include <QtGui>
#include <QPen>

drawwidget::drawwidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix=new QPixmap(size());
    pix->fill(Qt::white);
    setMinimumSize(600,400);

}

void drawwidget::mousePressEvent(QMouseEvent *e)
{
    startPos = e->pos();
}

void drawwidget::mouseMoveEvent(QMouseEvent *e)
{
    QPainter *painter = new QPainter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(weight);
    pen.setColor(color);
    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startPos,e->pos());
    painter->end();
    startPos = e->pos();
    update();
}

void drawwidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}





void drawwidget::resizeEvent(QResizeEvent *event)
{
    if(height()>pix->height()||width()>pix->width())
    {
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}

void drawwidget::setStyle(int s)
{
    style =s;
}

void drawwidget::setWidth(int w)
{
    weight =w;
}

void drawwidget::setColor(QColor c)
{
    color = c;
}

void drawwidget::clear()
{
    QPixmap *clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    pix=clearPix;
    update();
}
