/********************************************************************************
** Form generated from reading UI file 'decimaterToolbar.ui'
**
** Created: Sat May 18 02:55:25 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECIMATERTOOLBAR_H
#define UI_DECIMATERTOOLBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DecimaterToolbar
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *rbUseDecimater;
    QRadioButton *rbUseMC;
    QRadioButton *rbUseMixed;
    QWidget *decTypeOps;
    QGridLayout *gridLayout_3;
    QLabel *mcSamplesLabel;
    QSpinBox *randomSamplesCounter;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QLabel *mixedFactorLabel;
    QDoubleSpinBox *mixedFactorCounter;
    QLabel *mixedMCSliderLabel;
    QLabel *mixedSliderLabel;
    QSlider *mixedFactorSlider;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rbByDistance;
    QRadioButton *rbByNormalDeviation;
    QRadioButton *rbByEdgeLength;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QCheckBox *cbDistance;
    QDoubleSpinBox *distance;
    QCheckBox *cbNormalDev;
    QSlider *normalDeviationSlider;
    QSpinBox *normalDeviation;
    QCheckBox *cbRoundness;
    QSlider *roundnessSlider;
    QDoubleSpinBox *roundness;
    QCheckBox *cbAspectRatio;
    QDoubleSpinBox *aspectRatio;
    QSlider *aspectRatioSlider;
    QCheckBox *cbEdgeLength;
    QDoubleSpinBox *edgeLength;
    QCheckBox *cbIndependentSets;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *currentNumVertices;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QRadioButton *rbTriangles;
    QSlider *trianglesCountSlider;
    QSpinBox *trianglesCount;
    QRadioButton *rbVertices;
    QSlider *verticesCountSlider;
    QSpinBox *verticesCount;
    QRadioButton *rbConstraintsOnly;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbInitialize;
    QPushButton *pbDecimate;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DecimaterToolbar)
    {
        if (DecimaterToolbar->objectName().isEmpty())
            DecimaterToolbar->setObjectName(QString::fromUtf8("DecimaterToolbar"));
        DecimaterToolbar->resize(378, 740);
        verticalLayout = new QVBoxLayout(DecimaterToolbar);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_4 = new QGroupBox(DecimaterToolbar);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        rbUseDecimater = new QRadioButton(groupBox_4);
        rbUseDecimater->setObjectName(QString::fromUtf8("rbUseDecimater"));
        rbUseDecimater->setChecked(true);

        verticalLayout_5->addWidget(rbUseDecimater);

        rbUseMC = new QRadioButton(groupBox_4);
        rbUseMC->setObjectName(QString::fromUtf8("rbUseMC"));

        verticalLayout_5->addWidget(rbUseMC);

        rbUseMixed = new QRadioButton(groupBox_4);
        rbUseMixed->setObjectName(QString::fromUtf8("rbUseMixed"));

        verticalLayout_5->addWidget(rbUseMixed);

        decTypeOps = new QWidget(groupBox_4);
        decTypeOps->setObjectName(QString::fromUtf8("decTypeOps"));
        decTypeOps->setEnabled(true);
        gridLayout_3 = new QGridLayout(decTypeOps);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mcSamplesLabel = new QLabel(decTypeOps);
        mcSamplesLabel->setObjectName(QString::fromUtf8("mcSamplesLabel"));
        mcSamplesLabel->setEnabled(true);

        gridLayout_3->addWidget(mcSamplesLabel, 0, 0, 1, 2);

        randomSamplesCounter = new QSpinBox(decTypeOps);
        randomSamplesCounter->setObjectName(QString::fromUtf8("randomSamplesCounter"));
        randomSamplesCounter->setEnabled(true);
        randomSamplesCounter->setMinimum(1);
        randomSamplesCounter->setMaximum(50);
        randomSamplesCounter->setValue(8);

        gridLayout_3->addWidget(randomSamplesCounter, 0, 3, 1, 1);

        widget = new QWidget(decTypeOps);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mixedFactorLabel = new QLabel(widget);
        mixedFactorLabel->setObjectName(QString::fromUtf8("mixedFactorLabel"));
        mixedFactorLabel->setEnabled(true);
        mixedFactorLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(mixedFactorLabel, 0, 3, 1, 1);

        mixedFactorCounter = new QDoubleSpinBox(widget);
        mixedFactorCounter->setObjectName(QString::fromUtf8("mixedFactorCounter"));
        mixedFactorCounter->setMaximum(100);
        mixedFactorCounter->setValue(20);

        gridLayout_4->addWidget(mixedFactorCounter, 0, 0, 1, 1);

        mixedMCSliderLabel = new QLabel(widget);
        mixedMCSliderLabel->setObjectName(QString::fromUtf8("mixedMCSliderLabel"));
        mixedMCSliderLabel->setEnabled(true);
        mixedMCSliderLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(mixedMCSliderLabel, 0, 4, 1, 1);

        mixedSliderLabel = new QLabel(widget);
        mixedSliderLabel->setObjectName(QString::fromUtf8("mixedSliderLabel"));
        mixedSliderLabel->setEnabled(true);

        gridLayout_4->addWidget(mixedSliderLabel, 0, 1, 1, 1);

        mixedFactorSlider = new QSlider(widget);
        mixedFactorSlider->setObjectName(QString::fromUtf8("mixedFactorSlider"));
        mixedFactorSlider->setEnabled(true);
        mixedFactorSlider->setMinimum(0);
        mixedFactorSlider->setMaximum(100);
        mixedFactorSlider->setValue(80);
        mixedFactorSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(mixedFactorSlider, 1, 0, 1, 5);


        gridLayout_3->addWidget(widget, 1, 0, 1, 4);


        verticalLayout_5->addWidget(decTypeOps);


        verticalLayout->addWidget(groupBox_4);

        groupBox = new QGroupBox(DecimaterToolbar);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rbByDistance = new QRadioButton(groupBox);
        rbByDistance->setObjectName(QString::fromUtf8("rbByDistance"));
        rbByDistance->setChecked(true);

        verticalLayout_3->addWidget(rbByDistance);

        rbByNormalDeviation = new QRadioButton(groupBox);
        rbByNormalDeviation->setObjectName(QString::fromUtf8("rbByNormalDeviation"));

        verticalLayout_3->addWidget(rbByNormalDeviation);

        rbByEdgeLength = new QRadioButton(groupBox);
        rbByEdgeLength->setObjectName(QString::fromUtf8("rbByEdgeLength"));

        verticalLayout_3->addWidget(rbByEdgeLength);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(DecimaterToolbar);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbDistance = new QCheckBox(groupBox_2);
        cbDistance->setObjectName(QString::fromUtf8("cbDistance"));
        cbDistance->setChecked(true);

        gridLayout->addWidget(cbDistance, 0, 0, 1, 1);

        distance = new QDoubleSpinBox(groupBox_2);
        distance->setObjectName(QString::fromUtf8("distance"));
        distance->setDecimals(5);
        distance->setMaximum(10000);
        distance->setSingleStep(1);
        distance->setValue(0.05);

        gridLayout->addWidget(distance, 0, 2, 1, 1);

        cbNormalDev = new QCheckBox(groupBox_2);
        cbNormalDev->setObjectName(QString::fromUtf8("cbNormalDev"));
        cbNormalDev->setChecked(true);

        gridLayout->addWidget(cbNormalDev, 1, 0, 1, 1);

        normalDeviationSlider = new QSlider(groupBox_2);
        normalDeviationSlider->setObjectName(QString::fromUtf8("normalDeviationSlider"));
        normalDeviationSlider->setMaximum(180);
        normalDeviationSlider->setValue(10);
        normalDeviationSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(normalDeviationSlider, 1, 1, 1, 1);

        normalDeviation = new QSpinBox(groupBox_2);
        normalDeviation->setObjectName(QString::fromUtf8("normalDeviation"));
        normalDeviation->setEnabled(true);
        normalDeviation->setMaximum(180);
        normalDeviation->setValue(5);

        gridLayout->addWidget(normalDeviation, 1, 2, 1, 1);

        cbRoundness = new QCheckBox(groupBox_2);
        cbRoundness->setObjectName(QString::fromUtf8("cbRoundness"));
        cbRoundness->setEnabled(true);
        cbRoundness->setCheckable(true);
        cbRoundness->setChecked(false);

        gridLayout->addWidget(cbRoundness, 3, 0, 1, 1);

        roundnessSlider = new QSlider(groupBox_2);
        roundnessSlider->setObjectName(QString::fromUtf8("roundnessSlider"));
        roundnessSlider->setMaximum(100);
        roundnessSlider->setValue(50);
        roundnessSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(roundnessSlider, 3, 1, 1, 1);

        roundness = new QDoubleSpinBox(groupBox_2);
        roundness->setObjectName(QString::fromUtf8("roundness"));
        roundness->setEnabled(true);
        roundness->setDecimals(5);
        roundness->setMaximum(1);
        roundness->setSingleStep(0.01);
        roundness->setValue(0.5);

        gridLayout->addWidget(roundness, 3, 2, 1, 1);

        cbAspectRatio = new QCheckBox(groupBox_2);
        cbAspectRatio->setObjectName(QString::fromUtf8("cbAspectRatio"));

        gridLayout->addWidget(cbAspectRatio, 4, 0, 1, 1);

        aspectRatio = new QDoubleSpinBox(groupBox_2);
        aspectRatio->setObjectName(QString::fromUtf8("aspectRatio"));
        aspectRatio->setDecimals(4);
        aspectRatio->setMinimum(1.2);
        aspectRatio->setMaximum(15);
        aspectRatio->setSingleStep(0.1);
        aspectRatio->setValue(3);

        gridLayout->addWidget(aspectRatio, 4, 2, 1, 1);

        aspectRatioSlider = new QSlider(groupBox_2);
        aspectRatioSlider->setObjectName(QString::fromUtf8("aspectRatioSlider"));
        aspectRatioSlider->setMinimum(120);
        aspectRatioSlider->setMaximum(1500);
        aspectRatioSlider->setValue(300);
        aspectRatioSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(aspectRatioSlider, 4, 1, 1, 1);

        cbEdgeLength = new QCheckBox(groupBox_2);
        cbEdgeLength->setObjectName(QString::fromUtf8("cbEdgeLength"));

        gridLayout->addWidget(cbEdgeLength, 2, 0, 1, 1);

        edgeLength = new QDoubleSpinBox(groupBox_2);
        edgeLength->setObjectName(QString::fromUtf8("edgeLength"));
        edgeLength->setDecimals(5);
        edgeLength->setSingleStep(0.01);

        gridLayout->addWidget(edgeLength, 2, 2, 1, 1);

        cbIndependentSets = new QCheckBox(groupBox_2);
        cbIndependentSets->setObjectName(QString::fromUtf8("cbIndependentSets"));

        gridLayout->addWidget(cbIndependentSets, 5, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        currentNumVertices = new QLabel(groupBox_2);
        currentNumVertices->setObjectName(QString::fromUtf8("currentNumVertices"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        currentNumVertices->setFont(font);

        horizontalLayout->addWidget(currentNumVertices);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rbTriangles = new QRadioButton(groupBox_3);
        rbTriangles->setObjectName(QString::fromUtf8("rbTriangles"));

        gridLayout_2->addWidget(rbTriangles, 0, 0, 1, 1);

        trianglesCountSlider = new QSlider(groupBox_3);
        trianglesCountSlider->setObjectName(QString::fromUtf8("trianglesCountSlider"));
        trianglesCountSlider->setMinimum(1);
        trianglesCountSlider->setMaximum(100000);
        trianglesCountSlider->setValue(5000);
        trianglesCountSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(trianglesCountSlider, 0, 1, 1, 1);

        trianglesCount = new QSpinBox(groupBox_3);
        trianglesCount->setObjectName(QString::fromUtf8("trianglesCount"));
        trianglesCount->setMinimum(1);
        trianglesCount->setMaximum(99999);
        trianglesCount->setValue(5000);

        gridLayout_2->addWidget(trianglesCount, 0, 2, 1, 1);

        rbVertices = new QRadioButton(groupBox_3);
        rbVertices->setObjectName(QString::fromUtf8("rbVertices"));
        rbVertices->setChecked(true);

        gridLayout_2->addWidget(rbVertices, 1, 0, 1, 1);

        verticesCountSlider = new QSlider(groupBox_3);
        verticesCountSlider->setObjectName(QString::fromUtf8("verticesCountSlider"));
        verticesCountSlider->setMinimum(1);
        verticesCountSlider->setMaximum(100000);
        verticesCountSlider->setValue(5000);
        verticesCountSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(verticesCountSlider, 1, 1, 1, 1);

        verticesCount = new QSpinBox(groupBox_3);
        verticesCount->setObjectName(QString::fromUtf8("verticesCount"));
        verticesCount->setEnabled(true);
        verticesCount->setMinimum(1);
        verticesCount->setMaximum(99999);
        verticesCount->setValue(5000);

        gridLayout_2->addWidget(verticesCount, 1, 2, 1, 1);

        rbConstraintsOnly = new QRadioButton(groupBox_3);
        rbConstraintsOnly->setObjectName(QString::fromUtf8("rbConstraintsOnly"));

        gridLayout_2->addWidget(rbConstraintsOnly, 2, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pbInitialize = new QPushButton(groupBox_2);
        pbInitialize->setObjectName(QString::fromUtf8("pbInitialize"));

        horizontalLayout_3->addWidget(pbInitialize);

        pbDecimate = new QPushButton(groupBox_2);
        pbDecimate->setObjectName(QString::fromUtf8("pbDecimate"));
        pbDecimate->setEnabled(false);

        horizontalLayout_3->addWidget(pbDecimate);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DecimaterToolbar);
        QObject::connect(verticesCount, SIGNAL(valueChanged(int)), verticesCountSlider, SLOT(setValue(int)));
        QObject::connect(verticesCountSlider, SIGNAL(sliderMoved(int)), verticesCount, SLOT(setValue(int)));
        QObject::connect(trianglesCount, SIGNAL(valueChanged(int)), trianglesCountSlider, SLOT(setValue(int)));
        QObject::connect(trianglesCountSlider, SIGNAL(sliderMoved(int)), trianglesCount, SLOT(setValue(int)));
        QObject::connect(normalDeviation, SIGNAL(valueChanged(int)), normalDeviationSlider, SLOT(setValue(int)));
        QObject::connect(normalDeviationSlider, SIGNAL(valueChanged(int)), normalDeviation, SLOT(setValue(int)));
        QObject::connect(rbUseMC, SIGNAL(clicked(bool)), decTypeOps, SLOT(setVisible(bool)));
        QObject::connect(rbUseMixed, SIGNAL(clicked(bool)), decTypeOps, SLOT(setVisible(bool)));
        QObject::connect(rbUseMixed, SIGNAL(clicked(bool)), widget, SLOT(setVisible(bool)));
        QObject::connect(rbUseMC, SIGNAL(clicked(bool)), widget, SLOT(setHidden(bool)));
        QObject::connect(rbUseDecimater, SIGNAL(clicked(bool)), decTypeOps, SLOT(setHidden(bool)));

        QMetaObject::connectSlotsByName(DecimaterToolbar);
    } // setupUi

    void retranslateUi(QWidget *DecimaterToolbar)
    {
        DecimaterToolbar->setWindowTitle(QApplication::translate("DecimaterToolbar", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("DecimaterToolbar", "Decimater", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbUseDecimater->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>The incremental decimater takes the best collapse in each iteration (based on the given order).</p><p>So, this decimater is the first choice for optimal<span style=\" font-weight:600;\"> results</span>, but might be slow.</p><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        rbUseDecimater->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>The incremental decimater takes the best collapse in each iteration (based on the given order).</p><p>So, this decimater is the first choice for optimal<span style=\" font-weight:600;\"> results</span>, but might be slow.</p><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbUseDecimater->setText(QApplication::translate("DecimaterToolbar", "Incremental", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbUseMC->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Multiple choice decimater</p><p>The multiple choice decimater checks #Random Samples and takes the best one for the next collapse. As there is no heap involved, this is <span style=\" font-weight:600;\">faster</span> than the incremental decimater but as it is randomized, the result is not guaranteed to be the best, but still inside the specified constraints.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        rbUseMC->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Multiple choice decimater</p><p>The multiple choice decimater checks #Random Samples and takes the best one for the next collapse. As there is no heap involved, this is <span style=\" font-weight:600;\">faster</span> than the incremental decimater but as it is randomized, the result is not guaranteed to be the best, but still inside the specified constraints.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbUseMC->setText(QApplication::translate("DecimaterToolbar", "Multiple Choice", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbUseMixed->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Mixed Decimater</p><p>Uses Multiple Choice Decimater and Incremental Decimater to get as <span style=\" font-weight:600;\">good and fast results</span> as possible. This decimater uses several steps of the Multiple Choice Decimater with increasing constraint threshold. When 80% of the maximal error are reached or 80% of the collapses have been performed, it switches back to the Incremental Decimater to do the rest.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        rbUseMixed->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Mixed Decimater</p><p>Uses Multiple Choice Decimater and Incremental Decimater to get as <span style=\" font-weight:600;\">good and fast results</span> as possible. This decimater uses several steps of the Multiple Choice Decimater with increasing constraint threshold. When 80% of the maximal error are reached or 80% of the collapses have been performed, it switches back to the Incremental Decimater to do the rest.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbUseMixed->setText(QApplication::translate("DecimaterToolbar", "Mixed", 0, QApplication::UnicodeUTF8));
        mcSamplesLabel->setText(QApplication::translate("DecimaterToolbar", "Random Samples", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        randomSamplesCounter->setToolTip(QApplication::translate("DecimaterToolbar", "Number of Random samples used by the Multiple Choice Decimater", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        randomSamplesCounter->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Number of Random samples used by the Multiple Choice Decimater. The samples will be compared and the best collapse will be used. Increasing this value will result in better quality, but lowers the perfomance.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        mixedFactorLabel->setText(QApplication::translate("DecimaterToolbar", "80%", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        mixedFactorCounter->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Specify what percentage of the decimation should be performed by which decimater.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        mixedFactorCounter->setStatusTip(QApplication::translate("DecimaterToolbar", "Specify what percentage of the decimation should be performed by which decimater.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        mixedFactorCounter->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Specify what percentage of the decimation should be performed by which decimater.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        mixedMCSliderLabel->setText(QApplication::translate("DecimaterToolbar", "Multiple Choice", 0, QApplication::UnicodeUTF8));
        mixedSliderLabel->setText(QApplication::translate("DecimaterToolbar", "Incremental", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        mixedFactorSlider->setToolTip(QApplication::translate("DecimaterToolbar", "Specify what percentage of the decimation should be performed by which decimater.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        mixedFactorSlider->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Specify what percentage of the decimation should be performed by which decimater.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("DecimaterToolbar", "Decimation Order", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbByDistance->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Sets the collapse priority to the distance to the original surface (Quadrics).</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        rbByDistance->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Sets the collapse priority to the distance to the original surface (Quadrics).</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbByDistance->setText(QApplication::translate("DecimaterToolbar", "by Distance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        rbByNormalDeviation->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Sets the collapse priority to the normal deviaton.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbByNormalDeviation->setText(QApplication::translate("DecimaterToolbar", "by Normal Deviation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbByEdgeLength->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Sets the collapse priority to the edge length.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        rbByEdgeLength->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Sets the collapse priority to the edge length.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbByEdgeLength->setText(QApplication::translate("DecimaterToolbar", "by Edge length", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DecimaterToolbar", "Constraints", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cbDistance->setToolTip(QApplication::translate("DecimaterToolbar", "The Hausdorff distance between the original and the decimated mesh will be lower than the given tolerance.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbDistance->setWhatsThis(QApplication::translate("DecimaterToolbar", "The Hausdorff distance between the original and the decimated mesh will be lower than the given tolerance.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cbDistance->setText(QApplication::translate("DecimaterToolbar", "Distance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        distance->setToolTip(QApplication::translate("DecimaterToolbar", "The Hausdorff distance between the original and the decimated mesh will be lower than the given tolerance.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        distance->setWhatsThis(QApplication::translate("DecimaterToolbar", "The Hausdorff distance between the original and the decimated mesh will be lower than the given tolerance.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        cbNormalDev->setToolTip(QApplication::translate("DecimaterToolbar", "Restrict Normal Deviation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        cbNormalDev->setStatusTip(QApplication::translate("DecimaterToolbar", "Restrict Normal Deviation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        cbNormalDev->setWhatsThis(QApplication::translate("DecimaterToolbar", "Restrict Normal Deviation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cbNormalDev->setText(QApplication::translate("DecimaterToolbar", "Normal Dev.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        normalDeviationSlider->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Maximal normal deviation between </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">original normal and normals after </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">decimation step defined in degrees.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        normalDeviationSlider->setStatusTip(QApplication::translate("DecimaterToolbar", "Restrict Normal Deviation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        normalDeviation->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Maximal normal deviation between </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">original normal and normals after </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">decimation step defined in degrees.</p></body></html>", "Maximal normal deviation between original normal and normals after decimation step defined in degrees.", QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        normalDeviation->setStatusTip(QApplication::translate("DecimaterToolbar", "Restrict Normal deviation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        normalDeviation->setWhatsThis(QApplication::translate("DecimaterToolbar", "Restrict Normal deviation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        cbRoundness->setToolTip(QApplication::translate("DecimaterToolbar", "The roundness ( radius of the circumference divided by the   length of the shortest edge) after the collapse has to be lower than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbRoundness->setWhatsThis(QApplication::translate("DecimaterToolbar", "The roundness ( radius of the circumference divided by the   length of the shortest edge) after the collapse has to be lower than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cbRoundness->setText(QApplication::translate("DecimaterToolbar", "Roundness", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        roundness->setToolTip(QApplication::translate("DecimaterToolbar", "The roundness ( radius of the circumference divided by the   length of the shortest edge) after the collapse has to be lower than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        roundness->setWhatsThis(QApplication::translate("DecimaterToolbar", "The roundness ( radius of the circumference divided by the   length of the shortest edge) after the collapse has to be lower than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        cbAspectRatio->setToolTip(QApplication::translate("DecimaterToolbar", "The aspect ration of a triangle( the length of the longest edge divided by its corresponding height) after the collapse has to be greater than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbAspectRatio->setWhatsThis(QApplication::translate("DecimaterToolbar", "The aspect ration of a triangle( the length of the longest edge divided by its corresponding height) after the collapse has to be greater than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cbAspectRatio->setText(QApplication::translate("DecimaterToolbar", "AspectRatio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        aspectRatio->setToolTip(QApplication::translate("DecimaterToolbar", "The aspect ration of a triangle( the length of the longest edge divided by its corresponding height) after the collapse has to be greater than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        aspectRatio->setWhatsThis(QApplication::translate("DecimaterToolbar", "The aspect ration of a triangle( the length of the longest edge divided by its corresponding height) after the collapse has to be greater than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        cbEdgeLength->setToolTip(QApplication::translate("DecimaterToolbar", "A collapse is only performed, if the length after the collapse is lower than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbEdgeLength->setWhatsThis(QApplication::translate("DecimaterToolbar", "A collapse is only performed, if the length after the collapse is lower than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cbEdgeLength->setText(QApplication::translate("DecimaterToolbar", "Edge Length", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        edgeLength->setToolTip(QApplication::translate("DecimaterToolbar", "A collapse is only performed, if the length after the collapse is lower than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        edgeLength->setWhatsThis(QApplication::translate("DecimaterToolbar", "A collapse is only performed, if the length after the collapse is lower than the given value.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        cbIndependentSets->setToolTip(QApplication::translate("DecimaterToolbar", "Lock one-ring around remaining vertex after a collapse to prevent further collapses of halfedges incident to the one-ring vertices.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        cbIndependentSets->setWhatsThis(QApplication::translate("DecimaterToolbar", "Lock one-ring around remaining vertex after a collapse to prevent further collapses of halfedges incident to the one-ring vertices.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        cbIndependentSets->setText(QApplication::translate("DecimaterToolbar", "Independent Sets", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DecimaterToolbar", "Current number of vertices:", 0, QApplication::UnicodeUTF8));
        currentNumVertices->setText(QApplication::translate("DecimaterToolbar", "<not available>", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("DecimaterToolbar", "Stop conditions", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        rbTriangles->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until the given number of triangles is reached, or constraint limits would be violated.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        rbTriangles->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until the given number of triangles is reached, or constraint limits would be violated.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbTriangles->setText(QApplication::translate("DecimaterToolbar", "#Triangles", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        trianglesCount->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until the given number of triangles, or constraint limit.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        trianglesCount->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until the given number of triangles, or constraint limit.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        rbVertices->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until the given number of vertices is reached, or constraint limits would be violated.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        rbVertices->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until the given number of vertices is reached, or constraint limits would be violated.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbVertices->setText(QApplication::translate("DecimaterToolbar", "#Vertices", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        verticesCount->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until the given number of vertices, or constraint limit.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        verticesCount->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until the given number of vertices, or constraint limit.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        rbConstraintsOnly->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until constraint limits would be violated by any further collapse.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        rbConstraintsOnly->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimate until constraint limits would be violated by any further collapse.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rbConstraintsOnly->setText(QApplication::translate("DecimaterToolbar", "Constraints only", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbInitialize->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p><span style=\" font-weight:600;\">Initialize</span> decimaters for all target meshes with the given values and modules. </p><p>Initialization saves the error quadrics per vertex until <span style=\" font-style:italic;\">Initialize</span> will be pressed again. So, if you don't reinitialize, you can decimate multiple times with the original errors. <span style=\" font-weight:600;\">Reinitialize updates</span> the errors according to the decimated mesh.</p><p><span style=\" font-weight:600;\">Reinitialize</span> is <span style=\" font-weight:600;\">needed</span>, if you change the <span style=\" font-weight:600;\">Decimater</span> (not the parameter for the decimater e.g. &quot;Random Samples&quot; for Multiple Choice), <span style=\" font-weight:600;\">Decimation Order</span> or add/remove a <span style=\" font-weight:600;\">Constraint</span>. </p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pbInitialize->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p><span style=\" font-weight:600;\">Initialize</span> decimaters for all target meshes with the given values and modules. </p><p>Initialization saves the error quadrics per vertex until <span style=\" font-style:italic;\">Initialize</span> will be pressed again. So, if you don't reinitialize, you can decimate multiple times with the original errors. <span style=\" font-weight:600;\">Reinitialize updates</span> the errors according to the current decimated mesh.</p><p><span style=\" font-weight:600;\">Reinitialize</span> is <span style=\" font-weight:600;\">needed</span>, if you change the <span style=\" font-weight:600;\">Decimater</span> (not the parameter for the decimater e.g. &quot;Random Samples&quot; for Multiple Choice), <span style=\" font-weight:600;\">Decimation Order</span> or add/remove a <span style=\" font-weight:600;\">Constraint</span>. </p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pbInitialize->setText(QApplication::translate("DecimaterToolbar", "Initialize", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbDecimate->setToolTip(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimates all target meshes. If you change Constraints (add/remove), Decimation Order, the Decimater or the mesh, initialize again.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pbDecimate->setWhatsThis(QApplication::translate("DecimaterToolbar", "<html><head/><body><p>Decimates all target meshes. If you change Constraints (add/remove), Decimation Order, the Decimater or the mesh, initialize again.</p><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pbDecimate->setText(QApplication::translate("DecimaterToolbar", "Decimate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DecimaterToolbar: public Ui_DecimaterToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECIMATERTOOLBAR_H
