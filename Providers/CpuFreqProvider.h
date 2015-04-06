/* 
 * File:   CpuFreqProvider.h
 * Author: attila
 *
 * Created on 2015. április 5., 17:37
 */

#ifndef CPUFREQPROVIDER_H
#define	CPUFREQPROVIDER_H

#include "Provider.h"

class CpuFreqProvider : public Provider{
public:
    CpuFreqProvider(int core);    
    void update(Data * data);
    static float getMaxFreq();
private:

};

#endif	/* CPUFREQPROVIDER_H */

