/********************************************************************************
** Form generated from reading UI file 'setProps.ui'
**
** Created: Sat May 18 02:56:57 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPROPS_H
#define UI_SETPROPS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setProps
{
public:
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QPushButton *projectTangentButton;
    QPushButton *moveManipToCOG;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *posButton;
    QLineEdit *nposx;
    QLineEdit *nposz;
    QLineEdit *nposy;
    QFrame *line_3;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *axisAButton;
    QLineEdit *ndirAx;
    QLineEdit *ndirAy;
    QLineEdit *ndirAz;
    QPushButton *axisBButton;
    QLineEdit *ndirBx;
    QLineEdit *ndirBy;
    QLineEdit *ndirBz;
    QPushButton *dirButton;
    QFrame *line;
    QGridLayout *gridLayout_4;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *transButton;
    QLineEdit *translationX;
    QLineEdit *translationY;
    QLineEdit *translationZ;
    QFrame *line_2;
    QGridLayout *_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *rotButton;
    QLineEdit *rotx;
    QLineEdit *roty;
    QLineEdit *rotz;
    QLineEdit *rotAngle;
    QHBoxLayout *_3;
    QPushButton *scaleButton;
    QLineEdit *scalex;
    QLineEdit *scaley;
    QLineEdit *scalez;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *posx;
    QLineEdit *posy;
    QLineEdit *posz;
    QLabel *label_12;
    QLineEdit *dirxx;
    QLineEdit *dirxy;
    QLineEdit *dirxz;
    QLabel *label_17;
    QLineEdit *diryx;
    QLineEdit *diryy;
    QLineEdit *diryz;
    QLabel *label_18;
    QLineEdit *dirzx;
    QLineEdit *dirzy;
    QLineEdit *dirzz;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *selectionRadioButton;
    QRadioButton *objectRadioButton;

    void setupUi(QWidget *setProps)
    {
        if (setProps->objectName().isEmpty())
            setProps->setObjectName(QString::fromUtf8("setProps"));
        setProps->resize(348, 993);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(setProps->sizePolicy().hasHeightForWidth());
        setProps->setSizePolicy(sizePolicy);
        setProps->setMaximumSize(QSize(348, 16777215));
        verticalLayout_6 = new QVBoxLayout(setProps);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(setProps);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 680, 308, 111));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        projectTangentButton = new QPushButton(groupBox_4);
        projectTangentButton->setObjectName(QString::fromUtf8("projectTangentButton"));

        verticalLayout->addWidget(projectTangentButton);

        moveManipToCOG = new QPushButton(groupBox_4);
        moveManipToCOG->setObjectName(QString::fromUtf8("moveManipToCOG"));

        verticalLayout->addWidget(moveManipToCOG);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 236, 308, 441));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        posButton = new QPushButton(groupBox_3);
        posButton->setObjectName(QString::fromUtf8("posButton"));

        gridLayout_2->addWidget(posButton, 1, 0, 1, 1);

        nposx = new QLineEdit(groupBox_3);
        nposx->setObjectName(QString::fromUtf8("nposx"));
        nposx->setMinimumSize(QSize(1, 0));
        nposx->setMaxLength(15);

        gridLayout_2->addWidget(nposx, 1, 1, 1, 1);

        nposz = new QLineEdit(groupBox_3);
        nposz->setObjectName(QString::fromUtf8("nposz"));
        nposz->setMinimumSize(QSize(1, 0));
        nposz->setMaxLength(15);

        gridLayout_2->addWidget(nposz, 1, 3, 1, 1);

        nposy = new QLineEdit(groupBox_3);
        nposy->setObjectName(QString::fromUtf8("nposy"));
        nposy->setMinimumSize(QSize(1, 0));
        nposy->setMaxLength(15);

        gridLayout_2->addWidget(nposy, 1, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        line_3 = new QFrame(groupBox_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_7, 0, 3, 1, 1);

        axisAButton = new QPushButton(groupBox_3);
        axisAButton->setObjectName(QString::fromUtf8("axisAButton"));

        gridLayout_3->addWidget(axisAButton, 1, 0, 1, 1);

        ndirAx = new QLineEdit(groupBox_3);
        ndirAx->setObjectName(QString::fromUtf8("ndirAx"));
        ndirAx->setMinimumSize(QSize(1, 0));
        ndirAx->setMaxLength(15);

        gridLayout_3->addWidget(ndirAx, 1, 1, 1, 1);

        ndirAy = new QLineEdit(groupBox_3);
        ndirAy->setObjectName(QString::fromUtf8("ndirAy"));
        ndirAy->setMinimumSize(QSize(1, 0));
        ndirAy->setMaxLength(15);

        gridLayout_3->addWidget(ndirAy, 1, 2, 1, 1);

        ndirAz = new QLineEdit(groupBox_3);
        ndirAz->setObjectName(QString::fromUtf8("ndirAz"));
        ndirAz->setMinimumSize(QSize(1, 0));
        ndirAz->setMaxLength(15);

        gridLayout_3->addWidget(ndirAz, 1, 3, 1, 1);

        axisBButton = new QPushButton(groupBox_3);
        axisBButton->setObjectName(QString::fromUtf8("axisBButton"));

        gridLayout_3->addWidget(axisBButton, 2, 0, 1, 1);

        ndirBx = new QLineEdit(groupBox_3);
        ndirBx->setObjectName(QString::fromUtf8("ndirBx"));
        ndirBx->setMinimumSize(QSize(1, 0));
        ndirBx->setMaxLength(15);

        gridLayout_3->addWidget(ndirBx, 2, 1, 1, 1);

        ndirBy = new QLineEdit(groupBox_3);
        ndirBy->setObjectName(QString::fromUtf8("ndirBy"));
        ndirBy->setMinimumSize(QSize(1, 0));
        ndirBy->setMaxLength(15);

        gridLayout_3->addWidget(ndirBy, 2, 2, 1, 1);

        ndirBz = new QLineEdit(groupBox_3);
        ndirBz->setObjectName(QString::fromUtf8("ndirBz"));
        ndirBz->setMinimumSize(QSize(1, 0));
        ndirBz->setMaxLength(15);

        gridLayout_3->addWidget(ndirBz, 2, 3, 1, 1);

        dirButton = new QPushButton(groupBox_3);
        dirButton->setObjectName(QString::fromUtf8("dirButton"));

        gridLayout_3->addWidget(dirButton, 3, 1, 1, 3);


        verticalLayout_4->addLayout(gridLayout_3);

        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_21, 0, 1, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_19, 0, 2, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_20, 0, 3, 1, 1);

        transButton = new QPushButton(groupBox_3);
        transButton->setObjectName(QString::fromUtf8("transButton"));

        gridLayout_4->addWidget(transButton, 1, 0, 1, 1);

        translationX = new QLineEdit(groupBox_3);
        translationX->setObjectName(QString::fromUtf8("translationX"));
        translationX->setMinimumSize(QSize(1, 0));
        translationX->setMaxLength(15);

        gridLayout_4->addWidget(translationX, 1, 1, 1, 1);

        translationY = new QLineEdit(groupBox_3);
        translationY->setObjectName(QString::fromUtf8("translationY"));
        translationY->setMinimumSize(QSize(1, 0));
        translationY->setMaxLength(15);

        gridLayout_4->addWidget(translationY, 1, 2, 1, 1);

        translationZ = new QLineEdit(groupBox_3);
        translationZ->setObjectName(QString::fromUtf8("translationZ"));
        translationZ->setMinimumSize(QSize(1, 0));
        translationZ->setMaxLength(15);

        gridLayout_4->addWidget(translationZ, 1, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        line_2 = new QFrame(groupBox_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        _2 = new QGridLayout();
        _2->setObjectName(QString::fromUtf8("_2"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        _2->addWidget(label_13, 0, 1, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        _2->addWidget(label_14, 0, 2, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignCenter);

        _2->addWidget(label_15, 0, 3, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        _2->addWidget(label_16, 0, 4, 1, 1);

        rotButton = new QPushButton(groupBox_3);
        rotButton->setObjectName(QString::fromUtf8("rotButton"));

        _2->addWidget(rotButton, 1, 0, 1, 1);

        rotx = new QLineEdit(groupBox_3);
        rotx->setObjectName(QString::fromUtf8("rotx"));
        rotx->setMinimumSize(QSize(1, 0));
        rotx->setMaxLength(15);

        _2->addWidget(rotx, 1, 1, 1, 1);

        roty = new QLineEdit(groupBox_3);
        roty->setObjectName(QString::fromUtf8("roty"));
        roty->setMinimumSize(QSize(1, 0));
        roty->setMaxLength(15);

        _2->addWidget(roty, 1, 2, 1, 1);

        rotz = new QLineEdit(groupBox_3);
        rotz->setObjectName(QString::fromUtf8("rotz"));
        rotz->setMinimumSize(QSize(1, 0));
        rotz->setMaxLength(15);

        _2->addWidget(rotz, 1, 3, 1, 1);

        rotAngle = new QLineEdit(groupBox_3);
        rotAngle->setObjectName(QString::fromUtf8("rotAngle"));
        rotAngle->setMinimumSize(QSize(1, 0));
        rotAngle->setMaxLength(15);

        _2->addWidget(rotAngle, 1, 4, 1, 1);


        verticalLayout_4->addLayout(_2);

        _3 = new QHBoxLayout();
        _3->setObjectName(QString::fromUtf8("_3"));
        scaleButton = new QPushButton(groupBox_3);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));

        _3->addWidget(scaleButton);

        scalex = new QLineEdit(groupBox_3);
        scalex->setObjectName(QString::fromUtf8("scalex"));
        scalex->setMinimumSize(QSize(1, 0));
        scalex->setMaxLength(15);

        _3->addWidget(scalex);

        scaley = new QLineEdit(groupBox_3);
        scaley->setObjectName(QString::fromUtf8("scaley"));
        scaley->setMinimumSize(QSize(1, 0));
        scaley->setMaxLength(15);

        _3->addWidget(scaley);

        scalez = new QLineEdit(groupBox_3);
        scalez->setObjectName(QString::fromUtf8("scalez"));
        scalez->setMinimumSize(QSize(1, 0));
        scalez->setMaxLength(15);

        _3->addWidget(scalez);


        verticalLayout_4->addLayout(_3);

        line->raise();
        line_2->raise();
        line_3->raise();
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 30, 308, 198));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 0, 3, 1, 1);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        posx = new QLineEdit(groupBox_5);
        posx->setObjectName(QString::fromUtf8("posx"));
        posx->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(posx->sizePolicy().hasHeightForWidth());
        posx->setSizePolicy(sizePolicy1);
        posx->setMinimumSize(QSize(2, 0));
        posx->setMaxLength(15);

        gridLayout->addWidget(posx, 1, 1, 1, 1);

        posy = new QLineEdit(groupBox_5);
        posy->setObjectName(QString::fromUtf8("posy"));
        posy->setEnabled(false);
        posy->setMinimumSize(QSize(1, 0));
        posy->setMaxLength(15);

        gridLayout->addWidget(posy, 1, 2, 1, 1);

        posz = new QLineEdit(groupBox_5);
        posz->setObjectName(QString::fromUtf8("posz"));
        posz->setEnabled(false);
        posz->setMinimumSize(QSize(1, 0));
        posz->setMaxLength(15);

        gridLayout->addWidget(posz, 1, 3, 1, 1);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        dirxx = new QLineEdit(groupBox_5);
        dirxx->setObjectName(QString::fromUtf8("dirxx"));
        dirxx->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dirxx->sizePolicy().hasHeightForWidth());
        dirxx->setSizePolicy(sizePolicy2);
        dirxx->setMinimumSize(QSize(1, 0));
        dirxx->setMaxLength(15);

        gridLayout->addWidget(dirxx, 2, 1, 1, 1);

        dirxy = new QLineEdit(groupBox_5);
        dirxy->setObjectName(QString::fromUtf8("dirxy"));
        dirxy->setEnabled(false);
        dirxy->setMinimumSize(QSize(1, 0));
        dirxy->setMaxLength(15);

        gridLayout->addWidget(dirxy, 2, 2, 1, 1);

        dirxz = new QLineEdit(groupBox_5);
        dirxz->setObjectName(QString::fromUtf8("dirxz"));
        dirxz->setEnabled(false);
        dirxz->setMinimumSize(QSize(1, 0));
        dirxz->setMaxLength(15);

        gridLayout->addWidget(dirxz, 2, 3, 1, 1);

        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 3, 0, 1, 1);

        diryx = new QLineEdit(groupBox_5);
        diryx->setObjectName(QString::fromUtf8("diryx"));
        diryx->setEnabled(false);
        sizePolicy2.setHeightForWidth(diryx->sizePolicy().hasHeightForWidth());
        diryx->setSizePolicy(sizePolicy2);
        diryx->setMinimumSize(QSize(1, 0));
        diryx->setMaxLength(15);

        gridLayout->addWidget(diryx, 3, 1, 1, 1);

        diryy = new QLineEdit(groupBox_5);
        diryy->setObjectName(QString::fromUtf8("diryy"));
        diryy->setEnabled(false);
        diryy->setMinimumSize(QSize(1, 0));
        diryy->setMaxLength(15);

        gridLayout->addWidget(diryy, 3, 2, 1, 1);

        diryz = new QLineEdit(groupBox_5);
        diryz->setObjectName(QString::fromUtf8("diryz"));
        diryz->setEnabled(false);
        diryz->setMinimumSize(QSize(1, 0));
        diryz->setMaxLength(15);

        gridLayout->addWidget(diryz, 3, 3, 1, 1);

        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 4, 0, 1, 1);

        dirzx = new QLineEdit(groupBox_5);
        dirzx->setObjectName(QString::fromUtf8("dirzx"));
        dirzx->setEnabled(false);
        sizePolicy2.setHeightForWidth(dirzx->sizePolicy().hasHeightForWidth());
        dirzx->setSizePolicy(sizePolicy2);
        dirzx->setMinimumSize(QSize(1, 0));
        dirzx->setMaxLength(15);

        gridLayout->addWidget(dirzx, 4, 1, 1, 1);

        dirzy = new QLineEdit(groupBox_5);
        dirzy->setObjectName(QString::fromUtf8("dirzy"));
        dirzy->setEnabled(false);
        dirzy->setMinimumSize(QSize(1, 0));
        dirzy->setMaxLength(15);

        gridLayout->addWidget(dirzy, 4, 2, 1, 1);

        dirzz = new QLineEdit(groupBox_5);
        dirzz->setObjectName(QString::fromUtf8("dirzz"));
        dirzz->setEnabled(false);
        dirzz->setMinimumSize(QSize(1, 0));
        dirzz->setMaxLength(15);

        gridLayout->addWidget(dirzz, 4, 3, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 800, 308, 111));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        selectionRadioButton = new QRadioButton(groupBox_2);
        selectionRadioButton->setObjectName(QString::fromUtf8("selectionRadioButton"));

        verticalLayout_3->addWidget(selectionRadioButton);

        objectRadioButton = new QRadioButton(groupBox_2);
        objectRadioButton->setObjectName(QString::fromUtf8("objectRadioButton"));

        verticalLayout_3->addWidget(objectRadioButton);


        verticalLayout_6->addWidget(groupBox);

        QWidget::setTabOrder(posx, posy);
        QWidget::setTabOrder(posy, posz);
        QWidget::setTabOrder(posz, dirxx);
        QWidget::setTabOrder(dirxx, dirxy);
        QWidget::setTabOrder(dirxy, dirxz);
        QWidget::setTabOrder(dirxz, diryx);
        QWidget::setTabOrder(diryx, diryy);
        QWidget::setTabOrder(diryy, diryz);
        QWidget::setTabOrder(diryz, dirzx);
        QWidget::setTabOrder(dirzx, dirzy);
        QWidget::setTabOrder(dirzy, dirzz);
        QWidget::setTabOrder(dirzz, posButton);
        QWidget::setTabOrder(posButton, nposx);
        QWidget::setTabOrder(nposx, nposy);
        QWidget::setTabOrder(nposy, nposz);
        QWidget::setTabOrder(nposz, axisAButton);
        QWidget::setTabOrder(axisAButton, ndirAx);
        QWidget::setTabOrder(ndirAx, ndirAy);
        QWidget::setTabOrder(ndirAy, ndirAz);
        QWidget::setTabOrder(ndirAz, axisBButton);
        QWidget::setTabOrder(axisBButton, ndirBx);
        QWidget::setTabOrder(ndirBx, ndirBy);
        QWidget::setTabOrder(ndirBy, ndirBz);
        QWidget::setTabOrder(ndirBz, dirButton);
        QWidget::setTabOrder(dirButton, transButton);
        QWidget::setTabOrder(transButton, translationX);
        QWidget::setTabOrder(translationX, translationY);
        QWidget::setTabOrder(translationY, translationZ);
        QWidget::setTabOrder(translationZ, rotButton);
        QWidget::setTabOrder(rotButton, rotx);
        QWidget::setTabOrder(rotx, roty);
        QWidget::setTabOrder(roty, rotz);
        QWidget::setTabOrder(rotz, rotAngle);
        QWidget::setTabOrder(rotAngle, scaleButton);
        QWidget::setTabOrder(scaleButton, scalex);
        QWidget::setTabOrder(scalex, scaley);
        QWidget::setTabOrder(scaley, scalez);
        QWidget::setTabOrder(scalez, projectTangentButton);
        QWidget::setTabOrder(projectTangentButton, moveManipToCOG);

        retranslateUi(setProps);

        QMetaObject::connectSlotsByName(setProps);
    } // setupUi

    void retranslateUi(QWidget *setProps)
    {
        setProps->setWindowTitle(QApplication::translate("setProps", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("setProps", "Set Properties", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("setProps", "Special operations for manipulators", 0, QApplication::UnicodeUTF8));
        projectTangentButton->setText(QApplication::translate("setProps", "project to Tangent Plane", 0, QApplication::UnicodeUTF8));
        moveManipToCOG->setText(QApplication::translate("setProps", "Move to COG", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("setProps", "Set Values", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setProps", "<font color=red>X</font>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("setProps", "<font color=green>Y</font>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("setProps", "<font color=blue>Z</font>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        posButton->setToolTip(QApplication::translate("setProps", "Set the position of the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        posButton->setStatusTip(QApplication::translate("setProps", "Set the position of the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        posButton->setText(QApplication::translate("setProps", "Position", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("setProps", "<font color=red>X</font>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("setProps", "<font color=green>Y</font>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("setProps", "<font color=blue>Z</font>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        axisAButton->setToolTip(QApplication::translate("setProps", "Toggle the direction axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        axisAButton->setStatusTip(QApplication::translate("setProps", "Toggle the direction axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        axisAButton->setText(QApplication::translate("setProps", "X Direction", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        axisBButton->setToolTip(QApplication::translate("setProps", "Toggle the direction axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        axisBButton->setStatusTip(QApplication::translate("setProps", "Toggle the direction axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        axisBButton->setText(QApplication::translate("setProps", "Y Direction", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dirButton->setToolTip(QApplication::translate("setProps", "Set the directions of the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        dirButton->setStatusTip(QApplication::translate("setProps", "Set the directions of the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        dirButton->setText(QApplication::translate("setProps", "Set Direction", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("setProps", "<font color=red>X</font>", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("setProps", "<font color=green>Y</font>", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("setProps", "<font color=blue>Z</font>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        transButton->setToolTip(QApplication::translate("setProps", "Translate the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        transButton->setStatusTip(QApplication::translate("setProps", "Translate the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        transButton->setText(QApplication::translate("setProps", "Translate", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("setProps", "<font color=red>X</font>", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("setProps", "<font color=green>Y</font>", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("setProps", "<font color=blue>Z</font>", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("setProps", "angle", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rotButton->setToolTip(QApplication::translate("setProps", "Rotate the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        rotButton->setStatusTip(QApplication::translate("setProps", "Rotate the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        rotButton->setText(QApplication::translate("setProps", "Rotate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        scaleButton->setToolTip(QApplication::translate("setProps", "Scale the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        scaleButton->setStatusTip(QApplication::translate("setProps", "Scale the manipulator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        scaleButton->setText(QApplication::translate("setProps", "Scale", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("setProps", "Current Values", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("setProps", "<font color=red>X</font>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("setProps", "<font color=green>Y</font>", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("setProps", "<font color=blue>Z</font>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("setProps", "Position", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("setProps", "X Direction", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("setProps", "Y Direction", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("setProps", "Z Direction", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("setProps", "Manipulator Mode", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selectionRadioButton->setToolTip(QApplication::translate("setProps", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Selection properties</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Set properties for a selection on an object.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        selectionRadioButton->setText(QApplication::translate("setProps", "Selection", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        objectRadioButton->setToolTip(QApplication::translate("setProps", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Object properties</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Set properties for an object.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        objectRadioButton->setText(QApplication::translate("setProps", "Object", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setProps: public Ui_setProps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPROPS_H
