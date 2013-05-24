/********************************************************************************
** Form generated from reading UI file 'toolbox.ui'
**
** Created: Sat May 18 02:56:07 2013
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IsotropicRemesherTool
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *minEdgeLength;
    QPushButton *meanEdgeLength;
    QPushButton *maxEdgeLength;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *targetEdgeLength;
    QPushButton *remeshButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *IsotropicRemesherTool)
    {
        if (IsotropicRemesherTool->objectName().isEmpty())
            IsotropicRemesherTool->setObjectName(QString::fromUtf8("IsotropicRemesherTool"));
        IsotropicRemesherTool->setEnabled(true);
        IsotropicRemesherTool->resize(289, 286);
        verticalLayout_3 = new QVBoxLayout(IsotropicRemesherTool);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(IsotropicRemesherTool);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        minEdgeLength = new QPushButton(groupBox);
        minEdgeLength->setObjectName(QString::fromUtf8("minEdgeLength"));

        horizontalLayout_3->addWidget(minEdgeLength);

        meanEdgeLength = new QPushButton(groupBox);
        meanEdgeLength->setObjectName(QString::fromUtf8("meanEdgeLength"));

        horizontalLayout_3->addWidget(meanEdgeLength);

        maxEdgeLength = new QPushButton(groupBox);
        maxEdgeLength->setObjectName(QString::fromUtf8("maxEdgeLength"));

        horizontalLayout_3->addWidget(maxEdgeLength);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        targetEdgeLength = new QDoubleSpinBox(groupBox);
        targetEdgeLength->setObjectName(QString::fromUtf8("targetEdgeLength"));
        targetEdgeLength->setDecimals(6);
        targetEdgeLength->setMaximum(100000);

        horizontalLayout->addWidget(targetEdgeLength);


        verticalLayout_2->addLayout(horizontalLayout);

        remeshButton = new QPushButton(groupBox);
        remeshButton->setObjectName(QString::fromUtf8("remeshButton"));

        verticalLayout_2->addWidget(remeshButton);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(275, 119, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(IsotropicRemesherTool);

        QMetaObject::connectSlotsByName(IsotropicRemesherTool);
    } // setupUi

    void retranslateUi(QWidget *IsotropicRemesherTool)
    {
        IsotropicRemesherTool->setWindowTitle(QApplication::translate("IsotropicRemesherTool", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("IsotropicRemesherTool", " Isotropic Remeshing ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("IsotropicRemesherTool", "Set target Object edge length:", 0, QApplication::UnicodeUTF8));
        minEdgeLength->setText(QApplication::translate("IsotropicRemesherTool", "Min", 0, QApplication::UnicodeUTF8));
        meanEdgeLength->setText(QApplication::translate("IsotropicRemesherTool", "Mean", 0, QApplication::UnicodeUTF8));
        maxEdgeLength->setText(QApplication::translate("IsotropicRemesherTool", "Max", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IsotropicRemesherTool", "Target Edge Length:", 0, QApplication::UnicodeUTF8));
        remeshButton->setText(QApplication::translate("IsotropicRemesherTool", "Remesh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IsotropicRemesherTool: public Ui_IsotropicRemesherTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
