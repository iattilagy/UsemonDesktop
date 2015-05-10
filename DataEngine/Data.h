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
    const static int size = 100; ///<Maximum size of the list

    /**
     * 
     * @param id
     */
    Data(Id id) : id(id) {
    }

    /**
     * 
     * @param orig
     */
    Data(const Data& orig) : id(orig.id) {
        this->datas = orig.datas;
    }

    virtual ~Data() {
    };

    /**
     * Returns Data's id
     * @return Id
     */
    Id getId() const {
        return id;
    }

    float getLastAdded() const;
    float getFirstAdded() const;

    /**
     * @return Real size of the list
     */
    int getRealSize() const {
        return datas.size();
    }

    void update(float e);

    void resetIterator() const;
    float getNext() const;
    bool isAfterLast() const;    
private:
    Id id; ///<Id sets datatype
    list<float> datas; ///<The list we store things in
    mutable list<float>::const_iterator iterator; ///<Iterator to get list elements
    mutable bool last; ///<Last is true if iterator is overrun
};

#endif	/* DATA_H */

