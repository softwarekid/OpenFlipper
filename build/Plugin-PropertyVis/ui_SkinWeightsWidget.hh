/********************************************************************************
** Form generated from reading UI file 'SkinWeightsWidget.ui'
**
** Created: Sat May 18 02:57:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKINWEIGHTSWIDGET_H
#define UI_SKINWEIGHTSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SkinWeightsWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *paramSkinWeights;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QSpinBox *boneId;

    void setupUi(QWidget *SkinWeightsWidget)
    {
        if (SkinWeightsWidget->objectName().isEmpty())
            SkinWeightsWidget->setObjectName(QString::fromUtf8("SkinWeightsWidget"));
        SkinWeightsWidget->resize(457, 69);
        verticalLayout_7 = new QVBoxLayout(SkinWeightsWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        paramSkinWeights = new QGroupBox(SkinWeightsWidget);
        paramSkinWeights->setObjectName(QString::fromUtf8("paramSkinWeights"));
        verticalLayout_6 = new QVBoxLayout(paramSkinWeights);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_12 = new QLabel(paramSkinWeights);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_11->addWidget(label_12);

        boneId = new QSpinBox(paramSkinWeights);
        boneId->setObjectName(QString::fromUtf8("boneId"));

        horizontalLayout_11->addWidget(boneId);


        verticalLayout_6->addLayout(horizontalLayout_11);


        verticalLayout_7->addWidget(paramSkinWeights);

#ifndef QT_NO_SHORTCUT
        label_12->setBuddy(boneId);
#endif // QT_NO_SHORTCUT

        retranslateUi(SkinWeightsWidget);

        QMetaObject::connectSlotsByName(SkinWeightsWidget);
    } // setupUi

    void retranslateUi(QWidget *SkinWeightsWidget)
    {
        SkinWeightsWidget->setWindowTitle(QApplication::translate("SkinWeightsWidget", "Property Visualization", 0, QApplication::UnicodeUTF8));
        paramSkinWeights->setTitle(QApplication::translate("SkinWeightsWidget", "Skin Weights", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SkinWeightsWidget", "Bone", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SkinWeightsWidget: public Ui_SkinWeightsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKINWEIGHTSWIDGET_H
