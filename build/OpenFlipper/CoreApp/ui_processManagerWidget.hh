/********************************************************************************
** Form generated from reading UI file 'processManagerWidget.ui'
**
** Created: Sat May 18 02:52:48 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSMANAGERWIDGET_H
#define UI_PROCESSMANAGERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessManagerWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *processList;

    void setupUi(QWidget *ProcessManagerWidget)
    {
        if (ProcessManagerWidget->objectName().isEmpty())
            ProcessManagerWidget->setObjectName(QString::fromUtf8("ProcessManagerWidget"));
        ProcessManagerWidget->resize(570, 478);
        verticalLayout = new QVBoxLayout(ProcessManagerWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        processList = new QTableWidget(ProcessManagerWidget);
        if (processList->columnCount() < 4)
            processList->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        processList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        processList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        processList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        processList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        processList->setObjectName(QString::fromUtf8("processList"));
        processList->setMinimumSize(QSize(0, 200));
        processList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        processList->setProperty("showDropIndicator", QVariant(true));
        processList->setAlternatingRowColors(true);
        processList->setSelectionMode(QAbstractItemView::SingleSelection);
        processList->setSelectionBehavior(QAbstractItemView::SelectRows);
        processList->setTextElideMode(Qt::ElideRight);
        processList->setShowGrid(true);
        processList->setCornerButtonEnabled(false);
        processList->horizontalHeader()->setCascadingSectionResizes(true);
        processList->horizontalHeader()->setDefaultSectionSize(110);
        processList->horizontalHeader()->setStretchLastSection(true);
        processList->verticalHeader()->setVisible(true);
        processList->verticalHeader()->setCascadingSectionResizes(false);

        verticalLayout->addWidget(processList);


        retranslateUi(ProcessManagerWidget);

        QMetaObject::connectSlotsByName(ProcessManagerWidget);
    } // setupUi

    void retranslateUi(QWidget *ProcessManagerWidget)
    {
        ProcessManagerWidget->setWindowTitle(QApplication::translate("ProcessManagerWidget", "Process Manager Window", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = processList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ProcessManagerWidget", "Process", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = processList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ProcessManagerWidget", "Description", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = processList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ProcessManagerWidget", "Progress", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = processList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ProcessManagerWidget", "Controls", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProcessManagerWidget: public Ui_ProcessManagerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSMANAGERWIDGET_H
