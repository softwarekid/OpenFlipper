/********************************************************************************
** Form generated from reading UI file 'lightWidget.ui'
**
** Created: Sat May 18 02:51:00 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTWIDGET_H
#define UI_LIGHTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LightWidgetBase
{
public:
    QVBoxLayout *verticalLayout_4;
    QCheckBox *directional;
    QCheckBox *fixedPosition;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *xpos;
    QLineEdit *ypos;
    QLineEdit *zpos;
    QWidget *page_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_8;
    QLineEdit *xdir;
    QLabel *label_4;
    QLineEdit *ydir;
    QLabel *label_6;
    QLineEdit *zdir;
    QLabel *label_5;
    QGroupBox *SpotGroup;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_9;
    QLabel *label_7;
    QLineEdit *spotx;
    QLabel *label_9;
    QLineEdit *spoty;
    QLabel *label_8;
    QLineEdit *spotz;
    QLabel *label_25;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QLabel *label_10;
    QLineEdit *angle;
    QLabel *label_11;
    QLineEdit *exponent;
    QGroupBox *ColorGroup;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QSlider *brightness;
    QLabel *label_13;
    QGridLayout *gridLayout_5;
    QLineEdit *ambientR;
    QLineEdit *ambientG;
    QLineEdit *ambientB;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *ambientA;
    QLabel *label_27;
    QLabel *label_17;
    QGridLayout *gridLayout_6;
    QLineEdit *diffuseR;
    QLineEdit *diffuseG;
    QLineEdit *diffuseB;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *diffuseA;
    QLabel *label_28;
    QLabel *label_21;
    QGridLayout *gridLayout_7;
    QLineEdit *specularR;
    QLineEdit *specularG;
    QLineEdit *specularB;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *specularA;
    QLabel *label_29;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_10;
    QLineEdit *radius;
    QLabel *label_26;

    void setupUi(QDialog *LightWidgetBase)
    {
        if (LightWidgetBase->objectName().isEmpty())
            LightWidgetBase->setObjectName(QString::fromUtf8("LightWidgetBase"));
        LightWidgetBase->resize(283, 721);
        verticalLayout_4 = new QVBoxLayout(LightWidgetBase);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        directional = new QCheckBox(LightWidgetBase);
        directional->setObjectName(QString::fromUtf8("directional"));

        verticalLayout_4->addWidget(directional);

        fixedPosition = new QCheckBox(LightWidgetBase);
        fixedPosition->setObjectName(QString::fromUtf8("fixedPosition"));

        verticalLayout_4->addWidget(fixedPosition);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(LightWidgetBase);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_4->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        xpos = new QLineEdit(groupBox);
        xpos->setObjectName(QString::fromUtf8("xpos"));

        gridLayout_4->addWidget(xpos, 1, 0, 1, 1);

        ypos = new QLineEdit(groupBox);
        ypos->setObjectName(QString::fromUtf8("ypos"));

        gridLayout_4->addWidget(ypos, 1, 1, 1, 1);

        zpos = new QLineEdit(groupBox);
        zpos->setObjectName(QString::fromUtf8("zpos"));

        gridLayout_4->addWidget(zpos, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_4, 6, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(4, 4, 261, 90));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        xdir = new QLineEdit(groupBox_2);
        xdir->setObjectName(QString::fromUtf8("xdir"));

        gridLayout_8->addWidget(xdir, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_8->addWidget(label_4, 0, 0, 1, 1);

        ydir = new QLineEdit(groupBox_2);
        ydir->setObjectName(QString::fromUtf8("ydir"));

        gridLayout_8->addWidget(ydir, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_8->addWidget(label_6, 0, 1, 1, 1);

        zdir = new QLineEdit(groupBox_2);
        zdir->setObjectName(QString::fromUtf8("zdir"));

        gridLayout_8->addWidget(zdir, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_8->addWidget(label_5, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_8, 0, 1, 1, 1);

        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);

        SpotGroup = new QGroupBox(LightWidgetBase);
        SpotGroup->setObjectName(QString::fromUtf8("SpotGroup"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SpotGroup->sizePolicy().hasHeightForWidth());
        SpotGroup->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(SpotGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_7 = new QLabel(SpotGroup);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_9->addWidget(label_7, 1, 0, 1, 1);

        spotx = new QLineEdit(SpotGroup);
        spotx->setObjectName(QString::fromUtf8("spotx"));

        gridLayout_9->addWidget(spotx, 2, 0, 1, 1);

        label_9 = new QLabel(SpotGroup);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_9->addWidget(label_9, 1, 1, 1, 1);

        spoty = new QLineEdit(SpotGroup);
        spoty->setObjectName(QString::fromUtf8("spoty"));

        gridLayout_9->addWidget(spoty, 2, 1, 1, 1);

        label_8 = new QLabel(SpotGroup);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_9->addWidget(label_8, 1, 2, 1, 1);

        spotz = new QLineEdit(SpotGroup);
        spotz->setObjectName(QString::fromUtf8("spotz"));

        gridLayout_9->addWidget(spotz, 2, 2, 1, 1);

        label_25 = new QLabel(SpotGroup);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_25, 0, 0, 1, 3);


        verticalLayout->addLayout(gridLayout_9);

        groupBox_3 = new QGroupBox(SpotGroup);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);

        angle = new QLineEdit(groupBox_3);
        angle->setObjectName(QString::fromUtf8("angle"));

        formLayout->setWidget(1, QFormLayout::FieldRole, angle);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_11);

        exponent = new QLineEdit(groupBox_3);
        exponent->setObjectName(QString::fromUtf8("exponent"));

        formLayout->setWidget(2, QFormLayout::FieldRole, exponent);


        verticalLayout->addWidget(groupBox_3);


        verticalLayout_2->addWidget(SpotGroup);

        ColorGroup = new QGroupBox(LightWidgetBase);
        ColorGroup->setObjectName(QString::fromUtf8("ColorGroup"));
        verticalLayout_6 = new QVBoxLayout(ColorGroup);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_12 = new QLabel(ColorGroup);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 0, 0, 1, 1);

        brightness = new QSlider(ColorGroup);
        brightness->setObjectName(QString::fromUtf8("brightness"));
        brightness->setMaximum(100);
        brightness->setSingleStep(5);
        brightness->setValue(100);
        brightness->setSliderPosition(100);
        brightness->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(brightness, 0, 1, 1, 1);

        label_13 = new QLabel(ColorGroup);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        ambientR = new QLineEdit(ColorGroup);
        ambientR->setObjectName(QString::fromUtf8("ambientR"));

        gridLayout_5->addWidget(ambientR, 1, 0, 1, 1);

        ambientG = new QLineEdit(ColorGroup);
        ambientG->setObjectName(QString::fromUtf8("ambientG"));

        gridLayout_5->addWidget(ambientG, 1, 1, 1, 1);

        ambientB = new QLineEdit(ColorGroup);
        ambientB->setObjectName(QString::fromUtf8("ambientB"));

        gridLayout_5->addWidget(ambientB, 1, 2, 1, 1);

        label_14 = new QLabel(ColorGroup);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_5->addWidget(label_14, 0, 0, 1, 1);

        label_15 = new QLabel(ColorGroup);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_5->addWidget(label_15, 0, 1, 1, 1);

        label_16 = new QLabel(ColorGroup);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_5->addWidget(label_16, 0, 2, 1, 1);

        ambientA = new QLineEdit(ColorGroup);
        ambientA->setObjectName(QString::fromUtf8("ambientA"));

        gridLayout_5->addWidget(ambientA, 1, 3, 1, 1);

        label_27 = new QLabel(ColorGroup);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_5->addWidget(label_27, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 1, 1, 1, 1);

        label_17 = new QLabel(ColorGroup);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 2, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        diffuseR = new QLineEdit(ColorGroup);
        diffuseR->setObjectName(QString::fromUtf8("diffuseR"));

        gridLayout_6->addWidget(diffuseR, 1, 0, 1, 1);

        diffuseG = new QLineEdit(ColorGroup);
        diffuseG->setObjectName(QString::fromUtf8("diffuseG"));

        gridLayout_6->addWidget(diffuseG, 1, 1, 1, 1);

        diffuseB = new QLineEdit(ColorGroup);
        diffuseB->setObjectName(QString::fromUtf8("diffuseB"));

        gridLayout_6->addWidget(diffuseB, 1, 2, 1, 1);

        label_18 = new QLabel(ColorGroup);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_6->addWidget(label_18, 0, 0, 1, 1);

        label_19 = new QLabel(ColorGroup);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_6->addWidget(label_19, 0, 1, 1, 1);

        label_20 = new QLabel(ColorGroup);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_6->addWidget(label_20, 0, 2, 1, 1);

        diffuseA = new QLineEdit(ColorGroup);
        diffuseA->setObjectName(QString::fromUtf8("diffuseA"));

        gridLayout_6->addWidget(diffuseA, 1, 3, 1, 1);

        label_28 = new QLabel(ColorGroup);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_6->addWidget(label_28, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_6, 2, 1, 1, 1);

        label_21 = new QLabel(ColorGroup);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_3->addWidget(label_21, 3, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        specularR = new QLineEdit(ColorGroup);
        specularR->setObjectName(QString::fromUtf8("specularR"));

        gridLayout_7->addWidget(specularR, 1, 0, 1, 1);

        specularG = new QLineEdit(ColorGroup);
        specularG->setObjectName(QString::fromUtf8("specularG"));

        gridLayout_7->addWidget(specularG, 1, 1, 1, 1);

        specularB = new QLineEdit(ColorGroup);
        specularB->setObjectName(QString::fromUtf8("specularB"));

        gridLayout_7->addWidget(specularB, 1, 2, 1, 1);

        label_22 = new QLabel(ColorGroup);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_7->addWidget(label_22, 0, 0, 1, 1);

        label_23 = new QLabel(ColorGroup);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_7->addWidget(label_23, 0, 1, 1, 1);

        label_24 = new QLabel(ColorGroup);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_7->addWidget(label_24, 0, 2, 1, 1);

        specularA = new QLineEdit(ColorGroup);
        specularA->setObjectName(QString::fromUtf8("specularA"));

        gridLayout_7->addWidget(specularA, 1, 3, 1, 1);

        label_29 = new QLabel(ColorGroup);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_7->addWidget(label_29, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_7, 3, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);


        verticalLayout_2->addWidget(ColorGroup);

        groupBox_7 = new QGroupBox(LightWidgetBase);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_7 = new QVBoxLayout(groupBox_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setSizeConstraint(QLayout::SetNoConstraint);
        radius = new QLineEdit(groupBox_7);
        radius->setObjectName(QString::fromUtf8("radius"));

        gridLayout_10->addWidget(radius, 0, 1, 1, 1);

        label_26 = new QLabel(groupBox_7);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_10->addWidget(label_26, 0, 0, 1, 1);

        gridLayout_10->setColumnMinimumWidth(0, 5);

        verticalLayout_7->addLayout(gridLayout_10);


        verticalLayout_2->addWidget(groupBox_7);


        verticalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(LightWidgetBase);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LightWidgetBase);
    } // setupUi

    void retranslateUi(QDialog *LightWidgetBase)
    {
        LightWidgetBase->setWindowTitle(QApplication::translate("LightWidgetBase", "Dialog", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        directional->setToolTip(QApplication::translate("LightWidgetBase", "Directional Light source or lightsource with position", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        directional->setText(QApplication::translate("LightWidgetBase", "Directional Light Source", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        fixedPosition->setToolTip(QApplication::translate("LightWidgetBase", "Light source fixed relatively to the viewer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fixedPosition->setText(QApplication::translate("LightWidgetBase", "Fixed Position/Direction", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LightWidgetBase", "Position", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LightWidgetBase", "Y", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LightWidgetBase", "X", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LightWidgetBase", "Z", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("LightWidgetBase", "Direction", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LightWidgetBase", "X", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LightWidgetBase", "Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LightWidgetBase", "Z", 0, QApplication::UnicodeUTF8));
        SpotGroup->setTitle(QApplication::translate("LightWidgetBase", "Spot", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LightWidgetBase", "X", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("LightWidgetBase", "Y", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LightWidgetBase", "Z", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("LightWidgetBase", "Direction", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("LightWidgetBase", "Parameters", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("LightWidgetBase", "Angle", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("LightWidgetBase", "Exponent", 0, QApplication::UnicodeUTF8));
        ColorGroup->setTitle(QApplication::translate("LightWidgetBase", "Colors", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("LightWidgetBase", "Brightness", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("LightWidgetBase", "Ambient", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("LightWidgetBase", "R", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("LightWidgetBase", "G", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("LightWidgetBase", "B", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("LightWidgetBase", "A", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("LightWidgetBase", "Diffuse", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("LightWidgetBase", "R", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("LightWidgetBase", "G", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("LightWidgetBase", "B", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("LightWidgetBase", "A", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("LightWidgetBase", "Specular", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("LightWidgetBase", "R", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("LightWidgetBase", "G", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("LightWidgetBase", "B", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("LightWidgetBase", "A", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("LightWidgetBase", "Misc", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radius->setToolTip(QApplication::translate("LightWidgetBase", "Determines the light source's radius. Note: This does not affect the standard OpenGL rendering.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        radius->setWhatsThis(QApplication::translate("LightWidgetBase", "Determines the light source's radius. Note: This does not affect the standard OpenGL rendering.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_26->setText(QApplication::translate("LightWidgetBase", "Radius", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LightWidgetBase: public Ui_LightWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTWIDGET_H
