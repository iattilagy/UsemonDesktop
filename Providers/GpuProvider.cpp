/* 
 * File:   GpuProvider.cpp
 * Author: attila
 * 
 * Created on 2015. április 5., 16:57
 */

#include "GpuProvider.h"
#include "DataSource.h"

GpuProvider::GpuProvider() {
    id = new Id(DataSource::GPU);
}

