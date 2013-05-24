/********************************************************************************
** Form generated from reading UI file 'rendererObjectWidget.ui'
**
** Created: Sat May 18 02:52:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDEREROBJECTWIDGET_H
#define UI_RENDEREROBJECTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RendererObjectWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QCheckBox *showShadersBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *RendererObjectWidget)
    {
        if (RendererObjectWidget->objectName().isEmpty())
            RendererObjectWidget->setObjectName(QString::fromUtf8("RendererObjectWidget"));
        RendererObjectWidget->resize(939, 527);
        verticalLayout = new QVBoxLayout(RendererObjectWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_3 = new QFrame(RendererObjectWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMaximumSize(QSize(16777215, 40));
        frame_3->setAutoFillBackground(false);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setMidLineWidth(0);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addWidget(frame_3);

        textBrowser = new QTextBrowser(RendererObjectWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        showShadersBox = new QCheckBox(RendererObjectWidget);
        showShadersBox->setObjectName(QString::fromUtf8("showShadersBox"));
        showShadersBox->setChecked(true);

        verticalLayout->addWidget(showShadersBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(RendererObjectWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(RendererObjectWidget);

        QMetaObject::connectSlotsByName(RendererObjectWidget);
    } // setupUi

    void retranslateUi(QWidget *RendererObjectWidget)
    {
        RendererObjectWidget->setWindowTitle(QApplication::translate("RendererObjectWidget", "Render Objects", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RendererObjectWidget", "Current Render Object Data", 0, QApplication::UnicodeUTF8));
        showShadersBox->setText(QApplication::translate("RendererObjectWidget", "Show Shaders", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("RendererObjectWidget", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RendererObjectWidget: public Ui_RendererObjectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDEREROBJECTWIDGET_H
