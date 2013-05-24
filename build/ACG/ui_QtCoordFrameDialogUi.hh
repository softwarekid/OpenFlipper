/********************************************************************************
** Form generated from reading UI file 'QtCoordFrameDialogUi.ui'
**
** Created: Sat May 18 02:49:50 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCOORDFRAMEDIALOGUI_H
#define UI_QTCOORDFRAMEDIALOGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QtCoordFrameDialogUi
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *x_groupbox;
    QHBoxLayout *hboxLayout;
    QComboBox *x_combobox;
    QPushButton *x_add_button;
    QPushButton *x_mod_button;
    QPushButton *x_del_button;
    QGroupBox *y_groupbox;
    QHBoxLayout *hboxLayout1;
    QComboBox *y_combobox;
    QPushButton *y_add_button;
    QPushButton *y_mod_button;
    QPushButton *y_del_button;
    QGroupBox *z_groupbox;
    QHBoxLayout *hboxLayout2;
    QComboBox *z_combobox;
    QPushButton *z_add_button;
    QPushButton *z_mod_button;
    QPushButton *z_del_button;
    QHBoxLayout *hboxLayout3;
    QPushButton *OkButton;
    QPushButton *ApplyButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *QtCoordFrameDialogUi)
    {
        if (QtCoordFrameDialogUi->objectName().isEmpty())
            QtCoordFrameDialogUi->setObjectName(QString::fromUtf8("QtCoordFrameDialogUi"));
        QtCoordFrameDialogUi->resize(400, 289);
        vboxLayout = new QVBoxLayout(QtCoordFrameDialogUi);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        x_groupbox = new QGroupBox(QtCoordFrameDialogUi);
        x_groupbox->setObjectName(QString::fromUtf8("x_groupbox"));
        hboxLayout = new QHBoxLayout(x_groupbox);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        x_combobox = new QComboBox(x_groupbox);
        x_combobox->setObjectName(QString::fromUtf8("x_combobox"));
        x_combobox->setEditable(true);

        hboxLayout->addWidget(x_combobox);

        x_add_button = new QPushButton(x_groupbox);
        x_add_button->setObjectName(QString::fromUtf8("x_add_button"));

        hboxLayout->addWidget(x_add_button);

        x_mod_button = new QPushButton(x_groupbox);
        x_mod_button->setObjectName(QString::fromUtf8("x_mod_button"));

        hboxLayout->addWidget(x_mod_button);

        x_del_button = new QPushButton(x_groupbox);
        x_del_button->setObjectName(QString::fromUtf8("x_del_button"));

        hboxLayout->addWidget(x_del_button);


        vboxLayout->addWidget(x_groupbox);

        y_groupbox = new QGroupBox(QtCoordFrameDialogUi);
        y_groupbox->setObjectName(QString::fromUtf8("y_groupbox"));
        hboxLayout1 = new QHBoxLayout(y_groupbox);
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        y_combobox = new QComboBox(y_groupbox);
        y_combobox->setObjectName(QString::fromUtf8("y_combobox"));
        y_combobox->setEditable(true);

        hboxLayout1->addWidget(y_combobox);

        y_add_button = new QPushButton(y_groupbox);
        y_add_button->setObjectName(QString::fromUtf8("y_add_button"));

        hboxLayout1->addWidget(y_add_button);

        y_mod_button = new QPushButton(y_groupbox);
        y_mod_button->setObjectName(QString::fromUtf8("y_mod_button"));

        hboxLayout1->addWidget(y_mod_button);

        y_del_button = new QPushButton(y_groupbox);
        y_del_button->setObjectName(QString::fromUtf8("y_del_button"));

        hboxLayout1->addWidget(y_del_button);


        vboxLayout->addWidget(y_groupbox);

        z_groupbox = new QGroupBox(QtCoordFrameDialogUi);
        z_groupbox->setObjectName(QString::fromUtf8("z_groupbox"));
        hboxLayout2 = new QHBoxLayout(z_groupbox);
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        z_combobox = new QComboBox(z_groupbox);
        z_combobox->setObjectName(QString::fromUtf8("z_combobox"));
        z_combobox->setEditable(true);

        hboxLayout2->addWidget(z_combobox);

        z_add_button = new QPushButton(z_groupbox);
        z_add_button->setObjectName(QString::fromUtf8("z_add_button"));

        hboxLayout2->addWidget(z_add_button);

        z_mod_button = new QPushButton(z_groupbox);
        z_mod_button->setObjectName(QString::fromUtf8("z_mod_button"));

        hboxLayout2->addWidget(z_mod_button);

        z_del_button = new QPushButton(z_groupbox);
        z_del_button->setObjectName(QString::fromUtf8("z_del_button"));

        hboxLayout2->addWidget(z_del_button);


        vboxLayout->addWidget(z_groupbox);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        OkButton = new QPushButton(QtCoordFrameDialogUi);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));

        hboxLayout3->addWidget(OkButton);

        ApplyButton = new QPushButton(QtCoordFrameDialogUi);
        ApplyButton->setObjectName(QString::fromUtf8("ApplyButton"));

        hboxLayout3->addWidget(ApplyButton);

        CancelButton = new QPushButton(QtCoordFrameDialogUi);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        hboxLayout3->addWidget(CancelButton);


        vboxLayout->addLayout(hboxLayout3);


        retranslateUi(QtCoordFrameDialogUi);
        QObject::connect(OkButton, SIGNAL(clicked()), QtCoordFrameDialogUi, SLOT(accept()));
        QObject::connect(CancelButton, SIGNAL(clicked()), QtCoordFrameDialogUi, SLOT(reject()));

        QMetaObject::connectSlotsByName(QtCoordFrameDialogUi);
    } // setupUi

    void retranslateUi(QDialog *QtCoordFrameDialogUi)
    {
        QtCoordFrameDialogUi->setWindowTitle(QApplication::translate("QtCoordFrameDialogUi", "Dialog", 0, QApplication::UnicodeUTF8));
        x_groupbox->setTitle(QApplication::translate("QtCoordFrameDialogUi", "X-Planes", 0, QApplication::UnicodeUTF8));
        x_add_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Add", 0, QApplication::UnicodeUTF8));
        x_mod_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Mod", 0, QApplication::UnicodeUTF8));
        x_del_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Del", 0, QApplication::UnicodeUTF8));
        y_groupbox->setTitle(QApplication::translate("QtCoordFrameDialogUi", "Y-Planes", 0, QApplication::UnicodeUTF8));
        y_add_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Add", 0, QApplication::UnicodeUTF8));
        y_mod_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Mod", 0, QApplication::UnicodeUTF8));
        y_del_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Del", 0, QApplication::UnicodeUTF8));
        z_groupbox->setTitle(QApplication::translate("QtCoordFrameDialogUi", "Z-Planes", 0, QApplication::UnicodeUTF8));
        z_add_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Add", 0, QApplication::UnicodeUTF8));
        z_mod_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Mod", 0, QApplication::UnicodeUTF8));
        z_del_button->setText(QApplication::translate("QtCoordFrameDialogUi", "Del", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("QtCoordFrameDialogUi", "&OK", 0, QApplication::UnicodeUTF8));
        ApplyButton->setText(QApplication::translate("QtCoordFrameDialogUi", "A&pply", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("QtCoordFrameDialogUi", "Can&cel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtCoordFrameDialogUi: public Ui_QtCoordFrameDialogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCOORDFRAMEDIALOGUI_H
