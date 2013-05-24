/********************************************************************************
** Form generated from reading UI file 'viewModeChange.ui'
**
** Created: Sat May 18 02:52:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWMODECHANGE_H
#define UI_VIEWMODECHANGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ViewModeChangeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *viewModeList;

    void setupUi(QDialog *ViewModeChangeDialog)
    {
        if (ViewModeChangeDialog->objectName().isEmpty())
            ViewModeChangeDialog->setObjectName(QString::fromUtf8("ViewModeChangeDialog"));
        ViewModeChangeDialog->resize(389, 341);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ViewModeChangeDialog->sizePolicy().hasHeightForWidth());
        ViewModeChangeDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ViewModeChangeDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        viewModeList = new QListWidget(ViewModeChangeDialog);
        viewModeList->setObjectName(QString::fromUtf8("viewModeList"));
        viewModeList->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(viewModeList->sizePolicy().hasHeightForWidth());
        viewModeList->setSizePolicy(sizePolicy1);
        viewModeList->setMaximumSize(QSize(380, 16777215));
        viewModeList->setSizeIncrement(QSize(0, 0));
        viewModeList->setAutoFillBackground(false);
        viewModeList->setFrameShadow(QFrame::Sunken);
        viewModeList->setLineWidth(1);
        viewModeList->setMidLineWidth(0);
        viewModeList->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        viewModeList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        viewModeList->setIconSize(QSize(100, 100));
        viewModeList->setMovement(QListView::Static);
        viewModeList->setFlow(QListView::LeftToRight);
        viewModeList->setProperty("isWrapping", QVariant(true));
        viewModeList->setResizeMode(QListView::Adjust);
        viewModeList->setViewMode(QListView::IconMode);
        viewModeList->setWordWrap(true);
        viewModeList->setSortingEnabled(true);

        verticalLayout->addWidget(viewModeList);


        retranslateUi(ViewModeChangeDialog);

        QMetaObject::connectSlotsByName(ViewModeChangeDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewModeChangeDialog)
    {
        ViewModeChangeDialog->setWindowTitle(QApplication::translate("ViewModeChangeDialog", "Choose View Mode", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewModeChangeDialog: public Ui_ViewModeChangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWMODECHANGE_H
