/********************************************************************************
** Form generated from reading UI file 'helpWidget.ui'
**
** Created: Sat May 18 02:52:48 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWIDGET_H
#define UI_HELPWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWidget
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_;
    QWidget *widget;
    QToolButton *backButton_;
    QToolButton *searchButton_;
    QToolButton *forwardButton_;
    QToolButton *homeButton_;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HelpWidget)
    {
        if (HelpWidget->objectName().isEmpty())
            HelpWidget->setObjectName(QString::fromUtf8("HelpWidget"));
        HelpWidget->resize(800, 641);
        centralwidget = new QWidget(HelpWidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_ = new QGridLayout();
        gridLayout_->setObjectName(QString::fromUtf8("gridLayout_"));

        gridLayout->addLayout(gridLayout_, 1, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(300, 45));
        widget->setMaximumSize(QSize(16777215, 45));
        backButton_ = new QToolButton(widget);
        backButton_->setObjectName(QString::fromUtf8("backButton_"));
        backButton_->setGeometry(QRect(70, 10, 45, 25));
        backButton_->setMaximumSize(QSize(16777215, 31));
        searchButton_ = new QToolButton(widget);
        searchButton_->setObjectName(QString::fromUtf8("searchButton_"));
        searchButton_->setGeometry(QRect(170, 10, 57, 25));
        searchButton_->setMaximumSize(QSize(16777215, 31));
        forwardButton_ = new QToolButton(widget);
        forwardButton_->setObjectName(QString::fromUtf8("forwardButton_"));
        forwardButton_->setGeometry(QRect(120, 10, 45, 25));
        forwardButton_->setMaximumSize(QSize(16777215, 31));
        homeButton_ = new QToolButton(widget);
        homeButton_->setObjectName(QString::fromUtf8("homeButton_"));
        homeButton_->setGeometry(QRect(10, 10, 51, 25));
        homeButton_->setMaximumSize(QSize(16777215, 31));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        HelpWidget->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(HelpWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HelpWidget->setStatusBar(statusbar);

        retranslateUi(HelpWidget);

        QMetaObject::connectSlotsByName(HelpWidget);
    } // setupUi

    void retranslateUi(QMainWindow *HelpWidget)
    {
        HelpWidget->setWindowTitle(QApplication::translate("HelpWidget", "OpenFlipper Help", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        backButton_->setToolTip(QApplication::translate("HelpWidget", "Go one page back.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        backButton_->setWhatsThis(QApplication::translate("HelpWidget", "Go one page back.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        backButton_->setText(QApplication::translate("HelpWidget", "Back", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        searchButton_->setToolTip(QApplication::translate("HelpWidget", "Search help for specified item.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        searchButton_->setWhatsThis(QApplication::translate("HelpWidget", "Search help for specified item.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        searchButton_->setText(QApplication::translate("HelpWidget", "Search", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        forwardButton_->setToolTip(QApplication::translate("HelpWidget", "Go one page forward.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        forwardButton_->setWhatsThis(QApplication::translate("HelpWidget", "Go one page forward.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        forwardButton_->setText(QApplication::translate("HelpWidget", "Forward", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        homeButton_->setToolTip(QApplication::translate("HelpWidget", "Open home site.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        homeButton_->setWhatsThis(QApplication::translate("HelpWidget", "Open home site.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        homeButton_->setText(QApplication::translate("HelpWidget", "Home", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HelpWidget: public Ui_HelpWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWIDGET_H
