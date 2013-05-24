/********************************************************************************
** Form generated from reading UI file 'VectorWidget.ui'
**
** Created: Sat May 18 02:57:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECTORWIDGET_H
#define UI_VECTORWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ACG/QtWidgets/QtColorChooserButton.hh"

QT_BEGIN_NAMESPACE

class Ui_VectorWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *paramVector;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *vectors_strokes_rb;
    QRadioButton *vectors_colors_rb;
    QRadioButton *vectors_edges_rb;
    QWidget *vector_strokes_widget;
    QVBoxLayout *verticalLayout_11;
    QCheckBox *normalize;
    QHBoxLayout *horizontalLayout;
    QCheckBox *scale;
    QDoubleSpinBox *scaleBox;
    QtColorChooserButton *lineColor;
    QWidget *vector_edgeColors_widget;
    QHBoxLayout *horizontalLayout_15;
    QDoubleSpinBox *vectors_edges_alpha;
    QLabel *label_4;
    QDoubleSpinBox *vectors_edges_beta;
    QSpacerItem *verticalSpacer_3;
    QButtonGroup *vector_buttonGroup;

    void setupUi(QWidget *VectorWidget)
    {
        if (VectorWidget->objectName().isEmpty())
            VectorWidget->setObjectName(QString::fromUtf8("VectorWidget"));
        VectorWidget->resize(437, 198);
        verticalLayout_7 = new QVBoxLayout(VectorWidget);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        paramVector = new QGroupBox(VectorWidget);
        paramVector->setObjectName(QString::fromUtf8("paramVector"));
        verticalLayout = new QVBoxLayout(paramVector);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        vectors_strokes_rb = new QRadioButton(paramVector);
        vector_buttonGroup = new QButtonGroup(VectorWidget);
        vector_buttonGroup->setObjectName(QString::fromUtf8("vector_buttonGroup"));
        vector_buttonGroup->addButton(vectors_strokes_rb);
        vectors_strokes_rb->setObjectName(QString::fromUtf8("vectors_strokes_rb"));
        vectors_strokes_rb->setChecked(true);

        horizontalLayout_2->addWidget(vectors_strokes_rb);

        vectors_colors_rb = new QRadioButton(paramVector);
        vector_buttonGroup->addButton(vectors_colors_rb);
        vectors_colors_rb->setObjectName(QString::fromUtf8("vectors_colors_rb"));

        horizontalLayout_2->addWidget(vectors_colors_rb);

        vectors_edges_rb = new QRadioButton(paramVector);
        vector_buttonGroup->addButton(vectors_edges_rb);
        vectors_edges_rb->setObjectName(QString::fromUtf8("vectors_edges_rb"));

        horizontalLayout_2->addWidget(vectors_edges_rb);


        verticalLayout->addLayout(horizontalLayout_2);

        vector_strokes_widget = new QWidget(paramVector);
        vector_strokes_widget->setObjectName(QString::fromUtf8("vector_strokes_widget"));
        verticalLayout_11 = new QVBoxLayout(vector_strokes_widget);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 0, 0, 0);
        normalize = new QCheckBox(vector_strokes_widget);
        normalize->setObjectName(QString::fromUtf8("normalize"));
        normalize->setChecked(false);

        verticalLayout_11->addWidget(normalize);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scale = new QCheckBox(vector_strokes_widget);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setChecked(false);

        horizontalLayout->addWidget(scale);

        scaleBox = new QDoubleSpinBox(vector_strokes_widget);
        scaleBox->setObjectName(QString::fromUtf8("scaleBox"));
        scaleBox->setEnabled(false);
        scaleBox->setDecimals(7);
        scaleBox->setMaximum(1000);
        scaleBox->setValue(0.2);

        horizontalLayout->addWidget(scaleBox);


        verticalLayout_11->addLayout(horizontalLayout);

        lineColor = new QtColorChooserButton(vector_strokes_widget);
        lineColor->setObjectName(QString::fromUtf8("lineColor"));
        lineColor->setProperty("color", QVariant(QColor(198, 0, 3)));

        verticalLayout_11->addWidget(lineColor);


        verticalLayout->addWidget(vector_strokes_widget);

        vector_edgeColors_widget = new QWidget(paramVector);
        vector_edgeColors_widget->setObjectName(QString::fromUtf8("vector_edgeColors_widget"));
        vector_edgeColors_widget->setVisible(false);
        horizontalLayout_15 = new QHBoxLayout(vector_edgeColors_widget);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(-1, 0, 0, 0);
        vectors_edges_alpha = new QDoubleSpinBox(vector_edgeColors_widget);
        vectors_edges_alpha->setObjectName(QString::fromUtf8("vectors_edges_alpha"));
        vectors_edges_alpha->setDecimals(4);
        vectors_edges_alpha->setMaximum(1);
        vectors_edges_alpha->setSingleStep(0.1);
        vectors_edges_alpha->setValue(0.4);

        horizontalLayout_15->addWidget(vectors_edges_alpha);

        label_4 = new QLabel(vector_edgeColors_widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(label_4);

        vectors_edges_beta = new QDoubleSpinBox(vector_edgeColors_widget);
        vectors_edges_beta->setObjectName(QString::fromUtf8("vectors_edges_beta"));
        vectors_edges_beta->setDecimals(4);
        vectors_edges_beta->setMaximum(1);
        vectors_edges_beta->setSingleStep(0.1);
        vectors_edges_beta->setValue(0.6);

        horizontalLayout_15->addWidget(vectors_edges_beta);


        verticalLayout->addWidget(vector_edgeColors_widget);


        verticalLayout_7->addWidget(paramVector);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        QWidget::setTabOrder(scale, scaleBox);

        retranslateUi(VectorWidget);
        QObject::connect(scale, SIGNAL(toggled(bool)), scaleBox, SLOT(setEnabled(bool)));
        QObject::connect(vectors_strokes_rb, SIGNAL(toggled(bool)), vector_strokes_widget, SLOT(setVisible(bool)));
        QObject::connect(vectors_edges_rb, SIGNAL(toggled(bool)), vector_edgeColors_widget, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(VectorWidget);
    } // setupUi

    void retranslateUi(QWidget *VectorWidget)
    {
        VectorWidget->setWindowTitle(QApplication::translate("VectorWidget", "Property Visualization", 0, QApplication::UnicodeUTF8));
        paramVector->setTitle(QApplication::translate("VectorWidget", "3D Vector Parameters", 0, QApplication::UnicodeUTF8));
        vectors_strokes_rb->setText(QApplication::translate("VectorWidget", "Strokes", 0, QApplication::UnicodeUTF8));
        vectors_colors_rb->setText(QApplication::translate("VectorWidget", "Colors", 0, QApplication::UnicodeUTF8));
        vectors_edges_rb->setText(QApplication::translate("VectorWidget", "Color Edges According\n"
" to Angle btw. Vectors", 0, QApplication::UnicodeUTF8));
        normalize->setText(QApplication::translate("VectorWidget", "Normalize", 0, QApplication::UnicodeUTF8));
        scale->setText(QApplication::translate("VectorWidget", "Scale with factor", 0, QApplication::UnicodeUTF8));
        lineColor->setText(QApplication::translate("VectorWidget", "Line color: ", 0, QApplication::UnicodeUTF8));
        vectors_edges_alpha->setPrefix(QApplication::translate("VectorWidget", "\316\261 = ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("VectorWidget", "\342\211\244", 0, QApplication::UnicodeUTF8));
        vectors_edges_beta->setPrefix(QApplication::translate("VectorWidget", "\316\262 = ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VectorWidget: public Ui_VectorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORWIDGET_H
