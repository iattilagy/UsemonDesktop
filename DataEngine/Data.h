/* 
 * File:   Data.h
 * Author: attila
 *
 * Created on 2015. március 25., 19:58
 */

#ifndef DATA_H
#define	DATA_H

#include "Id.h"
#include <list>
using namespace std;

class Data {
public:
    const static int size = 100;

    Data(Id id) : id(id) {
    }

    Data(const Data& orig) : id(orig.id) {
        this->datas = orig.datas;
    }

    virtual ~Data() {
    };

    Id getId() const {
        return id;
    }

    float getLastAdded() const;
    float getFirstAdded() const;

    int getRealSize() const {
        return datas.size();
    }

    void update(float e);

    void resetIterator() const;
    float getNext() const;
    bool isAfterLast() const;    
private:
    Id id;
    list<float> datas;
    mutable list<float>::const_iterator iterator;
    mutable bool last;
};

#endif	/* DATA_H */

