/* 
 * File:   Id.cpp
 * Author: attila
 * 
 * Created on 2015. március 25., 19:59
 */

#include "Id.h"

/**
 * Compares two id's
 * @param id1
 * @param id2
 * @return 
 */
bool operator==(const Id &id1, const Id &id2) {
    return id1.primary == id2.primary && id1.secondary == id2.secondary;
}

