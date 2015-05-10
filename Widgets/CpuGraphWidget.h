/* 
 * File:   CpuGraphWidget.h
 * Author: attila
 *
 * Created on 2015. április 6., 12:27
 */

#ifndef CPUGRAPHWIDGET_H
#define	CPUGRAPHWIDGET_H

#include "GraphWidget.h"

/**
 * Also works as GpuGraphWidget
 */
class CpuGraphWidget : public GraphWidget {
    Q_OBJECT
public:
    CpuGraphWidget(Id id,QColor c);
protected:
    QString getText(float data);
private:

};

#endif	/* CPUGRAPHWIDGET_H */

