/* 
 * File:   CpuProvider.h
 * Author: attila
 *
 * Created on 2015. március 29., 16:09
 */

#ifndef CPUPROVIDER_H
#define	CPUPROVIDER_H

#include "Provider.h"
#include "DataSource.h"

class CpuProvider : public Provider {
public:
    CpuProvider(int core = -1);
    void update(Data * data);
    static int getNumberOfCores();
private:
    int lastuse;
    int lasttotal;
    float getUsage(int lineum = 0);
};

#endif	/* CPUPROVIDER_H */

