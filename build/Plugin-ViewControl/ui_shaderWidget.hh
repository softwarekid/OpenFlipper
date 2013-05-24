/********************************************************************************
** Form generated from reading UI file 'shaderWidget.ui'
**
** Created: Sat May 18 02:59:41 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHADERWIDGET_H
#define UI_SHADERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShaderSettings
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *setShaderButton;
    QPushButton *closeButton;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QListWidget *availableShaders;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *drawModes;
    QGroupBox *uniformBox;
    QVBoxLayout *verticalLayout;
    QTableWidget *uniforms;
    QGroupBox *groupBox2;
    QVBoxLayout *verticalLayout_4;
    QLabel *example;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *shaderName;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *version;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *description;
    QLabel *label_4;
    QTextEdit *details;
    QLabel *label_8;
    QLineEdit *fragmentShader;
    QLabel *label_7;
    QLineEdit *vertexShader;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *pickVertexShader;
    QLineEdit *pickFragmentShader;

    void setupUi(QWidget *ShaderSettings)
    {
        if (ShaderSettings->objectName().isEmpty())
            ShaderSettings->setObjectName(QString::fromUtf8("ShaderSettings"));
        ShaderSettings->resize(784, 636);
        gridLayout_2 = new QGridLayout(ShaderSettings);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 2, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(418, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        setShaderButton = new QPushButton(ShaderSettings);
        setShaderButton->setObjectName(QString::fromUtf8("setShaderButton"));

        horizontalLayout_6->addWidget(setShaderButton);

        closeButton = new QPushButton(ShaderSettings);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_6->addWidget(closeButton);


        gridLayout_2->addLayout(horizontalLayout_6, 3, 0, 1, 3);

        groupBox_4 = new QGroupBox(ShaderSettings);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        availableShaders = new QListWidget(groupBox_4);
        availableShaders->setObjectName(QString::fromUtf8("availableShaders"));

        verticalLayout_3->addWidget(availableShaders);


        gridLayout_2->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(ShaderSettings);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        drawModes = new QListWidget(groupBox_3);
        drawModes->setObjectName(QString::fromUtf8("drawModes"));

        verticalLayout_2->addWidget(drawModes);


        gridLayout_2->addWidget(groupBox_3, 0, 1, 1, 1);

        uniformBox = new QGroupBox(ShaderSettings);
        uniformBox->setObjectName(QString::fromUtf8("uniformBox"));
        verticalLayout = new QVBoxLayout(uniformBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        uniforms = new QTableWidget(uniformBox);
        uniforms->setObjectName(QString::fromUtf8("uniforms"));

        verticalLayout->addWidget(uniforms);


        gridLayout_2->addWidget(uniformBox, 0, 2, 1, 1);

        groupBox2 = new QGroupBox(ShaderSettings);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        groupBox2->setMinimumSize(QSize(250, 250));
        groupBox2->setMaximumSize(QSize(250, 250));
        verticalLayout_4 = new QVBoxLayout(groupBox2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        example = new QLabel(groupBox2);
        example->setObjectName(QString::fromUtf8("example"));
        example->setScaledContents(true);

        verticalLayout_4->addWidget(example);


        gridLayout_2->addWidget(groupBox2, 1, 2, 1, 1);

        groupBox = new QGroupBox(ShaderSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        shaderName = new QLineEdit(groupBox);
        shaderName->setObjectName(QString::fromUtf8("shaderName"));

        horizontalLayout_2->addWidget(shaderName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        version = new QLineEdit(groupBox);
        version->setObjectName(QString::fromUtf8("version"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(version->sizePolicy().hasHeightForWidth());
        version->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(version);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        description = new QLineEdit(groupBox);
        description->setObjectName(QString::fromUtf8("description"));

        gridLayout->addWidget(description, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        details = new QTextEdit(groupBox);
        details->setObjectName(QString::fromUtf8("details"));

        gridLayout->addWidget(details, 2, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        fragmentShader = new QLineEdit(groupBox);
        fragmentShader->setObjectName(QString::fromUtf8("fragmentShader"));

        gridLayout->addWidget(fragmentShader, 5, 2, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        vertexShader = new QLineEdit(groupBox);
        vertexShader->setObjectName(QString::fromUtf8("vertexShader"));

        gridLayout->addWidget(vertexShader, 3, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        pickVertexShader = new QLineEdit(groupBox);
        pickVertexShader->setObjectName(QString::fromUtf8("pickVertexShader"));

        gridLayout->addWidget(pickVertexShader, 6, 2, 1, 1);

        pickFragmentShader = new QLineEdit(groupBox);
        pickFragmentShader->setObjectName(QString::fromUtf8("pickFragmentShader"));

        gridLayout->addWidget(pickFragmentShader, 7, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 2, 2);


        retranslateUi(ShaderSettings);

        QMetaObject::connectSlotsByName(ShaderSettings);
    } // setupUi

    void retranslateUi(QWidget *ShaderSettings)
    {
        ShaderSettings->setWindowTitle(QApplication::translate("ShaderSettings", "Shader Settings", 0, QApplication::UnicodeUTF8));
        setShaderButton->setText(QApplication::translate("ShaderSettings", "Set shader", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("ShaderSettings", "Close", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("ShaderSettings", "Available Shaders", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ShaderSettings", "DrawModes using shader", 0, QApplication::UnicodeUTF8));
        uniformBox->setTitle(QApplication::translate("ShaderSettings", "Uniforms", 0, QApplication::UnicodeUTF8));
        groupBox2->setTitle(QApplication::translate("ShaderSettings", "Example", 0, QApplication::UnicodeUTF8));
        example->setText(QString());
        groupBox->setTitle(QApplication::translate("ShaderSettings", "Info", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ShaderSettings", "Version", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ShaderSettings", "Name", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ShaderSettings", "Description", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ShaderSettings", "Details", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ShaderSettings", "FragmentShader", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ShaderSettings", "VertexShader", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ShaderSettings", "Pick Vertex Shader", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ShaderSettings", "Pick FragmentShader", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShaderSettings: public Ui_ShaderSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHADERWIDGET_H
