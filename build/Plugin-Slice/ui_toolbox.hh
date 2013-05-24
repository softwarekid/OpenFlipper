/********************************************************************************
** Form generated from reading UI file 'toolbox.ui'
**
** Created: Sat May 18 02:58:59 2013
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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SliceTool
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioTarget;
    QRadioButton *radioAll;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioX;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioY;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioZ;
    QLabel *label;
    QSlider *posSlider;
    QLabel *label_2;
    QSlider *sizeSlider;
    QPushButton *resetButton;
    QPushButton *enabled;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SliceTool)
    {
        if (SliceTool->objectName().isEmpty())
            SliceTool->setObjectName(QString::fromUtf8("SliceTool"));
        SliceTool->resize(339, 210);
        verticalLayout = new QVBoxLayout(SliceTool);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_4 = new QLabel(SliceTool);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioTarget = new QRadioButton(SliceTool);
        radioTarget->setObjectName(QString::fromUtf8("radioTarget"));
        radioTarget->setEnabled(false);
        radioTarget->setAutoExclusive(true);

        horizontalLayout_2->addWidget(radioTarget);

        radioAll = new QRadioButton(SliceTool);
        radioAll->setObjectName(QString::fromUtf8("radioAll"));
        radioAll->setEnabled(false);
        radioAll->setChecked(true);
        radioAll->setAutoExclusive(true);

        horizontalLayout_2->addWidget(radioAll);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);

        label_3 = new QLabel(SliceTool);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioX = new QRadioButton(SliceTool);
        radioX->setObjectName(QString::fromUtf8("radioX"));
        radioX->setEnabled(false);
        radioX->setChecked(true);
        radioX->setAutoExclusive(true);

        horizontalLayout->addWidget(radioX);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioY = new QRadioButton(SliceTool);
        radioY->setObjectName(QString::fromUtf8("radioY"));
        radioY->setEnabled(false);
        radioY->setAutoExclusive(true);

        horizontalLayout->addWidget(radioY);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        radioZ = new QRadioButton(SliceTool);
        radioZ->setObjectName(QString::fromUtf8("radioZ"));
        radioZ->setEnabled(false);
        radioZ->setAutoExclusive(true);

        horizontalLayout->addWidget(radioZ);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        label = new QLabel(SliceTool);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        posSlider = new QSlider(SliceTool);
        posSlider->setObjectName(QString::fromUtf8("posSlider"));
        posSlider->setEnabled(false);
        posSlider->setMinimum(-101);
        posSlider->setMaximum(101);
        posSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, posSlider);

        label_2 = new QLabel(SliceTool);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        sizeSlider = new QSlider(SliceTool);
        sizeSlider->setObjectName(QString::fromUtf8("sizeSlider"));
        sizeSlider->setEnabled(false);
        sizeSlider->setMinimum(0);
        sizeSlider->setMaximum(102);
        sizeSlider->setValue(102);
        sizeSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(3, QFormLayout::FieldRole, sizeSlider);

        resetButton = new QPushButton(SliceTool);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, resetButton);


        verticalLayout->addLayout(formLayout);

        enabled = new QPushButton(SliceTool);
        enabled->setObjectName(QString::fromUtf8("enabled"));
        enabled->setCheckable(true);

        verticalLayout->addWidget(enabled);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(SliceTool);
        QObject::connect(enabled, SIGNAL(toggled(bool)), sizeSlider, SLOT(setEnabled(bool)));
        QObject::connect(enabled, SIGNAL(toggled(bool)), posSlider, SLOT(setEnabled(bool)));
        QObject::connect(enabled, SIGNAL(toggled(bool)), radioZ, SLOT(setEnabled(bool)));
        QObject::connect(enabled, SIGNAL(toggled(bool)), radioX, SLOT(setEnabled(bool)));
        QObject::connect(enabled, SIGNAL(toggled(bool)), radioY, SLOT(setEnabled(bool)));
        QObject::connect(enabled, SIGNAL(toggled(bool)), radioTarget, SLOT(setEnabled(bool)));
        QObject::connect(enabled, SIGNAL(toggled(bool)), radioAll, SLOT(setEnabled(bool)));
        QObject::connect(enabled, SIGNAL(toggled(bool)), resetButton, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(SliceTool);
    } // setupUi

    void retranslateUi(QWidget *SliceTool)
    {
        SliceTool->setWindowTitle(QApplication::translate("SliceTool", "Form", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SliceTool", "Bounding Box:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioTarget->setToolTip(QApplication::translate("SliceTool", "Use only target objects to determine the bounding box for the slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioTarget->setStatusTip(QApplication::translate("SliceTool", "Use only target objects to determine the bounding box for the slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        radioTarget->setText(QApplication::translate("SliceTool", "Target Objects", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioAll->setToolTip(QApplication::translate("SliceTool", "Use all objects to determine the bounding box for the slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioAll->setStatusTip(QApplication::translate("SliceTool", "Use all objects to determine the bounding box for the slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        radioAll->setText(QApplication::translate("SliceTool", "All Objects", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SliceTool", "Axis:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioX->setToolTip(QApplication::translate("SliceTool", "Uses X as slicing axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioX->setStatusTip(QApplication::translate("SliceTool", "Uses X as slicing axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        radioX->setText(QApplication::translate("SliceTool", "X", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioY->setToolTip(QApplication::translate("SliceTool", "Uses Y as slicing axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioY->setStatusTip(QApplication::translate("SliceTool", "Uses Y as slicing axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        radioY->setText(QApplication::translate("SliceTool", "Y", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioZ->setToolTip(QApplication::translate("SliceTool", "Uses Z as slicing axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioZ->setStatusTip(QApplication::translate("SliceTool", "Uses Z as slicing axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        radioZ->setText(QApplication::translate("SliceTool", "Z", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SliceTool", "Position:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        posSlider->setToolTip(QApplication::translate("SliceTool", "Adjust the position of the slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        posSlider->setStatusTip(QApplication::translate("SliceTool", "Adjust the position of the slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("SliceTool", "Size:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sizeSlider->setToolTip(QApplication::translate("SliceTool", "Adjust the size of the slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        sizeSlider->setStatusTip(QApplication::translate("SliceTool", "Adjust the size of the slice", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        resetButton->setToolTip(QApplication::translate("SliceTool", "Reset the above parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        resetButton->setStatusTip(QApplication::translate("SliceTool", "Reset the above parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        resetButton->setText(QApplication::translate("SliceTool", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        enabled->setToolTip(QApplication::translate("SliceTool", "Enable slicing for the current scene", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        enabled->setStatusTip(QApplication::translate("SliceTool", "Enable slicing for the current scene", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        enabled->setText(QApplication::translate("SliceTool", "Enable Slicing", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SliceTool: public Ui_SliceTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
