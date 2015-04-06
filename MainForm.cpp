/*
 * File:   MainForm.cpp
 * Author: attila
 *
 * Created on 2015. március 22., 11:37
 */

#include "MainForm.h"
#include "DataSource.h"
#include "CpuProvider.h"
#include "CpuFreqProvider.h"
#include "RamProvider.h"
#include "Widgets/GraphWidget.h"
#include "CpuGraphWidget.h"
#include "CpuFreqGraphWidget.h"
#include "RamGraphWidget.h"
#include <QDebug>

MainForm::MainForm() {
    widget.setupUi(this);
    GraphWidget *g = new CpuGraphWidget(DataSource::CPUSUM, QColor(0xFF, 0x98, 0x08, 0xff));
    g->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    g->setMaximumHeight(250);
    graphs.push_back(g);
    widget.cpuSumLayout->addWidget(g, 0);

    g = new RamGraphWidget(Qt::red);
    g->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    g->setMaximumHeight(250);
    graphs.push_back(g);
    widget.ramcpufreq->addWidget(g, 0);

    qDebug() << CpuProvider::getNumberOfCores();
    for (int i = 0; i < CpuProvider::getNumberOfCores(); i++) {
        Id id(DataSource::CPU, i);
        g = new CpuGraphWidget(id, QColor(0xFF, 0x98, 0x08, 0xff));
        g->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        if (i % 2 == 0) {
            widget.cpuEven->addWidget(g);
        } else {
            widget.cpuOdd->addWidget(g);
        }
        graphs.push_back(g);

        Id idfreq(DataSource::CPU_FREQ, i);
        g = new CpuFreqGraphWidget(idfreq, Qt::white);
        g->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        if (i % 2 == 0) {
            widget.cpuFreqEven->addWidget(g);
        } else {
            widget.cpuFreqOdd->addWidget(g);
        }
        graphs.push_back(g);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateData()));
    timer->setInterval(1000);
    timer->start();

    source = new DataSource();
    source->addProvider(new CpuProvider());
    source->addProvider(new RamProvider());
    for (int i = 0; i < CpuProvider::getNumberOfCores(); i++) {
        source->addProvider(new CpuProvider(i));
    }
    for (int i = 0; i < CpuProvider::getNumberOfCores(); i++) {
        source->addProvider(new CpuFreqProvider(i));
    }

}

MainForm::~MainForm() {
    delete timer;
    delete source;
    graphs.clear();
}

void MainForm::updateData() {
    source->update();
    for (unsigned int i = 0; i < graphs.size(); i++) {
        graphs[i]->setData(source->getData(graphs[i]->getId()));
    }

    this->update();
}


