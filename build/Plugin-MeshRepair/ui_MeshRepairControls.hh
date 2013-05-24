/********************************************************************************
** Form generated from reading UI file 'MeshRepairControls.ui'
**
** Created: Sat May 18 02:56:40 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHREPAIRCONTROLS_H
#define UI_MESHREPAIRCONTROLS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeshRepairControls
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *valenceThreeButton;
    QLabel *label_9;
    QDoubleSpinBox *valenceThreeSpinbox;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *repairRemoveVButton;
    QFrame *line_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *detectELargerButton;
    QPushButton *detectEShorterButton;
    QDoubleSpinBox *edgeSpin;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *repairCollapseEButton;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *detectCapAngle;
    QLabel *label_2;
    QDoubleSpinBox *capAngleSpinbox;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *repairFlipEButton;
    QFrame *line;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *detectFoldoverButton;
    QLabel *label;
    QDoubleSpinBox *detectFoldoverSpinbox;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *triangleAspectButton;
    QLabel *label_3;
    QDoubleSpinBox *triangleAspectSpinbox;
    QFrame *line_4;
    QLabel *label_12;
    QPushButton *flipOrientation;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *computeNormals;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *computeVertexNormals;
    QPushButton *computeHalfedgeNormals;
    QPushButton *computeFaceNormals;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *snapBoundaryButton;
    QLabel *label_10;
    QDoubleSpinBox *snapBoundarySpinBox;
    QPushButton *fixNonManifoldVerticesButton;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *fixMeshButton;
    QLabel *label_14;
    QDoubleSpinBox *fixMeshBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MeshRepairControls)
    {
        if (MeshRepairControls->objectName().isEmpty())
            MeshRepairControls->setObjectName(QString::fromUtf8("MeshRepairControls"));
        verticalLayout = new QVBoxLayout(MeshRepairControls);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_3 = new QGroupBox(MeshRepairControls);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_6->addWidget(label_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        valenceThreeButton = new QPushButton(groupBox_3);
        valenceThreeButton->setObjectName(QString::fromUtf8("valenceThreeButton"));

        horizontalLayout_10->addWidget(valenceThreeButton);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        valenceThreeSpinbox = new QDoubleSpinBox(groupBox_3);
        valenceThreeSpinbox->setObjectName(QString::fromUtf8("valenceThreeSpinbox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(80);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(valenceThreeSpinbox->sizePolicy().hasHeightForWidth());
        valenceThreeSpinbox->setSizePolicy(sizePolicy);
        valenceThreeSpinbox->setMaximum(180);
        valenceThreeSpinbox->setSingleStep(0.1);
        valenceThreeSpinbox->setValue(30);

        horizontalLayout_10->addWidget(valenceThreeSpinbox);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        repairRemoveVButton = new QPushButton(groupBox_3);
        repairRemoveVButton->setObjectName(QString::fromUtf8("repairRemoveVButton"));

        horizontalLayout_11->addWidget(repairRemoveVButton);


        verticalLayout_6->addLayout(horizontalLayout_11);

        line_3 = new QFrame(groupBox_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_3);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(MeshRepairControls);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        detectELargerButton = new QPushButton(groupBox);
        detectELargerButton->setObjectName(QString::fromUtf8("detectELargerButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(detectELargerButton->sizePolicy().hasHeightForWidth());
        detectELargerButton->setSizePolicy(sizePolicy1);
        detectELargerButton->setMinimumSize(QSize(0, 18));

        verticalLayout_5->addWidget(detectELargerButton);

        detectEShorterButton = new QPushButton(groupBox);
        detectEShorterButton->setObjectName(QString::fromUtf8("detectEShorterButton"));
        sizePolicy1.setHeightForWidth(detectEShorterButton->sizePolicy().hasHeightForWidth());
        detectEShorterButton->setSizePolicy(sizePolicy1);
        detectEShorterButton->setMinimumSize(QSize(0, 18));

        verticalLayout_5->addWidget(detectEShorterButton);


        horizontalLayout_3->addLayout(verticalLayout_5);

        edgeSpin = new QDoubleSpinBox(groupBox);
        edgeSpin->setObjectName(QString::fromUtf8("edgeSpin"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(edgeSpin->sizePolicy().hasHeightForWidth());
        edgeSpin->setSizePolicy(sizePolicy2);
        edgeSpin->setDecimals(4);
        edgeSpin->setMaximum(1e+09);
        edgeSpin->setSingleStep(0.1);
        edgeSpin->setValue(1);

        horizontalLayout_3->addWidget(edgeSpin);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        repairCollapseEButton = new QPushButton(groupBox);
        repairCollapseEButton->setObjectName(QString::fromUtf8("repairCollapseEButton"));
        repairCollapseEButton->setEnabled(true);

        horizontalLayout_8->addWidget(repairCollapseEButton);


        verticalLayout_4->addLayout(horizontalLayout_8);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        detectCapAngle = new QPushButton(groupBox);
        detectCapAngle->setObjectName(QString::fromUtf8("detectCapAngle"));

        horizontalLayout->addWidget(detectCapAngle);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        capAngleSpinbox = new QDoubleSpinBox(groupBox);
        capAngleSpinbox->setObjectName(QString::fromUtf8("capAngleSpinbox"));
        sizePolicy2.setHeightForWidth(capAngleSpinbox->sizePolicy().hasHeightForWidth());
        capAngleSpinbox->setSizePolicy(sizePolicy2);
        capAngleSpinbox->setMinimumSize(QSize(80, 0));
        capAngleSpinbox->setMaximum(180);
        capAngleSpinbox->setSingleStep(0.1);
        capAngleSpinbox->setValue(170);

        horizontalLayout->addWidget(capAngleSpinbox);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        repairFlipEButton = new QPushButton(groupBox);
        repairFlipEButton->setObjectName(QString::fromUtf8("repairFlipEButton"));

        horizontalLayout_7->addWidget(repairFlipEButton);


        verticalLayout_4->addLayout(horizontalLayout_7);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        detectFoldoverButton = new QPushButton(groupBox);
        detectFoldoverButton->setObjectName(QString::fromUtf8("detectFoldoverButton"));

        horizontalLayout_2->addWidget(detectFoldoverButton);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        detectFoldoverSpinbox = new QDoubleSpinBox(groupBox);
        detectFoldoverSpinbox->setObjectName(QString::fromUtf8("detectFoldoverSpinbox"));
        sizePolicy2.setHeightForWidth(detectFoldoverSpinbox->sizePolicy().hasHeightForWidth());
        detectFoldoverSpinbox->setSizePolicy(sizePolicy2);
        detectFoldoverSpinbox->setMinimumSize(QSize(80, 0));
        detectFoldoverSpinbox->setSizeIncrement(QSize(0, 0));
        detectFoldoverSpinbox->setMaximum(180);
        detectFoldoverSpinbox->setSingleStep(0.1);
        detectFoldoverSpinbox->setValue(90);

        horizontalLayout_2->addWidget(detectFoldoverSpinbox);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox);

        groupBox_4 = new QGroupBox(MeshRepairControls);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        triangleAspectButton = new QPushButton(groupBox_4);
        triangleAspectButton->setObjectName(QString::fromUtf8("triangleAspectButton"));

        horizontalLayout_5->addWidget(triangleAspectButton);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        triangleAspectSpinbox = new QDoubleSpinBox(groupBox_4);
        triangleAspectSpinbox->setObjectName(QString::fromUtf8("triangleAspectSpinbox"));
        sizePolicy2.setHeightForWidth(triangleAspectSpinbox->sizePolicy().hasHeightForWidth());
        triangleAspectSpinbox->setSizePolicy(sizePolicy2);
        triangleAspectSpinbox->setDecimals(4);
        triangleAspectSpinbox->setMaximum(1e+09);
        triangleAspectSpinbox->setSingleStep(0.1);
        triangleAspectSpinbox->setValue(10);

        horizontalLayout_5->addWidget(triangleAspectSpinbox);


        verticalLayout_3->addLayout(horizontalLayout_5);

        line_4 = new QFrame(groupBox_4);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        flipOrientation = new QPushButton(groupBox_4);
        flipOrientation->setObjectName(QString::fromUtf8("flipOrientation"));

        verticalLayout_3->addWidget(flipOrientation);


        verticalLayout->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(MeshRepairControls);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        computeNormals = new QPushButton(groupBox_2);
        computeNormals->setObjectName(QString::fromUtf8("computeNormals"));

        verticalLayout_2->addWidget(computeNormals);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        computeVertexNormals = new QPushButton(groupBox_2);
        computeVertexNormals->setObjectName(QString::fromUtf8("computeVertexNormals"));

        horizontalLayout_12->addWidget(computeVertexNormals);

        computeHalfedgeNormals = new QPushButton(groupBox_2);
        computeHalfedgeNormals->setObjectName(QString::fromUtf8("computeHalfedgeNormals"));

        horizontalLayout_12->addWidget(computeHalfedgeNormals);

        computeFaceNormals = new QPushButton(groupBox_2);
        computeFaceNormals->setObjectName(QString::fromUtf8("computeFaceNormals"));

        horizontalLayout_12->addWidget(computeFaceNormals);


        verticalLayout_2->addLayout(horizontalLayout_12);


        verticalLayout->addWidget(groupBox_2);

        groupBox_5 = new QGroupBox(MeshRepairControls);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        snapBoundaryButton = new QPushButton(groupBox_5);
        snapBoundaryButton->setObjectName(QString::fromUtf8("snapBoundaryButton"));

        horizontalLayout_13->addWidget(snapBoundaryButton);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(label_10);

        snapBoundarySpinBox = new QDoubleSpinBox(groupBox_5);
        snapBoundarySpinBox->setObjectName(QString::fromUtf8("snapBoundarySpinBox"));
        sizePolicy2.setHeightForWidth(snapBoundarySpinBox->sizePolicy().hasHeightForWidth());
        snapBoundarySpinBox->setSizePolicy(sizePolicy2);
        snapBoundarySpinBox->setDecimals(6);
        snapBoundarySpinBox->setMinimum(0);
        snapBoundarySpinBox->setMaximum(1e+09);
        snapBoundarySpinBox->setSingleStep(0.1);
        snapBoundarySpinBox->setValue(0.5);

        horizontalLayout_13->addWidget(snapBoundarySpinBox);


        verticalLayout_7->addLayout(horizontalLayout_13);

        fixNonManifoldVerticesButton = new QPushButton(groupBox_5);
        fixNonManifoldVerticesButton->setObjectName(QString::fromUtf8("fixNonManifoldVerticesButton"));

        verticalLayout_7->addWidget(fixNonManifoldVerticesButton);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        fixMeshButton = new QPushButton(groupBox_5);
        fixMeshButton->setObjectName(QString::fromUtf8("fixMeshButton"));

        horizontalLayout_9->addWidget(fixMeshButton);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_9->addWidget(label_14);

        fixMeshBox = new QDoubleSpinBox(groupBox_5);
        fixMeshBox->setObjectName(QString::fromUtf8("fixMeshBox"));
        sizePolicy2.setHeightForWidth(fixMeshBox->sizePolicy().hasHeightForWidth());
        fixMeshBox->setSizePolicy(sizePolicy2);
        fixMeshBox->setDecimals(6);
        fixMeshBox->setMinimum(1e-05);
        fixMeshBox->setMaximum(1e+09);
        fixMeshBox->setSingleStep(0.1);
        fixMeshBox->setValue(0.01);

        horizontalLayout_9->addWidget(fixMeshBox);


        verticalLayout_7->addLayout(horizontalLayout_9);


        verticalLayout->addWidget(groupBox_5);

        verticalSpacer = new QSpacerItem(QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(MeshRepairControls);

        QMetaObject::connectSlotsByName(MeshRepairControls);
    } // setupUi

    void retranslateUi(QWidget *MeshRepairControls)
    {
        MeshRepairControls->setWindowTitle(QApplication::translate("MeshRepairControls", "controls", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MeshRepairControls", "Vertex operations", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MeshRepairControls", "Detect flat triangles (with valence 3 vertices):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        valenceThreeButton->setToolTip(QApplication::translate("MeshRepairControls", "Select all vertices of valence three which don't make the mesh much more detailed. This is indicated by very similar adjacent face normals: the area around the vertex is nearly planar.\n"
"\n"
"These vertices can usually be removed without destroying the features of the mesh.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        valenceThreeButton->setText(QApplication::translate("MeshRepairControls", "Select vertices", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MeshRepairControls", "with angle difference < ", 0, QApplication::UnicodeUTF8));
        valenceThreeSpinbox->setSuffix(QApplication::translate("MeshRepairControls", "\302\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        repairRemoveVButton->setToolTip(QApplication::translate("MeshRepairControls", "Repair the mesh by collapsing the previously selected valence 3 vertices.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        repairRemoveVButton->setText(QApplication::translate("MeshRepairControls", "Collapse selected vertices", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MeshRepairControls", "Edge operations", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MeshRepairControls", "Detect skinny triangles:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MeshRepairControls", "Select edges of length", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        detectELargerButton->setToolTip(QApplication::translate("MeshRepairControls", "Detect short edges", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        detectELargerButton->setStatusTip(QApplication::translate("MeshRepairControls", "Detect long edges", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        detectELargerButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        detectELargerButton->setText(QApplication::translate("MeshRepairControls", ">", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        detectEShorterButton->setStatusTip(QApplication::translate("MeshRepairControls", "Detect short edges", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        detectEShorterButton->setText(QApplication::translate("MeshRepairControls", "<", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        edgeSpin->setToolTip(QApplication::translate("MeshRepairControls", "Edge length", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        edgeSpin->setStatusTip(QApplication::translate("MeshRepairControls", "Edge length", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        repairCollapseEButton->setToolTip(QApplication::translate("MeshRepairControls", "Repair skinny triangles by collapsing the previously selected short or long edges.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        repairCollapseEButton->setText(QApplication::translate("MeshRepairControls", "Collapse selected edges", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        detectCapAngle->setToolTip(QApplication::translate("MeshRepairControls", "Select all edges that have an opposite angle greater than or equal to the given angle. If this angle is very large, only edges of very skinny triangles will be selected.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        detectCapAngle->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        detectCapAngle->setText(QApplication::translate("MeshRepairControls", "Select opposite edges", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MeshRepairControls", "to angles >", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        capAngleSpinbox->setStatusTip(QApplication::translate("MeshRepairControls", "Angle threshold", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        capAngleSpinbox->setPrefix(QString());
        capAngleSpinbox->setSuffix(QApplication::translate("MeshRepairControls", "\302\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        repairFlipEButton->setToolTip(QApplication::translate("MeshRepairControls", "Repair skinny triangles by flipping the previously selected edges.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        repairFlipEButton->setText(QApplication::translate("MeshRepairControls", "Flip selected edges", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MeshRepairControls", "Detect foldovers:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        detectFoldoverButton->setToolTip(QApplication::translate("MeshRepairControls", "Select all edges that could be a foldover.\n"
"Foldover detection is done by comparing the normals of the adjacent faces. If their difference is greater than the given angle, the edge will be selected.\n"
"\n"
"There is no automatic algorithm to fix these foldovers here. So you will have to select the faces that are actual foldovers, and then flip them using \"Flip selected face orientation\" (in \"Face operations\").", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        detectFoldoverButton->setText(QApplication::translate("MeshRepairControls", "Select edges", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MeshRepairControls", "with angle difference >", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        detectFoldoverSpinbox->setStatusTip(QApplication::translate("MeshRepairControls", "Angle threshold", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        detectFoldoverSpinbox->setSuffix(QApplication::translate("MeshRepairControls", "\302\260", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MeshRepairControls", "Face operations", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MeshRepairControls", "Detect skinny triangles:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        triangleAspectButton->setToolTip(QApplication::translate("MeshRepairControls", "<html><head/><body><p>Selects all triangles with an aspect ratio greater than the given one. If this ratio is very large, only very skinny triangles will be selected.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        triangleAspectButton->setText(QApplication::translate("MeshRepairControls", "Select triangles", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MeshRepairControls", "of aspect ratio >", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MeshRepairControls", "Manually repair foldovers:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        flipOrientation->setToolTip(QApplication::translate("MeshRepairControls", "<html><head/><body><p>Flip the normals of all selected faces on the target meshes by reversing the vertex order. This can be used to manually fix foldovers detected in &quot;Edge operations&quot;. It either inverts the whole mesh or, if faces are selected, only the selection.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        flipOrientation->setStatusTip(QApplication::translate("MeshRepairControls", "Flip the normals of all target meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        flipOrientation->setText(QApplication::translate("MeshRepairControls", "Flip face orientation", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MeshRepairControls", "Normals", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        computeNormals->setToolTip(QApplication::translate("MeshRepairControls", "Recomputes Vertex and Face Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        computeNormals->setStatusTip(QApplication::translate("MeshRepairControls", "Recomputes Vertex and Face Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        computeNormals->setWhatsThis(QApplication::translate("MeshRepairControls", "Recomputes Vertex and Face Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        computeNormals->setText(QApplication::translate("MeshRepairControls", "Compute Normals", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        computeVertexNormals->setToolTip(QApplication::translate("MeshRepairControls", "Recomputes Vertex Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        computeVertexNormals->setStatusTip(QApplication::translate("MeshRepairControls", "Recomputes Vertex Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        computeVertexNormals->setWhatsThis(QApplication::translate("MeshRepairControls", "Recomputes Vertex Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        computeVertexNormals->setText(QApplication::translate("MeshRepairControls", "Vertex", 0, QApplication::UnicodeUTF8));
        computeHalfedgeNormals->setText(QApplication::translate("MeshRepairControls", "Halfedge", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        computeFaceNormals->setToolTip(QApplication::translate("MeshRepairControls", "Recomputes Face Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        computeFaceNormals->setStatusTip(QApplication::translate("MeshRepairControls", "Recomputes Face Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        computeFaceNormals->setWhatsThis(QApplication::translate("MeshRepairControls", "Recomputes Face Normals on all Target Meshes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        computeFaceNormals->setText(QApplication::translate("MeshRepairControls", "Face", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MeshRepairControls", "General Operations", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        snapBoundaryButton->setToolTip(QApplication::translate("MeshRepairControls", "<html><head/><body><p>Snaps selected boundary vertices if they are closer than the given distance. No new vertices will be introduced on either boundary side, so they are just snapped to existing ones.</p><p>If vertices in the interior are selected, they will also get snapped to the opposite boundary, if in range.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        snapBoundaryButton->setText(QApplication::translate("MeshRepairControls", "Snap Boundary", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MeshRepairControls", "max. Distance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        fixNonManifoldVerticesButton->setToolTip(QApplication::translate("MeshRepairControls", "<html><head/><body><p>Remove non-manifold vertices by duplicating them</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fixNonManifoldVerticesButton->setText(QApplication::translate("MeshRepairControls", "Fix non-manifold vertices", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        fixMeshButton->setToolTip(QApplication::translate("MeshRepairControls", "<html><head/><body><p>This button will try to fix triangle meshes. </p><p><br/></p><p>Degenerated faces will be removed and all vertices which are closer than the given distance will be collapsed. Non-manifold configurations at vertices will be removed and all faces of each component will be updated to have the same orientation.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fixMeshButton->setText(QApplication::translate("MeshRepairControls", "Fix Triangle Mesh", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MeshRepairControls", "distance", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MeshRepairControls: public Ui_MeshRepairControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHREPAIRCONTROLS_H
