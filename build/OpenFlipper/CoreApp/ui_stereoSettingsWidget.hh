/********************************************************************************
** Form generated from reading UI file 'stereoSettingsWidget.ui'
**
** Created: Sat May 18 02:52:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOSETTINGSWIDGET_H
#define UI_STEREOSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StereoSettingsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *stereoOpengl;
    QRadioButton *stereoAnaglyph;
    QRadioButton *stereoCustomAnaglyph;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_11;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_14;
    QDoubleSpinBox *eyeDistance;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_13;
    QSlider *focalDistance;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *StereoSettingsWidget)
    {
        if (StereoSettingsWidget->objectName().isEmpty())
            StereoSettingsWidget->setObjectName(QString::fromUtf8("StereoSettingsWidget"));
        StereoSettingsWidget->resize(448, 263);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StereoSettingsWidget->sizePolicy().hasHeightForWidth());
        StereoSettingsWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(StereoSettingsWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_5 = new QGroupBox(StereoSettingsWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stereoOpengl = new QRadioButton(groupBox_5);
        stereoOpengl->setObjectName(QString::fromUtf8("stereoOpengl"));

        verticalLayout_2->addWidget(stereoOpengl);

        stereoAnaglyph = new QRadioButton(groupBox_5);
        stereoAnaglyph->setObjectName(QString::fromUtf8("stereoAnaglyph"));

        verticalLayout_2->addWidget(stereoAnaglyph);

        stereoCustomAnaglyph = new QRadioButton(groupBox_5);
        stereoCustomAnaglyph->setObjectName(QString::fromUtf8("stereoCustomAnaglyph"));

        verticalLayout_2->addWidget(stereoCustomAnaglyph);

        stackedWidget = new QStackedWidget(groupBox_5);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_7 = new QGroupBox(page);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_15 = new QHBoxLayout(groupBox_7);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_11 = new QLabel(groupBox_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_18->addWidget(label_11);

        label_12 = new QLabel(groupBox_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_18->addWidget(label_12);


        horizontalLayout_15->addLayout(verticalLayout_18);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        eyeDistance = new QDoubleSpinBox(groupBox_7);
        eyeDistance->setObjectName(QString::fromUtf8("eyeDistance"));
        eyeDistance->setDecimals(4);
        eyeDistance->setMaximum(1);
        eyeDistance->setSingleStep(0.01);

        horizontalLayout_14->addWidget(eyeDistance);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);


        verticalLayout_20->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_13->setFont(font);

        horizontalLayout_16->addWidget(label_13);

        focalDistance = new QSlider(groupBox_7);
        focalDistance->setObjectName(QString::fromUtf8("focalDistance"));
        focalDistance->setMaximum(1000);
        focalDistance->setSingleStep(10);
        focalDistance->setPageStep(100);
        focalDistance->setValue(50);
        focalDistance->setOrientation(Qt::Horizontal);

        horizontalLayout_16->addWidget(focalDistance);

        label_14 = new QLabel(groupBox_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        horizontalLayout_16->addWidget(label_14);


        verticalLayout_20->addLayout(horizontalLayout_16);


        horizontalLayout_15->addLayout(verticalLayout_20);


        verticalLayout_3->addWidget(groupBox_7);

        stackedWidget->addWidget(page);

        verticalLayout_2->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(groupBox_5);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(120, 0));

        horizontalLayout->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox_5);


        retranslateUi(StereoSettingsWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StereoSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *StereoSettingsWidget)
    {
        StereoSettingsWidget->setWindowTitle(QApplication::translate("StereoSettingsWidget", "Stereo Settings", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("StereoSettingsWidget", "Stereo Mode", 0, QApplication::UnicodeUTF8));
        stereoOpengl->setText(QApplication::translate("StereoSettingsWidget", "OpenGL stereo buffers", 0, QApplication::UnicodeUTF8));
        stereoAnaglyph->setText(QApplication::translate("StereoSettingsWidget", "Red/Cyan Anaglyph", 0, QApplication::UnicodeUTF8));
        stereoCustomAnaglyph->setText(QApplication::translate("StereoSettingsWidget", "Custom Anaglyph", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("StereoSettingsWidget", "View properties", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("StereoSettingsWidget", "Eye distance:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("StereoSettingsWidget", "Focal distance:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("StereoSettingsWidget", "Near", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("StereoSettingsWidget", "Far", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("StereoSettingsWidget", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StereoSettingsWidget: public Ui_StereoSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOSETTINGSWIDGET_H
