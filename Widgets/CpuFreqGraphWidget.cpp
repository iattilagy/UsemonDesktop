/* 
 * File:   CpuFreqGraphWidget.cpp
 * Author: attila
 * 
 * Created on 2015. április 6., 15:29
 */

#include "CpuFreqGraphWidget.h"
#include "CpuFreqProvider.h"
#include "GraphWidget.h"

#include <QColor>

/**
 * @param id Data type
 * @param c Graph color
 */
CpuFreqGraphWidget::CpuFreqGraphWidget(Id id, QColor c)
: GraphWidget(id, c, CpuFreqProvider::getMaxFreq()) {
}

/**
 * @param data Current value
 * @return String for graphwidget
 */
QString CpuFreqGraphWidget::getText(float data) {
    QString temp = "";
    temp.sprintf("cpu%d: %dMhz", id.GetSecondary(), int(data));
    return temp;
}

