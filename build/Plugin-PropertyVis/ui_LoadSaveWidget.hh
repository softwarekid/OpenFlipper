/********************************************************************************
** Form generated from reading UI file 'LoadSaveWidget.ui'
**
** Created: Sat May 18 02:57:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADSAVEWIDGET_H
#define UI_LOADSAVEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadSaveWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *load_property;
    QPushButton *save_property;
    QCheckBox *binary_cb;

    void setupUi(QWidget *LoadSaveWidget)
    {
        if (LoadSaveWidget->objectName().isEmpty())
            LoadSaveWidget->setObjectName(QString::fromUtf8("LoadSaveWidget"));
        LoadSaveWidget->resize(449, 69);
        verticalLayout_7 = new QVBoxLayout(LoadSaveWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_2 = new QGroupBox(LoadSaveWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        load_property = new QPushButton(groupBox_2);
        load_property->setObjectName(QString::fromUtf8("load_property"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(load_property->sizePolicy().hasHeightForWidth());
        load_property->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(load_property);

        save_property = new QPushButton(groupBox_2);
        save_property->setObjectName(QString::fromUtf8("save_property"));
        sizePolicy.setHeightForWidth(save_property->sizePolicy().hasHeightForWidth());
        save_property->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(save_property);

        binary_cb = new QCheckBox(groupBox_2);
        binary_cb->setObjectName(QString::fromUtf8("binary_cb"));
        binary_cb->setEnabled(false);

        horizontalLayout_6->addWidget(binary_cb);


        gridLayout_4->addLayout(horizontalLayout_6, 1, 0, 1, 2);


        verticalLayout_7->addWidget(groupBox_2);

        QWidget::setTabOrder(load_property, save_property);
        QWidget::setTabOrder(save_property, binary_cb);

        retranslateUi(LoadSaveWidget);

        QMetaObject::connectSlotsByName(LoadSaveWidget);
    } // setupUi

    void retranslateUi(QWidget *LoadSaveWidget)
    {
        LoadSaveWidget->setWindowTitle(QApplication::translate("LoadSaveWidget", "Property Visualization", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("LoadSaveWidget", "Load/Save", 0, QApplication::UnicodeUTF8));
        load_property->setText(QApplication::translate("LoadSaveWidget", "Load", 0, QApplication::UnicodeUTF8));
        save_property->setText(QApplication::translate("LoadSaveWidget", "Save", 0, QApplication::UnicodeUTF8));
        binary_cb->setText(QApplication::translate("LoadSaveWidget", "binary", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoadSaveWidget: public Ui_LoadSaveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADSAVEWIDGET_H
