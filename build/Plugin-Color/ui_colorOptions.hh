/********************************************************************************
** Form generated from reading UI file 'colorOptions.ui'
**
** Created: Sat May 18 02:52:43 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLOROPTIONS_H
#define UI_COLOROPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_colorOptions
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *defaultColors;
    QFormLayout *formLayout;
    QLabel *label_2;
    QPushButton *backgroundDefault;
    QLabel *label_3;
    QPushButton *baseDefault;
    QLabel *label_4;
    QPushButton *materialDefault;
    QLabel *label;
    QDoubleSpinBox *lineDefault;
    QWidget *paper;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QPushButton *backgroundPaper;
    QLabel *label_8;
    QPushButton *basePaper;
    QLabel *label_7;
    QPushButton *materialPaper;
    QLabel *label_6;
    QDoubleSpinBox *linePaper;
    QWidget *presentation;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QPushButton *backgroundPresentation;
    QLabel *label_12;
    QPushButton *basePresentation;
    QLabel *label_11;
    QPushButton *materialPresentation;
    QLabel *label_10;
    QDoubleSpinBox *linePresentation;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *colorOptions)
    {
        if (colorOptions->objectName().isEmpty())
            colorOptions->setObjectName(QString::fromUtf8("colorOptions"));
        colorOptions->resize(487, 393);
        verticalLayout = new QVBoxLayout(colorOptions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(colorOptions);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        defaultColors = new QWidget();
        defaultColors->setObjectName(QString::fromUtf8("defaultColors"));
        formLayout = new QFormLayout(defaultColors);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(defaultColors);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        backgroundDefault = new QPushButton(defaultColors);
        backgroundDefault->setObjectName(QString::fromUtf8("backgroundDefault"));

        formLayout->setWidget(0, QFormLayout::FieldRole, backgroundDefault);

        label_3 = new QLabel(defaultColors);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        baseDefault = new QPushButton(defaultColors);
        baseDefault->setObjectName(QString::fromUtf8("baseDefault"));

        formLayout->setWidget(1, QFormLayout::FieldRole, baseDefault);

        label_4 = new QLabel(defaultColors);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        materialDefault = new QPushButton(defaultColors);
        materialDefault->setObjectName(QString::fromUtf8("materialDefault"));

        formLayout->setWidget(2, QFormLayout::FieldRole, materialDefault);

        label = new QLabel(defaultColors);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        lineDefault = new QDoubleSpinBox(defaultColors);
        lineDefault->setObjectName(QString::fromUtf8("lineDefault"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineDefault);

        tabWidget->addTab(defaultColors, QString());
        paper = new QWidget();
        paper->setObjectName(QString::fromUtf8("paper"));
        formLayout_2 = new QFormLayout(paper);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_5 = new QLabel(paper);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        backgroundPaper = new QPushButton(paper);
        backgroundPaper->setObjectName(QString::fromUtf8("backgroundPaper"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, backgroundPaper);

        label_8 = new QLabel(paper);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        basePaper = new QPushButton(paper);
        basePaper->setObjectName(QString::fromUtf8("basePaper"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, basePaper);

        label_7 = new QLabel(paper);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_7);

        materialPaper = new QPushButton(paper);
        materialPaper->setObjectName(QString::fromUtf8("materialPaper"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, materialPaper);

        label_6 = new QLabel(paper);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_6);

        linePaper = new QDoubleSpinBox(paper);
        linePaper->setObjectName(QString::fromUtf8("linePaper"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, linePaper);

        tabWidget->addTab(paper, QString());
        presentation = new QWidget();
        presentation->setObjectName(QString::fromUtf8("presentation"));
        formLayout_3 = new QFormLayout(presentation);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_9 = new QLabel(presentation);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_9);

        backgroundPresentation = new QPushButton(presentation);
        backgroundPresentation->setObjectName(QString::fromUtf8("backgroundPresentation"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, backgroundPresentation);

        label_12 = new QLabel(presentation);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_12);

        basePresentation = new QPushButton(presentation);
        basePresentation->setObjectName(QString::fromUtf8("basePresentation"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, basePresentation);

        label_11 = new QLabel(presentation);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        materialPresentation = new QPushButton(presentation);
        materialPresentation->setObjectName(QString::fromUtf8("materialPresentation"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, materialPresentation);

        label_10 = new QLabel(presentation);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_10);

        linePresentation = new QDoubleSpinBox(presentation);
        linePresentation->setObjectName(QString::fromUtf8("linePresentation"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, linePresentation);

        tabWidget->addTab(presentation, QString());

        verticalLayout->addWidget(tabWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(colorOptions);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(colorOptions);
    } // setupUi

    void retranslateUi(QWidget *colorOptions)
    {
        colorOptions->setWindowTitle(QApplication::translate("colorOptions", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("colorOptions", "Background Color:", 0, QApplication::UnicodeUTF8));
        backgroundDefault->setText(QString());
        label_3->setText(QApplication::translate("colorOptions", "Base Color:", 0, QApplication::UnicodeUTF8));
        baseDefault->setText(QString());
        label_4->setText(QApplication::translate("colorOptions", "Material Color:", 0, QApplication::UnicodeUTF8));
        materialDefault->setText(QString());
        label->setText(QApplication::translate("colorOptions", "Line Width:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(defaultColors), QApplication::translate("colorOptions", "Default Colors", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("colorOptions", "Background Color:", 0, QApplication::UnicodeUTF8));
        backgroundPaper->setText(QString());
        label_8->setText(QApplication::translate("colorOptions", "Base Color:", 0, QApplication::UnicodeUTF8));
        basePaper->setText(QString());
        label_7->setText(QApplication::translate("colorOptions", "Material Color:", 0, QApplication::UnicodeUTF8));
        materialPaper->setText(QString());
        label_6->setText(QApplication::translate("colorOptions", "Line Width:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(paper), QApplication::translate("colorOptions", "Paper Colors", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("colorOptions", "Background Color:", 0, QApplication::UnicodeUTF8));
        backgroundPresentation->setText(QString());
        label_12->setText(QApplication::translate("colorOptions", "Base Color:", 0, QApplication::UnicodeUTF8));
        basePresentation->setText(QString());
        label_11->setText(QApplication::translate("colorOptions", "Material Color:", 0, QApplication::UnicodeUTF8));
        materialPresentation->setText(QString());
        label_10->setText(QApplication::translate("colorOptions", "Line Width:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(presentation), QApplication::translate("colorOptions", "Presentation Colors", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class colorOptions: public Ui_colorOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLOROPTIONS_H
