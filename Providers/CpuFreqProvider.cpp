/* 
 * File:   CpuFreqProvider.cpp
 * Author: attila
 * 
 * Created on 2015. április 5., 17:37
 */

#include "CpuFreqProvider.h"
#include "DataSource.h"
#include "string"
#include "sstream"
#include <fstream>
#include <QApplication>

using namespace std;

/**
 * 
 * @param core Core id
 */
CpuFreqProvider::CpuFreqProvider(int core) {
    id = new Id(DataSource::CPU_FREQ, core);
}


/**
 * Value in data will be in Mhz
 * @param data Data to update
 */
void CpuFreqProvider::update(Data* data) {
    ostringstream ss;
    ss << "/sys/devices/system/cpu/cpu" << id->GetSecondary()
            << "/cpufreq/scaling_cur_freq";
    ifstream infile(ss.str().c_str());
    
    if (!infile.is_open()) {
        ss <<" cannot be opened";
        perror(ss.str().c_str());
        QApplication::exit(1);
    }
    
    int freq;
    infile >> freq;
    data->update(freq/1000);    
}

/**
 * @return Maximum cpu frequency in Mhz
 */
float CpuFreqProvider::getMaxFreq(){
    ifstream infile("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq");
    if (!infile.is_open()) {
        perror("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq cannot be opened");
        QApplication::exit(1);
    }
    
    float freq;
    infile >> freq;
    return freq/1000;
}

