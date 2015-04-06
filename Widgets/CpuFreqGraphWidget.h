/* 
 * File:   CpuFreqGraphWidget.h
 * Author: attila
 *
 * Created on 2015. április 6., 15:29
 */

#ifndef CPUFREQGRAPHWIDGET_H
#define	CPUFREQGRAPHWIDGET_H

#include <GraphWidget.h>


class CpuFreqGraphWidget :public GraphWidget {
public:
    CpuFreqGraphWidget(Id id, QColor c);
protected:
    QString getText(float data);
private:

};

#endif	/* CPUFREQGRAPHWIDGET_H */

