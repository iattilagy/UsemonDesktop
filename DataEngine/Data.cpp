/* 
 * File:   Data.cpp
 * Author: attila
 * 
 * Created on 2015. március 25., 19:58
 */

#include "Data.h"
#include <algorithm>
#include <vector>
#include <list> 
#include <QDebug>

/**
 * Inserts e into Data
 * @param e
 */
void Data::update(float e) {
    datas.push_back(e);
    if (datas.size() > size)
        datas.pop_front();
}

/**
 * @return Last element of the list
 */
float Data::getLastAdded() const {
    return datas.back();
}

/**
 * @return First element of the list
 */
float Data::getFirstAdded() const {
    return datas.front();
}

/**
 * Sets iterator to the start of the list
 */
void Data::resetIterator() const {
    iterator = datas.begin();
    //qDebug() << *iterator;
    last = false;
}

/**
 * Returns the element pointed by iterator and
 * increments iterator
 * @return Current element
 */
float Data::getNext() const {
    float d = *iterator;
    if (distance(iterator, datas.end()) == 1)
        last = true;
    ++iterator;

    return d;
}

/**
 * Returns true if iterator is overrun
 * @return 
 */
bool Data::isAfterLast() const {
    return last;
}
