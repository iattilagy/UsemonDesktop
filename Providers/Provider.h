/* 
 * File:   Provider.h
 * Author: attila
 *
 * Created on 2015. március 29., 16:07
 */

#ifndef PROVIDER_H
#define	PROVIDER_H

#include "Id.h"
#include "Data.h"

class Provider {
public:
    Provider();
    Provider(const Provider& orig);
    virtual ~Provider();
    virtual void update(Data* data) = 0;

    const Id getId() {
        return *id;
    }
protected:
    Id *id;
};

#endif	/* PROVIDER_H */

