/* 
 * File:   MainForm.h
 * Author: attila
 *
 * Created on 2015. március 22., 11:37
 */

#ifndef _MAINFORM_H
#define	_MAINFORM_H

#include "ui_MainForm.h"
#include <QTimer>
#include "DataSource.h"
#include "GraphWidget.h"

class MainForm : public QMainWindow {
    Q_OBJECT
public:
    MainForm();
    virtual ~MainForm();
private:
    Ui::MainForm widget;
    QTimer *timer;
    DataSource *source;
    vector<GraphWidget*> graphs;

private slots:
    void updateData();
};

#endif	/* _MAINFORM_H */
