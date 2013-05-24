/********************************************************************************
** Form generated from reading UI file 'SelectionBaseToolbox.ui'
**
** Created: Sat May 18 03:02:37 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTIONBASETOOLBOX_H
#define UI_SELECTIONBASETOOLBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectionBaseToolbox
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *typeTabWidget;
    QFrame *line_3;
    QPushButton *restrictOnTargets;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadSelection;
    QPushButton *saveSelection;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *maxFloodFillAngle;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SelectionBaseToolbox)
    {
        if (SelectionBaseToolbox->objectName().isEmpty())
            SelectionBaseToolbox->setObjectName(QString::fromUtf8("SelectionBaseToolbox"));
        SelectionBaseToolbox->resize(456, 592);
        verticalLayout_2 = new QVBoxLayout(SelectionBaseToolbox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        typeTabWidget = new QTabWidget(SelectionBaseToolbox);
        typeTabWidget->setObjectName(QString::fromUtf8("typeTabWidget"));

        verticalLayout->addWidget(typeTabWidget);

        line_3 = new QFrame(SelectionBaseToolbox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        restrictOnTargets = new QPushButton(SelectionBaseToolbox);
        restrictOnTargets->setObjectName(QString::fromUtf8("restrictOnTargets"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(restrictOnTargets->sizePolicy().hasHeightForWidth());
        restrictOnTargets->setSizePolicy(sizePolicy);
        restrictOnTargets->setCheckable(true);
        restrictOnTargets->setChecked(false);

        verticalLayout->addWidget(restrictOnTargets);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loadSelection = new QPushButton(SelectionBaseToolbox);
        loadSelection->setObjectName(QString::fromUtf8("loadSelection"));

        horizontalLayout->addWidget(loadSelection);

        saveSelection = new QPushButton(SelectionBaseToolbox);
        saveSelection->setObjectName(QString::fromUtf8("saveSelection"));

        horizontalLayout->addWidget(saveSelection);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        groupBox_4 = new QGroupBox(SelectionBaseToolbox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(groupBox_4);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        formLayout_2 = new QFormLayout(tab_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        maxFloodFillAngle = new QDoubleSpinBox(tab_2);
        maxFloodFillAngle->setObjectName(QString::fromUtf8("maxFloodFillAngle"));
        maxFloodFillAngle->setMaximum(180);
        maxFloodFillAngle->setValue(15);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, maxFloodFillAngle);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);


        verticalLayout_2->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(SelectionBaseToolbox);

        typeTabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SelectionBaseToolbox);
    } // setupUi

    void retranslateUi(QWidget *SelectionBaseToolbox)
    {
        SelectionBaseToolbox->setWindowTitle(QApplication::translate("SelectionBaseToolbox", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        restrictOnTargets->setToolTip(QApplication::translate("SelectionBaseToolbox", "Restrict all selection methods in this toolbox to target objects", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        restrictOnTargets->setStatusTip(QApplication::translate("SelectionBaseToolbox", "Restrict all selection methods in this toolbox to target objects", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        restrictOnTargets->setText(QApplication::translate("SelectionBaseToolbox", "Select on target objects only", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        loadSelection->setToolTip(QApplication::translate("SelectionBaseToolbox", "Load current selection from file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        loadSelection->setStatusTip(QApplication::translate("SelectionBaseToolbox", "Load current selection from file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        loadSelection->setText(QApplication::translate("SelectionBaseToolbox", "Load Selection", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveSelection->setToolTip(QApplication::translate("SelectionBaseToolbox", "Save current selection to file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        saveSelection->setStatusTip(QApplication::translate("SelectionBaseToolbox", "Save current selection to file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        saveSelection->setText(QApplication::translate("SelectionBaseToolbox", "Save Selection", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("SelectionBaseToolbox", "Tool Parameters", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SelectionBaseToolbox", "Maximum angle:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        maxFloodFillAngle->setToolTip(QApplication::translate("SelectionBaseToolbox", "Maximum angle between faces that get flood filled", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        maxFloodFillAngle->setStatusTip(QApplication::translate("SelectionBaseToolbox", "Maximum angle between faces that get flood filled", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SelectionBaseToolbox", "Flood Fill", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectionBaseToolbox: public Ui_SelectionBaseToolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTIONBASETOOLBOX_H
