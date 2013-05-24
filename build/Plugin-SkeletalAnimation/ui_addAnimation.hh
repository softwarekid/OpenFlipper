/********************************************************************************
** Form generated from reading UI file 'addAnimation.ui'
**
** Created: Sat May 18 02:58:41 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDANIMATION_H
#define UI_ADDANIMATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddAnimation
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *animationName;
    QLabel *label;
    QSpinBox *frames;
    QFrame *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddAnimation)
    {
        if (AddAnimation->objectName().isEmpty())
            AddAnimation->setObjectName(QString::fromUtf8("AddAnimation"));
        AddAnimation->resize(400, 105);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddAnimation->sizePolicy().hasHeightForWidth());
        AddAnimation->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(AddAnimation);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(AddAnimation);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        animationName = new QLineEdit(AddAnimation);
        animationName->setObjectName(QString::fromUtf8("animationName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, animationName);

        label = new QLabel(AddAnimation);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        frames = new QSpinBox(AddAnimation);
        frames->setObjectName(QString::fromUtf8("frames"));
        frames->setMinimum(1);
        frames->setMaximum(10000);

        formLayout->setWidget(1, QFormLayout::FieldRole, frames);


        verticalLayout->addLayout(formLayout);

        line = new QFrame(AddAnimation);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        buttonBox = new QDialogButtonBox(AddAnimation);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddAnimation);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddAnimation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddAnimation, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddAnimation);
    } // setupUi

    void retranslateUi(QDialog *AddAnimation)
    {
        AddAnimation->setWindowTitle(QApplication::translate("AddAnimation", "Add Animation", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddAnimation", "Animation Name:", 0, QApplication::UnicodeUTF8));
        animationName->setText(QApplication::translate("AddAnimation", "Animation01", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddAnimation", "Number of Frames:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddAnimation: public Ui_AddAnimation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDANIMATION_H
