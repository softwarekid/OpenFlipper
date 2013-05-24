/********************************************************************************
** Form generated from reading UI file 'smootherToolbar.ui'
**
** Created: Sat May 18 02:59:04 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMOOTHERTOOLBAR_H
#define UI_SMOOTHERTOOLBAR_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmootherToolbar
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbTangential;
    QRadioButton *rbNormal;
    QRadioButton *rbTangential_and_Normal;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rB_c0;
    QRadioButton *rB_c1;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cbDistance;
    QLineEdit *distance;
    QCheckBox *respectFeatures;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *sB_iter;
    QLabel *label3;
    QCheckBox *cbReinitialize;
    QPushButton *pB_smooth;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SmootherToolbar)
    {
        if (SmootherToolbar->objectName().isEmpty())
            SmootherToolbar->setObjectName(QString::fromUtf8("SmootherToolbar"));
        SmootherToolbar->resize(341, 584);
        verticalLayout_7 = new QVBoxLayout(SmootherToolbar);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_5 = new QGroupBox(SmootherToolbar);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbTangential = new QRadioButton(groupBox_5);
        rbTangential->setObjectName(QString::fromUtf8("rbTangential"));
        rbTangential->setChecked(false);

        verticalLayout->addWidget(rbTangential);

        rbNormal = new QRadioButton(groupBox_5);
        rbNormal->setObjectName(QString::fromUtf8("rbNormal"));

        verticalLayout->addWidget(rbNormal);

        rbTangential_and_Normal = new QRadioButton(groupBox_5);
        rbTangential_and_Normal->setObjectName(QString::fromUtf8("rbTangential_and_Normal"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rbTangential_and_Normal->sizePolicy().hasHeightForWidth());
        rbTangential_and_Normal->setSizePolicy(sizePolicy);
        rbTangential_and_Normal->setChecked(true);

        verticalLayout->addWidget(rbTangential_and_Normal);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_7->addWidget(groupBox_5);

        groupBox_4 = new QGroupBox(SmootherToolbar);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rB_c0 = new QRadioButton(groupBox_4);
        rB_c0->setObjectName(QString::fromUtf8("rB_c0"));
        rB_c0->setChecked(true);

        horizontalLayout->addWidget(rB_c0);

        rB_c1 = new QRadioButton(groupBox_4);
        rB_c1->setObjectName(QString::fromUtf8("rB_c1"));

        horizontalLayout->addWidget(rB_c1);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_7->addWidget(groupBox_4);

        groupBox = new QGroupBox(SmootherToolbar);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cbDistance = new QCheckBox(groupBox);
        cbDistance->setObjectName(QString::fromUtf8("cbDistance"));

        horizontalLayout_2->addWidget(cbDistance);

        distance = new QLineEdit(groupBox);
        distance->setObjectName(QString::fromUtf8("distance"));

        horizontalLayout_2->addWidget(distance);


        verticalLayout_4->addLayout(horizontalLayout_2);

        respectFeatures = new QCheckBox(groupBox);
        respectFeatures->setObjectName(QString::fromUtf8("respectFeatures"));

        verticalLayout_4->addWidget(respectFeatures);


        verticalLayout_7->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SmootherToolbar);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        sB_iter = new QSpinBox(groupBox_2);
        sB_iter->setObjectName(QString::fromUtf8("sB_iter"));
        sB_iter->setMaximum(9999);
        sB_iter->setValue(5);

        horizontalLayout_3->addWidget(sB_iter);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        label3 = new QLabel(groupBox_2);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setWordWrap(false);

        gridLayout->addWidget(label3, 0, 0, 1, 1);

        cbReinitialize = new QCheckBox(groupBox_2);
        cbReinitialize->setObjectName(QString::fromUtf8("cbReinitialize"));
        cbReinitialize->setChecked(true);

        gridLayout->addWidget(cbReinitialize, 2, 0, 1, 1);

        pB_smooth = new QPushButton(groupBox_2);
        pB_smooth->setObjectName(QString::fromUtf8("pB_smooth"));
        pB_smooth->setEnabled(true);

        gridLayout->addWidget(pB_smooth, 2, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout);


        verticalLayout_7->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        retranslateUi(SmootherToolbar);

        QMetaObject::connectSlotsByName(SmootherToolbar);
    } // setupUi

    void retranslateUi(QWidget *SmootherToolbar)
    {
        SmootherToolbar->setWindowTitle(QApplication::translate("SmootherToolbar", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_5->setToolTip(QApplication::translate("SmootherToolbar", "Set the smoothing directions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_5->setStatusTip(QApplication::translate("SmootherToolbar", "Set the smoothing directions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        groupBox_5->setTitle(QApplication::translate("SmootherToolbar", "Component", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbTangential->setToolTip(QApplication::translate("SmootherToolbar", "Smooth in tangent direction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rbTangential->setStatusTip(QApplication::translate("SmootherToolbar", "Smooth in tangent direction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rbTangential->setText(QApplication::translate("SmootherToolbar", "Tangential", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbNormal->setToolTip(QApplication::translate("SmootherToolbar", "Smooth in normal direction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rbNormal->setStatusTip(QApplication::translate("SmootherToolbar", "Smooth in normal direction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rbNormal->setText(QApplication::translate("SmootherToolbar", "Normal", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbTangential_and_Normal->setToolTip(QApplication::translate("SmootherToolbar", "Smooth in tangent and normal direction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rbTangential_and_Normal->setStatusTip(QApplication::translate("SmootherToolbar", "Smooth in tangent and normal direction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rbTangential_and_Normal->setText(QApplication::translate("SmootherToolbar", "Tangential+Normal", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_4->setToolTip(QApplication::translate("SmootherToolbar", "Set the continuity that should be used", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_4->setStatusTip(QApplication::translate("SmootherToolbar", "Set the continuity that should be used", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        groupBox_4->setTitle(QApplication::translate("SmootherToolbar", "Continuity", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rB_c0->setToolTip(QApplication::translate("SmootherToolbar", "use C0 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rB_c0->setStatusTip(QApplication::translate("SmootherToolbar", "use C0 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rB_c0->setText(QApplication::translate("SmootherToolbar", "C0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rB_c1->setToolTip(QApplication::translate("SmootherToolbar", "use C1 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rB_c1->setStatusTip(QApplication::translate("SmootherToolbar", "use C1 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rB_c1->setText(QApplication::translate("SmootherToolbar", "C1", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SmootherToolbar", "Constraints", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cbDistance->setToolTip(QApplication::translate("SmootherToolbar", "the maximum distance that the smoothed mesh is allowed to differ from the original mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        cbDistance->setStatusTip(QApplication::translate("SmootherToolbar", "the maximum distance that the smoothed mesh is allowed to differ from the original mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        cbDistance->setText(QApplication::translate("SmootherToolbar", "Distance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        distance->setToolTip(QApplication::translate("SmootherToolbar", "the maximum distance that the smoothed mesh is allowed to differ from the original mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        distance->setStatusTip(QApplication::translate("SmootherToolbar", "the maximum distance that the smoothed mesh is allowed to differ from the original mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        respectFeatures->setText(QApplication::translate("SmootherToolbar", "Respect Features", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SmootherToolbar", "Smoothing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sB_iter->setToolTip(QApplication::translate("SmootherToolbar", "number of smoothing iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        sB_iter->setStatusTip(QApplication::translate("SmootherToolbar", "number of smoothing iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        label3->setToolTip(QApplication::translate("SmootherToolbar", "number of smoothing iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label3->setStatusTip(QApplication::translate("SmootherToolbar", "number of smoothing iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label3->setText(QApplication::translate("SmootherToolbar", "Iterations", 0, QApplication::UnicodeUTF8));
        cbReinitialize->setText(QApplication::translate("SmootherToolbar", "Re-Init Weights", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pB_smooth->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pB_smooth->setText(QApplication::translate("SmootherToolbar", "Smooth", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SmootherToolbar: public Ui_SmootherToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMOOTHERTOOLBAR_H
