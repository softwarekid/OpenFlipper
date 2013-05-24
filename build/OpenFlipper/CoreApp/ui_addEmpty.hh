/********************************************************************************
** Form generated from reading UI file 'addEmpty.ui'
**
** Created: Sat May 18 02:52:48 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEMPTY_H
#define UI_ADDEMPTY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addEmpty
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QComboBox *typeBox;
    QSpacerItem *spacerItem;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout1;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem2;
    QPushButton *addButton;

    void setupUi(QDialog *addEmpty)
    {
        if (addEmpty->objectName().isEmpty())
            addEmpty->setObjectName(QString::fromUtf8("addEmpty"));
        addEmpty->resize(312, 82);
        vboxLayout = new QVBoxLayout(addEmpty);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label = new QLabel(addEmpty);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        typeBox = new QComboBox(addEmpty);
        typeBox->setObjectName(QString::fromUtf8("typeBox"));
        typeBox->setMinimumSize(QSize(150, 0));

        hboxLayout->addWidget(typeBox);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        vboxLayout->addLayout(hboxLayout);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        cancelButton = new QPushButton(addEmpty);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout1->addWidget(cancelButton);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem2);

        addButton = new QPushButton(addEmpty);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        hboxLayout1->addWidget(addButton);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(addEmpty);

        QMetaObject::connectSlotsByName(addEmpty);
    } // setupUi

    void retranslateUi(QDialog *addEmpty)
    {
        addEmpty->setWindowTitle(QApplication::translate("addEmpty", "Add Empty Object", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addEmpty", "Datatype:", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("addEmpty", "Cancel", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("addEmpty", "Add", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addEmpty: public Ui_addEmpty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEMPTY_H
