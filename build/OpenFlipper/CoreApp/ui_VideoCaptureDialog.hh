/********************************************************************************
** Form generated from reading UI file 'VideoCaptureDialog.ui'
**
** Created: Sat May 18 02:52:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOCAPTUREDIALOG_H
#define UI_VIDEOCAPTUREDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VideoCaptureDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *filename;
    QToolButton *findButton;
    QLabel *label_2;
    QSpinBox *fps;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *captureViewers;
    QRadioButton *captureApplication;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *videoWidth;
    QLabel *label_4;
    QSpinBox *videoHeight;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *resButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *startButton;

    void setupUi(QDialog *VideoCaptureDialog)
    {
        if (VideoCaptureDialog->objectName().isEmpty())
            VideoCaptureDialog->setObjectName(QString::fromUtf8("VideoCaptureDialog"));
        VideoCaptureDialog->setWindowModality(Qt::ApplicationModal);
        VideoCaptureDialog->resize(441, 283);
        verticalLayout = new QVBoxLayout(VideoCaptureDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(VideoCaptureDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        filename = new QLineEdit(VideoCaptureDialog);
        filename->setObjectName(QString::fromUtf8("filename"));

        horizontalLayout_2->addWidget(filename);

        findButton = new QToolButton(VideoCaptureDialog);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        horizontalLayout_2->addWidget(findButton);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);

        label_2 = new QLabel(VideoCaptureDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        fps = new QSpinBox(VideoCaptureDialog);
        fps->setObjectName(QString::fromUtf8("fps"));
        fps->setMinimum(1);
        fps->setMaximum(60);
        fps->setValue(25);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, fps);


        verticalLayout->addLayout(formLayout_2);

        groupBox = new QGroupBox(VideoCaptureDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        captureViewers = new QRadioButton(groupBox);
        captureViewers->setObjectName(QString::fromUtf8("captureViewers"));

        horizontalLayout->addWidget(captureViewers);

        captureApplication = new QRadioButton(groupBox);
        captureApplication->setObjectName(QString::fromUtf8("captureApplication"));
        captureApplication->setChecked(true);

        horizontalLayout->addWidget(captureApplication);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(VideoCaptureDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        videoWidth = new QSpinBox(groupBox_2);
        videoWidth->setObjectName(QString::fromUtf8("videoWidth"));
        videoWidth->setMinimum(100);
        videoWidth->setMaximum(2000);
        videoWidth->setValue(1280);

        horizontalLayout_4->addWidget(videoWidth);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        videoHeight = new QSpinBox(groupBox_2);
        videoHeight->setObjectName(QString::fromUtf8("videoHeight"));
        videoHeight->setMinimum(100);
        videoHeight->setMaximum(2000);
        videoHeight->setValue(1024);

        horizontalLayout_4->addWidget(videoHeight);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        resButton = new QPushButton(groupBox_2);
        resButton->setObjectName(QString::fromUtf8("resButton"));

        horizontalLayout_4->addWidget(resButton);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cancelButton = new QPushButton(VideoCaptureDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        startButton = new QPushButton(VideoCaptureDialog);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout_3->addWidget(startButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(VideoCaptureDialog);

        QMetaObject::connectSlotsByName(VideoCaptureDialog);
    } // setupUi

    void retranslateUi(QDialog *VideoCaptureDialog)
    {
        VideoCaptureDialog->setWindowTitle(QApplication::translate("VideoCaptureDialog", "Start Video Capturing", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VideoCaptureDialog", "Output filename:", 0, QApplication::UnicodeUTF8));
        findButton->setText(QApplication::translate("VideoCaptureDialog", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VideoCaptureDialog", "Frames per second:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("VideoCaptureDialog", " Capture Region ", 0, QApplication::UnicodeUTF8));
        captureViewers->setText(QApplication::translate("VideoCaptureDialog", "Viewers only", 0, QApplication::UnicodeUTF8));
        captureApplication->setText(QApplication::translate("VideoCaptureDialog", "Application", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("VideoCaptureDialog", " Video Resolution ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("VideoCaptureDialog", "Width:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("VideoCaptureDialog", "Height:", 0, QApplication::UnicodeUTF8));
        resButton->setText(QApplication::translate("VideoCaptureDialog", "Change now", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("VideoCaptureDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("VideoCaptureDialog", "Start Capturing", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VideoCaptureDialog: public Ui_VideoCaptureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOCAPTUREDIALOG_H
