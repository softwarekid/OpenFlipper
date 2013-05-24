/********************************************************************************
** Form generated from reading UI file 'QtMaterialDialogUi.ui'
**
** Created: Sat May 18 02:49:50 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMATERIALDIALOGUI_H
#define UI_QTMATERIALDIALOGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ACG/QtWidgets/QtColorChooserButton.hh"

QT_BEGIN_NAMESPACE

class Ui_QtMaterialDialogUi
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *MaterialBox;
    QGridLayout *MaterialBoxLayout;
    QSpacerItem *s4;
    QSpacerItem *spacerItem;
    QGridLayout *ColorButtonLayout;
    QtColorChooserButton *baseColorButton;
    QLabel *label;
    QtColorChooserButton *ambientColorButton;
    QLabel *label_2;
    QtColorChooserButton *diffuseColorButton;
    QLabel *label_3;
    QtColorChooserButton *specularColorButton;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QSlider *shininessSlider;
    QSpinBox *shininessBox;
    QLabel *label_8;
    QtColorChooserButton *overlayColorButton;
    QSpacerItem *s3;
    QSpacerItem *spacerItem1;
    QGroupBox *ThicknessBox;
    QGridLayout *ThicknessBoxLayout;
    QVBoxLayout *vboxLayout;
    QGridLayout *PointLayout;
    QSpinBox *pointSizeSpinBox;
    QSpinBox *lineWidthSpinBox;
    QLabel *label_6;
    QLabel *label_7;
    QCheckBox *roundPointsCheckBox;
    QCheckBox *lineSmoothCheckBox;
    QSpacerItem *spacerItem2;
    QSpacerItem *spacerItem3;
    QSpacerItem *spacerItem4;
    QSpacerItem *spacerItem5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *RenderingBox;
    QGridLayout *gridLayout;
    QCheckBox *backfaceCulling;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *alphaTest;
    QSlider *alpha;
    QCheckBox *blending;
    QComboBox *blendParam1;
    QComboBox *blendParam2;
    QCheckBox *colorMaterial;
    QCheckBox *multiSampling;
    QSpacerItem *sp1;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QCheckBox *baseColorActive;
    QCheckBox *materialActive;
    QCheckBox *pointSizeActive;
    QCheckBox *lineWidthActive;
    QCheckBox *roundPointsActive;
    QCheckBox *lineSmoothActive;
    QCheckBox *alphaTestActive;
    QCheckBox *blendingActive;
    QCheckBox *backfaceCullingActive;
    QCheckBox *colorMaterialActive;
    QCheckBox *multiSamplingActive;
    QHBoxLayout *l1;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem6;
    QPushButton *okButton;

    void setupUi(QWidget *QtMaterialDialogUi)
    {
        if (QtMaterialDialogUi->objectName().isEmpty())
            QtMaterialDialogUi->setObjectName(QString::fromUtf8("QtMaterialDialogUi"));
        QtMaterialDialogUi->resize(623, 663);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtMaterialDialogUi->sizePolicy().hasHeightForWidth());
        QtMaterialDialogUi->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(QtMaterialDialogUi);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        MaterialBox = new QGroupBox(QtMaterialDialogUi);
        MaterialBox->setObjectName(QString::fromUtf8("MaterialBox"));
        sizePolicy.setHeightForWidth(MaterialBox->sizePolicy().hasHeightForWidth());
        MaterialBox->setSizePolicy(sizePolicy);
        MaterialBoxLayout = new QGridLayout(MaterialBox);
#ifndef Q_OS_MAC
        MaterialBoxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        MaterialBoxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        MaterialBoxLayout->setObjectName(QString::fromUtf8("MaterialBoxLayout"));
        s4 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MaterialBoxLayout->addItem(s4, 0, 1, 1, 1);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        MaterialBoxLayout->addItem(spacerItem, 1, 0, 1, 1);

        ColorButtonLayout = new QGridLayout();
#ifndef Q_OS_MAC
        ColorButtonLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        ColorButtonLayout->setContentsMargins(0, 0, 0, 0);
#endif
        ColorButtonLayout->setObjectName(QString::fromUtf8("ColorButtonLayout"));
        baseColorButton = new QtColorChooserButton(MaterialBox);
        baseColorButton->setObjectName(QString::fromUtf8("baseColorButton"));

        ColorButtonLayout->addWidget(baseColorButton, 0, 0, 1, 1);

        label = new QLabel(MaterialBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        ColorButtonLayout->addWidget(label, 0, 1, 1, 1);

        ambientColorButton = new QtColorChooserButton(MaterialBox);
        ambientColorButton->setObjectName(QString::fromUtf8("ambientColorButton"));

        ColorButtonLayout->addWidget(ambientColorButton, 1, 0, 1, 1);

        label_2 = new QLabel(MaterialBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        ColorButtonLayout->addWidget(label_2, 1, 1, 1, 1);

        diffuseColorButton = new QtColorChooserButton(MaterialBox);
        diffuseColorButton->setObjectName(QString::fromUtf8("diffuseColorButton"));

        ColorButtonLayout->addWidget(diffuseColorButton, 2, 0, 1, 1);

        label_3 = new QLabel(MaterialBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        ColorButtonLayout->addWidget(label_3, 2, 1, 1, 1);

        specularColorButton = new QtColorChooserButton(MaterialBox);
        specularColorButton->setObjectName(QString::fromUtf8("specularColorButton"));

        ColorButtonLayout->addWidget(specularColorButton, 3, 0, 1, 1);

        label_4 = new QLabel(MaterialBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        ColorButtonLayout->addWidget(label_4, 3, 1, 1, 1);

        label_5 = new QLabel(MaterialBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        ColorButtonLayout->addWidget(label_5, 5, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        shininessSlider = new QSlider(MaterialBox);
        shininessSlider->setObjectName(QString::fromUtf8("shininessSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(shininessSlider->sizePolicy().hasHeightForWidth());
        shininessSlider->setSizePolicy(sizePolicy2);
        shininessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(shininessSlider);

        shininessBox = new QSpinBox(MaterialBox);
        shininessBox->setObjectName(QString::fromUtf8("shininessBox"));

        horizontalLayout_4->addWidget(shininessBox);


        ColorButtonLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        label_8 = new QLabel(MaterialBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        ColorButtonLayout->addWidget(label_8, 4, 1, 1, 1);

        overlayColorButton = new QtColorChooserButton(MaterialBox);
        overlayColorButton->setObjectName(QString::fromUtf8("overlayColorButton"));

        ColorButtonLayout->addWidget(overlayColorButton, 4, 0, 1, 1);


        MaterialBoxLayout->addLayout(ColorButtonLayout, 1, 1, 1, 1);

        s3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        MaterialBoxLayout->addItem(s3, 1, 2, 1, 1);

        spacerItem1 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        MaterialBoxLayout->addItem(spacerItem1, 2, 1, 1, 1);


        horizontalLayout_3->addWidget(MaterialBox);

        ThicknessBox = new QGroupBox(QtMaterialDialogUi);
        ThicknessBox->setObjectName(QString::fromUtf8("ThicknessBox"));
        sizePolicy.setHeightForWidth(ThicknessBox->sizePolicy().hasHeightForWidth());
        ThicknessBox->setSizePolicy(sizePolicy);
        ThicknessBoxLayout = new QGridLayout(ThicknessBox);
#ifndef Q_OS_MAC
        ThicknessBoxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        ThicknessBoxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        ThicknessBoxLayout->setObjectName(QString::fromUtf8("ThicknessBoxLayout"));
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        PointLayout = new QGridLayout();
#ifndef Q_OS_MAC
        PointLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        PointLayout->setContentsMargins(0, 0, 0, 0);
#endif
        PointLayout->setObjectName(QString::fromUtf8("PointLayout"));
        pointSizeSpinBox = new QSpinBox(ThicknessBox);
        pointSizeSpinBox->setObjectName(QString::fromUtf8("pointSizeSpinBox"));
        pointSizeSpinBox->setAlignment(Qt::AlignRight);

        PointLayout->addWidget(pointSizeSpinBox, 0, 0, 1, 1);

        lineWidthSpinBox = new QSpinBox(ThicknessBox);
        lineWidthSpinBox->setObjectName(QString::fromUtf8("lineWidthSpinBox"));
        lineWidthSpinBox->setAlignment(Qt::AlignRight);

        PointLayout->addWidget(lineWidthSpinBox, 1, 0, 1, 1);

        label_6 = new QLabel(ThicknessBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);

        PointLayout->addWidget(label_6, 0, 1, 1, 1);

        label_7 = new QLabel(ThicknessBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);

        PointLayout->addWidget(label_7, 1, 1, 1, 1);


        vboxLayout->addLayout(PointLayout);

        roundPointsCheckBox = new QCheckBox(ThicknessBox);
        roundPointsCheckBox->setObjectName(QString::fromUtf8("roundPointsCheckBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(roundPointsCheckBox->sizePolicy().hasHeightForWidth());
        roundPointsCheckBox->setSizePolicy(sizePolicy4);

        vboxLayout->addWidget(roundPointsCheckBox);

        lineSmoothCheckBox = new QCheckBox(ThicknessBox);
        lineSmoothCheckBox->setObjectName(QString::fromUtf8("lineSmoothCheckBox"));

        vboxLayout->addWidget(lineSmoothCheckBox);


        ThicknessBoxLayout->addLayout(vboxLayout, 1, 1, 1, 1);

        spacerItem2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ThicknessBoxLayout->addItem(spacerItem2, 1, 0, 1, 1);

        spacerItem3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ThicknessBoxLayout->addItem(spacerItem3, 1, 2, 1, 1);

        spacerItem4 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ThicknessBoxLayout->addItem(spacerItem4, 0, 1, 1, 1);

        spacerItem5 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ThicknessBoxLayout->addItem(spacerItem5, 2, 1, 1, 1);


        horizontalLayout_3->addWidget(ThicknessBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        RenderingBox = new QGroupBox(QtMaterialDialogUi);
        RenderingBox->setObjectName(QString::fromUtf8("RenderingBox"));
        gridLayout = new QGridLayout(RenderingBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        backfaceCulling = new QCheckBox(RenderingBox);
        backfaceCulling->setObjectName(QString::fromUtf8("backfaceCulling"));
        backfaceCulling->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(backfaceCulling, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        alphaTest = new QCheckBox(RenderingBox);
        alphaTest->setObjectName(QString::fromUtf8("alphaTest"));
        alphaTest->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(alphaTest);

        alpha = new QSlider(RenderingBox);
        alpha->setObjectName(QString::fromUtf8("alpha"));
        alpha->setMaximum(100);
        alpha->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(alpha);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        blending = new QCheckBox(RenderingBox);
        blending->setObjectName(QString::fromUtf8("blending"));
        blending->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(blending, 4, 0, 1, 1);

        blendParam1 = new QComboBox(RenderingBox);
        blendParam1->setObjectName(QString::fromUtf8("blendParam1"));

        gridLayout->addWidget(blendParam1, 5, 1, 1, 1);

        blendParam2 = new QComboBox(RenderingBox);
        blendParam2->setObjectName(QString::fromUtf8("blendParam2"));

        gridLayout->addWidget(blendParam2, 6, 1, 1, 1);

        colorMaterial = new QCheckBox(RenderingBox);
        colorMaterial->setObjectName(QString::fromUtf8("colorMaterial"));

        gridLayout->addWidget(colorMaterial, 2, 0, 1, 1);

        multiSampling = new QCheckBox(RenderingBox);
        multiSampling->setObjectName(QString::fromUtf8("multiSampling"));

        gridLayout->addWidget(multiSampling, 3, 0, 1, 1);


        verticalLayout_2->addWidget(RenderingBox);

        sp1 = new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(sp1);


        horizontalLayout->addLayout(verticalLayout_2);

        groupBox_4 = new QGroupBox(QtMaterialDialogUi);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        baseColorActive = new QCheckBox(groupBox_4);
        baseColorActive->setObjectName(QString::fromUtf8("baseColorActive"));

        verticalLayout->addWidget(baseColorActive);

        materialActive = new QCheckBox(groupBox_4);
        materialActive->setObjectName(QString::fromUtf8("materialActive"));

        verticalLayout->addWidget(materialActive);

        pointSizeActive = new QCheckBox(groupBox_4);
        pointSizeActive->setObjectName(QString::fromUtf8("pointSizeActive"));

        verticalLayout->addWidget(pointSizeActive);

        lineWidthActive = new QCheckBox(groupBox_4);
        lineWidthActive->setObjectName(QString::fromUtf8("lineWidthActive"));

        verticalLayout->addWidget(lineWidthActive);

        roundPointsActive = new QCheckBox(groupBox_4);
        roundPointsActive->setObjectName(QString::fromUtf8("roundPointsActive"));

        verticalLayout->addWidget(roundPointsActive);

        lineSmoothActive = new QCheckBox(groupBox_4);
        lineSmoothActive->setObjectName(QString::fromUtf8("lineSmoothActive"));

        verticalLayout->addWidget(lineSmoothActive);

        alphaTestActive = new QCheckBox(groupBox_4);
        alphaTestActive->setObjectName(QString::fromUtf8("alphaTestActive"));

        verticalLayout->addWidget(alphaTestActive);

        blendingActive = new QCheckBox(groupBox_4);
        blendingActive->setObjectName(QString::fromUtf8("blendingActive"));

        verticalLayout->addWidget(blendingActive);

        backfaceCullingActive = new QCheckBox(groupBox_4);
        backfaceCullingActive->setObjectName(QString::fromUtf8("backfaceCullingActive"));

        verticalLayout->addWidget(backfaceCullingActive);

        colorMaterialActive = new QCheckBox(groupBox_4);
        colorMaterialActive->setObjectName(QString::fromUtf8("colorMaterialActive"));

        verticalLayout->addWidget(colorMaterialActive);

        multiSamplingActive = new QCheckBox(groupBox_4);
        multiSamplingActive->setObjectName(QString::fromUtf8("multiSamplingActive"));

        verticalLayout->addWidget(multiSamplingActive);


        horizontalLayout->addWidget(groupBox_4);


        verticalLayout_3->addLayout(horizontalLayout);

        l1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        l1->setSpacing(6);
#endif
        l1->setContentsMargins(0, 0, 0, 0);
        l1->setObjectName(QString::fromUtf8("l1"));
        cancelButton = new QPushButton(QtMaterialDialogUi);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        l1->addWidget(cancelButton);

        spacerItem6 = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        l1->addItem(spacerItem6);

        okButton = new QPushButton(QtMaterialDialogUi);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        l1->addWidget(okButton);


        verticalLayout_3->addLayout(l1);


        retranslateUi(QtMaterialDialogUi);
        QObject::connect(shininessSlider, SIGNAL(valueChanged(int)), shininessBox, SLOT(setValue(int)));
        QObject::connect(shininessBox, SIGNAL(valueChanged(int)), shininessSlider, SLOT(setValue(int)));

        blendParam1->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QtMaterialDialogUi);
    } // setupUi

    void retranslateUi(QWidget *QtMaterialDialogUi)
    {
        QtMaterialDialogUi->setWindowTitle(QApplication::translate("QtMaterialDialogUi", "Edit Material", 0, QApplication::UnicodeUTF8));
        MaterialBox->setTitle(QApplication::translate("QtMaterialDialogUi", "Material", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        baseColorButton->setToolTip(QApplication::translate("QtMaterialDialogUi", "Emitted color (Independent of light sources)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        baseColorButton->setStatusTip(QApplication::translate("QtMaterialDialogUi", "Emitted color (Independent of light sources)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        baseColorButton->setWhatsThis(QApplication::translate("QtMaterialDialogUi", "Emitted color (Independent of light sources)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        baseColorButton->setText(QString());
        label->setText(QApplication::translate("QtMaterialDialogUi", "Emissive Color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ambientColorButton->setToolTip(QApplication::translate("QtMaterialDialogUi", "Ambient color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        ambientColorButton->setStatusTip(QApplication::translate("QtMaterialDialogUi", "Ambient color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        ambientColorButton->setWhatsThis(QApplication::translate("QtMaterialDialogUi", "Ambient color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        ambientColorButton->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        ambientColorButton->setText(QString());
        label_2->setText(QApplication::translate("QtMaterialDialogUi", "Ambient Color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        diffuseColorButton->setToolTip(QApplication::translate("QtMaterialDialogUi", "Diffuse color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        diffuseColorButton->setStatusTip(QApplication::translate("QtMaterialDialogUi", "Diffuse color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        diffuseColorButton->setWhatsThis(QApplication::translate("QtMaterialDialogUi", "Diffuse color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        diffuseColorButton->setText(QString());
        label_3->setText(QApplication::translate("QtMaterialDialogUi", "Diffuse Color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        specularColorButton->setToolTip(QApplication::translate("QtMaterialDialogUi", "Specular color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        specularColorButton->setStatusTip(QApplication::translate("QtMaterialDialogUi", "Specular color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        specularColorButton->setWhatsThis(QApplication::translate("QtMaterialDialogUi", "Specular color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        specularColorButton->setText(QString());
        label_4->setText(QApplication::translate("QtMaterialDialogUi", "Specular Color", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QtMaterialDialogUi", "Shininess", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QtMaterialDialogUi", "Overlay Color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        overlayColorButton->setToolTip(QApplication::translate("QtMaterialDialogUi", "Overlay color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        overlayColorButton->setStatusTip(QApplication::translate("QtMaterialDialogUi", "Overlay color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        overlayColorButton->setWhatsThis(QApplication::translate("QtMaterialDialogUi", "<html><head/><body><p>Additional Overlay color.</p><p><br/></p><p>This is mainly used for overlays, such as wireframe</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        overlayColorButton->setText(QString());
        ThicknessBox->setTitle(QApplication::translate("QtMaterialDialogUi", "Thickness", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QtMaterialDialogUi", "Point Size", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QtMaterialDialogUi", "Line Width", 0, QApplication::UnicodeUTF8));
        roundPointsCheckBox->setText(QApplication::translate("QtMaterialDialogUi", "Round Points", 0, QApplication::UnicodeUTF8));
        lineSmoothCheckBox->setText(QApplication::translate("QtMaterialDialogUi", "Smooth Lines", 0, QApplication::UnicodeUTF8));
        RenderingBox->setTitle(QApplication::translate("QtMaterialDialogUi", "Rendering", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        backfaceCulling->setToolTip(QApplication::translate("QtMaterialDialogUi", "This checkbox controls if faces where only the \n"
"back is visible should be rendered.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        backfaceCulling->setText(QApplication::translate("QtMaterialDialogUi", "Backface Culling", 0, QApplication::UnicodeUTF8));
        alphaTest->setText(QApplication::translate("QtMaterialDialogUi", "Alpha Test", 0, QApplication::UnicodeUTF8));
        blending->setText(QApplication::translate("QtMaterialDialogUi", "Blending", 0, QApplication::UnicodeUTF8));
        blendParam1->clear();
        blendParam1->insertItems(0, QStringList()
         << QApplication::translate("QtMaterialDialogUi", "GL_ZERO", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_SRC_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_SRC_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_DST_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_DST_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_SRC_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_SRC_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_DST_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_DST_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_CONSTANT_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_CONSTANT_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_CONSTANT_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_CONSTANT_ALPHA", 0, QApplication::UnicodeUTF8)
        );
        blendParam2->clear();
        blendParam2->insertItems(0, QStringList()
         << QApplication::translate("QtMaterialDialogUi", "GL_ZERO", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_SRC_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_SRC_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_DST_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_DST_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_SRC_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_SRC_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_DST_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_DST_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_CONSTANT_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_CONSTANT_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_CONSTANT_ALPHA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QtMaterialDialogUi", "GL_ONE_MINUS_CONSTANT_ALPHA", 0, QApplication::UnicodeUTF8)
        );
        colorMaterial->setText(QApplication::translate("QtMaterialDialogUi", "Color Material", 0, QApplication::UnicodeUTF8));
        multiSampling->setText(QApplication::translate("QtMaterialDialogUi", "Multi Sampling", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("QtMaterialDialogUi", "Active Properties", 0, QApplication::UnicodeUTF8));
        baseColorActive->setText(QApplication::translate("QtMaterialDialogUi", "Base Color", 0, QApplication::UnicodeUTF8));
        materialActive->setText(QApplication::translate("QtMaterialDialogUi", "Material", 0, QApplication::UnicodeUTF8));
        pointSizeActive->setText(QApplication::translate("QtMaterialDialogUi", "Point Size", 0, QApplication::UnicodeUTF8));
        lineWidthActive->setText(QApplication::translate("QtMaterialDialogUi", "Line Width", 0, QApplication::UnicodeUTF8));
        roundPointsActive->setText(QApplication::translate("QtMaterialDialogUi", "Round Points", 0, QApplication::UnicodeUTF8));
        lineSmoothActive->setText(QApplication::translate("QtMaterialDialogUi", "Line Smooth", 0, QApplication::UnicodeUTF8));
        alphaTestActive->setText(QApplication::translate("QtMaterialDialogUi", "Alpha Test", 0, QApplication::UnicodeUTF8));
        blendingActive->setText(QApplication::translate("QtMaterialDialogUi", "Blending", 0, QApplication::UnicodeUTF8));
        backfaceCullingActive->setText(QApplication::translate("QtMaterialDialogUi", "Backface Culling", 0, QApplication::UnicodeUTF8));
        colorMaterialActive->setText(QApplication::translate("QtMaterialDialogUi", "Color Material", 0, QApplication::UnicodeUTF8));
        multiSamplingActive->setText(QApplication::translate("QtMaterialDialogUi", "Multi Sampling", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("QtMaterialDialogUi", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("QtMaterialDialogUi", "Apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtMaterialDialogUi: public Ui_QtMaterialDialogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMATERIALDIALOGUI_H
