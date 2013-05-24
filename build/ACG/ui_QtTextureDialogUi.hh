/********************************************************************************
** Form generated from reading UI file 'QtTextureDialogUi.ui'
**
** Created: Sat May 18 02:49:51 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTEXTUREDIALOGUI_H
#define UI_QTTEXTUREDIALOGUI_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTextureDialogUi
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QCheckBox *mipmapping;
    QSpacerItem *sp1;
    QHBoxLayout *l1;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem;
    QPushButton *okButton;

    void setupUi(QWidget *QtTextureDialogUi)
    {
        if (QtTextureDialogUi->objectName().isEmpty())
            QtTextureDialogUi->setObjectName(QString::fromUtf8("QtTextureDialogUi"));
        QtTextureDialogUi->resize(312, 235);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtTextureDialogUi->sizePolicy().hasHeightForWidth());
        QtTextureDialogUi->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(QtTextureDialogUi);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_3 = new QGroupBox(QtTextureDialogUi);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mipmapping = new QCheckBox(groupBox_3);
        mipmapping->setObjectName(QString::fromUtf8("mipmapping"));

        gridLayout->addWidget(mipmapping, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        sp1 = new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(sp1);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        l1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        l1->setSpacing(6);
#endif
        l1->setContentsMargins(0, 0, 0, 0);
        l1->setObjectName(QString::fromUtf8("l1"));
        cancelButton = new QPushButton(QtTextureDialogUi);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        l1->addWidget(cancelButton);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        l1->addItem(spacerItem);

        okButton = new QPushButton(QtTextureDialogUi);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        l1->addWidget(okButton);


        verticalLayout_3->addLayout(l1);


        retranslateUi(QtTextureDialogUi);

        QMetaObject::connectSlotsByName(QtTextureDialogUi);
    } // setupUi

    void retranslateUi(QWidget *QtTextureDialogUi)
    {
        QtTextureDialogUi->setWindowTitle(QApplication::translate("QtTextureDialogUi", "Edit Texture", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("QtTextureDialogUi", "Rendering", 0, QApplication::UnicodeUTF8));
        mipmapping->setText(QApplication::translate("QtTextureDialogUi", "Mipmapping", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("QtTextureDialogUi", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("QtTextureDialogUi", "Apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtTextureDialogUi: public Ui_QtTextureDialogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTEXTUREDIALOGUI_H
