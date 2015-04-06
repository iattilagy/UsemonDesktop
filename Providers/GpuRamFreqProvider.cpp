/* 
 * File:   GpuRamFreqProvider.cpp
 * Author: attila
 * 
 * Created on 2015. április 5., 18:06
 */

#include "GpuRamFreqProvider.h"
#include "DataSource.h"
#include "Id.h"

GpuRamFreqProvider::GpuRamFreqProvider() {
    id = new Id(DataSource::GPU_RAM_FREQ);
}

