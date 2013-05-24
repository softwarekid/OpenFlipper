/********************************************************************************
** Form generated from reading UI file 'toolbox.ui'
**
** Created: Sat May 18 02:55:08 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBOX_H
#define UI_TOOLBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "TreeView.hh"

QT_BEGIN_NAMESPACE

class Ui_dctoolbox
{
public:
    QVBoxLayout *verticalLayout_3;
    DataControlTreeView *treeView;
    QPushButton *visibleDataBtn;
    QWidget *visibleDataWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *lightSources;
    QFrame *line_2;
    QPushButton *boundingBoxBtn;
    QWidget *boundingBoxWidget;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *notSelected;
    QCheckBox *sourceSelected;
    QCheckBox *targetSelected;

    void setupUi(QWidget *dctoolbox)
    {
        if (dctoolbox->objectName().isEmpty())
            dctoolbox->setObjectName(QString::fromUtf8("dctoolbox"));
        dctoolbox->resize(268, 456);
        verticalLayout_3 = new QVBoxLayout(dctoolbox);
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        treeView = new DataControlTreeView(dctoolbox);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setMinimumSize(QSize(0, 250));
        treeView->setContextMenuPolicy(Qt::CustomContextMenu);
        treeView->setAcceptDrops(true);
        treeView->setDragEnabled(true);
        treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_3->addWidget(treeView);

        visibleDataBtn = new QPushButton(dctoolbox);
        visibleDataBtn->setObjectName(QString::fromUtf8("visibleDataBtn"));
        visibleDataBtn->setCheckable(true);
        visibleDataBtn->setChecked(true);
        visibleDataBtn->setFlat(true);

        verticalLayout_3->addWidget(visibleDataBtn);

        visibleDataWidget = new QWidget(dctoolbox);
        visibleDataWidget->setObjectName(QString::fromUtf8("visibleDataWidget"));
        verticalLayout = new QVBoxLayout(visibleDataWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lightSources = new QCheckBox(visibleDataWidget);
        lightSources->setObjectName(QString::fromUtf8("lightSources"));

        verticalLayout->addWidget(lightSources);


        verticalLayout_3->addWidget(visibleDataWidget);

        line_2 = new QFrame(dctoolbox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        boundingBoxBtn = new QPushButton(dctoolbox);
        boundingBoxBtn->setObjectName(QString::fromUtf8("boundingBoxBtn"));
        boundingBoxBtn->setCheckable(true);
        boundingBoxBtn->setChecked(true);
        boundingBoxBtn->setFlat(true);

        verticalLayout_3->addWidget(boundingBoxBtn);

        boundingBoxWidget = new QWidget(dctoolbox);
        boundingBoxWidget->setObjectName(QString::fromUtf8("boundingBoxWidget"));
        verticalLayout_2 = new QVBoxLayout(boundingBoxWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        notSelected = new QCheckBox(boundingBoxWidget);
        notSelected->setObjectName(QString::fromUtf8("notSelected"));

        verticalLayout_2->addWidget(notSelected);

        sourceSelected = new QCheckBox(boundingBoxWidget);
        sourceSelected->setObjectName(QString::fromUtf8("sourceSelected"));

        verticalLayout_2->addWidget(sourceSelected);

        targetSelected = new QCheckBox(boundingBoxWidget);
        targetSelected->setObjectName(QString::fromUtf8("targetSelected"));

        verticalLayout_2->addWidget(targetSelected);


        verticalLayout_3->addWidget(boundingBoxWidget);


        retranslateUi(dctoolbox);
        QObject::connect(visibleDataBtn, SIGNAL(toggled(bool)), visibleDataWidget, SLOT(setVisible(bool)));
        QObject::connect(boundingBoxBtn, SIGNAL(toggled(bool)), boundingBoxWidget, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(dctoolbox);
    } // setupUi

    void retranslateUi(QWidget *dctoolbox)
    {
        dctoolbox->setWindowTitle(QApplication::translate("dctoolbox", "Form", 0, QApplication::UnicodeUTF8));
        visibleDataBtn->setText(QApplication::translate("dctoolbox", "Object Visibility", 0, QApplication::UnicodeUTF8));
        lightSources->setText(QApplication::translate("dctoolbox", "Show Light Sources", 0, QApplication::UnicodeUTF8));
        boundingBoxBtn->setText(QApplication::translate("dctoolbox", "Object Bounding Box", 0, QApplication::UnicodeUTF8));
        notSelected->setText(QApplication::translate("dctoolbox", "Show always", 0, QApplication::UnicodeUTF8));
        sourceSelected->setText(QApplication::translate("dctoolbox", "Show on source objects", 0, QApplication::UnicodeUTF8));
        targetSelected->setText(QApplication::translate("dctoolbox", "Show on target objects", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dctoolbox: public Ui_dctoolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
