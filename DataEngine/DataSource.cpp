/* 
 * File:   DataSource.cpp
 * Author: attila
 * 
 * Created on 2015. március 25., 19:54
 */

#include "DataSource.h"
#include "Provider.h"

DataSource::DataSource() {
}

DataSource::~DataSource() {
    store.clear();
    providers.clear();
}

bool DataSource::addProvider(Provider * p) {
    for (unsigned int i = 0; i < providers.size(); i++) {
        if (providers[i]->getId() == p->getId())
            return false;
    }
    providers.push_back(p);
    return true;
}

Data* DataSource::getDataPrivate(const Id& id, bool create) {
    for (unsigned int i = 0; i < store.size(); i++) {
        if (store[i].getId() == id)
            return &store[i];
    }
    
    if (!create)
        return new Data(DataSource::EMPTY);
    else {
        addData(id);
        return &store[store.size() - 1];
    }
}

const Data* DataSource::getData(const Id& id, bool create) {
    for (unsigned int i = 0; i < store.size(); i++) {
        if (store[i].getId() == id)
            return &store[i];
    }
    
    if (!create)
        return new Data(DataSource::EMPTY);
    else {
        addData(id);
        return &store[store.size() - 1];
    }
}

bool DataSource::addData(Id id) {
    for (unsigned int i = 0; i < store.size(); i++) {
        if (store[i].getId() == id)
            return false;
    }
    Data a(id);
    store.push_back(a);
    return true;
}

void DataSource::update() {
    for (unsigned int i = 0; i < providers.size(); i++) {
        providers[i]->update(getDataPrivate(providers[i]->getId(),true));
    }
}
