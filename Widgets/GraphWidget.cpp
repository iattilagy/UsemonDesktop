/* 
 * File:   GraphWidget.cpp
 * Author: attila
 * 
 * Created on 2015. április 5., 19:16
 */

#include "GraphWidget.h"

#include <QPainter>
#include <QDebug>

/**
 * @param id Data id
 * @param c Graph color
 * @param divider Data is being divided by this (defaults to 1)
 */
GraphWidget::GraphWidget(Id id, QColor c, float divider) : id(id), color(c), divider(divider) {
    data = NULL;
}

/**
 * Overridden paintEvent to draw the graph
 * @param 
 */
void GraphWidget::paintEvent(QPaintEvent*) {

    //Set up painter
    float w = width();
    float h = height();
    QPainter painter(this);
    painter.setPen(color);
    painter.setRenderHint(QPainter::Antialiasing);

    //Draw the graph path
    if (data) {
        QPainterPath pathuse;
        float startpoint = w / Data::size * (Data::size - data->getRealSize());
        pathuse.moveTo(startpoint, h);

        int i = 0;
        data->resetIterator();
        for (; !data->isAfterLast(); i++) {
            pathuse.lineTo(w / Data::size * ((Data::size - data->getRealSize()) + i + 1),
                    h - (data->getNext() / divider * h));
        }
        pathuse.lineTo(w, h);
        pathuse.moveTo(startpoint, h);
        pathuse.moveTo(startpoint,
                h - (data->getFirstAdded() / divider * h));

        QColor trans = color;
        trans.setAlpha(50);
        painter.setBrush(trans);
        painter.drawPath(pathuse);
    }


    if (h >= textMinHeight) {
        QColor blacktrans = Qt::black; //Drawing black rectangle for text
        blacktrans.setAlpha(100);
        painter.setBrush(blacktrans);
        painter.setPen(blacktrans);
        float textwidth = textRectPlusWidth;
        if (data)
            textwidth += painter.fontMetrics().width(getText(data->getLastAdded()));
        painter.drawRoundedRect(w / 2 - textwidth / 2, h - textRectFromBottom,
                textwidth, textRectHeight, textRectCurve, textRectCurve);

        painter.setPen(Qt::lightGray); //Drawing the usage into the black rectangle
        if (data) painter.drawText(w / 2 - textwidth / 2,
                h - textRectFromBottom, textwidth, textRectHeight,
                Qt::AlignCenter, getText(data->getLastAdded()), 0);
    }

    QPen pen(color); //Drawing borders
    pen.setWidth(BorderWidth);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(0, 0, w, h, BorderCurve, BorderCurve);
}