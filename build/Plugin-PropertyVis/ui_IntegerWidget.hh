/********************************************************************************
** Form generated from reading UI file 'IntegerWidget.ui'
**
** Created: Sat May 18 02:57:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTEGERWIDGET_H
#define UI_INTEGERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ACG/QtWidgets/QtColorChooserButton.hh"

QT_BEGIN_NAMESPACE

class Ui_IntegerWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *paramInt;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *intColorCoder;
    QHBoxLayout *horizontalLayout_13;
    QtColorChooserButton *intMin;
    QtColorChooserButton *intMax;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *intFixedRange;
    QDoubleSpinBox *intFixedRangeMin;
    QDoubleSpinBox *intFixedRangeMax;
    QCheckBox *intAbsolute;
    QCheckBox *intRandom;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *intMapBlack;
    QSpinBox *intMapBlackValue;

    void setupUi(QWidget *IntegerWidget)
    {
        if (IntegerWidget->objectName().isEmpty())
            IntegerWidget->setObjectName(QString::fromUtf8("IntegerWidget"));
        IntegerWidget->resize(387, 243);
        verticalLayout_7 = new QVBoxLayout(IntegerWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        paramInt = new QGroupBox(IntegerWidget);
        paramInt->setObjectName(QString::fromUtf8("paramInt"));
        verticalLayout_3 = new QVBoxLayout(paramInt);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        intColorCoder = new QCheckBox(paramInt);
        intColorCoder->setObjectName(QString::fromUtf8("intColorCoder"));
        intColorCoder->setChecked(true);

        verticalLayout_3->addWidget(intColorCoder);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        intMin = new QtColorChooserButton(paramInt);
        intMin->setObjectName(QString::fromUtf8("intMin"));
        intMin->setEnabled(false);
        intMin->setProperty("color", QVariant(QColor(0, 0, 255)));

        horizontalLayout_13->addWidget(intMin);

        intMax = new QtColorChooserButton(paramInt);
        intMax->setObjectName(QString::fromUtf8("intMax"));
        intMax->setEnabled(false);
        intMax->setProperty("color", QVariant(QColor(255, 0, 0)));

        horizontalLayout_13->addWidget(intMax);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        intFixedRange = new QCheckBox(paramInt);
        intFixedRange->setObjectName(QString::fromUtf8("intFixedRange"));

        horizontalLayout_4->addWidget(intFixedRange);

        intFixedRangeMin = new QDoubleSpinBox(paramInt);
        intFixedRangeMin->setObjectName(QString::fromUtf8("intFixedRangeMin"));
        intFixedRangeMin->setDecimals(0);
        intFixedRangeMin->setMinimum(-1e+09);
        intFixedRangeMin->setMaximum(1e+09);

        horizontalLayout_4->addWidget(intFixedRangeMin);

        intFixedRangeMax = new QDoubleSpinBox(paramInt);
        intFixedRangeMax->setObjectName(QString::fromUtf8("intFixedRangeMax"));
        intFixedRangeMax->setDecimals(0);
        intFixedRangeMax->setMinimum(-1e+09);
        intFixedRangeMax->setMaximum(1e+09);
        intFixedRangeMax->setValue(1);

        horizontalLayout_4->addWidget(intFixedRangeMax);


        verticalLayout_3->addLayout(horizontalLayout_4);

        intAbsolute = new QCheckBox(paramInt);
        intAbsolute->setObjectName(QString::fromUtf8("intAbsolute"));

        verticalLayout_3->addWidget(intAbsolute);

        intRandom = new QCheckBox(paramInt);
        intRandom->setObjectName(QString::fromUtf8("intRandom"));
        intRandom->setEnabled(false);

        verticalLayout_3->addWidget(intRandom);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        intMapBlack = new QCheckBox(paramInt);
        intMapBlack->setObjectName(QString::fromUtf8("intMapBlack"));
        intMapBlack->setEnabled(false);
        intMapBlack->setChecked(true);

        horizontalLayout_2->addWidget(intMapBlack);

        intMapBlackValue = new QSpinBox(paramInt);
        intMapBlackValue->setObjectName(QString::fromUtf8("intMapBlackValue"));
        intMapBlackValue->setEnabled(false);
        intMapBlackValue->setMinimum(-100);
        intMapBlackValue->setMaximum(100);
        intMapBlackValue->setValue(-1);

        horizontalLayout_2->addWidget(intMapBlackValue);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_7->addWidget(paramInt);

        QWidget::setTabOrder(intFixedRange, intFixedRangeMin);
        QWidget::setTabOrder(intFixedRangeMin, intFixedRangeMax);
        QWidget::setTabOrder(intFixedRangeMax, intAbsolute);
        QWidget::setTabOrder(intAbsolute, intRandom);
        QWidget::setTabOrder(intRandom, intMapBlack);
        QWidget::setTabOrder(intMapBlack, intMapBlackValue);

        retranslateUi(IntegerWidget);
        QObject::connect(intRandom, SIGNAL(toggled(bool)), intMin, SLOT(setDisabled(bool)));
        QObject::connect(intRandom, SIGNAL(toggled(bool)), intMax, SLOT(setDisabled(bool)));
        QObject::connect(intRandom, SIGNAL(toggled(bool)), intMapBlack, SLOT(setEnabled(bool)));
        QObject::connect(intRandom, SIGNAL(toggled(bool)), intMapBlackValue, SLOT(setEnabled(bool)));
        QObject::connect(intColorCoder, SIGNAL(toggled(bool)), intMin, SLOT(setDisabled(bool)));
        QObject::connect(intColorCoder, SIGNAL(toggled(bool)), intMax, SLOT(setDisabled(bool)));
        QObject::connect(intColorCoder, SIGNAL(toggled(bool)), intRandom, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(IntegerWidget);
    } // setupUi

    void retranslateUi(QWidget *IntegerWidget)
    {
        IntegerWidget->setWindowTitle(QApplication::translate("IntegerWidget", "Property Visualization", 0, QApplication::UnicodeUTF8));
        paramInt->setTitle(QApplication::translate("IntegerWidget", "Integer Parameters", 0, QApplication::UnicodeUTF8));
        intColorCoder->setText(QApplication::translate("IntegerWidget", "Use color coder", 0, QApplication::UnicodeUTF8));
        intMin->setText(QApplication::translate("IntegerWidget", "Min Col.: ", 0, QApplication::UnicodeUTF8));
        intMax->setText(QApplication::translate("IntegerWidget", "Max Col.: ", 0, QApplication::UnicodeUTF8));
        intFixedRange->setText(QApplication::translate("IntegerWidget", "Fixed Range", 0, QApplication::UnicodeUTF8));
        intAbsolute->setText(QApplication::translate("IntegerWidget", "Use absolute values", 0, QApplication::UnicodeUTF8));
        intRandom->setText(QApplication::translate("IntegerWidget", "Use random colors", 0, QApplication::UnicodeUTF8));
        intMapBlack->setText(QApplication::translate("IntegerWidget", "Map value to black", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IntegerWidget: public Ui_IntegerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTEGERWIDGET_H
