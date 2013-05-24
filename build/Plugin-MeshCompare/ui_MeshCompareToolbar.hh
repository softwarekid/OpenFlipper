/********************************************************************************
** Form generated from reading UI file 'MeshCompareToolbar.ui'
**
** Created: Sat May 18 02:56:34 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHCOMPARETOOLBAR_H
#define UI_MESHCOMPARETOOLBAR_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeshCompareToolbar
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *distance;
    QRadioButton *normalAngle;
    QRadioButton *meanCurvature;
    QRadioButton *gaussCurvature;
    QGroupBox *frame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *minValue;
    QLabel *label_4;
    QLabel *maxValue;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *doClamp;
    QDoubleSpinBox *minVal;
    QDoubleSpinBox *maxVal;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *compare;
    QPushButton *clear;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MeshCompareToolbar)
    {
        if (MeshCompareToolbar->objectName().isEmpty())
            MeshCompareToolbar->setObjectName(QString::fromUtf8("MeshCompareToolbar"));
        MeshCompareToolbar->resize(304, 368);
        verticalLayout_2 = new QVBoxLayout(MeshCompareToolbar);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_5 = new QGroupBox(MeshCompareToolbar);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        distance = new QRadioButton(groupBox_5);
        distance->setObjectName(QString::fromUtf8("distance"));
        distance->setChecked(true);

        verticalLayout->addWidget(distance);

        normalAngle = new QRadioButton(groupBox_5);
        normalAngle->setObjectName(QString::fromUtf8("normalAngle"));

        verticalLayout->addWidget(normalAngle);

        meanCurvature = new QRadioButton(groupBox_5);
        meanCurvature->setObjectName(QString::fromUtf8("meanCurvature"));

        verticalLayout->addWidget(meanCurvature);

        gaussCurvature = new QRadioButton(groupBox_5);
        gaussCurvature->setObjectName(QString::fromUtf8("gaussCurvature"));

        verticalLayout->addWidget(gaussCurvature);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addWidget(groupBox_5);

        frame = new QGroupBox(MeshCompareToolbar);
        frame->setObjectName(QString::fromUtf8("frame"));

        verticalLayout_2->addWidget(frame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(MeshCompareToolbar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        minValue = new QLabel(MeshCompareToolbar);
        minValue->setObjectName(QString::fromUtf8("minValue"));

        horizontalLayout_3->addWidget(minValue);

        label_4 = new QLabel(MeshCompareToolbar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        maxValue = new QLabel(MeshCompareToolbar);
        maxValue->setObjectName(QString::fromUtf8("maxValue"));

        horizontalLayout_3->addWidget(maxValue);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        doClamp = new QCheckBox(MeshCompareToolbar);
        doClamp->setObjectName(QString::fromUtf8("doClamp"));

        horizontalLayout_4->addWidget(doClamp);

        minVal = new QDoubleSpinBox(MeshCompareToolbar);
        minVal->setObjectName(QString::fromUtf8("minVal"));
        minVal->setDecimals(5);
        minVal->setSingleStep(0.01);

        horizontalLayout_4->addWidget(minVal);

        maxVal = new QDoubleSpinBox(MeshCompareToolbar);
        maxVal->setObjectName(QString::fromUtf8("maxVal"));
        maxVal->setDecimals(5);
        maxVal->setSingleStep(0.01);

        horizontalLayout_4->addWidget(maxVal);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        compare = new QPushButton(MeshCompareToolbar);
        compare->setObjectName(QString::fromUtf8("compare"));

        horizontalLayout->addWidget(compare);

        clear = new QPushButton(MeshCompareToolbar);
        clear->setObjectName(QString::fromUtf8("clear"));

        horizontalLayout->addWidget(clear);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(MeshCompareToolbar);

        QMetaObject::connectSlotsByName(MeshCompareToolbar);
    } // setupUi

    void retranslateUi(QWidget *MeshCompareToolbar)
    {
        MeshCompareToolbar->setWindowTitle(QApplication::translate("MeshCompareToolbar", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_5->setToolTip(QApplication::translate("MeshCompareToolbar", "Set the smoothing directions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_5->setStatusTip(QApplication::translate("MeshCompareToolbar", "Set the smoothing directions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        groupBox_5->setTitle(QApplication::translate("MeshCompareToolbar", "Property", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        distance->setToolTip(QApplication::translate("MeshCompareToolbar", "Compare distance between meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        distance->setStatusTip(QApplication::translate("MeshCompareToolbar", "Compare distance between meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        distance->setText(QApplication::translate("MeshCompareToolbar", "Distance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        normalAngle->setToolTip(QApplication::translate("MeshCompareToolbar", "Compare normal deviation between meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        normalAngle->setStatusTip(QApplication::translate("MeshCompareToolbar", "Compare normal deviation between meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        normalAngle->setText(QApplication::translate("MeshCompareToolbar", "Normal", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        meanCurvature->setToolTip(QApplication::translate("MeshCompareToolbar", "Compare mean curvature between meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        meanCurvature->setStatusTip(QApplication::translate("MeshCompareToolbar", "Compare mean curvature between meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        meanCurvature->setText(QApplication::translate("MeshCompareToolbar", "Mean curvature", 0, QApplication::UnicodeUTF8));
        gaussCurvature->setText(QApplication::translate("MeshCompareToolbar", "Gauss curvature", 0, QApplication::UnicodeUTF8));
        frame->setTitle(QApplication::translate("MeshCompareToolbar", "Histogramm", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MeshCompareToolbar", "Min:", 0, QApplication::UnicodeUTF8));
        minValue->setText(QApplication::translate("MeshCompareToolbar", "MinValue", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MeshCompareToolbar", "Max:", 0, QApplication::UnicodeUTF8));
        maxValue->setText(QApplication::translate("MeshCompareToolbar", "MaxValue", 0, QApplication::UnicodeUTF8));
        doClamp->setText(QApplication::translate("MeshCompareToolbar", "Clamp", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        compare->setToolTip(QApplication::translate("MeshCompareToolbar", "Compute distance between to meshes.\n"
"\n"
"Select one source mesh(the reference) and one target mesh. The points of the reference are projected onto target and the deviation(distance,normal) gets visualized by colored points.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        compare->setText(QApplication::translate("MeshCompareToolbar", "Compare", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("MeshCompareToolbar", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MeshCompareToolbar: public Ui_MeshCompareToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHCOMPARETOOLBAR_H
