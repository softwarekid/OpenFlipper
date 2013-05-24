/********************************************************************************
** Form generated from reading UI file 'QwtFunctionPlotBase.ui'
**
** Created: Sat May 18 02:56:34 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWTFUNCTIONPLOTBASE_H
#define UI_QWTFUNCTIONPLOTBASE_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_QwtFunctionPlotBase
{
public:
    QHBoxLayout *horizontalLayout;
    QwtPlot *qwtPlot;

    void setupUi(QWidget *QwtFunctionPlotBase)
    {
        if (QwtFunctionPlotBase->objectName().isEmpty())
            QwtFunctionPlotBase->setObjectName(QString::fromUtf8("QwtFunctionPlotBase"));
        QwtFunctionPlotBase->setWindowModality(Qt::NonModal);
        QwtFunctionPlotBase->resize(613, 474);
        horizontalLayout = new QHBoxLayout(QwtFunctionPlotBase);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        qwtPlot = new QwtPlot(QwtFunctionPlotBase);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));

        horizontalLayout->addWidget(qwtPlot);


        retranslateUi(QwtFunctionPlotBase);

        QMetaObject::connectSlotsByName(QwtFunctionPlotBase);
    } // setupUi

    void retranslateUi(QWidget *QwtFunctionPlotBase)
    {
        QwtFunctionPlotBase->setWindowTitle(QApplication::translate("QwtFunctionPlotBase", "Function Plot", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QwtFunctionPlotBase: public Ui_QwtFunctionPlotBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWTFUNCTIONPLOTBASE_H
