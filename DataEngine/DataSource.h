/* 
 * File:   DataSource.h
 * Author: attila
 *
 * Created on 2015. március 25., 19:54
 */

#ifndef DATASOURCE_H
#define	DATASOURCE_H

#include <string>
#include <vector>
#include "Data.h"
#include "Provider.h"


using namespace std;

class DataSource {
public:
    const static int EMPTY = -1;
    const static int CPUSUM = 0;
    const static int CPU = 6;
    const static int CPU_FREQ = 1;
    const static int RAM = 2;
    const static int GPU = 3;
    const static int GPU_FREQ = 4;
    const static int GPU_RAM_FREQ = 5;


    DataSource();
    DataSource(const DataSource& orig);
    virtual ~DataSource();

    bool addProvider(Provider * const p);

    const Data* getData(const Id& id, bool create = false);
    bool exportToCsv(string filename);
    void update();
private:
    vector<Data> store; //<Vector that stores Data elements
    vector<Provider*> providers; //<Store of Providers
    bool addData(Id id);
    Data* getDataPrivate(const Id& id, bool create = false);
};

#endif	/* DATASOURCE_H */

