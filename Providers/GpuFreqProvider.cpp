/* 
 * File:   GpuFreqProvider.cpp
 * Author: attila
 * 
 * Created on 2015. április 5., 17:37
 */

#include "GpuFreqProvider.h"
#include "DataSource.h"

GpuFreqProvider::GpuFreqProvider() {
    id = new Id(DataSource::GPU_FREQ);
}

