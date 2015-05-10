/* 
 * File:   GraphWidget.h
 * Author: attila
 *
 * Created on 2015. április 5., 19:16
 */

#ifndef GRAPHWIDGET_H
#define	GRAPHWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QColor>
#include <QString>
#include "Data.h"

class GraphWidget : public QWidget {
    Q_OBJECT
        public:
            const static float textRectPlusWidth = 6.0;
    const static float textRectHeight = 20.0;
    const static float textRectCurve = 2.0;
    const static float textRectFromBottom = 30.0;
    const static float BorderCurve = 5.0;
    const static float BorderWidth = 1.0;
    const static float textMinHeight = 40.0;

    explicit GraphWidget(QWidget *parent = 0);
    GraphWidget(Id id, QColor c, float divider = 1);
    GraphWidget(const GraphWidget& orig);

    ~GraphWidget() {

    }

    /**
     * @param data Data to GraphWidget
     */
    void setData(const Data *data) {
        this->data = data;
        data->resetIterator();
    }

    /**
     * @return GraphWidget's id
     */
    const Id getId() const {
        return id;
    }
protected:
    void paintEvent(QPaintEvent*);
    /**
     * Defined in custom classes for data types
     * @param data Data to make string from
     * @return Custom formatted string for data type
     */
    virtual QString getText(float data) = 0;
    const Id id;

private:
    const QColor color; //<Color of the graph
    const float divider; //<Data is being divided by that for drawing
    const Data *data; //<Data to read from
    void parseData(int i); 
};

#endif	/* GRAPHWIDGET_H */

