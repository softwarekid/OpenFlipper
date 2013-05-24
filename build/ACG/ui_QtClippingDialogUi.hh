/********************************************************************************
** Form generated from reading UI file 'QtClippingDialogUi.ui'
**
** Created: Sat May 18 02:49:50 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCLIPPINGDIALOGUI_H
#define UI_QTCLIPPINGDIALOGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtClippingDialogUi
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout1;
    QLineEdit *sweepRangeLineEdit;
    QSpacerItem *spacerItem;
    QLabel *label_4;
    QSlider *sweepRangeSlider;
    QGroupBox *groupBox;
    QGridLayout *gridLayout2;
    QSpacerItem *spacerItem1;
    QSpacerItem *spacerItem2;
    QSpacerItem *spacerItem3;
    QGridLayout *gridLayout3;
    QSpacerItem *spacerItem4;
    QPushButton *setButton;
    QGridLayout *gridLayout4;
    QLineEdit *normalXLineEdit;
    QLabel *label_2;
    QLineEdit *normalZLineEdit;
    QLabel *label_3;
    QLineEdit *sliceWidthLineEdit;
    QLineEdit *positionYLineEdit;
    QLabel *label;
    QLineEdit *positionXLineEdit;
    QLineEdit *positionZLineEdit;
    QSpacerItem *spacerItem5;
    QLineEdit *normalYLineEdit;
    QSpacerItem *spacerItem6;
    QSpacerItem *spacerItem7;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem8;
    QPushButton *okButton;

    void setupUi(QWidget *QtClippingDialogUi)
    {
        if (QtClippingDialogUi->objectName().isEmpty())
            QtClippingDialogUi->setObjectName(QString::fromUtf8("QtClippingDialogUi"));
        QtClippingDialogUi->resize(491, 457);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtClippingDialogUi->sizePolicy().hasHeightForWidth());
        QtClippingDialogUi->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(QtClippingDialogUi);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(QtClippingDialogUi);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout1 = new QGridLayout(groupBox_2);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        sweepRangeLineEdit = new QLineEdit(groupBox_2);
        sweepRangeLineEdit->setObjectName(QString::fromUtf8("sweepRangeLineEdit"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sweepRangeLineEdit->sizePolicy().hasHeightForWidth());
        sweepRangeLineEdit->setSizePolicy(sizePolicy1);
        sweepRangeLineEdit->setMinimumSize(QSize(50, 0));
        sweepRangeLineEdit->setAlignment(Qt::AlignRight);

        gridLayout1->addWidget(sweepRangeLineEdit, 0, 2, 1, 1);

        spacerItem = new QSpacerItem(1, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(5));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        gridLayout1->addWidget(label_4, 0, 0, 1, 1);

        sweepRangeSlider = new QSlider(groupBox_2);
        sweepRangeSlider->setObjectName(QString::fromUtf8("sweepRangeSlider"));
        sizePolicy2.setHeightForWidth(sweepRangeSlider->sizePolicy().hasHeightForWidth());
        sweepRangeSlider->setSizePolicy(sizePolicy2);
        sweepRangeSlider->setMinimum(-100);
        sweepRangeSlider->setMaximum(100);
        sweepRangeSlider->setOrientation(Qt::Horizontal);

        gridLayout1->addWidget(sweepRangeSlider, 1, 0, 1, 3);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(QtClippingDialogUi);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout2 = new QGridLayout(groupBox);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        spacerItem1 = new QSpacerItem(1, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem1, 1, 2, 1, 1);

        spacerItem2 = new QSpacerItem(10, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout2->addItem(spacerItem2, 0, 1, 1, 1);

        spacerItem3 = new QSpacerItem(1, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem3, 1, 0, 1, 1);

        gridLayout3 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        spacerItem4 = new QSpacerItem(1, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout3->addItem(spacerItem4, 1, 0, 1, 1);

        setButton = new QPushButton(groupBox);
        setButton->setObjectName(QString::fromUtf8("setButton"));

        gridLayout3->addWidget(setButton, 1, 1, 1, 1);

        gridLayout4 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout4->setSpacing(6);
#endif
        gridLayout4->setContentsMargins(0, 0, 0, 0);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        normalXLineEdit = new QLineEdit(groupBox);
        normalXLineEdit->setObjectName(QString::fromUtf8("normalXLineEdit"));
        QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(normalXLineEdit->sizePolicy().hasHeightForWidth());
        normalXLineEdit->setSizePolicy(sizePolicy3);
        normalXLineEdit->setMinimumSize(QSize(50, 0));
        normalXLineEdit->setAlignment(Qt::AlignRight);

        gridLayout4->addWidget(normalXLineEdit, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout4->addWidget(label_2, 1, 0, 1, 1);

        normalZLineEdit = new QLineEdit(groupBox);
        normalZLineEdit->setObjectName(QString::fromUtf8("normalZLineEdit"));
        sizePolicy3.setHeightForWidth(normalZLineEdit->sizePolicy().hasHeightForWidth());
        normalZLineEdit->setSizePolicy(sizePolicy3);
        normalZLineEdit->setMinimumSize(QSize(50, 0));
        normalZLineEdit->setMaximumSize(QSize(16777215, 16777215));
        normalZLineEdit->setAlignment(Qt::AlignRight);

        gridLayout4->addWidget(normalZLineEdit, 1, 4, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout4->addWidget(label_3, 2, 0, 1, 1);

        sliceWidthLineEdit = new QLineEdit(groupBox);
        sliceWidthLineEdit->setObjectName(QString::fromUtf8("sliceWidthLineEdit"));
        sizePolicy3.setHeightForWidth(sliceWidthLineEdit->sizePolicy().hasHeightForWidth());
        sliceWidthLineEdit->setSizePolicy(sizePolicy3);
        sliceWidthLineEdit->setMinimumSize(QSize(50, 0));
        sliceWidthLineEdit->setAlignment(Qt::AlignRight);

        gridLayout4->addWidget(sliceWidthLineEdit, 2, 2, 1, 1);

        positionYLineEdit = new QLineEdit(groupBox);
        positionYLineEdit->setObjectName(QString::fromUtf8("positionYLineEdit"));
        sizePolicy3.setHeightForWidth(positionYLineEdit->sizePolicy().hasHeightForWidth());
        positionYLineEdit->setSizePolicy(sizePolicy3);
        positionYLineEdit->setMinimumSize(QSize(50, 0));
        positionYLineEdit->setAlignment(Qt::AlignRight);

        gridLayout4->addWidget(positionYLineEdit, 0, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout4->addWidget(label, 0, 0, 1, 1);

        positionXLineEdit = new QLineEdit(groupBox);
        positionXLineEdit->setObjectName(QString::fromUtf8("positionXLineEdit"));
        sizePolicy3.setHeightForWidth(positionXLineEdit->sizePolicy().hasHeightForWidth());
        positionXLineEdit->setSizePolicy(sizePolicy3);
        positionXLineEdit->setMinimumSize(QSize(50, 0));
        positionXLineEdit->setAlignment(Qt::AlignRight);

        gridLayout4->addWidget(positionXLineEdit, 0, 2, 1, 1);

        positionZLineEdit = new QLineEdit(groupBox);
        positionZLineEdit->setObjectName(QString::fromUtf8("positionZLineEdit"));
        sizePolicy3.setHeightForWidth(positionZLineEdit->sizePolicy().hasHeightForWidth());
        positionZLineEdit->setSizePolicy(sizePolicy3);
        positionZLineEdit->setMinimumSize(QSize(50, 0));
        positionZLineEdit->setMaximumSize(QSize(16777215, 16777215));
        positionZLineEdit->setAlignment(Qt::AlignRight);

        gridLayout4->addWidget(positionZLineEdit, 0, 4, 1, 1);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout4->addItem(spacerItem5, 0, 1, 1, 1);

        normalYLineEdit = new QLineEdit(groupBox);
        normalYLineEdit->setObjectName(QString::fromUtf8("normalYLineEdit"));
        sizePolicy3.setHeightForWidth(normalYLineEdit->sizePolicy().hasHeightForWidth());
        normalYLineEdit->setSizePolicy(sizePolicy3);
        normalYLineEdit->setMinimumSize(QSize(50, 0));
        normalYLineEdit->setAlignment(Qt::AlignRight);

        gridLayout4->addWidget(normalYLineEdit, 1, 3, 1, 1);


        gridLayout3->addLayout(gridLayout4, 0, 0, 1, 2);


        gridLayout2->addLayout(gridLayout3, 1, 1, 1, 1);

        spacerItem6 = new QSpacerItem(10, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout2->addItem(spacerItem6, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        spacerItem7 = new QSpacerItem(10, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem7, 2, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem8 = new QSpacerItem(1, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem8);

        okButton = new QPushButton(QtClippingDialogUi);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);


        gridLayout->addLayout(hboxLayout, 3, 0, 1, 1);


        retranslateUi(QtClippingDialogUi);

        QMetaObject::connectSlotsByName(QtClippingDialogUi);
    } // setupUi

    void retranslateUi(QWidget *QtClippingDialogUi)
    {
        QtClippingDialogUi->setWindowTitle(QApplication::translate("QtClippingDialogUi", "Clip Planes", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("QtClippingDialogUi", "Sweep", 0, QApplication::UnicodeUTF8));
        sweepRangeLineEdit->setText(QApplication::translate("QtClippingDialogUi", "1", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QtClippingDialogUi", "Sweep range", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QtClippingDialogUi", "Plane(s)", 0, QApplication::UnicodeUTF8));
        setButton->setText(QApplication::translate("QtClippingDialogUi", "Set", 0, QApplication::UnicodeUTF8));
        normalXLineEdit->setText(QString());
        label_2->setText(QApplication::translate("QtClippingDialogUi", "Normal", 0, QApplication::UnicodeUTF8));
        normalZLineEdit->setText(QString());
        label_3->setText(QApplication::translate("QtClippingDialogUi", "Slice width", 0, QApplication::UnicodeUTF8));
        sliceWidthLineEdit->setText(QString());
        positionYLineEdit->setText(QString());
        label->setText(QApplication::translate("QtClippingDialogUi", "Position", 0, QApplication::UnicodeUTF8));
        positionXLineEdit->setText(QString());
        positionZLineEdit->setText(QString());
        normalYLineEdit->setText(QString());
        okButton->setText(QApplication::translate("QtClippingDialogUi", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtClippingDialogUi: public Ui_QtClippingDialogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCLIPPINGDIALOGUI_H
