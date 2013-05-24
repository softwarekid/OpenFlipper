/********************************************************************************
** Form generated from reading UI file 'ImageDialog.ui'
**
** Created: Sat May 18 03:00:46 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDIALOG_H
#define UI_IMAGEDIALOG_H

#include <QClickableLabel.hh>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImageDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QClickableLabel *image;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *minY;
    QSpacerItem *verticalSpacer;
    QSpinBox *maxY;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *minX;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *maxX;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDoubleSpinBox *heightValue;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImageDialog)
    {
        if (ImageDialog->objectName().isEmpty())
            ImageDialog->setObjectName(QString::fromUtf8("ImageDialog"));
        ImageDialog->setWindowModality(Qt::ApplicationModal);
        ImageDialog->setEnabled(true);
        ImageDialog->resize(482, 511);
        ImageDialog->setFocusPolicy(Qt::NoFocus);
        ImageDialog->setSizeGripEnabled(false);
        ImageDialog->setModal(false);
        verticalLayout_4 = new QVBoxLayout(ImageDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        image = new QClickableLabel(ImageDialog);
        image->setObjectName(QString::fromUtf8("image"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setMinimumSize(QSize(400, 400));
        image->setMaximumSize(QSize(400, 400));
        image->setMouseTracking(true);
        image->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(image);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        minY = new QSpinBox(ImageDialog);
        minY->setObjectName(QString::fromUtf8("minY"));

        verticalLayout_2->addWidget(minY);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        maxY = new QSpinBox(ImageDialog);
        maxY->setObjectName(QString::fromUtf8("maxY"));

        verticalLayout_2->addWidget(maxY);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        minX = new QSpinBox(ImageDialog);
        minX->setObjectName(QString::fromUtf8("minX"));

        horizontalLayout_2->addWidget(minX);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        maxX = new QSpinBox(ImageDialog);
        maxX->setObjectName(QString::fromUtf8("maxX"));

        horizontalLayout_2->addWidget(maxX);

        horizontalSpacer = new QSpacerItem(64, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(ImageDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        heightValue = new QDoubleSpinBox(ImageDialog);
        heightValue->setObjectName(QString::fromUtf8("heightValue"));
        heightValue->setDecimals(3);
        heightValue->setMaximum(1000);
        heightValue->setValue(10);

        horizontalLayout_4->addWidget(heightValue);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(576, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(ImageDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(ImageDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImageDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImageDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImageDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageDialog)
    {
        ImageDialog->setWindowTitle(QApplication::translate("ImageDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        image->setText(QApplication::translate("ImageDialog", "Image Placeholder", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ImageDialog", "Maximal height:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageDialog: public Ui_ImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDIALOG_H
