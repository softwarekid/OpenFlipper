/********************************************************************************
** Form generated from reading UI file 'postProcessorWidget.ui'
**
** Created: Sat May 18 02:52:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTPROCESSORWIDGET_H
#define UI_POSTPROCESSORWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostProcessorWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QListWidget *list;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *PostProcessorWidget)
    {
        if (PostProcessorWidget->objectName().isEmpty())
            PostProcessorWidget->setObjectName(QString::fromUtf8("PostProcessorWidget"));
        PostProcessorWidget->resize(939, 527);
        verticalLayout = new QVBoxLayout(PostProcessorWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_3 = new QFrame(PostProcessorWidget);
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

        list = new QListWidget(PostProcessorWidget);
        list->setObjectName(QString::fromUtf8("list"));
        list->setEditTriggers(QAbstractItemView::NoEditTriggers);
        list->setAlternatingRowColors(true);
        list->setSelectionMode(QAbstractItemView::ExtendedSelection);
        list->setSelectionBehavior(QAbstractItemView::SelectRows);
        list->setViewMode(QListView::ListMode);
        list->setSelectionRectVisible(false);

        verticalLayout->addWidget(list);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(PostProcessorWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PostProcessorWidget);

        QMetaObject::connectSlotsByName(PostProcessorWidget);
    } // setupUi

    void retranslateUi(QWidget *PostProcessorWidget)
    {
        PostProcessorWidget->setWindowTitle(QApplication::translate("PostProcessorWidget", "post processors", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PostProcessorWidget", "Available Post Processors", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("PostProcessorWidget", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PostProcessorWidget: public Ui_PostProcessorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTPROCESSORWIDGET_H
