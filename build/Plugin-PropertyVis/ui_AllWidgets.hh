/********************************************************************************
** Form generated from reading UI file 'AllWidgets.ui'
**
** Created: Sat May 18 02:57:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLWIDGETS_H
#define UI_ALLWIDGETS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ACG/QtWidgets/QtColorChooserButton.hh"

QT_BEGIN_NAMESPACE

class Ui_PropertyVisToolbarBase
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *visualizeButton;
    QPushButton *clearButton;
    QHBoxLayout *horizontalLayout_9;
    QListView *propertyName_lv;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer;
    QToolButton *refresh_property_names_tb;
    QToolButton *duplicate_property_tb;
    QToolButton *remove_property_tb;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QComboBox *meshNames;
    QGroupBox *hint_gb;
    QVBoxLayout *verticalLayout_9;
    QLabel *label;
    QGroupBox *paramBool;
    QGridLayout *gridLayout_5;
    QtColorChooserButton *colorTrue;
    QtColorChooserButton *colorFalse;
    QGroupBox *paramUint;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *uintColorCoder;
    QHBoxLayout *horizontalLayout_3;
    QtColorChooserButton *uintMin;
    QtColorChooserButton *uintMax;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *uintFixedRange;
    QDoubleSpinBox *uintFixedRangeMin;
    QDoubleSpinBox *uintFixedRangeMax;
    QCheckBox *uintRandom;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *uintMapBlack;
    QSpinBox *uintMapBlackValue;
    QGroupBox *paramInt;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *intColorCoder;
    QHBoxLayout *horizontalLayout_13;
    QtColorChooserButton *intMin;
    QtColorChooserButton *intMax;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *intFixedRange;
    QDoubleSpinBox *intFixedRangeMin;
    QDoubleSpinBox *intFixedRangeMax;
    QCheckBox *intAbsolute;
    QCheckBox *intRandom;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *intMapBlack;
    QSpinBox *intMapBlackValue;
    QGroupBox *paramDouble;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *doubleColorCoder;
    QHBoxLayout *horizontalLayout_14;
    QtColorChooserButton *doubleMin;
    QtColorChooserButton *doubleMax;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *doubleFixedRange;
    QDoubleSpinBox *doubleFixedRangeMin;
    QDoubleSpinBox *doubleFixedRangeMax;
    QCheckBox *doubleAbsolute;
    QGroupBox *vectorFieldDifference_gb;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *visualizeVectorDifference_cb;
    QRadioButton *vecFieldDiff_4symm_rb;
    QRadioButton *vecFieldDiff_diff_norm_rb;
    QRadioButton *vecFieldDiff_norm_diff_rb;
    QGroupBox *paramVector;
    QVBoxLayout *verticalLayout;
    QCheckBox *normalize;
    QHBoxLayout *horizontalLayout;
    QCheckBox *scale;
    QDoubleSpinBox *scaleBox;
    QtColorChooserButton *lineColor;
    QGroupBox *paramSkinWeights;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QSpinBox *boneId;
    QGroupBox *pickProp;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *pickedHandle;
    QLabel *label_9;
    QLabel *pickedValue;
    QPushButton *pickButton;
    QGroupBox *test;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_2;
    QComboBox *propertyDataType;
    QComboBox *propertyType;
    QPushButton *createNewButton;
    QLineEdit *property_name_le;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *load_property;
    QPushButton *save_property;
    QCheckBox *binary_cb;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *PropertyVisToolbarBase)
    {
        if (PropertyVisToolbarBase->objectName().isEmpty())
            PropertyVisToolbarBase->setObjectName(QString::fromUtf8("PropertyVisToolbarBase"));
        PropertyVisToolbarBase->resize(473, 1727);
        verticalLayout_7 = new QVBoxLayout(PropertyVisToolbarBase);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox = new QGroupBox(PropertyVisToolbarBase);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        visualizeButton = new QPushButton(groupBox);
        visualizeButton->setObjectName(QString::fromUtf8("visualizeButton"));

        gridLayout->addWidget(visualizeButton, 7, 0, 1, 1);

        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout->addWidget(clearButton, 7, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        propertyName_lv = new QListView(groupBox);
        propertyName_lv->setObjectName(QString::fromUtf8("propertyName_lv"));
        propertyName_lv->setMinimumSize(QSize(0, 192));
        propertyName_lv->setSelectionMode(QAbstractItemView::ExtendedSelection);

        horizontalLayout_9->addWidget(propertyName_lv);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        refresh_property_names_tb = new QToolButton(groupBox);
        refresh_property_names_tb->setObjectName(QString::fromUtf8("refresh_property_names_tb"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(refresh_property_names_tb->sizePolicy().hasHeightForWidth());
        refresh_property_names_tb->setSizePolicy(sizePolicy);
        refresh_property_names_tb->setMinimumSize(QSize(0, 37));

        verticalLayout_8->addWidget(refresh_property_names_tb);

        duplicate_property_tb = new QToolButton(groupBox);
        duplicate_property_tb->setObjectName(QString::fromUtf8("duplicate_property_tb"));
        sizePolicy.setHeightForWidth(duplicate_property_tb->sizePolicy().hasHeightForWidth());
        duplicate_property_tb->setSizePolicy(sizePolicy);
        duplicate_property_tb->setMinimumSize(QSize(0, 37));

        verticalLayout_8->addWidget(duplicate_property_tb);

        remove_property_tb = new QToolButton(groupBox);
        remove_property_tb->setObjectName(QString::fromUtf8("remove_property_tb"));
        sizePolicy.setHeightForWidth(remove_property_tb->sizePolicy().hasHeightForWidth());
        remove_property_tb->setSizePolicy(sizePolicy);
        remove_property_tb->setMinimumSize(QSize(0, 37));

        verticalLayout_8->addWidget(remove_property_tb);


        horizontalLayout_9->addLayout(verticalLayout_8);


        gridLayout->addLayout(horizontalLayout_9, 5, 0, 1, 2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_10->addWidget(label_3);

        meshNames = new QComboBox(groupBox);
        meshNames->setObjectName(QString::fromUtf8("meshNames"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(meshNames->sizePolicy().hasHeightForWidth());
        meshNames->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(meshNames);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 2);


        verticalLayout_7->addWidget(groupBox);

        hint_gb = new QGroupBox(PropertyVisToolbarBase);
        hint_gb->setObjectName(QString::fromUtf8("hint_gb"));
        verticalLayout_9 = new QVBoxLayout(hint_gb);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label = new QLabel(hint_gb);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout_9->addWidget(label);


        verticalLayout_7->addWidget(hint_gb);

        paramBool = new QGroupBox(PropertyVisToolbarBase);
        paramBool->setObjectName(QString::fromUtf8("paramBool"));
        gridLayout_5 = new QGridLayout(paramBool);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        colorTrue = new QtColorChooserButton(paramBool);
        colorTrue->setObjectName(QString::fromUtf8("colorTrue"));
        colorTrue->setProperty("color", QVariant(QColor(255, 0, 4)));

        gridLayout_5->addWidget(colorTrue, 0, 0, 1, 1);

        colorFalse = new QtColorChooserButton(paramBool);
        colorFalse->setObjectName(QString::fromUtf8("colorFalse"));
        colorFalse->setProperty("color", QVariant(QColor(0, 255, 0)));

        gridLayout_5->addWidget(colorFalse, 0, 1, 1, 1);


        verticalLayout_7->addWidget(paramBool);

        paramUint = new QGroupBox(PropertyVisToolbarBase);
        paramUint->setObjectName(QString::fromUtf8("paramUint"));
        verticalLayout_5 = new QVBoxLayout(paramUint);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        uintColorCoder = new QCheckBox(paramUint);
        uintColorCoder->setObjectName(QString::fromUtf8("uintColorCoder"));
        uintColorCoder->setChecked(true);

        verticalLayout_5->addWidget(uintColorCoder);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        uintMin = new QtColorChooserButton(paramUint);
        uintMin->setObjectName(QString::fromUtf8("uintMin"));
        uintMin->setEnabled(false);
        uintMin->setProperty("color", QVariant(QColor(0, 0, 255)));

        horizontalLayout_3->addWidget(uintMin);

        uintMax = new QtColorChooserButton(paramUint);
        uintMax->setObjectName(QString::fromUtf8("uintMax"));
        uintMax->setEnabled(false);
        uintMax->setProperty("color", QVariant(QColor(255, 0, 4)));

        horizontalLayout_3->addWidget(uintMax);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        uintFixedRange = new QCheckBox(paramUint);
        uintFixedRange->setObjectName(QString::fromUtf8("uintFixedRange"));

        horizontalLayout_7->addWidget(uintFixedRange);

        uintFixedRangeMin = new QDoubleSpinBox(paramUint);
        uintFixedRangeMin->setObjectName(QString::fromUtf8("uintFixedRangeMin"));
        uintFixedRangeMin->setDecimals(4);
        uintFixedRangeMin->setMinimum(-1e+09);
        uintFixedRangeMin->setMaximum(1e+09);

        horizontalLayout_7->addWidget(uintFixedRangeMin);

        uintFixedRangeMax = new QDoubleSpinBox(paramUint);
        uintFixedRangeMax->setObjectName(QString::fromUtf8("uintFixedRangeMax"));
        uintFixedRangeMax->setDecimals(4);
        uintFixedRangeMax->setMinimum(-1e+09);
        uintFixedRangeMax->setMaximum(1e+09);
        uintFixedRangeMax->setValue(1);

        horizontalLayout_7->addWidget(uintFixedRangeMax);


        verticalLayout_5->addLayout(horizontalLayout_7);

        uintRandom = new QCheckBox(paramUint);
        uintRandom->setObjectName(QString::fromUtf8("uintRandom"));

        verticalLayout_5->addWidget(uintRandom);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        uintMapBlack = new QCheckBox(paramUint);
        uintMapBlack->setObjectName(QString::fromUtf8("uintMapBlack"));
        uintMapBlack->setEnabled(false);
        uintMapBlack->setChecked(true);

        horizontalLayout_8->addWidget(uintMapBlack);

        uintMapBlackValue = new QSpinBox(paramUint);
        uintMapBlackValue->setObjectName(QString::fromUtf8("uintMapBlackValue"));
        uintMapBlackValue->setEnabled(false);
        uintMapBlackValue->setMinimum(-100);
        uintMapBlackValue->setMaximum(100);
        uintMapBlackValue->setValue(-1);

        horizontalLayout_8->addWidget(uintMapBlackValue);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_7->addWidget(paramUint);

        paramInt = new QGroupBox(PropertyVisToolbarBase);
        paramInt->setObjectName(QString::fromUtf8("paramInt"));
        verticalLayout_3 = new QVBoxLayout(paramInt);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        intColorCoder = new QCheckBox(paramInt);
        intColorCoder->setObjectName(QString::fromUtf8("intColorCoder"));
        intColorCoder->setChecked(true);

        verticalLayout_3->addWidget(intColorCoder);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        intMin = new QtColorChooserButton(paramInt);
        intMin->setObjectName(QString::fromUtf8("intMin"));
        intMin->setEnabled(false);
        intMin->setProperty("color", QVariant(QColor(0, 0, 255)));

        horizontalLayout_13->addWidget(intMin);

        intMax = new QtColorChooserButton(paramInt);
        intMax->setObjectName(QString::fromUtf8("intMax"));
        intMax->setEnabled(false);
        intMax->setProperty("color", QVariant(QColor(255, 0, 0)));

        horizontalLayout_13->addWidget(intMax);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        intFixedRange = new QCheckBox(paramInt);
        intFixedRange->setObjectName(QString::fromUtf8("intFixedRange"));

        horizontalLayout_4->addWidget(intFixedRange);

        intFixedRangeMin = new QDoubleSpinBox(paramInt);
        intFixedRangeMin->setObjectName(QString::fromUtf8("intFixedRangeMin"));
        intFixedRangeMin->setDecimals(4);
        intFixedRangeMin->setMinimum(-1e+09);
        intFixedRangeMin->setMaximum(1e+09);

        horizontalLayout_4->addWidget(intFixedRangeMin);

        intFixedRangeMax = new QDoubleSpinBox(paramInt);
        intFixedRangeMax->setObjectName(QString::fromUtf8("intFixedRangeMax"));
        intFixedRangeMax->setDecimals(4);
        intFixedRangeMax->setMinimum(-1e+09);
        intFixedRangeMax->setMaximum(1e+09);
        intFixedRangeMax->setValue(1);

        horizontalLayout_4->addWidget(intFixedRangeMax);


        verticalLayout_3->addLayout(horizontalLayout_4);

        intAbsolute = new QCheckBox(paramInt);
        intAbsolute->setObjectName(QString::fromUtf8("intAbsolute"));

        verticalLayout_3->addWidget(intAbsolute);

        intRandom = new QCheckBox(paramInt);
        intRandom->setObjectName(QString::fromUtf8("intRandom"));

        verticalLayout_3->addWidget(intRandom);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        intMapBlack = new QCheckBox(paramInt);
        intMapBlack->setObjectName(QString::fromUtf8("intMapBlack"));
        intMapBlack->setEnabled(false);
        intMapBlack->setChecked(true);

        horizontalLayout_2->addWidget(intMapBlack);

        intMapBlackValue = new QSpinBox(paramInt);
        intMapBlackValue->setObjectName(QString::fromUtf8("intMapBlackValue"));
        intMapBlackValue->setEnabled(false);
        intMapBlackValue->setMinimum(-100);
        intMapBlackValue->setMaximum(100);
        intMapBlackValue->setValue(-1);

        horizontalLayout_2->addWidget(intMapBlackValue);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_7->addWidget(paramInt);

        paramDouble = new QGroupBox(PropertyVisToolbarBase);
        paramDouble->setObjectName(QString::fromUtf8("paramDouble"));
        verticalLayout_4 = new QVBoxLayout(paramDouble);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        doubleColorCoder = new QCheckBox(paramDouble);
        doubleColorCoder->setObjectName(QString::fromUtf8("doubleColorCoder"));
        doubleColorCoder->setChecked(true);

        verticalLayout_4->addWidget(doubleColorCoder);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        doubleMin = new QtColorChooserButton(paramDouble);
        doubleMin->setObjectName(QString::fromUtf8("doubleMin"));
        doubleMin->setEnabled(false);
        doubleMin->setProperty("color", QVariant(QColor(0, 0, 255)));

        horizontalLayout_14->addWidget(doubleMin);

        doubleMax = new QtColorChooserButton(paramDouble);
        doubleMax->setObjectName(QString::fromUtf8("doubleMax"));
        doubleMax->setEnabled(false);
        doubleMax->setProperty("color", QVariant(QColor(255, 0, 0)));

        horizontalLayout_14->addWidget(doubleMax);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        doubleFixedRange = new QCheckBox(paramDouble);
        doubleFixedRange->setObjectName(QString::fromUtf8("doubleFixedRange"));

        horizontalLayout_5->addWidget(doubleFixedRange);

        doubleFixedRangeMin = new QDoubleSpinBox(paramDouble);
        doubleFixedRangeMin->setObjectName(QString::fromUtf8("doubleFixedRangeMin"));
        doubleFixedRangeMin->setDecimals(4);
        doubleFixedRangeMin->setMinimum(-1e+09);
        doubleFixedRangeMin->setMaximum(1e+09);

        horizontalLayout_5->addWidget(doubleFixedRangeMin);

        doubleFixedRangeMax = new QDoubleSpinBox(paramDouble);
        doubleFixedRangeMax->setObjectName(QString::fromUtf8("doubleFixedRangeMax"));
        doubleFixedRangeMax->setDecimals(4);
        doubleFixedRangeMax->setMinimum(-1e+09);
        doubleFixedRangeMax->setMaximum(1e+09);
        doubleFixedRangeMax->setValue(1);

        horizontalLayout_5->addWidget(doubleFixedRangeMax);


        verticalLayout_4->addLayout(horizontalLayout_5);

        doubleAbsolute = new QCheckBox(paramDouble);
        doubleAbsolute->setObjectName(QString::fromUtf8("doubleAbsolute"));

        verticalLayout_4->addWidget(doubleAbsolute);


        verticalLayout_7->addWidget(paramDouble);

        vectorFieldDifference_gb = new QGroupBox(PropertyVisToolbarBase);
        vectorFieldDifference_gb->setObjectName(QString::fromUtf8("vectorFieldDifference_gb"));
        verticalLayout_10 = new QVBoxLayout(vectorFieldDifference_gb);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        visualizeVectorDifference_cb = new QCheckBox(vectorFieldDifference_gb);
        visualizeVectorDifference_cb->setObjectName(QString::fromUtf8("visualizeVectorDifference_cb"));

        verticalLayout_10->addWidget(visualizeVectorDifference_cb);

        vecFieldDiff_4symm_rb = new QRadioButton(vectorFieldDifference_gb);
        vecFieldDiff_4symm_rb->setObjectName(QString::fromUtf8("vecFieldDiff_4symm_rb"));
        vecFieldDiff_4symm_rb->setEnabled(false);

        verticalLayout_10->addWidget(vecFieldDiff_4symm_rb);

        vecFieldDiff_diff_norm_rb = new QRadioButton(vectorFieldDifference_gb);
        vecFieldDiff_diff_norm_rb->setObjectName(QString::fromUtf8("vecFieldDiff_diff_norm_rb"));
        vecFieldDiff_diff_norm_rb->setEnabled(false);

        verticalLayout_10->addWidget(vecFieldDiff_diff_norm_rb);

        vecFieldDiff_norm_diff_rb = new QRadioButton(vectorFieldDifference_gb);
        vecFieldDiff_norm_diff_rb->setObjectName(QString::fromUtf8("vecFieldDiff_norm_diff_rb"));
        vecFieldDiff_norm_diff_rb->setEnabled(false);
        vecFieldDiff_norm_diff_rb->setChecked(true);

        verticalLayout_10->addWidget(vecFieldDiff_norm_diff_rb);


        verticalLayout_7->addWidget(vectorFieldDifference_gb);

        paramVector = new QGroupBox(PropertyVisToolbarBase);
        paramVector->setObjectName(QString::fromUtf8("paramVector"));
        verticalLayout = new QVBoxLayout(paramVector);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        normalize = new QCheckBox(paramVector);
        normalize->setObjectName(QString::fromUtf8("normalize"));
        normalize->setChecked(false);

        verticalLayout->addWidget(normalize);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scale = new QCheckBox(paramVector);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setChecked(false);

        horizontalLayout->addWidget(scale);

        scaleBox = new QDoubleSpinBox(paramVector);
        scaleBox->setObjectName(QString::fromUtf8("scaleBox"));
        scaleBox->setEnabled(false);
        scaleBox->setDecimals(7);
        scaleBox->setValue(0.2);

        horizontalLayout->addWidget(scaleBox);


        verticalLayout->addLayout(horizontalLayout);

        lineColor = new QtColorChooserButton(paramVector);
        lineColor->setObjectName(QString::fromUtf8("lineColor"));
        lineColor->setProperty("color", QVariant(QColor(198, 0, 3)));

        verticalLayout->addWidget(lineColor);


        verticalLayout_7->addWidget(paramVector);

        paramSkinWeights = new QGroupBox(PropertyVisToolbarBase);
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

        pickProp = new QGroupBox(PropertyVisToolbarBase);
        pickProp->setObjectName(QString::fromUtf8("pickProp"));
        verticalLayout_2 = new QVBoxLayout(pickProp);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(pickProp);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMaximumSize(QSize(55, 16777215));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        pickedHandle = new QLabel(pickProp);
        pickedHandle->setObjectName(QString::fromUtf8("pickedHandle"));

        gridLayout_2->addWidget(pickedHandle, 0, 1, 1, 1);

        label_9 = new QLabel(pickProp);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        pickedValue = new QLabel(pickProp);
        pickedValue->setObjectName(QString::fromUtf8("pickedValue"));

        gridLayout_2->addWidget(pickedValue, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        pickButton = new QPushButton(pickProp);
        pickButton->setObjectName(QString::fromUtf8("pickButton"));
        pickButton->setCheckable(true);

        verticalLayout_2->addWidget(pickButton);


        verticalLayout_7->addWidget(pickProp);

        test = new QGroupBox(PropertyVisToolbarBase);
        test->setObjectName(QString::fromUtf8("test"));
        verticalLayout_12 = new QVBoxLayout(test);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));

        verticalLayout_12->addLayout(verticalLayout_11);


        verticalLayout_7->addWidget(test);

        groupBox_2 = new QGroupBox(PropertyVisToolbarBase);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_12->addWidget(label_2);

        propertyDataType = new QComboBox(groupBox_2);
        propertyDataType->setObjectName(QString::fromUtf8("propertyDataType"));
        sizePolicy1.setHeightForWidth(propertyDataType->sizePolicy().hasHeightForWidth());
        propertyDataType->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(propertyDataType);

        propertyType = new QComboBox(groupBox_2);
        propertyType->setObjectName(QString::fromUtf8("propertyType"));
        sizePolicy1.setHeightForWidth(propertyType->sizePolicy().hasHeightForWidth());
        propertyType->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(propertyType);


        gridLayout_4->addLayout(horizontalLayout_12, 0, 0, 1, 2);

        createNewButton = new QPushButton(groupBox_2);
        createNewButton->setObjectName(QString::fromUtf8("createNewButton"));

        gridLayout_4->addWidget(createNewButton, 2, 1, 1, 1);

        property_name_le = new QLineEdit(groupBox_2);
        property_name_le->setObjectName(QString::fromUtf8("property_name_le"));

        gridLayout_4->addWidget(property_name_le, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        load_property = new QPushButton(groupBox_2);
        load_property->setObjectName(QString::fromUtf8("load_property"));
        sizePolicy1.setHeightForWidth(load_property->sizePolicy().hasHeightForWidth());
        load_property->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(load_property);

        save_property = new QPushButton(groupBox_2);
        save_property->setObjectName(QString::fromUtf8("save_property"));
        sizePolicy1.setHeightForWidth(save_property->sizePolicy().hasHeightForWidth());
        save_property->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(save_property);

        binary_cb = new QCheckBox(groupBox_2);
        binary_cb->setObjectName(QString::fromUtf8("binary_cb"));
        binary_cb->setEnabled(false);

        horizontalLayout_6->addWidget(binary_cb);


        gridLayout_4->addLayout(horizontalLayout_6, 3, 0, 1, 2);


        verticalLayout_7->addWidget(groupBox_2);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(meshNames);
        label_12->setBuddy(boneId);
        label_2->setBuddy(propertyDataType);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(meshNames, propertyName_lv);
        QWidget::setTabOrder(propertyName_lv, visualizeButton);
        QWidget::setTabOrder(visualizeButton, clearButton);
        QWidget::setTabOrder(clearButton, colorTrue);
        QWidget::setTabOrder(colorTrue, colorFalse);
        QWidget::setTabOrder(colorFalse, uintFixedRange);
        QWidget::setTabOrder(uintFixedRange, uintFixedRangeMin);
        QWidget::setTabOrder(uintFixedRangeMin, uintFixedRangeMax);
        QWidget::setTabOrder(uintFixedRangeMax, uintRandom);
        QWidget::setTabOrder(uintRandom, uintMapBlack);
        QWidget::setTabOrder(uintMapBlack, uintMapBlackValue);
        QWidget::setTabOrder(uintMapBlackValue, intFixedRange);
        QWidget::setTabOrder(intFixedRange, intFixedRangeMin);
        QWidget::setTabOrder(intFixedRangeMin, intFixedRangeMax);
        QWidget::setTabOrder(intFixedRangeMax, intAbsolute);
        QWidget::setTabOrder(intAbsolute, intRandom);
        QWidget::setTabOrder(intRandom, intMapBlack);
        QWidget::setTabOrder(intMapBlack, intMapBlackValue);
        QWidget::setTabOrder(intMapBlackValue, doubleFixedRange);
        QWidget::setTabOrder(doubleFixedRange, doubleFixedRangeMin);
        QWidget::setTabOrder(doubleFixedRangeMin, doubleFixedRangeMax);
        QWidget::setTabOrder(doubleFixedRangeMax, doubleAbsolute);
        QWidget::setTabOrder(doubleAbsolute, visualizeVectorDifference_cb);
        QWidget::setTabOrder(visualizeVectorDifference_cb, vecFieldDiff_4symm_rb);
        QWidget::setTabOrder(vecFieldDiff_4symm_rb, vecFieldDiff_diff_norm_rb);
        QWidget::setTabOrder(vecFieldDiff_diff_norm_rb, vecFieldDiff_norm_diff_rb);
        QWidget::setTabOrder(vecFieldDiff_norm_diff_rb, scale);
        QWidget::setTabOrder(scale, scaleBox);
        QWidget::setTabOrder(scaleBox, lineColor);
        QWidget::setTabOrder(lineColor, boneId);
        QWidget::setTabOrder(boneId, pickButton);
        QWidget::setTabOrder(pickButton, propertyDataType);
        QWidget::setTabOrder(propertyDataType, propertyType);
        QWidget::setTabOrder(propertyType, property_name_le);
        QWidget::setTabOrder(property_name_le, createNewButton);
        QWidget::setTabOrder(createNewButton, load_property);
        QWidget::setTabOrder(load_property, save_property);
        QWidget::setTabOrder(save_property, binary_cb);

        retranslateUi(PropertyVisToolbarBase);
        QObject::connect(intRandom, SIGNAL(toggled(bool)), intMin, SLOT(setDisabled(bool)));
        QObject::connect(intRandom, SIGNAL(toggled(bool)), intMax, SLOT(setDisabled(bool)));
        QObject::connect(intRandom, SIGNAL(toggled(bool)), intMapBlack, SLOT(setEnabled(bool)));
        QObject::connect(intRandom, SIGNAL(toggled(bool)), intMapBlackValue, SLOT(setEnabled(bool)));
        QObject::connect(visualizeVectorDifference_cb, SIGNAL(toggled(bool)), paramVector, SLOT(setDisabled(bool)));
        QObject::connect(visualizeVectorDifference_cb, SIGNAL(toggled(bool)), vecFieldDiff_4symm_rb, SLOT(setEnabled(bool)));
        QObject::connect(visualizeVectorDifference_cb, SIGNAL(toggled(bool)), vecFieldDiff_diff_norm_rb, SLOT(setEnabled(bool)));
        QObject::connect(visualizeVectorDifference_cb, SIGNAL(toggled(bool)), vecFieldDiff_norm_diff_rb, SLOT(setEnabled(bool)));
        QObject::connect(uintColorCoder, SIGNAL(toggled(bool)), uintMin, SLOT(setDisabled(bool)));
        QObject::connect(uintColorCoder, SIGNAL(toggled(bool)), uintMax, SLOT(setDisabled(bool)));
        QObject::connect(intColorCoder, SIGNAL(toggled(bool)), intMin, SLOT(setDisabled(bool)));
        QObject::connect(intColorCoder, SIGNAL(toggled(bool)), intMax, SLOT(setDisabled(bool)));
        QObject::connect(doubleColorCoder, SIGNAL(toggled(bool)), doubleMin, SLOT(setDisabled(bool)));
        QObject::connect(doubleColorCoder, SIGNAL(toggled(bool)), doubleMax, SLOT(setDisabled(bool)));
        QObject::connect(scale, SIGNAL(toggled(bool)), scaleBox, SLOT(setEnabled(bool)));

        propertyDataType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PropertyVisToolbarBase);
    } // setupUi

    void retranslateUi(QWidget *PropertyVisToolbarBase)
    {
        PropertyVisToolbarBase->setWindowTitle(QApplication::translate("PropertyVisToolbarBase", "Property Visualization", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PropertyVisToolbarBase", "Properties", 0, QApplication::UnicodeUTF8));
        visualizeButton->setText(QApplication::translate("PropertyVisToolbarBase", "Visualize", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("PropertyVisToolbarBase", "Clear", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        refresh_property_names_tb->setToolTip(QApplication::translate("PropertyVisToolbarBase", "Reload property list.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        refresh_property_names_tb->setText(QApplication::translate("PropertyVisToolbarBase", "\342\237\262", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        duplicate_property_tb->setToolTip(QApplication::translate("PropertyVisToolbarBase", "Duplicate selected properties.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        duplicate_property_tb->setText(QApplication::translate("PropertyVisToolbarBase", "dup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        remove_property_tb->setToolTip(QApplication::translate("PropertyVisToolbarBase", "Remove selected properties.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        remove_property_tb->setText(QApplication::translate("PropertyVisToolbarBase", "rem", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PropertyVisToolbarBase", "Mesh:", 0, QApplication::UnicodeUTF8));
        hint_gb->setTitle(QApplication::translate("PropertyVisToolbarBase", "Hint", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PropertyVisToolbarBase", "Select more than one property of the same types in order to see additional functions.", 0, QApplication::UnicodeUTF8));
        paramBool->setTitle(QApplication::translate("PropertyVisToolbarBase", "Bool Parameters", 0, QApplication::UnicodeUTF8));
        colorTrue->setText(QApplication::translate("PropertyVisToolbarBase", "True color:", 0, QApplication::UnicodeUTF8));
        colorFalse->setText(QApplication::translate("PropertyVisToolbarBase", "False color:", 0, QApplication::UnicodeUTF8));
        paramUint->setTitle(QApplication::translate("PropertyVisToolbarBase", "Usigned Integer Parameters", 0, QApplication::UnicodeUTF8));
        uintColorCoder->setText(QApplication::translate("PropertyVisToolbarBase", "Use color coder", 0, QApplication::UnicodeUTF8));
        uintMin->setText(QApplication::translate("PropertyVisToolbarBase", "Min Col.: ", 0, QApplication::UnicodeUTF8));
        uintMax->setText(QApplication::translate("PropertyVisToolbarBase", "Max Col.: ", 0, QApplication::UnicodeUTF8));
        uintFixedRange->setText(QApplication::translate("PropertyVisToolbarBase", "Fixed Range", 0, QApplication::UnicodeUTF8));
        uintRandom->setText(QApplication::translate("PropertyVisToolbarBase", "Use random colors", 0, QApplication::UnicodeUTF8));
        uintMapBlack->setText(QApplication::translate("PropertyVisToolbarBase", "Map value to black", 0, QApplication::UnicodeUTF8));
        paramInt->setTitle(QApplication::translate("PropertyVisToolbarBase", "Integer Parameters", 0, QApplication::UnicodeUTF8));
        intColorCoder->setText(QApplication::translate("PropertyVisToolbarBase", "Use color coder", 0, QApplication::UnicodeUTF8));
        intMin->setText(QApplication::translate("PropertyVisToolbarBase", "Min Col.: ", 0, QApplication::UnicodeUTF8));
        intMax->setText(QApplication::translate("PropertyVisToolbarBase", "Max Col.: ", 0, QApplication::UnicodeUTF8));
        intFixedRange->setText(QApplication::translate("PropertyVisToolbarBase", "Fixed Range", 0, QApplication::UnicodeUTF8));
        intAbsolute->setText(QApplication::translate("PropertyVisToolbarBase", "Use absolute values", 0, QApplication::UnicodeUTF8));
        intRandom->setText(QApplication::translate("PropertyVisToolbarBase", "Use random colors", 0, QApplication::UnicodeUTF8));
        intMapBlack->setText(QApplication::translate("PropertyVisToolbarBase", "Map value to black", 0, QApplication::UnicodeUTF8));
        paramDouble->setTitle(QApplication::translate("PropertyVisToolbarBase", "Double Parameters", 0, QApplication::UnicodeUTF8));
        doubleColorCoder->setText(QApplication::translate("PropertyVisToolbarBase", "Use color coder", 0, QApplication::UnicodeUTF8));
        doubleMin->setText(QApplication::translate("PropertyVisToolbarBase", "Min Col.: ", 0, QApplication::UnicodeUTF8));
        doubleMax->setText(QApplication::translate("PropertyVisToolbarBase", "Max Col.: ", 0, QApplication::UnicodeUTF8));
        doubleFixedRange->setText(QApplication::translate("PropertyVisToolbarBase", "Fixed Range", 0, QApplication::UnicodeUTF8));
        doubleAbsolute->setText(QApplication::translate("PropertyVisToolbarBase", "Use absolute values", 0, QApplication::UnicodeUTF8));
        vectorFieldDifference_gb->setTitle(QApplication::translate("PropertyVisToolbarBase", "Vector Field Difference", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        visualizeVectorDifference_cb->setToolTip(QApplication::translate("PropertyVisToolbarBase", "This will only have effect if two properties of the same type (primitive and data) are selected.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        visualizeVectorDifference_cb->setText(QApplication::translate("PropertyVisToolbarBase", "Don't visualize vectors, visualize vector difference instead.", 0, QApplication::UnicodeUTF8));
        vecFieldDiff_4symm_rb->setText(QApplication::translate("PropertyVisToolbarBase", "4-Symmetric Difference (0\302\260 \342\200\223 45\302\260)", 0, QApplication::UnicodeUTF8));
        vecFieldDiff_diff_norm_rb->setText(QApplication::translate("PropertyVisToolbarBase", "Difference in Magnitude (|\342\210\245a\342\210\245-\342\210\245b\342\210\245|)", 0, QApplication::UnicodeUTF8));
        vecFieldDiff_norm_diff_rb->setText(QApplication::translate("PropertyVisToolbarBase", "Norm of Difference (\342\210\245a-b\342\210\245)", 0, QApplication::UnicodeUTF8));
        paramVector->setTitle(QApplication::translate("PropertyVisToolbarBase", "3D Vector Parameters", 0, QApplication::UnicodeUTF8));
        normalize->setText(QApplication::translate("PropertyVisToolbarBase", "Normalize", 0, QApplication::UnicodeUTF8));
        scale->setText(QApplication::translate("PropertyVisToolbarBase", "Scale with factor", 0, QApplication::UnicodeUTF8));
        lineColor->setText(QApplication::translate("PropertyVisToolbarBase", "Line color: ", 0, QApplication::UnicodeUTF8));
        paramSkinWeights->setTitle(QApplication::translate("PropertyVisToolbarBase", "Skin Weights", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("PropertyVisToolbarBase", "Bone", 0, QApplication::UnicodeUTF8));
        pickProp->setTitle(QApplication::translate("PropertyVisToolbarBase", "Pick Property", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PropertyVisToolbarBase", "Handle:", 0, QApplication::UnicodeUTF8));
        pickedHandle->setText(QApplication::translate("PropertyVisToolbarBase", "-", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("PropertyVisToolbarBase", "Value:", 0, QApplication::UnicodeUTF8));
        pickedValue->setText(QApplication::translate("PropertyVisToolbarBase", "-", 0, QApplication::UnicodeUTF8));
        pickButton->setText(QApplication::translate("PropertyVisToolbarBase", "Pick Property", 0, QApplication::UnicodeUTF8));
        test->setTitle(QApplication::translate("PropertyVisToolbarBase", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("PropertyVisToolbarBase", "Load/Save/Create", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PropertyVisToolbarBase", "Property Type:", 0, QApplication::UnicodeUTF8));
        propertyDataType->clear();
        propertyDataType->insertItems(0, QStringList()
         << QApplication::translate("PropertyVisToolbarBase", "Bool", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertyVisToolbarBase", "Unsigned Integer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertyVisToolbarBase", "Integer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertyVisToolbarBase", "Double", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertyVisToolbarBase", "3D Vector", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertyVisToolbarBase", "Skin Weights", 0, QApplication::UnicodeUTF8)
        );
        propertyType->clear();
        propertyType->insertItems(0, QStringList()
         << QApplication::translate("PropertyVisToolbarBase", "Vertex", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertyVisToolbarBase", "Edge", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertyVisToolbarBase", "Face", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertyVisToolbarBase", "HalfEdge", 0, QApplication::UnicodeUTF8)
        );
        createNewButton->setText(QApplication::translate("PropertyVisToolbarBase", "Create New", 0, QApplication::UnicodeUTF8));
        property_name_le->setPlaceholderText(QApplication::translate("PropertyVisToolbarBase", "New Property's Name", 0, QApplication::UnicodeUTF8));
        load_property->setText(QApplication::translate("PropertyVisToolbarBase", "Load", 0, QApplication::UnicodeUTF8));
        save_property->setText(QApplication::translate("PropertyVisToolbarBase", "Save", 0, QApplication::UnicodeUTF8));
        binary_cb->setText(QApplication::translate("PropertyVisToolbarBase", "binary", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PropertyVisToolbarBase: public Ui_PropertyVisToolbarBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLWIDGETS_H
