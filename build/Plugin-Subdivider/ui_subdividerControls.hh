/********************************************************************************
** Form generated from reading UI file 'subdividerControls.ui'
**
** Created: Sat May 18 02:59:16 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBDIVIDERCONTROLS_H
#define UI_SUBDIVIDERCONTROLS_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubdividerControls
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *Uniform;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *subdivision_steps_spinBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *loop_radioButton;
    QRadioButton *sqrt3_radioButton;
    QRadioButton *LabsikGreiner_radioButton;
    QRadioButton *modifiedButterfly_radioButton;
    QRadioButton *catmullClark_radioButton;
    QCheckBox *updatePoints;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *subdivide_uniform_toolButton;
    QSpacerItem *horizontalSpacer;
    QWidget *Simple;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *longestEdgeSplit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QDoubleSpinBox *maximalEdgeLength;
    QSpacerItem *verticalSpacer_2;
    QPushButton *simpleButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SubdividerControls)
    {
        if (SubdividerControls->objectName().isEmpty())
            SubdividerControls->setObjectName(QString::fromUtf8("SubdividerControls"));
        SubdividerControls->resize(410, 646);
        verticalLayout_4 = new QVBoxLayout(SubdividerControls);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tabWidget = new QTabWidget(SubdividerControls);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        Uniform = new QWidget();
        Uniform->setObjectName(QString::fromUtf8("Uniform"));
        verticalLayout_3 = new QVBoxLayout(Uniform);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(Uniform);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        subdivision_steps_spinBox = new QSpinBox(Uniform);
        subdivision_steps_spinBox->setObjectName(QString::fromUtf8("subdivision_steps_spinBox"));
        subdivision_steps_spinBox->setValue(1);

        horizontalLayout_3->addWidget(subdivision_steps_spinBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(Uniform);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loop_radioButton = new QRadioButton(groupBox);
        loop_radioButton->setObjectName(QString::fromUtf8("loop_radioButton"));
        loop_radioButton->setChecked(true);

        horizontalLayout->addWidget(loop_radioButton);


        verticalLayout->addLayout(horizontalLayout);

        sqrt3_radioButton = new QRadioButton(groupBox);
        sqrt3_radioButton->setObjectName(QString::fromUtf8("sqrt3_radioButton"));

        verticalLayout->addWidget(sqrt3_radioButton);

        LabsikGreiner_radioButton = new QRadioButton(groupBox);
        LabsikGreiner_radioButton->setObjectName(QString::fromUtf8("LabsikGreiner_radioButton"));

        verticalLayout->addWidget(LabsikGreiner_radioButton);

        modifiedButterfly_radioButton = new QRadioButton(groupBox);
        modifiedButterfly_radioButton->setObjectName(QString::fromUtf8("modifiedButterfly_radioButton"));

        verticalLayout->addWidget(modifiedButterfly_radioButton);

        catmullClark_radioButton = new QRadioButton(groupBox);
        catmullClark_radioButton->setObjectName(QString::fromUtf8("catmullClark_radioButton"));

        verticalLayout->addWidget(catmullClark_radioButton);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        updatePoints = new QCheckBox(groupBox);
        updatePoints->setObjectName(QString::fromUtf8("updatePoints"));
        updatePoints->setEnabled(true);
        updatePoints->setCheckable(true);
        updatePoints->setChecked(true);

        verticalLayout_2->addWidget(updatePoints);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        subdivide_uniform_toolButton = new QToolButton(groupBox);
        subdivide_uniform_toolButton->setObjectName(QString::fromUtf8("subdivide_uniform_toolButton"));

        horizontalLayout_4->addWidget(subdivide_uniform_toolButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(groupBox);

        tabWidget->addTab(Uniform, QString());
        Simple = new QWidget();
        Simple->setObjectName(QString::fromUtf8("Simple"));
        verticalLayout_5 = new QVBoxLayout(Simple);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        longestEdgeSplit = new QRadioButton(Simple);
        longestEdgeSplit->setObjectName(QString::fromUtf8("longestEdgeSplit"));
        longestEdgeSplit->setChecked(true);

        horizontalLayout_6->addWidget(longestEdgeSplit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_3 = new QLabel(Simple);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        maximalEdgeLength = new QDoubleSpinBox(Simple);
        maximalEdgeLength->setObjectName(QString::fromUtf8("maximalEdgeLength"));
        maximalEdgeLength->setDecimals(3);
        maximalEdgeLength->setMinimum(0);
        maximalEdgeLength->setMaximum(1000);
        maximalEdgeLength->setValue(1);

        horizontalLayout_5->addWidget(maximalEdgeLength);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        simpleButton = new QPushButton(Simple);
        simpleButton->setObjectName(QString::fromUtf8("simpleButton"));

        verticalLayout_5->addWidget(simpleButton);

        tabWidget->addTab(Simple, QString());

        verticalLayout_4->addWidget(tabWidget);

        verticalSpacer = new QSpacerItem(20, 495, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        retranslateUi(SubdividerControls);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SubdividerControls);
    } // setupUi

    void retranslateUi(QWidget *SubdividerControls)
    {
        SubdividerControls->setWindowTitle(QApplication::translate("SubdividerControls", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SubdividerControls", "Subdivision steps:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SubdividerControls", "Uniform Subdivision", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SubdividerControls", "Method:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        loop_radioButton->setToolTip(QApplication::translate("SubdividerControls", "C. T. Loop, \"Smooth Subdivision Surfaces Based on Triangles\",\n"
"M.S. Thesis, Department of Mathematics, University of Utah, August 1987.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        loop_radioButton->setText(QApplication::translate("SubdividerControls", "Loop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sqrt3_radioButton->setToolTip(QApplication::translate("SubdividerControls", "L. Kobbelt, <a href=\"http://www-i8.informatik.rwth-aachen.de/publications/downloads/sqrt3.pdf\">\"Sqrt(3) subdivision\"</a>, Proceedings of SIGGRAPH 2000.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        sqrt3_radioButton->setText(QApplication::translate("SubdividerControls", "Sqrt3", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        LabsikGreiner_radioButton->setToolTip(QApplication::translate("SubdividerControls", "Interpolating Labsik Greiner Subdivider as described in \"interpolating sqrt(3) subdivision\" Labsik & Greiner, 2000", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        LabsikGreiner_radioButton->setText(QApplication::translate("SubdividerControls", "Interpolating Sqrt3", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        modifiedButterfly_radioButton->setToolTip(QApplication::translate("SubdividerControls", "The modified butterfly scheme of Denis Zorin, Peter Schr\303\266der and Wim Sweldens, \n"
"``Interpolating subdivision for meshes with arbitrary topology,'' in Proceedings \n"
"of SIGGRAPH 1996, ACM SIGGRAPH, 1996, pp. 189-192.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        modifiedButterfly_radioButton->setText(QApplication::translate("SubdividerControls", "Modified Butterfly", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        catmullClark_radioButton->setToolTip(QApplication::translate("SubdividerControls", "<html><head/><body><p>Catmull Clark subdivision</p><p><br/></p><p><span style=\" font-weight:600;\">Note: Only works on quadrangular meshes!</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        catmullClark_radioButton->setText(QApplication::translate("SubdividerControls", "Catmull Clark", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        updatePoints->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        updatePoints->setText(QApplication::translate("SubdividerControls", "Update Points", 0, QApplication::UnicodeUTF8));
        subdivide_uniform_toolButton->setText(QApplication::translate("SubdividerControls", "Uniform Subdivide", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Uniform), QApplication::translate("SubdividerControls", "Uniform", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        longestEdgeSplit->setToolTip(QApplication::translate("SubdividerControls", "This algorithm splits edges longer than the given maximal length. For each split, the longest edge is split at its midpoint.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        longestEdgeSplit->setText(QApplication::translate("SubdividerControls", "Longest Edge ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SubdividerControls", "Max Edge Length", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        maximalEdgeLength->setToolTip(QApplication::translate("SubdividerControls", "Maximal edge length after the algorithm", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        simpleButton->setText(QApplication::translate("SubdividerControls", "Subdivide", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Simple), QApplication::translate("SubdividerControls", "Simple", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubdividerControls: public Ui_SubdividerControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBDIVIDERCONTROLS_H
