/* 
 * File:   GpuProvider.h
 * Author: attila
 *
 * Created on 2015. április 5., 16:57
 */

#ifndef GPUPROVIDER_H
#define	GPUPROVIDER_H

#include "Provider.h"
#include <string>

class GpuProvider : public Provider{
public:
    GpuProvider();
    void update(Data * data);
private:    
    static std::string exec(const char* cmd);
};

#endif	/* GPUPROVIDER_H */

