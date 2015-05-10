/* 
 * File:   GpuProvider.cpp
 * Author: attila
 * 
 * Created on 2015. április 5., 16:57
 */

#include "GpuProvider.h"
#include "DataSource.h"

#include <string>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <QDebug>

GpuProvider::GpuProvider() {
    id = new Id(DataSource::GPU);
}

/**
 * @param data Data to update
 */
void GpuProvider::update(Data* data) {
    float usage = 0;
    std::string out = exec("aticonfig --odgc --odgt |grep 'GPU load'");
    std::istringstream iss(out);
    iss >>out;
    iss >>out;
    iss >>out;
    iss >>usage;
    usage/=100;
    data->update(usage);
}

/**
 * Executes a command and returns it's output
 * @param cmd System command to execute
 * @return Output string
 */
std::string GpuProvider::exec(const char* const cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}
