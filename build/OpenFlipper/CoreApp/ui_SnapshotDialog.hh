/********************************************************************************
** Form generated from reading UI file 'SnapshotDialog.ui'
**
** Created: Sat May 18 02:52:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPSHOTDIALOG_H
#define UI_SNAPSHOTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnapshotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *filename;
    QToolButton *findButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QSpinBox *snapHeight;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *snapWidth;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *resButton;
    QCheckBox *keepAspect;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *transparent;
    QCheckBox *hideCoordsys;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *multisampling;
    QSpinBox *num_samples;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *metaData_storeComments_cb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *metaData_comments_visibleOnly_cb;
    QCheckBox *metaData_comments_targetedOnly_cb;
    QCheckBox *metaData_storeView_cb;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SnapshotDialog)
    {
        if (SnapshotDialog->objectName().isEmpty())
            SnapshotDialog->setObjectName(QString::fromUtf8("SnapshotDialog"));
        SnapshotDialog->setWindowModality(Qt::ApplicationModal);
        verticalLayout = new QVBoxLayout(SnapshotDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(SnapshotDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        filename = new QLineEdit(SnapshotDialog);
        filename->setObjectName(QString::fromUtf8("filename"));

        horizontalLayout_2->addWidget(filename);

        findButton = new QToolButton(SnapshotDialog);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        horizontalLayout_2->addWidget(findButton);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        groupBox_2 = new QGroupBox(SnapshotDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        snapHeight = new QSpinBox(groupBox_2);
        snapHeight->setObjectName(QString::fromUtf8("snapHeight"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(snapHeight->sizePolicy().hasHeightForWidth());
        snapHeight->setSizePolicy(sizePolicy);
        snapHeight->setMinimumSize(QSize(80, 0));
        snapHeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        snapHeight->setMinimum(1);
        snapHeight->setMaximum(8192);
        snapHeight->setValue(600);

        gridLayout_3->addWidget(snapHeight, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        snapWidth = new QSpinBox(groupBox_2);
        snapWidth->setObjectName(QString::fromUtf8("snapWidth"));
        snapWidth->setMinimumSize(QSize(80, 0));
        snapWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        snapWidth->setMinimum(1);
        snapWidth->setMaximum(8192);
        snapWidth->setValue(800);

        gridLayout_3->addWidget(snapWidth, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        resButton = new QPushButton(groupBox_2);
        resButton->setObjectName(QString::fromUtf8("resButton"));

        gridLayout_3->addWidget(resButton, 3, 2, 1, 1);

        keepAspect = new QCheckBox(groupBox_2);
        keepAspect->setObjectName(QString::fromUtf8("keepAspect"));

        gridLayout_3->addWidget(keepAspect, 2, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(SnapshotDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        transparent = new QCheckBox(groupBox);
        transparent->setObjectName(QString::fromUtf8("transparent"));

        verticalLayout_6->addWidget(transparent);

        hideCoordsys = new QCheckBox(groupBox);
        hideCoordsys->setObjectName(QString::fromUtf8("hideCoordsys"));

        verticalLayout_6->addWidget(hideCoordsys);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        multisampling = new QCheckBox(groupBox);
        multisampling->setObjectName(QString::fromUtf8("multisampling"));
        multisampling->setChecked(true);

        horizontalLayout_6->addWidget(multisampling);

        num_samples = new QSpinBox(groupBox);
        num_samples->setObjectName(QString::fromUtf8("num_samples"));
        num_samples->setMinimum(2);
        num_samples->setMaximum(16);
        num_samples->setValue(16);

        horizontalLayout_6->addWidget(num_samples);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(SnapshotDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        metaData_storeComments_cb = new QCheckBox(groupBox_3);
        metaData_storeComments_cb->setObjectName(QString::fromUtf8("metaData_storeComments_cb"));
        metaData_storeComments_cb->setChecked(true);

        verticalLayout_2->addWidget(metaData_storeComments_cb);

        widget = new QWidget(groupBox_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(16, 0, 0, 0);
        metaData_comments_visibleOnly_cb = new QCheckBox(widget);
        metaData_comments_visibleOnly_cb->setObjectName(QString::fromUtf8("metaData_comments_visibleOnly_cb"));
        metaData_comments_visibleOnly_cb->setChecked(true);

        horizontalLayout_4->addWidget(metaData_comments_visibleOnly_cb);

        metaData_comments_targetedOnly_cb = new QCheckBox(widget);
        metaData_comments_targetedOnly_cb->setObjectName(QString::fromUtf8("metaData_comments_targetedOnly_cb"));

        horizontalLayout_4->addWidget(metaData_comments_targetedOnly_cb);


        verticalLayout_2->addWidget(widget);

        metaData_storeView_cb = new QCheckBox(groupBox_3);
        metaData_storeView_cb->setObjectName(QString::fromUtf8("metaData_storeView_cb"));
        metaData_storeView_cb->setChecked(true);

        verticalLayout_2->addWidget(metaData_storeView_cb);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(8);
        label_5->setFont(font);
        label_5->setWordWrap(true);

        verticalLayout_2->addWidget(label_5);


        verticalLayout->addWidget(groupBox_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cancelButton = new QPushButton(SnapshotDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okButton = new QPushButton(SnapshotDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setDefault(true);

        horizontalLayout_3->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(filename, findButton);
        QWidget::setTabOrder(findButton, snapWidth);
        QWidget::setTabOrder(snapWidth, snapHeight);
        QWidget::setTabOrder(snapHeight, keepAspect);
        QWidget::setTabOrder(keepAspect, resButton);
        QWidget::setTabOrder(resButton, transparent);
        QWidget::setTabOrder(transparent, hideCoordsys);
        QWidget::setTabOrder(hideCoordsys, multisampling);
        QWidget::setTabOrder(multisampling, num_samples);
        QWidget::setTabOrder(num_samples, metaData_storeComments_cb);
        QWidget::setTabOrder(metaData_storeComments_cb, metaData_comments_visibleOnly_cb);
        QWidget::setTabOrder(metaData_comments_visibleOnly_cb, metaData_comments_targetedOnly_cb);
        QWidget::setTabOrder(metaData_comments_targetedOnly_cb, cancelButton);
        QWidget::setTabOrder(cancelButton, okButton);

        retranslateUi(SnapshotDialog);
        QObject::connect(metaData_storeComments_cb, SIGNAL(toggled(bool)), widget, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(SnapshotDialog);
    } // setupUi

    void retranslateUi(QDialog *SnapshotDialog)
    {
        SnapshotDialog->setWindowTitle(QApplication::translate("SnapshotDialog", "Take Snapshot", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SnapshotDialog", "Save to: ", 0, QApplication::UnicodeUTF8));
        findButton->setText(QApplication::translate("SnapshotDialog", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SnapshotDialog", " Resolution ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SnapshotDialog", "Height:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SnapshotDialog", "Width:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        resButton->setToolTip(QApplication::translate("SnapshotDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Changes the resolution of the application window and thus of the snapshot taken. It will be reset to its original value when this dialog is closed.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">This will not work when the application is maximized or fullscreen.</span></p>\n"
"<p style=\"-qt-paragrap"
                        "h-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Only available when taking application snapshots.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        resButton->setText(QApplication::translate("SnapshotDialog", "Change Resolution", 0, QApplication::UnicodeUTF8));
        keepAspect->setText(QApplication::translate("SnapshotDialog", "Keep aspect ratio", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SnapshotDialog", "Rendering options", 0, QApplication::UnicodeUTF8));
        transparent->setText(QApplication::translate("SnapshotDialog", "Transparent background", 0, QApplication::UnicodeUTF8));
        hideCoordsys->setText(QApplication::translate("SnapshotDialog", "Hide coordinate system", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        multisampling->setToolTip(QApplication::translate("SnapshotDialog", "Activating this option will render the image with the given number of samples.\n"
"Deactivating this option will use only one sample.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        multisampling->setText(QApplication::translate("SnapshotDialog", "Multisampling:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        num_samples->setToolTip(QApplication::translate("SnapshotDialog", "Number of samples for multisampling.\n"
"Allowed values: any number between 2 and 16.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("SnapshotDialog", "samples", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_3->setToolTip(QApplication::translate("SnapshotDialog", "Use e.g. ImageMagick (\"identify -verbose <filename>\") to display the image file's meta data.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("SnapshotDialog", "Image Meta Data*", 0, QApplication::UnicodeUTF8));
        metaData_storeComments_cb->setText(QApplication::translate("SnapshotDialog", "Store Mesh Comments (if available)", 0, QApplication::UnicodeUTF8));
        metaData_comments_visibleOnly_cb->setText(QApplication::translate("SnapshotDialog", "Visible Objects Only", 0, QApplication::UnicodeUTF8));
        metaData_comments_targetedOnly_cb->setText(QApplication::translate("SnapshotDialog", "Targeted Objects Only", 0, QApplication::UnicodeUTF8));
        metaData_storeView_cb->setText(QApplication::translate("SnapshotDialog", "Store View Settings", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SnapshotDialog", "* If you have ImageMagick use \"identify -verbose <file>\" to display meta data.", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SnapshotDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("SnapshotDialog", "Take snapshot!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SnapshotDialog: public Ui_SnapshotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPSHOTDIALOG_H
