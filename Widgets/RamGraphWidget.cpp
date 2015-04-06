/* 
 * File:   RamGraphWidget.cpp
 * Author: attila
 * 
 * Created on 2015. április 6., 14:55
 */

#include "RamGraphWidget.h"
#include "RamProvider.h"
#include "DataSource.h"
#include <QColor>
#include <QString>

RamGraphWidget::RamGraphWidget(QColor c) :
GraphWidget(DataSource::RAM, c, RamProvider::getRamTotal()) {
}

QString RamGraphWidget::getText(float data) {
    QString temp = "";
    temp.sprintf("%dMB", int(data / 1000));
    return temp;
}

