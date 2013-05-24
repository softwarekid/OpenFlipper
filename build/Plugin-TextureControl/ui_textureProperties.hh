/********************************************************************************
** Form generated from reading UI file 'textureProperties.ui'
**
** Created: Sat May 18 02:59:27 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTUREPROPERTIES_H
#define UI_TEXTUREPROPERTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *textureLabel;
    QTreeWidget *textureList;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *typeLabel;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *indexLabel;
    QComboBox *indexBox;
    QFrame *line;
    QCheckBox *repeatBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *max_val;
    QCheckBox *clampBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *clamp_min;
    QLabel *label_2;
    QDoubleSpinBox *clamp_max;
    QCheckBox *centerBox;
    QCheckBox *absBox;
    QCheckBox *scaleBox;
    QGroupBox *imageBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *imageLabel;
    QLabel *fileLabel;
    QPushButton *changeImageButton;
    QGroupBox *originalData;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(968, 618);
        Dialog->setMinimumSize(QSize(0, 0));
        Dialog->setMaximumSize(QSize(90000, 90000));
        verticalLayout_5 = new QVBoxLayout(Dialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textureLabel = new QLabel(layoutWidget);
        textureLabel->setObjectName(QString::fromUtf8("textureLabel"));

        verticalLayout_2->addWidget(textureLabel);

        textureList = new QTreeWidget(layoutWidget);
        textureList->setObjectName(QString::fromUtf8("textureList"));
        textureList->setMinimumSize(QSize(300, 0));
        textureList->setRootIsDecorated(true);
        textureList->setUniformRowHeights(false);
        textureList->setItemsExpandable(true);
        textureList->setHeaderHidden(true);

        verticalLayout_2->addWidget(textureList);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(layoutWidget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        typeLabel = new QLabel(groupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(typeLabel);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        indexLabel = new QLabel(groupBox);
        indexLabel->setObjectName(QString::fromUtf8("indexLabel"));

        horizontalLayout_4->addWidget(indexLabel);

        indexBox = new QComboBox(groupBox);
        indexBox->setObjectName(QString::fromUtf8("indexBox"));

        horizontalLayout_4->addWidget(indexBox);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        repeatBox = new QCheckBox(groupBox);
        repeatBox->setObjectName(QString::fromUtf8("repeatBox"));

        verticalLayout->addWidget(repeatBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        max_val = new QDoubleSpinBox(groupBox);
        max_val->setObjectName(QString::fromUtf8("max_val"));

        horizontalLayout_2->addWidget(max_val);


        verticalLayout->addLayout(horizontalLayout_2);

        clampBox = new QCheckBox(groupBox);
        clampBox->setObjectName(QString::fromUtf8("clampBox"));

        verticalLayout->addWidget(clampBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        clamp_min = new QDoubleSpinBox(groupBox);
        clamp_min->setObjectName(QString::fromUtf8("clamp_min"));
        clamp_min->setDecimals(3);
        clamp_min->setMinimum(-9999);
        clamp_min->setMaximum(9999);
        clamp_min->setSingleStep(0.5);

        horizontalLayout->addWidget(clamp_min);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        clamp_max = new QDoubleSpinBox(groupBox);
        clamp_max->setObjectName(QString::fromUtf8("clamp_max"));
        clamp_max->setDecimals(3);
        clamp_max->setMinimum(-9999);
        clamp_max->setMaximum(9999);
        clamp_max->setSingleStep(0.5);

        horizontalLayout->addWidget(clamp_max);


        verticalLayout->addLayout(horizontalLayout);

        centerBox = new QCheckBox(groupBox);
        centerBox->setObjectName(QString::fromUtf8("centerBox"));

        verticalLayout->addWidget(centerBox);

        absBox = new QCheckBox(groupBox);
        absBox->setObjectName(QString::fromUtf8("absBox"));

        verticalLayout->addWidget(absBox);

        scaleBox = new QCheckBox(groupBox);
        scaleBox->setObjectName(QString::fromUtf8("scaleBox"));

        verticalLayout->addWidget(scaleBox);


        horizontalLayout_3->addWidget(groupBox);

        imageBox = new QGroupBox(layoutWidget1);
        imageBox->setObjectName(QString::fromUtf8("imageBox"));
        imageBox->setMinimumSize(QSize(280, 280));
        verticalLayout_4 = new QVBoxLayout(imageBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        imageLabel = new QLabel(imageBox);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy);
        imageLabel->setMinimumSize(QSize(100, 100));
        imageLabel->setMaximumSize(QSize(250, 250));

        verticalLayout_4->addWidget(imageLabel);

        fileLabel = new QLabel(imageBox);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        fileLabel->setWordWrap(true);

        verticalLayout_4->addWidget(fileLabel);

        changeImageButton = new QPushButton(imageBox);
        changeImageButton->setObjectName(QString::fromUtf8("changeImageButton"));

        verticalLayout_4->addWidget(changeImageButton);


        horizontalLayout_3->addWidget(imageBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        originalData = new QGroupBox(layoutWidget1);
        originalData->setObjectName(QString::fromUtf8("originalData"));
        originalData->setMinimumSize(QSize(400, 0));

        verticalLayout_3->addWidget(originalData);

        splitter->addWidget(layoutWidget1);

        verticalLayout_5->addWidget(splitter);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(buttonBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Texture Properties", 0, QApplication::UnicodeUTF8));
        textureLabel->setText(QApplication::translate("Dialog", "Textures:", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = textureList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Dialog", "1", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "Properties", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("Dialog", "Type:", 0, QApplication::UnicodeUTF8));
        indexLabel->setText(QApplication::translate("Dialog", "Index Property:", 0, QApplication::UnicodeUTF8));
        repeatBox->setText(QApplication::translate("Dialog", "Repeat Texture", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Maximum:", 0, QApplication::UnicodeUTF8));
        clampBox->setText(QApplication::translate("Dialog", "Clamp Texture", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Minimum:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Maximum:", 0, QApplication::UnicodeUTF8));
        centerBox->setText(QApplication::translate("Dialog", "Center", 0, QApplication::UnicodeUTF8));
        absBox->setText(QApplication::translate("Dialog", "Use Absolute values", 0, QApplication::UnicodeUTF8));
        scaleBox->setText(QApplication::translate("Dialog", "Scale", 0, QApplication::UnicodeUTF8));
        imageBox->setTitle(QApplication::translate("Dialog", "Image", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QApplication::translate("Dialog", "Image", 0, QApplication::UnicodeUTF8));
        fileLabel->setText(QApplication::translate("Dialog", "File:", 0, QApplication::UnicodeUTF8));
        changeImageButton->setText(QApplication::translate("Dialog", "Change Image", 0, QApplication::UnicodeUTF8));
        originalData->setTitle(QApplication::translate("Dialog", " Visualization of current values ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTUREPROPERTIES_H
