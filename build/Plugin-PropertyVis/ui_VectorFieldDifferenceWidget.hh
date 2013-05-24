/********************************************************************************
** Form generated from reading UI file 'VectorFieldDifferenceWidget.ui'
**
** Created: Sat May 18 02:57:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECTORFIELDDIFFERENCEWIDGET_H
#define UI_VECTORFIELDDIFFERENCEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VectorFieldDifferenceWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *paramVectorFieldDifference;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *vecFieldDiff_4symm_rb;
    QRadioButton *vecFieldDiff_diff_norm_rb;
    QRadioButton *vecFieldDiff_norm_diff_rb;

    void setupUi(QWidget *VectorFieldDifferenceWidget)
    {
        if (VectorFieldDifferenceWidget->objectName().isEmpty())
            VectorFieldDifferenceWidget->setObjectName(QString::fromUtf8("VectorFieldDifferenceWidget"));
        VectorFieldDifferenceWidget->resize(449, 126);
        verticalLayout_7 = new QVBoxLayout(VectorFieldDifferenceWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        paramVectorFieldDifference = new QGroupBox(VectorFieldDifferenceWidget);
        paramVectorFieldDifference->setObjectName(QString::fromUtf8("paramVectorFieldDifference"));
        verticalLayout_10 = new QVBoxLayout(paramVectorFieldDifference);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        vecFieldDiff_4symm_rb = new QRadioButton(paramVectorFieldDifference);
        vecFieldDiff_4symm_rb->setObjectName(QString::fromUtf8("vecFieldDiff_4symm_rb"));
        vecFieldDiff_4symm_rb->setEnabled(true);

        verticalLayout_10->addWidget(vecFieldDiff_4symm_rb);

        vecFieldDiff_diff_norm_rb = new QRadioButton(paramVectorFieldDifference);
        vecFieldDiff_diff_norm_rb->setObjectName(QString::fromUtf8("vecFieldDiff_diff_norm_rb"));
        vecFieldDiff_diff_norm_rb->setEnabled(true);

        verticalLayout_10->addWidget(vecFieldDiff_diff_norm_rb);

        vecFieldDiff_norm_diff_rb = new QRadioButton(paramVectorFieldDifference);
        vecFieldDiff_norm_diff_rb->setObjectName(QString::fromUtf8("vecFieldDiff_norm_diff_rb"));
        vecFieldDiff_norm_diff_rb->setEnabled(true);
        vecFieldDiff_norm_diff_rb->setChecked(true);

        verticalLayout_10->addWidget(vecFieldDiff_norm_diff_rb);


        verticalLayout_7->addWidget(paramVectorFieldDifference);

        QWidget::setTabOrder(vecFieldDiff_4symm_rb, vecFieldDiff_diff_norm_rb);
        QWidget::setTabOrder(vecFieldDiff_diff_norm_rb, vecFieldDiff_norm_diff_rb);

        retranslateUi(VectorFieldDifferenceWidget);

        QMetaObject::connectSlotsByName(VectorFieldDifferenceWidget);
    } // setupUi

    void retranslateUi(QWidget *VectorFieldDifferenceWidget)
    {
        VectorFieldDifferenceWidget->setWindowTitle(QApplication::translate("VectorFieldDifferenceWidget", "Property Visualization", 0, QApplication::UnicodeUTF8));
        paramVectorFieldDifference->setTitle(QApplication::translate("VectorFieldDifferenceWidget", "Vector Field Difference", 0, QApplication::UnicodeUTF8));
        vecFieldDiff_4symm_rb->setText(QApplication::translate("VectorFieldDifferenceWidget", "4-Symmetric Difference (0\302\260 \342\200\223 45\302\260)", 0, QApplication::UnicodeUTF8));
        vecFieldDiff_diff_norm_rb->setText(QApplication::translate("VectorFieldDifferenceWidget", "Difference in Magnitude (|\342\210\245a\342\210\245-\342\210\245b\342\210\245|)", 0, QApplication::UnicodeUTF8));
        vecFieldDiff_norm_diff_rb->setText(QApplication::translate("VectorFieldDifferenceWidget", "Norm of Difference (\342\210\245a-b\342\210\245)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VectorFieldDifferenceWidget: public Ui_VectorFieldDifferenceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORFIELDDIFFERENCEWIDGET_H
