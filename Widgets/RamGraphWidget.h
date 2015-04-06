/* 
 * File:   RamGraphWidget.h
 * Author: attila
 *
 * Created on 2015. április 6., 14:55
 */

#ifndef RAMGRAPHWIDGET_H
#define	RAMGRAPHWIDGET_H

#include "GraphWidget.h"

class RamGraphWidget : public GraphWidget{
    Q_OBJECT
public:
    RamGraphWidget(QColor c);
protected:
    QString getText(float data);
private:

};

#endif	/* RAMGRAPHWIDGET_H */

