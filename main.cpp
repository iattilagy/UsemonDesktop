/*
 * File:   main.cpp
 * Author: attila
 *
 * Created on 2015. március 22., 11:36
 */

#include <QApplication>
#include "MainForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    MainForm m;
    m.show();

    // create and show your widgets here

    return app.exec();
}
