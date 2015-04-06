/* 
 * File:   Id.h
 * Author: attila
 *
 * Created on 2015. március 25., 19:59
 */

#ifndef ID_H
#define	ID_H

class Id {
public:
    Id(const int p, const int s = 0) {
        primary = p;
        secondary = s;
    }

    Id(const Id& i) {
        this->primary = i.primary;
        this->secondary = i.secondary;
    }

    int GetPrimary() const {
        return primary;
    }

    int GetSecondary() const {
        return secondary;
    }

    virtual ~Id() {
    };

    friend bool operator==(const Id &id1, const Id &id2);
private:
    int primary;
    int secondary;
};

#endif	/* ID_H */

