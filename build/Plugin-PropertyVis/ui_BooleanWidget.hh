/********************************************************************************
** Form generated from reading UI file 'BooleanWidget.ui'
**
** Created: Sat May 18 02:57:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOLEANWIDGET_H
#define UI_BOOLEANWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ACG/QtWidgets/QtColorChooserButton.hh"

QT_BEGIN_NAMESPACE

class Ui_BooleanWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *paramBool;
    QGridLayout *gridLayout_5;
    QtColorChooserButton *colorTrue;
    QtColorChooserButton *colorFalse;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *BooleanWidget)
    {
        if (BooleanWidget->objectName().isEmpty())
            BooleanWidget->setObjectName(QString::fromUtf8("BooleanWidget"));
        BooleanWidget->resize(454, 67);
        verticalLayout_7 = new QVBoxLayout(BooleanWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        paramBool = new QGroupBox(BooleanWidget);
        paramBool->setObjectName(QString::fromUtf8("paramBool"));
        gridLayout_5 = new QGridLayout(paramBool);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        colorTrue = new QtColorChooserButton(paramBool);
        colorTrue->setObjectName(QString::fromUtf8("colorTrue"));
        colorTrue->setProperty("color", QVariant(QColor(0, 255, 0)));

        gridLayout_5->addWidget(colorTrue, 0, 0, 1, 1);

        colorFalse = new QtColorChooserButton(paramBool);
        colorFalse->setObjectName(QString::fromUtf8("colorFalse"));
        colorFalse->setProperty("color", QVariant(QColor(255, 0, 0)));

        gridLayout_5->addWidget(colorFalse, 0, 1, 1, 1);


        verticalLayout_7->addWidget(paramBool);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        QWidget::setTabOrder(colorTrue, colorFalse);

        retranslateUi(BooleanWidget);

        QMetaObject::connectSlotsByName(BooleanWidget);
    } // setupUi

    void retranslateUi(QWidget *BooleanWidget)
    {
        BooleanWidget->setWindowTitle(QApplication::translate("BooleanWidget", "Property Visualization", 0, QApplication::UnicodeUTF8));
        paramBool->setTitle(QApplication::translate("BooleanWidget", "Bool Parameters", 0, QApplication::UnicodeUTF8));
        colorTrue->setText(QApplication::translate("BooleanWidget", "True color:", 0, QApplication::UnicodeUTF8));
        colorFalse->setText(QApplication::translate("BooleanWidget", "False color:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BooleanWidget: public Ui_BooleanWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOLEANWIDGET_H
