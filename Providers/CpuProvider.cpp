/* 
 * File:   CpuProvider.cpp
 * Author: attila
 * 
 * Created on 2015. március 29., 16:09
 */

#include <QtCore/qcoreapplication.h>

#include "CpuProvider.h"
#include <fstream>
#include <iostream>
#include <QApplication>
#include <sstream>
#include <unistd.h>
#include <QDebug>

/**
 * Implementation of Provider interface
 * @param data Data to update
 */
void CpuProvider::update(Data *data) {
    if (id->GetPrimary() == DataSource::CPUSUM) {
        data->update(getUsage());
    } else {
        data->update(getUsage(id->GetSecondary() + 1));
    }
}

/**
 * @param core Core id (use -1 for summarized)
 */
CpuProvider::CpuProvider(int core) {
    if (core == -1) {
        id = new Id(DataSource::CPUSUM);
    } else {
        id = new Id(DataSource::CPU, core);
    }
    lastuse = 0;
    lasttotal = 0;
}

/**
 * @param linenum 0th line is sum, 1st is cpu0, 2nd cpu1 etc.
 * @return CPU usage (1 means 100%, 0 means 0%)
 */
float CpuProvider::getUsage(int linenum) {
    ifstream infile("/proc/stat");
    int u1, u2, u3, t;

    if (!infile.is_open()) {
        perror("/proc/stat cannot be opened");
        return 0;
    }

    for (std::string line; getline(infile, line) && linenum >= 0; linenum--) {
        if (linenum == 0) {
            std::istringstream iss(line);
            iss.ignore(5, ' ');
            iss >> u1 >> u2 >> u3 >> t;
        }
    }



    int useint = u1 + u2 + u3;
    float usage = (float) (useint - lastuse) / (t - lasttotal);

    /*This is the first run, no previous data available, 0 is returned
     *Calculated value would be avarage usage since boot up
     */
    if (lastuse == 0 && lasttotal == 0)
        usage = 0;

    lastuse = useint;
    lasttotal = t;

    return usage;
}

/**
 * @return Number of cpu threads (with HT corenum*2)
 */
int CpuProvider::getNumberOfCores() {
    return sysconf(_SC_NPROCESSORS_ONLN);
}


