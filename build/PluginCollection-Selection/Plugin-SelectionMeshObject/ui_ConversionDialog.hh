/********************************************************************************
** Form generated from reading UI file 'ConversionDialog.ui'
**
** Created: Sat May 18 03:02:57 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSIONDIALOG_H
#define UI_CONVERSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConversionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *convertFromBox;
    QComboBox *convertToBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *convertButton;
    QCheckBox *deselect;

    void setupUi(QWidget *ConversionDialog)
    {
        if (ConversionDialog->objectName().isEmpty())
            ConversionDialog->setObjectName(QString::fromUtf8("ConversionDialog"));
        ConversionDialog->resize(384, 111);
        verticalLayout = new QVBoxLayout(ConversionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label = new QLabel(ConversionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(ConversionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_2);

        convertFromBox = new QComboBox(ConversionDialog);
        convertFromBox->setObjectName(QString::fromUtf8("convertFromBox"));
        convertFromBox->setMinimumSize(QSize(180, 0));

        formLayout->setWidget(1, QFormLayout::LabelRole, convertFromBox);

        convertToBox = new QComboBox(ConversionDialog);
        convertToBox->setObjectName(QString::fromUtf8("convertToBox"));
        convertToBox->setMinimumSize(QSize(180, 0));

        formLayout->setWidget(1, QFormLayout::FieldRole, convertToBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        convertButton = new QPushButton(ConversionDialog);
        convertButton->setObjectName(QString::fromUtf8("convertButton"));

        horizontalLayout_3->addWidget(convertButton);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);

        deselect = new QCheckBox(ConversionDialog);
        deselect->setObjectName(QString::fromUtf8("deselect"));
        deselect->setChecked(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, deselect);


        verticalLayout->addLayout(formLayout);


        retranslateUi(ConversionDialog);

        QMetaObject::connectSlotsByName(ConversionDialog);
    } // setupUi

    void retranslateUi(QWidget *ConversionDialog)
    {
        ConversionDialog->setWindowTitle(QApplication::translate("ConversionDialog", "Convert Selection", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConversionDialog", "Convert from", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConversionDialog", "to", 0, QApplication::UnicodeUTF8));
        convertButton->setText(QApplication::translate("ConversionDialog", "Convert", 0, QApplication::UnicodeUTF8));
        deselect->setText(QApplication::translate("ConversionDialog", "Deselect source selection", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConversionDialog: public Ui_ConversionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSIONDIALOG_H
