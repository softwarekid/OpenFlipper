/********************************************************************************
** Form generated from reading UI file 'scriptingWidget.ui'
**
** Created: Sat May 18 02:58:26 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTINGWIDGET_H
#define UI_SCRIPTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "FunctionList.hh"
#include "codeeditor.hh"

QT_BEGIN_NAMESPACE

class Ui_ScriptWidget
{
public:
    QAction *actionScan_Directory;
    QAction *actionCheck_Database;
    QAction *actionLoad_Script;
    QAction *actionSave_Script;
    QAction *actionClose;
    QAction *actionSave_Script_As;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout;
    CodeEditorWidget *currentScript;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *vboxLayout1;
    QTextEdit *liveEdit;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filterEdit;
    QPushButton *filterButton;
    QPushButton *resetButton;
    FunctionList *functionList;
    QGroupBox *description;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ScriptWidget)
    {
        if (ScriptWidget->objectName().isEmpty())
            ScriptWidget->setObjectName(QString::fromUtf8("ScriptWidget"));
        ScriptWidget->resize(895, 969);
        actionScan_Directory = new QAction(ScriptWidget);
        actionScan_Directory->setObjectName(QString::fromUtf8("actionScan_Directory"));
        actionCheck_Database = new QAction(ScriptWidget);
        actionCheck_Database->setObjectName(QString::fromUtf8("actionCheck_Database"));
        actionLoad_Script = new QAction(ScriptWidget);
        actionLoad_Script->setObjectName(QString::fromUtf8("actionLoad_Script"));
        actionSave_Script = new QAction(ScriptWidget);
        actionSave_Script->setObjectName(QString::fromUtf8("actionSave_Script"));
        actionSave_Script->setEnabled(false);
        actionClose = new QAction(ScriptWidget);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionSave_Script_As = new QAction(ScriptWidget);
        actionSave_Script_As->setObjectName(QString::fromUtf8("actionSave_Script_As"));
        centralwidget = new QWidget(ScriptWidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout = new QVBoxLayout(groupBox);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        currentScript = new CodeEditorWidget(groupBox);
        currentScript->setObjectName(QString::fromUtf8("currentScript"));
        currentScript->setEnabled(true);

        vboxLayout->addWidget(currentScript);

        splitter->addWidget(groupBox);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        vboxLayout1 = new QVBoxLayout(tab);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        liveEdit = new QTextEdit(tab);
        liveEdit->setObjectName(QString::fromUtf8("liveEdit"));
        liveEdit->setReadOnly(true);
        liveEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        vboxLayout1->addWidget(liveEdit);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filterEdit = new QLineEdit(groupBox_2);
        filterEdit->setObjectName(QString::fromUtf8("filterEdit"));

        horizontalLayout->addWidget(filterEdit);

        filterButton = new QPushButton(groupBox_2);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        horizontalLayout->addWidget(filterButton);

        resetButton = new QPushButton(groupBox_2);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        horizontalLayout->addWidget(resetButton);


        verticalLayout->addWidget(groupBox_2);

        functionList = new FunctionList(tab_2);
        functionList->setObjectName(QString::fromUtf8("functionList"));
        functionList->setDragEnabled(true);
        functionList->setDragDropMode(QAbstractItemView::DragOnly);

        verticalLayout->addWidget(functionList);

        description = new QGroupBox(tab_2);
        description->setObjectName(QString::fromUtf8("description"));

        verticalLayout->addWidget(description);

        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);

        verticalLayout_2->addWidget(splitter);

        ScriptWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ScriptWidget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 895, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        ScriptWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(ScriptWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ScriptWidget->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_Script);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Script);
        menuFile->addAction(actionSave_Script_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);

        retranslateUi(ScriptWidget);
        QObject::connect(filterEdit, SIGNAL(returnPressed()), filterButton, SLOT(click()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ScriptWidget);
    } // setupUi

    void retranslateUi(QMainWindow *ScriptWidget)
    {
        ScriptWidget->setWindowTitle(QApplication::translate("ScriptWidget", "Script Editor", 0, QApplication::UnicodeUTF8));
        actionScan_Directory->setText(QApplication::translate("ScriptWidget", "Scan Directory", 0, QApplication::UnicodeUTF8));
        actionCheck_Database->setText(QApplication::translate("ScriptWidget", "Check Database", 0, QApplication::UnicodeUTF8));
        actionLoad_Script->setText(QApplication::translate("ScriptWidget", "Open", 0, QApplication::UnicodeUTF8));
        actionSave_Script->setText(QApplication::translate("ScriptWidget", "Save", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("ScriptWidget", "Close", 0, QApplication::UnicodeUTF8));
        actionSave_Script_As->setText(QApplication::translate("ScriptWidget", "Save As", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ScriptWidget", "Current Script", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ScriptWidget", "Live View", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ScriptWidget", "Filter", 0, QApplication::UnicodeUTF8));
        filterButton->setText(QApplication::translate("ScriptWidget", "Filter", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("ScriptWidget", "Reset", 0, QApplication::UnicodeUTF8));
        description->setTitle(QApplication::translate("ScriptWidget", " Description ", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ScriptWidget", "Function List", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ScriptWidget", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScriptWidget: public Ui_ScriptWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTINGWIDGET_H
