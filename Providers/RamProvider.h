/* 
 * File:   RamProvider.h
 * Author: attila
 *
 * Created on 2015. március 30., 21:16
 */

#ifndef RAMPROVIDER_H
#define	RAMPROVIDER_H

#include "Provider.h"

class RamProvider : public Provider{
public:
    RamProvider();
    static int getRamTotal();    
    void update(Data * data);
private:

};

#endif	/* RAMPROVIDER_H */

