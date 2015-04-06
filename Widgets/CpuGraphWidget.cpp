/* 
 * File:   CpuGraphWidget.cpp
 * Author: attila
 * 
 * Created on 2015. április 6., 12:27
 */

#include "CpuGraphWidget.h"
#include "DataSource.h"

CpuGraphWidget::CpuGraphWidget(Id id, QColor c) : GraphWidget(id, c) {
}

QString CpuGraphWidget::getText(float data) {
    QString temp = "";
    if (id.GetPrimary() == DataSource::CPUSUM) {
        temp.sprintf("%d%%", int(data * 100));
    } else{
        temp.sprintf("cpu%d: %d%%",id.GetSecondary(), int(data * 100));
    }
    return temp;
}