/********************************************************************************
** Form generated from reading UI file 'QtShaderDialogUi.ui'
**
** Created: Sat May 18 02:49:50 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSHADERDIALOGUI_H
#define UI_QTSHADERDIALOGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtShaderDialogUi
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *drawModeBox;
    QSpacerItem *horizontalSpacer;
    QLineEdit *vertexShader;
    QLineEdit *fragmentShader;
    QLineEdit *shaderDir;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *QtShaderDialogUi)
    {
        if (QtShaderDialogUi->objectName().isEmpty())
            QtShaderDialogUi->setObjectName(QString::fromUtf8("QtShaderDialogUi"));
        QtShaderDialogUi->resize(572, 212);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtShaderDialogUi->sizePolicy().hasHeightForWidth());
        QtShaderDialogUi->setSizePolicy(sizePolicy);
        QtShaderDialogUi->setAcceptDrops(true);
        verticalLayout = new QVBoxLayout(QtShaderDialogUi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(QtShaderDialogUi);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        drawModeBox = new QComboBox(groupBox);
        drawModeBox->setObjectName(QString::fromUtf8("drawModeBox"));
        drawModeBox->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(drawModeBox);

        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        vertexShader = new QLineEdit(groupBox);
        vertexShader->setObjectName(QString::fromUtf8("vertexShader"));

        verticalLayout_3->addWidget(vertexShader);

        fragmentShader = new QLineEdit(groupBox);
        fragmentShader->setObjectName(QString::fromUtf8("fragmentShader"));

        verticalLayout_3->addWidget(fragmentShader);

        shaderDir = new QLineEdit(groupBox);
        shaderDir->setObjectName(QString::fromUtf8("shaderDir"));

        verticalLayout_3->addWidget(shaderDir);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacerItem = new QSpacerItem(387, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerItem);

        okButton = new QPushButton(QtShaderDialogUi);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(QtShaderDialogUi);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QtShaderDialogUi);

        QMetaObject::connectSlotsByName(QtShaderDialogUi);
    } // setupUi

    void retranslateUi(QWidget *QtShaderDialogUi)
    {
        QtShaderDialogUi->setWindowTitle(QApplication::translate("QtShaderDialogUi", "Edit Shaders", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QtShaderDialogUi", "Shaders", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QtShaderDialogUi", "Draw Mode", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QtShaderDialogUi", "Vertex Shader", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QtShaderDialogUi", "Fragment Shader", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QtShaderDialogUi", "Shader Directory", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("QtShaderDialogUi", "Ok", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("QtShaderDialogUi", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtShaderDialogUi: public Ui_QtShaderDialogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSHADERDIALOGUI_H
