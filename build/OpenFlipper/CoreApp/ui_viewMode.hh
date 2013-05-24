/********************************************************************************
** Form generated from reading UI file 'viewMode.ui'
**
** Created: Sat May 18 02:52:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWMODE_H
#define UI_VIEWMODE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewMode
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *viewModeList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *removeButton;
    QPushButton *copyButton;
    QPushButton *addButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *_7;
    QListWidget *toolboxList;
    QVBoxLayout *_8;
    QSpacerItem *spacerItem;
    QToolButton *upButtonToolbox;
    QToolButton *downButtonToolbox;
    QSpacerItem *spacerItem1;
    QVBoxLayout *_11;
    QSpacerItem *spacerItem2;
    QToolButton *rightArrowToolbox;
    QToolButton *leftArrowToolbox;
    QSpacerItem *spacerItem3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QListWidget *availableToolboxes;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QListWidget *toolbarList;
    QVBoxLayout *_9;
    QSpacerItem *spacerItem4;
    QToolButton *rightArrowToolbar;
    QToolButton *leftArrowToolbar;
    QSpacerItem *spacerItem5;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_6;
    QListWidget *availableToolbars;
    QWidget *tab_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_9;
    QGridLayout *_12;
    QListWidget *contextMenuList;
    QVBoxLayout *_13;
    QSpacerItem *spacerItem6;
    QToolButton *upButtonContextMenu;
    QToolButton *downButtonContextMenu;
    QSpacerItem *spacerItem7;
    QVBoxLayout *_14;
    QSpacerItem *spacerItem8;
    QToolButton *rightArrowContextMenu;
    QToolButton *leftArrowContextMenu;
    QSpacerItem *spacerItem9;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_10;
    QListWidget *availableContextMenus;
    QHBoxLayout *_10;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QSpacerItem *spacerItem10;
    QPushButton *okButton;

    void setupUi(QDialog *viewMode)
    {
        if (viewMode->objectName().isEmpty())
            viewMode->setObjectName(QString::fromUtf8("viewMode"));
        viewMode->resize(767, 816);
        verticalLayout = new QVBoxLayout(viewMode);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(viewMode);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(0, 270));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        groupBox_2->setBaseSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        viewModeList = new QListWidget(groupBox_2);
        viewModeList->setObjectName(QString::fromUtf8("viewModeList"));
        viewModeList->setBaseSize(QSize(0, 0));
        viewModeList->setAlternatingRowColors(false);
        viewModeList->setIconSize(QSize(125, 125));
        viewModeList->setFlow(QListView::LeftToRight);
        viewModeList->setSpacing(15);
        viewModeList->setViewMode(QListView::IconMode);
        viewModeList->setWordWrap(false);

        verticalLayout_2->addWidget(viewModeList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        removeButton = new QPushButton(groupBox_2);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout_2->addWidget(removeButton);

        copyButton = new QPushButton(groupBox_2);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        horizontalLayout_2->addWidget(copyButton);

        addButton = new QPushButton(groupBox_2);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout_2->addWidget(addButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox_2);

        tabWidget = new QTabWidget(viewMode);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_7 = new QVBoxLayout(tab);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        _7 = new QGridLayout();
        _7->setObjectName(QString::fromUtf8("_7"));
        toolboxList = new QListWidget(groupBox_3);
        toolboxList->setObjectName(QString::fromUtf8("toolboxList"));
        toolboxList->setProperty("showDropIndicator", QVariant(false));
        toolboxList->setDragDropOverwriteMode(false);
        toolboxList->setDragDropMode(QAbstractItemView::NoDragDrop);
        toolboxList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        toolboxList->setMovement(QListView::Static);
        toolboxList->setSortingEnabled(false);

        _7->addWidget(toolboxList, 0, 0, 1, 1);

        _8 = new QVBoxLayout();
        _8->setObjectName(QString::fromUtf8("_8"));
        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _8->addItem(spacerItem);

        upButtonToolbox = new QToolButton(groupBox_3);
        upButtonToolbox->setObjectName(QString::fromUtf8("upButtonToolbox"));

        _8->addWidget(upButtonToolbox);

        downButtonToolbox = new QToolButton(groupBox_3);
        downButtonToolbox->setObjectName(QString::fromUtf8("downButtonToolbox"));

        _8->addWidget(downButtonToolbox);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _8->addItem(spacerItem1);


        _7->addLayout(_8, 0, 1, 1, 1);


        verticalLayout_4->addLayout(_7);


        horizontalLayout_3->addWidget(groupBox_3);

        _11 = new QVBoxLayout();
        _11->setObjectName(QString::fromUtf8("_11"));
        spacerItem2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _11->addItem(spacerItem2);

        rightArrowToolbox = new QToolButton(tab);
        rightArrowToolbox->setObjectName(QString::fromUtf8("rightArrowToolbox"));

        _11->addWidget(rightArrowToolbox);

        leftArrowToolbox = new QToolButton(tab);
        leftArrowToolbox->setObjectName(QString::fromUtf8("leftArrowToolbox"));

        _11->addWidget(leftArrowToolbox);

        spacerItem3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _11->addItem(spacerItem3);


        horizontalLayout_3->addLayout(_11);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        availableToolboxes = new QListWidget(groupBox);
        availableToolboxes->setObjectName(QString::fromUtf8("availableToolboxes"));
        availableToolboxes->setSelectionMode(QAbstractItemView::ExtendedSelection);
        availableToolboxes->setSortingEnabled(true);

        verticalLayout_3->addWidget(availableToolboxes);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout_7->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout = new QHBoxLayout(tab_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        toolbarList = new QListWidget(groupBox_4);
        toolbarList->setObjectName(QString::fromUtf8("toolbarList"));
        toolbarList->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_5->addWidget(toolbarList);


        horizontalLayout->addWidget(groupBox_4);

        _9 = new QVBoxLayout();
        _9->setObjectName(QString::fromUtf8("_9"));
        spacerItem4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _9->addItem(spacerItem4);

        rightArrowToolbar = new QToolButton(tab_2);
        rightArrowToolbar->setObjectName(QString::fromUtf8("rightArrowToolbar"));

        _9->addWidget(rightArrowToolbar);

        leftArrowToolbar = new QToolButton(tab_2);
        leftArrowToolbar->setObjectName(QString::fromUtf8("leftArrowToolbar"));

        _9->addWidget(leftArrowToolbar);

        spacerItem5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _9->addItem(spacerItem5);


        horizontalLayout->addLayout(_9);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_6 = new QVBoxLayout(groupBox_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        availableToolbars = new QListWidget(groupBox_5);
        availableToolbars->setObjectName(QString::fromUtf8("availableToolbars"));
        availableToolbars->setSelectionMode(QAbstractItemView::ExtendedSelection);
        availableToolbars->setSortingEnabled(true);

        verticalLayout_6->addWidget(availableToolbars);


        horizontalLayout->addWidget(groupBox_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(4, 4, 729, 452));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_9 = new QVBoxLayout(groupBox_6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        _12 = new QGridLayout();
        _12->setObjectName(QString::fromUtf8("_12"));
        contextMenuList = new QListWidget(groupBox_6);
        contextMenuList->setObjectName(QString::fromUtf8("contextMenuList"));
        contextMenuList->setProperty("showDropIndicator", QVariant(false));
        contextMenuList->setDragDropOverwriteMode(false);
        contextMenuList->setDragDropMode(QAbstractItemView::NoDragDrop);
        contextMenuList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        contextMenuList->setMovement(QListView::Static);
        contextMenuList->setSortingEnabled(false);

        _12->addWidget(contextMenuList, 0, 0, 1, 1);

        _13 = new QVBoxLayout();
        _13->setObjectName(QString::fromUtf8("_13"));
        spacerItem6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _13->addItem(spacerItem6);

        upButtonContextMenu = new QToolButton(groupBox_6);
        upButtonContextMenu->setObjectName(QString::fromUtf8("upButtonContextMenu"));

        _13->addWidget(upButtonContextMenu);

        downButtonContextMenu = new QToolButton(groupBox_6);
        downButtonContextMenu->setObjectName(QString::fromUtf8("downButtonContextMenu"));

        _13->addWidget(downButtonContextMenu);

        spacerItem7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _13->addItem(spacerItem7);


        _12->addLayout(_13, 0, 1, 1, 1);


        verticalLayout_9->addLayout(_12);


        horizontalLayout_4->addWidget(groupBox_6);

        _14 = new QVBoxLayout();
        _14->setObjectName(QString::fromUtf8("_14"));
        spacerItem8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _14->addItem(spacerItem8);

        rightArrowContextMenu = new QToolButton(layoutWidget);
        rightArrowContextMenu->setObjectName(QString::fromUtf8("rightArrowContextMenu"));

        _14->addWidget(rightArrowContextMenu);

        leftArrowContextMenu = new QToolButton(layoutWidget);
        leftArrowContextMenu->setObjectName(QString::fromUtf8("leftArrowContextMenu"));

        _14->addWidget(leftArrowContextMenu);

        spacerItem9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _14->addItem(spacerItem9);


        horizontalLayout_4->addLayout(_14);

        groupBox_7 = new QGroupBox(layoutWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_10 = new QVBoxLayout(groupBox_7);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        availableContextMenus = new QListWidget(groupBox_7);
        availableContextMenus->setObjectName(QString::fromUtf8("availableContextMenus"));
        availableContextMenus->setSelectionMode(QAbstractItemView::ExtendedSelection);
        availableContextMenus->setSortingEnabled(true);

        verticalLayout_10->addWidget(availableContextMenus);


        horizontalLayout_4->addWidget(groupBox_7);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        _10 = new QHBoxLayout();
        _10->setObjectName(QString::fromUtf8("_10"));
        cancelButton = new QPushButton(viewMode);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        _10->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _10->addItem(horizontalSpacer);

        saveButton = new QPushButton(viewMode);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        _10->addWidget(saveButton);

        spacerItem10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _10->addItem(spacerItem10);

        okButton = new QPushButton(viewMode);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        _10->addWidget(okButton);


        verticalLayout->addLayout(_10);


        retranslateUi(viewMode);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(viewMode);
    } // setupUi

    void retranslateUi(QDialog *viewMode)
    {
        viewMode->setWindowTitle(QApplication::translate("viewMode", "Change View Mode", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("viewMode", "View Modes", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("viewMode", "Remove Mode", 0, QApplication::UnicodeUTF8));
        copyButton->setText(QApplication::translate("viewMode", "Copy Mode", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("viewMode", "Add Mode", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("viewMode", "Visible", 0, QApplication::UnicodeUTF8));
        upButtonToolbox->setText(QString());
        downButtonToolbox->setText(QString());
        rightArrowToolbox->setText(QString());
        leftArrowToolbox->setText(QString());
        groupBox->setTitle(QApplication::translate("viewMode", "Available", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("viewMode", "Toolboxes", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("viewMode", "Visible", 0, QApplication::UnicodeUTF8));
        rightArrowToolbar->setText(QString());
        leftArrowToolbar->setText(QString());
        groupBox_5->setTitle(QApplication::translate("viewMode", "Available", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("viewMode", "Toolbars", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("viewMode", "Visible", 0, QApplication::UnicodeUTF8));
        upButtonContextMenu->setText(QString());
        downButtonContextMenu->setText(QString());
        rightArrowContextMenu->setText(QString());
        leftArrowContextMenu->setText(QString());
        groupBox_7->setTitle(QApplication::translate("viewMode", "Available", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("viewMode", "Context Menus", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("viewMode", "&Cancel", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("viewMode", "Save Configuration", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("viewMode", "&Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class viewMode: public Ui_viewMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWMODE_H
