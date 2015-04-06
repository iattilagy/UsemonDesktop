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

void Data::update(float e) {
    datas.push_back(e);
    if (datas.size() > size)
        datas.pop_front();
}

float Data::getLastAdded() const {
    return datas.back();
}

float Data::getFirstAdded() const {
    return datas.front();
}

void Data::resetIterator() const {
    iterator = datas.begin();
    //qDebug() << *iterator;
    last = false;
}

float Data::getNext() const {
    float d = *iterator;
    if (distance(iterator, datas.end()) == 1)
        last = true;
    ++iterator;

    return d;
}

bool Data::isAfterLast() const {
    return last;
}
