/********************************************************************************
** Form generated from reading UI file 'QwtFunctionPlotBase.ui'
**
** Created: Sat May 18 02:59:27 2013
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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_QwtFunctionPlotBase
{
public:
    QHBoxLayout *horizontalLayout;
    QwtPlot *qwtPlot;
    QVBoxLayout *verticalLayout;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QPushButton *clampButton;
    QSpacerItem *verticalSpacer;

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

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        zoomInButton = new QPushButton(QwtFunctionPlotBase);
        zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));

        verticalLayout->addWidget(zoomInButton);

        zoomOutButton = new QPushButton(QwtFunctionPlotBase);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));

        verticalLayout->addWidget(zoomOutButton);

        clampButton = new QPushButton(QwtFunctionPlotBase);
        clampButton->setObjectName(QString::fromUtf8("clampButton"));

        verticalLayout->addWidget(clampButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(QwtFunctionPlotBase);

        QMetaObject::connectSlotsByName(QwtFunctionPlotBase);
    } // setupUi

    void retranslateUi(QWidget *QwtFunctionPlotBase)
    {
        QwtFunctionPlotBase->setWindowTitle(QApplication::translate("QwtFunctionPlotBase", "Function Plot", 0, QApplication::UnicodeUTF8));
        zoomInButton->setText(QApplication::translate("QwtFunctionPlotBase", "+", 0, QApplication::UnicodeUTF8));
        zoomOutButton->setText(QApplication::translate("QwtFunctionPlotBase", "-", 0, QApplication::UnicodeUTF8));
        clampButton->setText(QApplication::translate("QwtFunctionPlotBase", "C", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QwtFunctionPlotBase: public Ui_QwtFunctionPlotBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWTFUNCTIONPLOTBASE_H
