/********************************************************************************
** Form generated from reading UI file 'DoubleWidget.ui'
**
** Created: Sat May 18 02:57:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLEWIDGET_H
#define UI_DOUBLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ACG/QtWidgets/QtColorChooserButton.hh"

QT_BEGIN_NAMESPACE

class Ui_DoubleWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *paramDouble;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *doubleColorCoder;
    QHBoxLayout *horizontalLayout_14;
    QtColorChooserButton *doubleMin;
    QtColorChooserButton *doubleMax;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *doubleFixedRange;
    QDoubleSpinBox *doubleFixedRangeMin;
    QDoubleSpinBox *doubleFixedRangeMax;
    QCheckBox *doubleAbsolute;

    void setupUi(QWidget *DoubleWidget)
    {
        if (DoubleWidget->objectName().isEmpty())
            DoubleWidget->setObjectName(QString::fromUtf8("DoubleWidget"));
        DoubleWidget->resize(404, 172);
        verticalLayout_7 = new QVBoxLayout(DoubleWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        paramDouble = new QGroupBox(DoubleWidget);
        paramDouble->setObjectName(QString::fromUtf8("paramDouble"));
        verticalLayout_4 = new QVBoxLayout(paramDouble);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        doubleColorCoder = new QCheckBox(paramDouble);
        doubleColorCoder->setObjectName(QString::fromUtf8("doubleColorCoder"));
        doubleColorCoder->setChecked(true);

        verticalLayout_4->addWidget(doubleColorCoder);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        doubleMin = new QtColorChooserButton(paramDouble);
        doubleMin->setObjectName(QString::fromUtf8("doubleMin"));
        doubleMin->setEnabled(false);
        doubleMin->setProperty("color", QVariant(QColor(0, 0, 255)));

        horizontalLayout_14->addWidget(doubleMin);

        doubleMax = new QtColorChooserButton(paramDouble);
        doubleMax->setObjectName(QString::fromUtf8("doubleMax"));
        doubleMax->setEnabled(false);
        doubleMax->setProperty("color", QVariant(QColor(255, 0, 0)));

        horizontalLayout_14->addWidget(doubleMax);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        doubleFixedRange = new QCheckBox(paramDouble);
        doubleFixedRange->setObjectName(QString::fromUtf8("doubleFixedRange"));

        horizontalLayout_5->addWidget(doubleFixedRange);

        doubleFixedRangeMin = new QDoubleSpinBox(paramDouble);
        doubleFixedRangeMin->setObjectName(QString::fromUtf8("doubleFixedRangeMin"));
        doubleFixedRangeMin->setMinimumSize(QSize(100, 0));
        doubleFixedRangeMin->setDecimals(4);
        doubleFixedRangeMin->setMinimum(-1e+09);
        doubleFixedRangeMin->setMaximum(1e+09);

        horizontalLayout_5->addWidget(doubleFixedRangeMin);

        doubleFixedRangeMax = new QDoubleSpinBox(paramDouble);
        doubleFixedRangeMax->setObjectName(QString::fromUtf8("doubleFixedRangeMax"));
        doubleFixedRangeMax->setMinimumSize(QSize(100, 0));
        doubleFixedRangeMax->setDecimals(4);
        doubleFixedRangeMax->setMinimum(-1e+09);
        doubleFixedRangeMax->setMaximum(1e+09);
        doubleFixedRangeMax->setValue(1);

        horizontalLayout_5->addWidget(doubleFixedRangeMax);


        verticalLayout_4->addLayout(horizontalLayout_5);

        doubleAbsolute = new QCheckBox(paramDouble);
        doubleAbsolute->setObjectName(QString::fromUtf8("doubleAbsolute"));

        verticalLayout_4->addWidget(doubleAbsolute);


        verticalLayout_7->addWidget(paramDouble);

        QWidget::setTabOrder(doubleFixedRange, doubleFixedRangeMin);
        QWidget::setTabOrder(doubleFixedRangeMin, doubleFixedRangeMax);
        QWidget::setTabOrder(doubleFixedRangeMax, doubleAbsolute);

        retranslateUi(DoubleWidget);
        QObject::connect(doubleColorCoder, SIGNAL(toggled(bool)), doubleMin, SLOT(setDisabled(bool)));
        QObject::connect(doubleColorCoder, SIGNAL(toggled(bool)), doubleMax, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(DoubleWidget);
    } // setupUi

    void retranslateUi(QWidget *DoubleWidget)
    {
        DoubleWidget->setWindowTitle(QApplication::translate("DoubleWidget", "Property Visualization", 0, QApplication::UnicodeUTF8));
        paramDouble->setTitle(QApplication::translate("DoubleWidget", "Double Parameters", 0, QApplication::UnicodeUTF8));
        doubleColorCoder->setText(QApplication::translate("DoubleWidget", "Use color coder", 0, QApplication::UnicodeUTF8));
        doubleMin->setText(QApplication::translate("DoubleWidget", "Min Col.: ", 0, QApplication::UnicodeUTF8));
        doubleMax->setText(QApplication::translate("DoubleWidget", "Max Col.: ", 0, QApplication::UnicodeUTF8));
        doubleFixedRange->setText(QApplication::translate("DoubleWidget", "Fixed Range", 0, QApplication::UnicodeUTF8));
        doubleAbsolute->setText(QApplication::translate("DoubleWidget", "Use absolute values", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DoubleWidget: public Ui_DoubleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLEWIDGET_H
