/********************************************************************************
** Form generated from reading UI file 'philipsStereoSettingsWidget.ui'
**
** Created: Sat May 18 03:02:13 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHILIPSSTEREOSETTINGSWIDGET_H
#define UI_PHILIPSSTEREOSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhilipsStereoSettingsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *headerContentType;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *headerSelect;
    QHBoxLayout *horizontalLayout_2;
    QLabel *factorCounter;
    QSlider *headerFactor;
    QHBoxLayout *horizontalLayout_3;
    QLabel *offsetCounter;
    QSlider *headerOffsetCC;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *PhilipsStereoSettingsWidget)
    {
        if (PhilipsStereoSettingsWidget->objectName().isEmpty())
            PhilipsStereoSettingsWidget->setObjectName(QString::fromUtf8("PhilipsStereoSettingsWidget"));
        PhilipsStereoSettingsWidget->resize(464, 212);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PhilipsStereoSettingsWidget->sizePolicy().hasHeightForWidth());
        PhilipsStereoSettingsWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(PhilipsStereoSettingsWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(PhilipsStereoSettingsWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        headerContentType = new QComboBox(groupBox);
        headerContentType->setObjectName(QString::fromUtf8("headerContentType"));

        gridLayout->addWidget(headerContentType, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        headerSelect = new QComboBox(groupBox);
        headerSelect->setObjectName(QString::fromUtf8("headerSelect"));

        gridLayout->addWidget(headerSelect, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        factorCounter = new QLabel(groupBox);
        factorCounter->setObjectName(QString::fromUtf8("factorCounter"));
        factorCounter->setMinimumSize(QSize(30, 0));
        factorCounter->setMaximumSize(QSize(30, 16777215));
        factorCounter->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(factorCounter);

        headerFactor = new QSlider(groupBox);
        headerFactor->setObjectName(QString::fromUtf8("headerFactor"));
        headerFactor->setMaximum(255);
        headerFactor->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(headerFactor);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        offsetCounter = new QLabel(groupBox);
        offsetCounter->setObjectName(QString::fromUtf8("offsetCounter"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(offsetCounter->sizePolicy().hasHeightForWidth());
        offsetCounter->setSizePolicy(sizePolicy1);
        offsetCounter->setMinimumSize(QSize(30, 0));
        offsetCounter->setMaximumSize(QSize(30, 16777215));
        offsetCounter->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_3->addWidget(offsetCounter);

        headerOffsetCC = new QSlider(groupBox);
        headerOffsetCC->setObjectName(QString::fromUtf8("headerOffsetCC"));
        headerOffsetCC->setEnabled(true);
        headerOffsetCC->setMaximum(255);
        headerOffsetCC->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(headerOffsetCC);


        gridLayout->addLayout(horizontalLayout_3, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(PhilipsStereoSettingsWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(120, 0));

        horizontalLayout->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PhilipsStereoSettingsWidget);

        QMetaObject::connectSlotsByName(PhilipsStereoSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *PhilipsStereoSettingsWidget)
    {
        PhilipsStereoSettingsWidget->setWindowTitle(QApplication::translate("PhilipsStereoSettingsWidget", "Philips Stereo Settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PhilipsStereoSettingsWidget", "Philips Stereo properties", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PhilipsStereoSettingsWidget", "Header Content type", 0, QApplication::UnicodeUTF8));
        headerContentType->clear();
        headerContentType->insertItems(0, QStringList()
         << QApplication::translate("PhilipsStereoSettingsWidget", "No depth", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PhilipsStereoSettingsWidget", "Signage", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PhilipsStereoSettingsWidget", "Movie", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PhilipsStereoSettingsWidget", "Game", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PhilipsStereoSettingsWidget", "CGI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PhilipsStereoSettingsWidget", "Still", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("PhilipsStereoSettingsWidget", "Header factor", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PhilipsStereoSettingsWidget", "Header Offset CC", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PhilipsStereoSettingsWidget", "Header Select", 0, QApplication::UnicodeUTF8));
        headerSelect->clear();
        headerSelect->insertItems(0, QStringList()
         << QApplication::translate("PhilipsStereoSettingsWidget", "Automatic optimizations", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PhilipsStereoSettingsWidget", "Header provided factor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PhilipsStereoSettingsWidget", "Header provided offset", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PhilipsStereoSettingsWidget", "Header provided factor and offset", 0, QApplication::UnicodeUTF8)
        );
        factorCounter->setText(QApplication::translate("PhilipsStereoSettingsWidget", "0", 0, QApplication::UnicodeUTF8));
        offsetCounter->setText(QApplication::translate("PhilipsStereoSettingsWidget", "0", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("PhilipsStereoSettingsWidget", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PhilipsStereoSettingsWidget: public Ui_PhilipsStereoSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHILIPSSTEREOSETTINGSWIDGET_H
