# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = Usemon
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += DataEngine/Data.cpp DataEngine/DataSource.cpp DataEngine/Id.cpp MainForm.cpp Providers/CpuFreqProvider.cpp Providers/CpuProvider.cpp Providers/GpuProvider.cpp Providers/Provider.cpp Providers/RamProvider.cpp Widgets/CpuFreqGraphWidget.cpp Widgets/CpuGraphWidget.cpp Widgets/GraphWidget.cpp Widgets/RamGraphWidget.cpp main.cpp
HEADERS += DataEngine/Data.h DataEngine/DataSource.h DataEngine/Id.h MainForm.h Providers/CpuFreqProvider.h Providers/CpuProvider.h Providers/GpuProvider.h Providers/Provider.h Providers/RamProvider.h Widgets/CpuFreqGraphWidget.h Widgets/CpuGraphWidget.h Widgets/GraphWidget.h Widgets/RamGraphWidget.h
FORMS += MainForm.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
