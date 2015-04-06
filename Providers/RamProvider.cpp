/* 
 * File:   RamProvider.cpp
 * Author: attila
 * 
 * Created on 2015. március 30., 21:16
 */

#include <fstream>

#include "RamProvider.h"
#include "Id.h"
#include "DataSource.h"
#include <QApplication>
#include <QDebug>
#include <sstream>

RamProvider::RamProvider() {
    id = new Id(DataSource::RAM);
}

void RamProvider::update(Data* data) {
    ifstream infile("/proc/meminfo");
    
    if (!infile.is_open()) {
        perror("/proc/stat cannot be opened");
        QApplication::exit(1);
    }
    
    std::string line;
    int available; 
    /*MemAvailable should be used here, 
     *this is in 3rd line
     * Warning: this is not what free command
     * shows */
    
    //Ugly but faster than a for
    getline(infile, line);
    getline(infile, line);
    getline(infile, line);
    
    std::istringstream iss(line);
    iss.ignore(32, ' '); //'MemAvailable:' should be ignored
    iss >> available;
    data->update(getRamTotal()-((float)available)); 
    /*Used ram = data/total*/
}

/**
 * Returns total ram in kbytes
 * @return Total system ram in kbytes
 */
int RamProvider::getRamTotal() {
    ifstream infile("/proc/meminfo");
    /*First line of /proc/meminfo:
     * MemTotal: (amount) kb
     */
    
    if (!infile.is_open()) {
        perror("/proc/stat cannot be opened");
        QApplication::exit(1);
    }
    
    
    std::string line;
    int total;
    getline(infile, line); //We need the first line
    infile.close();
    std::istringstream iss(line);
    iss.ignore(32, ' '); //'MemTotal:' should be ignored
    iss >> total;
   
    return total;
}
