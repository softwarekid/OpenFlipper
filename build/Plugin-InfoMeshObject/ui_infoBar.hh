/********************************************************************************
** Form generated from reading UI file 'infoBar.ui'
**
** Created: Sat May 18 02:55:37 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOBAR_H
#define UI_INFOBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *verticesIcon;
    QLabel *vertices;
    QLabel *edgesIcon;
    QLabel *edges;
    QLabel *facesIcon;
    QLabel *faces;
    QLabel *info;

    void setupUi(QWidget *InfoBar)
    {
        if (InfoBar->objectName().isEmpty())
            InfoBar->setObjectName(QString::fromUtf8("InfoBar"));
        InfoBar->resize(235, 16);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InfoBar->sizePolicy().hasHeightForWidth());
        InfoBar->setSizePolicy(sizePolicy);
        InfoBar->setMinimumSize(QSize(0, 16));
        InfoBar->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(InfoBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticesIcon = new QLabel(InfoBar);
        verticesIcon->setObjectName(QString::fromUtf8("verticesIcon"));
        verticesIcon->setMaximumSize(QSize(10, 10));
        verticesIcon->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/bar_vertex.png")));

        horizontalLayout->addWidget(verticesIcon);

        vertices = new QLabel(InfoBar);
        vertices->setObjectName(QString::fromUtf8("vertices"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        vertices->setFont(font);
        vertices->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        vertices->setMargin(2);
        vertices->setIndent(10);

        horizontalLayout->addWidget(vertices);

        edgesIcon = new QLabel(InfoBar);
        edgesIcon->setObjectName(QString::fromUtf8("edgesIcon"));
        edgesIcon->setMaximumSize(QSize(10, 10));
        edgesIcon->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/bar_edge.png")));
        edgesIcon->setScaledContents(false);
        edgesIcon->setIndent(-1);

        horizontalLayout->addWidget(edgesIcon);

        edges = new QLabel(InfoBar);
        edges->setObjectName(QString::fromUtf8("edges"));
        edges->setFont(font);
        edges->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edges->setMargin(2);
        edges->setIndent(10);

        horizontalLayout->addWidget(edges);

        facesIcon = new QLabel(InfoBar);
        facesIcon->setObjectName(QString::fromUtf8("facesIcon"));
        facesIcon->setMaximumSize(QSize(10, 10));
        facesIcon->setPixmap(QPixmap(QString::fromUtf8(":/info/dialogIcons/bar_face.png")));

        horizontalLayout->addWidget(facesIcon);

        faces = new QLabel(InfoBar);
        faces->setObjectName(QString::fromUtf8("faces"));
        faces->setFont(font);
        faces->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        faces->setMargin(2);
        faces->setIndent(10);

        horizontalLayout->addWidget(faces);

        info = new QLabel(InfoBar);
        info->setObjectName(QString::fromUtf8("info"));

        horizontalLayout->addWidget(info);


        retranslateUi(InfoBar);

        QMetaObject::connectSlotsByName(InfoBar);
    } // setupUi

    void retranslateUi(QWidget *InfoBar)
    {
        InfoBar->setWindowTitle(QApplication::translate("InfoBar", "Form", 0, QApplication::UnicodeUTF8));
        verticesIcon->setText(QString());
        vertices->setText(QApplication::translate("InfoBar", "#vertex", 0, QApplication::UnicodeUTF8));
        edgesIcon->setText(QString());
        edges->setText(QApplication::translate("InfoBar", "#edges", 0, QApplication::UnicodeUTF8));
        facesIcon->setText(QString());
        faces->setText(QApplication::translate("InfoBar", "#faces", 0, QApplication::UnicodeUTF8));
        info->setText(QApplication::translate("InfoBar", "info", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InfoBar: public Ui_InfoBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOBAR_H
