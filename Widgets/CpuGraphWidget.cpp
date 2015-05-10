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

/**
 * Works for GPU too
 * @param data Current value
 * @return Percent formatted value
 */
QString CpuGraphWidget::getText(float data) {
    QString temp = "";
    if (id.GetPrimary() == DataSource::CPUSUM) {
        temp.sprintf("%d%%", int(data * 100));
    } else if (id.GetPrimary() == DataSource::GPU) {
        if (data > 0) {
            temp.sprintf("gpu: %d%%", int(data * 100));
        } else {
            temp.sprintf("gpu: 2D");
        }
    } else {
        temp.sprintf("cpu%d: %d%%", id.GetSecondary(), int(data * 100));
    }
    return temp;
}