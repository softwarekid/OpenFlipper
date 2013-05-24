/********************************************************************************
** Form generated from reading UI file 'PickWidget.ui'
**
** Created: Sat May 18 02:57:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICKWIDGET_H
#define UI_PICKWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PickWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *pickProp;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *pickedHandle;
    QLabel *label_9;
    QLabel *pickedValue;
    QPushButton *pickButton;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *PickWidget)
    {
        if (PickWidget->objectName().isEmpty())
            PickWidget->setObjectName(QString::fromUtf8("PickWidget"));
        PickWidget->resize(454, 123);
        verticalLayout_7 = new QVBoxLayout(PickWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        pickProp = new QGroupBox(PickWidget);
        pickProp->setObjectName(QString::fromUtf8("pickProp"));
        verticalLayout_2 = new QVBoxLayout(pickProp);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(pickProp);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(55, 16777215));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        pickedHandle = new QLabel(pickProp);
        pickedHandle->setObjectName(QString::fromUtf8("pickedHandle"));

        gridLayout_2->addWidget(pickedHandle, 0, 1, 1, 1);

        label_9 = new QLabel(pickProp);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        pickedValue = new QLabel(pickProp);
        pickedValue->setObjectName(QString::fromUtf8("pickedValue"));

        gridLayout_2->addWidget(pickedValue, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        pickButton = new QPushButton(pickProp);
        pickButton->setObjectName(QString::fromUtf8("pickButton"));
        pickButton->setCheckable(true);

        verticalLayout_2->addWidget(pickButton);


        verticalLayout_7->addWidget(pickProp);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        retranslateUi(PickWidget);

        QMetaObject::connectSlotsByName(PickWidget);
    } // setupUi

    void retranslateUi(QWidget *PickWidget)
    {
        PickWidget->setWindowTitle(QApplication::translate("PickWidget", "Property Visualization", 0, QApplication::UnicodeUTF8));
        pickProp->setTitle(QApplication::translate("PickWidget", "Pick Property", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PickWidget", "Handle:", 0, QApplication::UnicodeUTF8));
        pickedHandle->setText(QApplication::translate("PickWidget", "-", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("PickWidget", "Value:", 0, QApplication::UnicodeUTF8));
        pickedValue->setText(QApplication::translate("PickWidget", "-", 0, QApplication::UnicodeUTF8));
        pickButton->setText(QApplication::translate("PickWidget", "Pick Property", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PickWidget: public Ui_PickWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICKWIDGET_H
