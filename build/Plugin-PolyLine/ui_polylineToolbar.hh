/********************************************************************************
** Form generated from reading UI file 'polylineToolbar.ui'
**
** Created: Sat May 18 02:57:14 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLYLINETOOLBAR_H
#define UI_POLYLINETOOLBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PolyLineToolbar
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QRadioButton *rb_insert;
    QRadioButton *rb_delete;
    QRadioButton *rb_move;
    QVBoxLayout *vboxLayout1;
    QRadioButton *rb_smart_move;
    QRadioButton *rb_merge;
    QRadioButton *rb_split;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hboxLayout1;
    QLabel *label;
    QRadioButton *rb_smooth_c0;
    QRadioButton *rb_smooth_c1;
    QRadioButton *rb_smooth_c2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *sb_smooth_iter;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_smooth;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line_4;
    QLabel *label_4;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *sb_smooth_project_iter;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_project;
    QFrame *line;
    QPushButton *pb_smooth_project;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout2;
    QPushButton *pb_resample_on_edges;
    QGridLayout *gridLayout;
    QDoubleSpinBox *dsb_subdivide;
    QDoubleSpinBox *dsb_decimate;
    QPushButton *pb_decimate;
    QPushButton *pb_subdivide;
    QCheckBox *subdivide_relative;
    QCheckBox *decimate_relative;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PolyLineToolbar)
    {
        if (PolyLineToolbar->objectName().isEmpty())
            PolyLineToolbar->setObjectName(QString::fromUtf8("PolyLineToolbar"));
        PolyLineToolbar->resize(388, 713);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PolyLineToolbar->sizePolicy().hasHeightForWidth());
        PolyLineToolbar->setSizePolicy(sizePolicy);
        PolyLineToolbar->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(PolyLineToolbar);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(PolyLineToolbar);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setAlignment(Qt::AlignCenter);
        hboxLayout = new QHBoxLayout(groupBox);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        rb_insert = new QRadioButton(groupBox);
        rb_insert->setObjectName(QString::fromUtf8("rb_insert"));
        rb_insert->setChecked(true);

        vboxLayout->addWidget(rb_insert);

        rb_delete = new QRadioButton(groupBox);
        rb_delete->setObjectName(QString::fromUtf8("rb_delete"));

        vboxLayout->addWidget(rb_delete);

        rb_move = new QRadioButton(groupBox);
        rb_move->setObjectName(QString::fromUtf8("rb_move"));

        vboxLayout->addWidget(rb_move);


        hboxLayout->addLayout(vboxLayout);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        rb_smart_move = new QRadioButton(groupBox);
        rb_smart_move->setObjectName(QString::fromUtf8("rb_smart_move"));

        vboxLayout1->addWidget(rb_smart_move);

        rb_merge = new QRadioButton(groupBox);
        rb_merge->setObjectName(QString::fromUtf8("rb_merge"));

        vboxLayout1->addWidget(rb_merge);

        rb_split = new QRadioButton(groupBox);
        rb_split->setObjectName(QString::fromUtf8("rb_split"));

        vboxLayout1->addWidget(rb_split);


        hboxLayout->addLayout(vboxLayout1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PolyLineToolbar);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout1->addWidget(label);

        rb_smooth_c0 = new QRadioButton(groupBox_2);
        rb_smooth_c0->setObjectName(QString::fromUtf8("rb_smooth_c0"));
        rb_smooth_c0->setChecked(false);

        hboxLayout1->addWidget(rb_smooth_c0);

        rb_smooth_c1 = new QRadioButton(groupBox_2);
        rb_smooth_c1->setObjectName(QString::fromUtf8("rb_smooth_c1"));
        rb_smooth_c1->setChecked(true);

        hboxLayout1->addWidget(rb_smooth_c1);

        rb_smooth_c2 = new QRadioButton(groupBox_2);
        rb_smooth_c2->setObjectName(QString::fromUtf8("rb_smooth_c2"));

        hboxLayout1->addWidget(rb_smooth_c2);


        verticalLayout->addLayout(hboxLayout1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        sb_smooth_iter = new QSpinBox(groupBox_2);
        sb_smooth_iter->setObjectName(QString::fromUtf8("sb_smooth_iter"));
        sb_smooth_iter->setMaximum(9999);
        sb_smooth_iter->setValue(5);

        horizontalLayout_3->addWidget(sb_smooth_iter);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pb_smooth = new QPushButton(groupBox_2);
        pb_smooth->setObjectName(QString::fromUtf8("pb_smooth"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_smooth->sizePolicy().hasHeightForWidth());
        pb_smooth->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(pb_smooth);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        line_4 = new QFrame(groupBox_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        sizePolicy2.setHeightForWidth(line_4->sizePolicy().hasHeightForWidth());
        line_4->setSizePolicy(sizePolicy2);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_4);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        line_5 = new QFrame(groupBox_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        sizePolicy2.setHeightForWidth(line_5->sizePolicy().hasHeightForWidth());
        line_5->setSizePolicy(sizePolicy2);
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        sb_smooth_project_iter = new QSpinBox(groupBox_2);
        sb_smooth_project_iter->setObjectName(QString::fromUtf8("sb_smooth_project_iter"));
        sb_smooth_project_iter->setMaximum(9999);
        sb_smooth_project_iter->setValue(1);

        horizontalLayout_4->addWidget(sb_smooth_project_iter);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pb_project = new QPushButton(groupBox_2);
        pb_project->setObjectName(QString::fromUtf8("pb_project"));
        sizePolicy2.setHeightForWidth(pb_project->sizePolicy().hasHeightForWidth());
        pb_project->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(pb_project);


        verticalLayout->addLayout(horizontalLayout_6);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        pb_smooth_project = new QPushButton(groupBox_2);
        pb_smooth_project->setObjectName(QString::fromUtf8("pb_smooth_project"));

        verticalLayout->addWidget(pb_smooth_project);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(PolyLineToolbar);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        vboxLayout2 = new QVBoxLayout(groupBox_3);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        pb_resample_on_edges = new QPushButton(groupBox_3);
        pb_resample_on_edges->setObjectName(QString::fromUtf8("pb_resample_on_edges"));

        vboxLayout2->addWidget(pb_resample_on_edges);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dsb_subdivide = new QDoubleSpinBox(groupBox_3);
        dsb_subdivide->setObjectName(QString::fromUtf8("dsb_subdivide"));
        dsb_subdivide->setDecimals(4);
        dsb_subdivide->setMaximum(1e+08);
        dsb_subdivide->setSingleStep(0.01);
        dsb_subdivide->setValue(0.05);

        gridLayout->addWidget(dsb_subdivide, 0, 1, 1, 1);

        dsb_decimate = new QDoubleSpinBox(groupBox_3);
        dsb_decimate->setObjectName(QString::fromUtf8("dsb_decimate"));
        dsb_decimate->setDecimals(4);
        dsb_decimate->setMaximum(1e+07);
        dsb_decimate->setSingleStep(0.01);
        dsb_decimate->setValue(0.05);

        gridLayout->addWidget(dsb_decimate, 1, 1, 1, 1);

        pb_decimate = new QPushButton(groupBox_3);
        pb_decimate->setObjectName(QString::fromUtf8("pb_decimate"));

        gridLayout->addWidget(pb_decimate, 1, 0, 1, 1);

        pb_subdivide = new QPushButton(groupBox_3);
        pb_subdivide->setObjectName(QString::fromUtf8("pb_subdivide"));

        gridLayout->addWidget(pb_subdivide, 0, 0, 1, 1);

        subdivide_relative = new QCheckBox(groupBox_3);
        subdivide_relative->setObjectName(QString::fromUtf8("subdivide_relative"));
        subdivide_relative->setChecked(true);

        gridLayout->addWidget(subdivide_relative, 0, 2, 1, 1);

        decimate_relative = new QCheckBox(groupBox_3);
        decimate_relative->setObjectName(QString::fromUtf8("decimate_relative"));
        decimate_relative->setChecked(true);

        gridLayout->addWidget(decimate_relative, 1, 2, 1, 1);


        vboxLayout2->addLayout(gridLayout);


        verticalLayout_2->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(PolyLineToolbar);

        QMetaObject::connectSlotsByName(PolyLineToolbar);
    } // setupUi

    void retranslateUi(QWidget *PolyLineToolbar)
    {
        PolyLineToolbar->setWindowTitle(QApplication::translate("PolyLineToolbar", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PolyLineToolbar", "Mouse Mode", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_insert->setToolTip(QApplication::translate("PolyLineToolbar", "Insert a new Polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_insert->setStatusTip(QApplication::translate("PolyLineToolbar", "Insert a new Polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_insert->setText(QApplication::translate("PolyLineToolbar", "Insert", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_delete->setToolTip(QApplication::translate("PolyLineToolbar", "Delete a Polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_delete->setStatusTip(QApplication::translate("PolyLineToolbar", "Delete a Polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_delete->setText(QApplication::translate("PolyLineToolbar", "Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_move->setToolTip(QApplication::translate("PolyLineToolbar", "Move a Point of a Polyline while keeping all others fixed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_move->setStatusTip(QApplication::translate("PolyLineToolbar", "Move a Point of a Polyline while keeping all others fixed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_move->setText(QApplication::translate("PolyLineToolbar", "Move Point", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_smart_move->setToolTip(QApplication::translate("PolyLineToolbar", "Move Points of a Polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_smart_move->setStatusTip(QApplication::translate("PolyLineToolbar", "Move Points of a Polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_smart_move->setText(QApplication::translate("PolyLineToolbar", "Smart Move", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_merge->setToolTip(QApplication::translate("PolyLineToolbar", "Merge two Polylines", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_merge->setStatusTip(QApplication::translate("PolyLineToolbar", "Merge two Polylines", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_merge->setText(QApplication::translate("PolyLineToolbar", "Merge", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_split->setToolTip(QApplication::translate("PolyLineToolbar", "Split a Polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_split->setStatusTip(QApplication::translate("PolyLineToolbar", "Split a Polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_split->setText(QApplication::translate("PolyLineToolbar", "Split", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("PolyLineToolbar", "Smoothing", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PolyLineToolbar", "Continuity:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_smooth_c0->setToolTip(QApplication::translate("PolyLineToolbar", "C0 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_smooth_c0->setStatusTip(QApplication::translate("PolyLineToolbar", "C0 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_smooth_c0->setText(QApplication::translate("PolyLineToolbar", "C0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_smooth_c1->setToolTip(QApplication::translate("PolyLineToolbar", "C1 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_smooth_c1->setStatusTip(QApplication::translate("PolyLineToolbar", "C1 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_smooth_c1->setText(QApplication::translate("PolyLineToolbar", "C1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rb_smooth_c2->setToolTip(QApplication::translate("PolyLineToolbar", "C2 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rb_smooth_c2->setStatusTip(QApplication::translate("PolyLineToolbar", "C2 continuity", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rb_smooth_c2->setText(QApplication::translate("PolyLineToolbar", "C2", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PolyLineToolbar", "Iterations:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sb_smooth_iter->setToolTip(QApplication::translate("PolyLineToolbar", "Smoothing Iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        sb_smooth_iter->setStatusTip(QApplication::translate("PolyLineToolbar", "Smoothing Iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        pb_smooth->setToolTip(QApplication::translate("PolyLineToolbar", "Smooth the target polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pb_smooth->setStatusTip(QApplication::translate("PolyLineToolbar", "Smooth the target polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pb_smooth->setText(QApplication::translate("PolyLineToolbar", "Smooth", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PolyLineToolbar", "Project", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PolyLineToolbar", "Iterations:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sb_smooth_project_iter->setToolTip(QApplication::translate("PolyLineToolbar", "Projection Iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        sb_smooth_project_iter->setStatusTip(QApplication::translate("PolyLineToolbar", "Projection Iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        pb_project->setToolTip(QApplication::translate("PolyLineToolbar", "Project the Polyline onto the object", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pb_project->setStatusTip(QApplication::translate("PolyLineToolbar", "Project the Polyline onto the object", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pb_project->setText(QApplication::translate("PolyLineToolbar", "Project", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pb_smooth_project->setToolTip(QApplication::translate("PolyLineToolbar", "Smooth the Polyline and project onto the object", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pb_smooth_project->setStatusTip(QApplication::translate("PolyLineToolbar", "Smooth the Polyline and project onto the object", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pb_smooth_project->setText(QApplication::translate("PolyLineToolbar", "Smooth + Project", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("PolyLineToolbar", "Resampling", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pb_resample_on_edges->setToolTip(QApplication::translate("PolyLineToolbar", "Resample on edges", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pb_resample_on_edges->setStatusTip(QApplication::translate("PolyLineToolbar", "Resample on edges", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pb_resample_on_edges->setText(QApplication::translate("PolyLineToolbar", "Resample on Edges", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dsb_subdivide->setToolTip(QApplication::translate("PolyLineToolbar", "Absolute segment length", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        dsb_subdivide->setStatusTip(QApplication::translate("PolyLineToolbar", "Absolute segment length", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        dsb_decimate->setToolTip(QApplication::translate("PolyLineToolbar", "Absolute segment length", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        dsb_decimate->setStatusTip(QApplication::translate("PolyLineToolbar", "Absolute segment length", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        pb_decimate->setToolTip(QApplication::translate("PolyLineToolbar", "Decimate the target polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pb_decimate->setStatusTip(QApplication::translate("PolyLineToolbar", "Decimate the target polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pb_decimate->setText(QApplication::translate("PolyLineToolbar", "Decimate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pb_subdivide->setToolTip(QApplication::translate("PolyLineToolbar", "Subdivide the target polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pb_subdivide->setStatusTip(QApplication::translate("PolyLineToolbar", "Subdivide the target polyline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pb_subdivide->setText(QApplication::translate("PolyLineToolbar", "Subdivide", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        subdivide_relative->setToolTip(QApplication::translate("PolyLineToolbar", "If this option is checked, interpret value as relative portion of the absolute line segment's length. If this option is unchecked, the current relative value is automatically converted to the corresponding absolute length. If this option is re-checked, the current absolute value is converted to the corresponding relative portion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        subdivide_relative->setText(QApplication::translate("PolyLineToolbar", "Relative", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        decimate_relative->setToolTip(QApplication::translate("PolyLineToolbar", "If this option is checked, interpret value as relative portion of the absolute line segment's length. If this option is unchecked, the current relative value is automatically converted to the corresponding absolute length. If this option is re-checked, the current absolute value is converted to the corresponding relative portion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        decimate_relative->setText(QApplication::translate("PolyLineToolbar", "Relative", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PolyLineToolbar: public Ui_PolyLineToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLYLINETOOLBAR_H
