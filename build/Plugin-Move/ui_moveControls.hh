/********************************************************************************
** Form generated from reading UI file 'moveControls.ui'
**
** Created: Sat May 18 02:56:57 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVECONTROLS_H
#define UI_MOVECONTROLS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_moveControls
{
public:
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QPushButton *moveToOrigin;
    QWidget *Transform;
    QVBoxLayout *verticalLayout_2;
    QPushButton *unifyBoundingBoxDiagonal;

    void setupUi(QWidget *moveControls)
    {
        if (moveControls->objectName().isEmpty())
            moveControls->setObjectName(QString::fromUtf8("moveControls"));
        moveControls->resize(380, 157);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(moveControls->sizePolicy().hasHeightForWidth());
        moveControls->setSizePolicy(sizePolicy);
        moveControls->setMaximumSize(QSize(380, 16777215));
        verticalLayout_6 = new QVBoxLayout(moveControls);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tabWidget = new QTabWidget(moveControls);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        moveToOrigin = new QPushButton(tab);
        moveToOrigin->setObjectName(QString::fromUtf8("moveToOrigin"));

        verticalLayout_3->addWidget(moveToOrigin);

        tabWidget->addTab(tab, QString());
        Transform = new QWidget();
        Transform->setObjectName(QString::fromUtf8("Transform"));
        verticalLayout_2 = new QVBoxLayout(Transform);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        unifyBoundingBoxDiagonal = new QPushButton(Transform);
        unifyBoundingBoxDiagonal->setObjectName(QString::fromUtf8("unifyBoundingBoxDiagonal"));

        verticalLayout_2->addWidget(unifyBoundingBoxDiagonal);

        tabWidget->addTab(Transform, QString());

        verticalLayout_6->addWidget(tabWidget);


        retranslateUi(moveControls);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(moveControls);
    } // setupUi

    void retranslateUi(QWidget *moveControls)
    {
        moveControls->setWindowTitle(QApplication::translate("moveControls", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        moveToOrigin->setToolTip(QApplication::translate("moveControls", "Move COG to origin", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        moveToOrigin->setStatusTip(QApplication::translate("moveControls", "Move COG of selected objects to origin", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        moveToOrigin->setWhatsThis(QApplication::translate("moveControls", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Moves the selected objects such that</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">their center of gravity is at the origin. <a href=\"index.html#move_cog\"><span style=\" text-decoration: underline; color:#0057ae;\">Click fore more information</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        moveToOrigin->setText(QApplication::translate("moveControls", "Move COG to origin", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("moveControls", "Move", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        unifyBoundingBoxDiagonal->setToolTip(QApplication::translate("moveControls", "Normalize bounding box diagonal of objects", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        unifyBoundingBoxDiagonal->setStatusTip(QApplication::translate("moveControls", "Normalize bounding box diagonal of objects", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        unifyBoundingBoxDiagonal->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        unifyBoundingBoxDiagonal->setText(QApplication::translate("moveControls", "Unify Boundingbox Diagonal", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Transform), QApplication::translate("moveControls", "Transform", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class moveControls: public Ui_moveControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVECONTROLS_H
