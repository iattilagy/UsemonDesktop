/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *cpu;
    QVBoxLayout *cpuSumLayout;
    QVBoxLayout *cpuLayout;
    QHBoxLayout *cpuByCores;
    QVBoxLayout *cpuOdd;
    QVBoxLayout *cpuEven;
    QVBoxLayout *ramcpufreq;
    QVBoxLayout *ramLayout;
    QHBoxLayout *cpufreq;
    QVBoxLayout *cpuFreqEven;
    QVBoxLayout *cpuFreqOdd;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(650, 632);
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cpu = new QVBoxLayout();
        cpu->setObjectName(QString::fromUtf8("cpu"));
        cpuSumLayout = new QVBoxLayout();
        cpuSumLayout->setObjectName(QString::fromUtf8("cpuSumLayout"));

        cpu->addLayout(cpuSumLayout);

        cpuLayout = new QVBoxLayout();
        cpuLayout->setObjectName(QString::fromUtf8("cpuLayout"));
        cpuByCores = new QHBoxLayout();
        cpuByCores->setObjectName(QString::fromUtf8("cpuByCores"));
        cpuOdd = new QVBoxLayout();
        cpuOdd->setObjectName(QString::fromUtf8("cpuOdd"));

        cpuByCores->addLayout(cpuOdd);

        cpuEven = new QVBoxLayout();
        cpuEven->setObjectName(QString::fromUtf8("cpuEven"));

        cpuByCores->addLayout(cpuEven);


        cpuLayout->addLayout(cpuByCores);


        cpu->addLayout(cpuLayout);


        horizontalLayout->addLayout(cpu);

        ramcpufreq = new QVBoxLayout();
        ramcpufreq->setObjectName(QString::fromUtf8("ramcpufreq"));
        ramLayout = new QVBoxLayout();
        ramLayout->setObjectName(QString::fromUtf8("ramLayout"));

        ramcpufreq->addLayout(ramLayout);

        cpufreq = new QHBoxLayout();
        cpufreq->setObjectName(QString::fromUtf8("cpufreq"));
        cpuFreqEven = new QVBoxLayout();
        cpuFreqEven->setObjectName(QString::fromUtf8("cpuFreqEven"));

        cpufreq->addLayout(cpuFreqEven);

        cpuFreqOdd = new QVBoxLayout();
        cpuFreqOdd->setObjectName(QString::fromUtf8("cpuFreqOdd"));

        cpufreq->addLayout(cpuFreqOdd);


        ramcpufreq->addLayout(cpufreq);


        horizontalLayout->addLayout(ramcpufreq);

        MainForm->setCentralWidget(centralwidget);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "Usemon", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
