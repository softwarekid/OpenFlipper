/********************************************************************************
** Form generated from reading UI file 'infoSkeletonWidget.ui'
**
** Created: Sat May 18 02:55:50 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOSKELETONWIDGET_H
#define UI_INFOSKELETONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoWidget
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QGroupBox *generalBox;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QLabel *bracketA_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *cogX;
    QLabel *cogY;
    QLabel *cogZ;
    QLabel *bracketB_3;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_12;
    QLabel *bracketA;
    QVBoxLayout *verticalLayout_2;
    QLabel *bbMinX;
    QLabel *bbMinY;
    QLabel *bbMinZ;
    QLabel *bracketB;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_21;
    QLabel *bracketA_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *bbMaxX;
    QLabel *bbMaxY;
    QLabel *bbMaxZ;
    QLabel *bracketB_2;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_13;
    QLabel *bracketA_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *bbSizeX;
    QLabel *bbSizeY;
    QLabel *bbSizeZ;
    QLabel *bracketB_5;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *id;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *joints;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBoxAnimations;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_15;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *clickPointLabel;
    QLabel *bracketA_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *pointX;
    QLabel *pointY;
    QLabel *pointZ;
    QLabel *bracketB_4;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QLabel *clickedJointLabel;
    QLabel *jointHandle;
    QLabel *adjacentJoints;
    QLabel *adjacentJointsHandles;

    void setupUi(QDialog *InfoWidget)
    {
        if (InfoWidget->objectName().isEmpty())
            InfoWidget->setObjectName(QString::fromUtf8("InfoWidget"));
        InfoWidget->resize(658, 614);
        gridLayout_3 = new QGridLayout(InfoWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(InfoWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        generalBox = new QGroupBox(InfoWidget);
        generalBox->setObjectName(QString::fromUtf8("generalBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        generalBox->setFont(font);
        gridLayout = new QGridLayout(generalBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_2 = new QFrame(generalBox);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        label_22 = new QLabel(frame_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);

        verticalLayout_5->addWidget(label_22);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        bracketA_3 = new QLabel(frame_2);
        bracketA_3->setObjectName(QString::fromUtf8("bracketA_3"));
        bracketA_3->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketA.png")));

        horizontalLayout_9->addWidget(bracketA_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        cogX = new QLabel(frame_2);
        cogX->setObjectName(QString::fromUtf8("cogX"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        cogX->setFont(font1);

        verticalLayout_4->addWidget(cogX);

        cogY = new QLabel(frame_2);
        cogY->setObjectName(QString::fromUtf8("cogY"));
        cogY->setFont(font1);

        verticalLayout_4->addWidget(cogY);

        cogZ = new QLabel(frame_2);
        cogZ->setObjectName(QString::fromUtf8("cogZ"));
        cogZ->setFont(font1);

        verticalLayout_4->addWidget(cogZ);


        horizontalLayout_9->addLayout(verticalLayout_4);

        bracketB_3 = new QLabel(frame_2);
        bracketB_3->setObjectName(QString::fromUtf8("bracketB_3"));
        bracketB_3->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketB.png")));

        horizontalLayout_9->addWidget(bracketB_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_5->addLayout(horizontalLayout_9);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_11->addLayout(verticalLayout_5);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_boundingbox.png")));

        horizontalLayout_11->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_11);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_6 = new QSpacerItem(62, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_10->addWidget(label_12);

        bracketA = new QLabel(frame_2);
        bracketA->setObjectName(QString::fromUtf8("bracketA"));
        bracketA->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketA.png")));

        horizontalLayout_10->addWidget(bracketA);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        bbMinX = new QLabel(frame_2);
        bbMinX->setObjectName(QString::fromUtf8("bbMinX"));
        bbMinX->setFont(font1);

        verticalLayout_2->addWidget(bbMinX);

        bbMinY = new QLabel(frame_2);
        bbMinY->setObjectName(QString::fromUtf8("bbMinY"));
        bbMinY->setFont(font1);

        verticalLayout_2->addWidget(bbMinY);

        bbMinZ = new QLabel(frame_2);
        bbMinZ->setObjectName(QString::fromUtf8("bbMinZ"));
        bbMinZ->setFont(font1);

        verticalLayout_2->addWidget(bbMinZ);


        horizontalLayout_10->addLayout(verticalLayout_2);

        bracketB = new QLabel(frame_2);
        bracketB->setObjectName(QString::fromUtf8("bracketB"));
        bracketB->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketB.png")));

        horizontalLayout_10->addWidget(bracketB);

        horizontalSpacer_5 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        label_21 = new QLabel(frame_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_10->addWidget(label_21);

        bracketA_2 = new QLabel(frame_2);
        bracketA_2->setObjectName(QString::fromUtf8("bracketA_2"));
        bracketA_2->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketA.png")));

        horizontalLayout_10->addWidget(bracketA_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        bbMaxX = new QLabel(frame_2);
        bbMaxX->setObjectName(QString::fromUtf8("bbMaxX"));
        bbMaxX->setFont(font1);

        verticalLayout_3->addWidget(bbMaxX);

        bbMaxY = new QLabel(frame_2);
        bbMaxY->setObjectName(QString::fromUtf8("bbMaxY"));
        bbMaxY->setFont(font1);

        verticalLayout_3->addWidget(bbMaxY);

        bbMaxZ = new QLabel(frame_2);
        bbMaxZ->setObjectName(QString::fromUtf8("bbMaxZ"));
        bbMaxZ->setFont(font1);

        verticalLayout_3->addWidget(bbMaxZ);


        horizontalLayout_10->addLayout(verticalLayout_3);

        bracketB_2 = new QLabel(frame_2);
        bracketB_2->setObjectName(QString::fromUtf8("bracketB_2"));
        bracketB_2->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketB.png")));

        horizontalLayout_10->addWidget(bracketB_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_10);

        line = new QFrame(frame_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalSpacer_9 = new QSpacerItem(91, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_16->addWidget(label_13);

        bracketA_5 = new QLabel(frame_2);
        bracketA_5->setObjectName(QString::fromUtf8("bracketA_5"));
        bracketA_5->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketA.png")));

        horizontalLayout_16->addWidget(bracketA_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        bbSizeX = new QLabel(frame_2);
        bbSizeX->setObjectName(QString::fromUtf8("bbSizeX"));
        bbSizeX->setFont(font1);

        verticalLayout_6->addWidget(bbSizeX);

        bbSizeY = new QLabel(frame_2);
        bbSizeY->setObjectName(QString::fromUtf8("bbSizeY"));
        bbSizeY->setFont(font1);

        verticalLayout_6->addWidget(bbSizeY);

        bbSizeZ = new QLabel(frame_2);
        bbSizeZ->setObjectName(QString::fromUtf8("bbSizeZ"));
        bbSizeZ->setFont(font1);

        verticalLayout_6->addWidget(bbSizeZ);


        horizontalLayout_16->addLayout(verticalLayout_6);

        bracketB_5 = new QLabel(frame_2);
        bracketB_5->setObjectName(QString::fromUtf8("bracketB_5"));
        bracketB_5->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketB.png")));

        horizontalLayout_16->addWidget(bracketB_5);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_16);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        frame = new QFrame(generalBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        id = new QLabel(frame);
        id->setObjectName(QString::fromUtf8("id"));
        id->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, id);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        joints = new QLabel(frame);
        joints->setObjectName(QString::fromUtf8("joints"));
        joints->setFont(font1);

        horizontalLayout_3->addWidget(joints);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBoxAnimations = new QComboBox(groupBox);
        comboBoxAnimations->setObjectName(QString::fromUtf8("comboBoxAnimations"));
        comboBoxAnimations->setEditable(false);

        horizontalLayout_4->addWidget(comboBoxAnimations);


        formLayout->setWidget(3, QFormLayout::LabelRole, groupBox);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        gridLayout_3->addWidget(generalBox, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(InfoWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 120));
        groupBox_3->setFont(font);
        horizontalLayout_15 = new QHBoxLayout(groupBox_3);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        clickPointLabel = new QLabel(groupBox_3);
        clickPointLabel->setObjectName(QString::fromUtf8("clickPointLabel"));
        clickPointLabel->setFont(font1);

        horizontalLayout_12->addWidget(clickPointLabel);

        bracketA_4 = new QLabel(groupBox_3);
        bracketA_4->setObjectName(QString::fromUtf8("bracketA_4"));
        bracketA_4->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketA.png")));

        horizontalLayout_12->addWidget(bracketA_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        pointX = new QLabel(groupBox_3);
        pointX->setObjectName(QString::fromUtf8("pointX"));
        pointX->setFont(font1);

        verticalLayout_7->addWidget(pointX);

        pointY = new QLabel(groupBox_3);
        pointY->setObjectName(QString::fromUtf8("pointY"));
        pointY->setFont(font1);

        verticalLayout_7->addWidget(pointY);

        pointZ = new QLabel(groupBox_3);
        pointZ->setObjectName(QString::fromUtf8("pointZ"));
        pointZ->setFont(font1);

        verticalLayout_7->addWidget(pointZ);


        horizontalLayout_12->addLayout(verticalLayout_7);

        bracketB_4 = new QLabel(groupBox_3);
        bracketB_4->setObjectName(QString::fromUtf8("bracketB_4"));
        bracketB_4->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/info_bracketB.png")));

        horizontalLayout_12->addWidget(bracketB_4);


        gridLayout_2->addLayout(horizontalLayout_12, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 1, 0, 1, 1);


        horizontalLayout_15->addLayout(gridLayout_2);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        clickedJointLabel = new QLabel(groupBox_2);
        clickedJointLabel->setObjectName(QString::fromUtf8("clickedJointLabel"));
        clickedJointLabel->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, clickedJointLabel);

        jointHandle = new QLabel(groupBox_2);
        jointHandle->setObjectName(QString::fromUtf8("jointHandle"));
        jointHandle->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, jointHandle);

        adjacentJoints = new QLabel(groupBox_2);
        adjacentJoints->setObjectName(QString::fromUtf8("adjacentJoints"));
        adjacentJoints->setFont(font1);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, adjacentJoints);

        adjacentJointsHandles = new QLabel(groupBox_2);
        adjacentJointsHandles->setObjectName(QString::fromUtf8("adjacentJointsHandles"));
        adjacentJointsHandles->setFont(font1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, adjacentJointsHandles);


        horizontalLayout_15->addWidget(groupBox_2);


        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);


        retranslateUi(InfoWidget);
        QObject::connect(pushButton, SIGNAL(clicked()), InfoWidget, SLOT(accept()));

        QMetaObject::connectSlotsByName(InfoWidget);
    } // setupUi

    void retranslateUi(QDialog *InfoWidget)
    {
        InfoWidget->setWindowTitle(QApplication::translate("InfoWidget", "Object Information", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("InfoWidget", "&Close", 0, QApplication::UnicodeUTF8));
        generalBox->setTitle(QApplication::translate("InfoWidget", "General object information", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("InfoWidget", "Center of Gravity:", 0, QApplication::UnicodeUTF8));
        bracketA_3->setText(QString());
        cogX->setText(QApplication::translate("InfoWidget", "cogX", 0, QApplication::UnicodeUTF8));
        cogY->setText(QApplication::translate("InfoWidget", "cogY", 0, QApplication::UnicodeUTF8));
        cogZ->setText(QApplication::translate("InfoWidget", "cogZ", 0, QApplication::UnicodeUTF8));
        bracketB_3->setText(QString());
        label_2->setText(QString());
        label_4->setText(QApplication::translate("InfoWidget", "Bounding Box:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("InfoWidget", "Minimum:", 0, QApplication::UnicodeUTF8));
        bracketA->setText(QString());
        bbMinX->setText(QApplication::translate("InfoWidget", "minX", 0, QApplication::UnicodeUTF8));
        bbMinY->setText(QApplication::translate("InfoWidget", "minY", 0, QApplication::UnicodeUTF8));
        bbMinZ->setText(QApplication::translate("InfoWidget", "minZ", 0, QApplication::UnicodeUTF8));
        bracketB->setText(QString());
        label_21->setText(QApplication::translate("InfoWidget", "Maximum:", 0, QApplication::UnicodeUTF8));
        bracketA_2->setText(QString());
        bbMaxX->setText(QApplication::translate("InfoWidget", "maxX", 0, QApplication::UnicodeUTF8));
        bbMaxY->setText(QApplication::translate("InfoWidget", "maxY", 0, QApplication::UnicodeUTF8));
        bbMaxZ->setText(QApplication::translate("InfoWidget", "maxZ", 0, QApplication::UnicodeUTF8));
        bracketB_2->setText(QString());
        label_13->setText(QApplication::translate("InfoWidget", "Size:", 0, QApplication::UnicodeUTF8));
        bracketA_5->setText(QString());
        bbSizeX->setText(QApplication::translate("InfoWidget", "minX", 0, QApplication::UnicodeUTF8));
        bbSizeY->setText(QApplication::translate("InfoWidget", "minY", 0, QApplication::UnicodeUTF8));
        bbSizeZ->setText(QApplication::translate("InfoWidget", "minZ", 0, QApplication::UnicodeUTF8));
        bracketB_5->setText(QString());
        label_3->setText(QApplication::translate("InfoWidget", "Object ID:", 0, QApplication::UnicodeUTF8));
        id->setText(QApplication::translate("InfoWidget", "id", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("InfoWidget", "Joints/Bones:", 0, QApplication::UnicodeUTF8));
        joints->setText(QApplication::translate("InfoWidget", "#Joints", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("InfoWidget", "Animations:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("InfoWidget", "Local Information at clicked position", 0, QApplication::UnicodeUTF8));
        clickPointLabel->setText(QApplication::translate("InfoWidget", "Clicked Point:", 0, QApplication::UnicodeUTF8));
        bracketA_4->setText(QString());
        pointX->setText(QApplication::translate("InfoWidget", "minX", 0, QApplication::UnicodeUTF8));
        pointY->setText(QApplication::translate("InfoWidget", "minY", 0, QApplication::UnicodeUTF8));
        pointZ->setText(QApplication::translate("InfoWidget", "minZ", 0, QApplication::UnicodeUTF8));
        bracketB_4->setText(QString());
        groupBox_2->setTitle(QApplication::translate("InfoWidget", "skeleton handles", 0, QApplication::UnicodeUTF8));
        clickedJointLabel->setText(QApplication::translate("InfoWidget", "Closest Joint:", 0, QApplication::UnicodeUTF8));
        jointHandle->setText(QApplication::translate("InfoWidget", "jointHandle", 0, QApplication::UnicodeUTF8));
        adjacentJoints->setText(QApplication::translate("InfoWidget", "Adjacent Joints:", 0, QApplication::UnicodeUTF8));
        adjacentJointsHandles->setText(QApplication::translate("InfoWidget", "adjacentJointsHandle", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InfoWidget: public Ui_InfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOSKELETONWIDGET_H
