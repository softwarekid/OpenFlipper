/********************************************************************************
** Form generated from reading UI file 'SelectionTypeFrame.ui'
**
** Created: Sat May 18 03:02:37 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTIONTYPEFRAME_H
#define UI_SELECTIONTYPEFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectionTypeFrame
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *modeGroup;
    QGridLayout *gridLayout_3;
    QWidget *toolPrimitivesBar;
    QGroupBox *selectionGroup;
    QGridLayout *gridLayout;
    QWidget *toolOperationsWidget;

    void setupUi(QWidget *SelectionTypeFrame)
    {
        if (SelectionTypeFrame->objectName().isEmpty())
            SelectionTypeFrame->setObjectName(QString::fromUtf8("SelectionTypeFrame"));
        verticalLayout = new QVBoxLayout(SelectionTypeFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        modeGroup = new QGroupBox(SelectionTypeFrame);
        modeGroup->setObjectName(QString::fromUtf8("modeGroup"));
        gridLayout_3 = new QGridLayout(modeGroup);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        toolPrimitivesBar = new QWidget(modeGroup);
        toolPrimitivesBar->setObjectName(QString::fromUtf8("toolPrimitivesBar"));
        toolPrimitivesBar->setMinimumSize(QSize(0, 60));

        gridLayout_3->addWidget(toolPrimitivesBar, 0, 0, 1, 1);


        verticalLayout->addWidget(modeGroup);

        selectionGroup = new QGroupBox(SelectionTypeFrame);
        selectionGroup->setObjectName(QString::fromUtf8("selectionGroup"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectionGroup->sizePolicy().hasHeightForWidth());
        selectionGroup->setSizePolicy(sizePolicy);
        selectionGroup->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        gridLayout = new QGridLayout(selectionGroup);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        toolOperationsWidget = new QWidget(selectionGroup);
        toolOperationsWidget->setObjectName(QString::fromUtf8("toolOperationsWidget"));
        sizePolicy.setHeightForWidth(toolOperationsWidget->sizePolicy().hasHeightForWidth());
        toolOperationsWidget->setSizePolicy(sizePolicy);
        toolOperationsWidget->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(toolOperationsWidget, 0, 0, 1, 2);


        verticalLayout->addWidget(selectionGroup);


        retranslateUi(SelectionTypeFrame);

        QMetaObject::connectSlotsByName(SelectionTypeFrame);
    } // setupUi

    void retranslateUi(QWidget *SelectionTypeFrame)
    {
        SelectionTypeFrame->setWindowTitle(QApplication::translate("SelectionTypeFrame", "Form", 0, QApplication::UnicodeUTF8));
        modeGroup->setTitle(QApplication::translate("SelectionTypeFrame", " Selection Mode ", 0, QApplication::UnicodeUTF8));
        selectionGroup->setTitle(QApplication::translate("SelectionTypeFrame", " Selection ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectionTypeFrame: public Ui_SelectionTypeFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTIONTYPEFRAME_H
