/********************************************************************************
** Form generated from reading UI file 'PropertyVisToolbarBase.ui'
**
** Created: Sat May 18 02:57:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTYVISTOOLBARBASE_H
#define UI_PROPERTYVISTOOLBARBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

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
    QVBoxLayout *propertyWidgets;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *PropertyVisToolbarBase)
    {
        if (PropertyVisToolbarBase->objectName().isEmpty())
            PropertyVisToolbarBase->setObjectName(QString::fromUtf8("PropertyVisToolbarBase"));
        PropertyVisToolbarBase->resize(485, 338);
        verticalLayout_7 = new QVBoxLayout(PropertyVisToolbarBase);
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

        propertyWidgets = new QVBoxLayout();
        propertyWidgets->setObjectName(QString::fromUtf8("propertyWidgets"));

        verticalLayout_7->addLayout(propertyWidgets);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(meshNames);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(meshNames, propertyName_lv);
        QWidget::setTabOrder(propertyName_lv, visualizeButton);
        QWidget::setTabOrder(visualizeButton, clearButton);

        retranslateUi(PropertyVisToolbarBase);

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
    } // retranslateUi

};

namespace Ui {
    class PropertyVisToolbarBase: public Ui_PropertyVisToolbarBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTYVISTOOLBARBASE_H
