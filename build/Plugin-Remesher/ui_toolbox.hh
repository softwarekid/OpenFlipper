/********************************************************************************
** Form generated from reading UI file 'toolbox.ui'
**
** Created: Sat May 18 02:58:13 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBOX_H
#define UI_TOOLBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemesherTool
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *adaptive_button;
    QSpinBox *adaptive_iters;
    QDoubleSpinBox *adaptive_error;
    QDoubleSpinBox *adaptive_min_edge;
    QDoubleSpinBox *adaptive_max_edge;
    QPushButton *adaptive_initial_values;
    QCheckBox *adaptive_projection;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *uniform_button;
    QSpinBox *uniform_area_iters;
    QSpinBox *uniform_iters;
    QDoubleSpinBox *uniform_edge_length;
    QPushButton *uniform_initial_values;
    QCheckBox *uniform_projection;

    void setupUi(QWidget *RemesherTool)
    {
        if (RemesherTool->objectName().isEmpty())
            RemesherTool->setObjectName(QString::fromUtf8("RemesherTool"));
        RemesherTool->setEnabled(true);
        RemesherTool->resize(377, 257);
        verticalLayout_2 = new QVBoxLayout(RemesherTool);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(RemesherTool);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        adaptive_button = new QPushButton(tab);
        adaptive_button->setObjectName(QString::fromUtf8("adaptive_button"));

        gridLayout->addWidget(adaptive_button, 6, 1, 1, 1);

        adaptive_iters = new QSpinBox(tab);
        adaptive_iters->setObjectName(QString::fromUtf8("adaptive_iters"));
        adaptive_iters->setMaximumSize(QSize(16777215, 16777215));
        adaptive_iters->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        adaptive_iters->setMinimum(1);
        adaptive_iters->setMaximum(100);
        adaptive_iters->setValue(10);

        gridLayout->addWidget(adaptive_iters, 3, 1, 1, 1);

        adaptive_error = new QDoubleSpinBox(tab);
        adaptive_error->setObjectName(QString::fromUtf8("adaptive_error"));
        adaptive_error->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        adaptive_error->setDecimals(4);
        adaptive_error->setMaximum(1e+07);
        adaptive_error->setSingleStep(0.1);
        adaptive_error->setValue(0.1);

        gridLayout->addWidget(adaptive_error, 0, 1, 1, 1);

        adaptive_min_edge = new QDoubleSpinBox(tab);
        adaptive_min_edge->setObjectName(QString::fromUtf8("adaptive_min_edge"));
        adaptive_min_edge->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        adaptive_min_edge->setDecimals(4);
        adaptive_min_edge->setMaximum(1e+07);
        adaptive_min_edge->setSingleStep(0.1);
        adaptive_min_edge->setValue(0.1);

        gridLayout->addWidget(adaptive_min_edge, 1, 1, 1, 1);

        adaptive_max_edge = new QDoubleSpinBox(tab);
        adaptive_max_edge->setObjectName(QString::fromUtf8("adaptive_max_edge"));
        adaptive_max_edge->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        adaptive_max_edge->setDecimals(4);
        adaptive_max_edge->setMaximum(1e+07);
        adaptive_max_edge->setSingleStep(0.1);
        adaptive_max_edge->setValue(0.1);

        gridLayout->addWidget(adaptive_max_edge, 2, 1, 1, 1);

        adaptive_initial_values = new QPushButton(tab);
        adaptive_initial_values->setObjectName(QString::fromUtf8("adaptive_initial_values"));

        gridLayout->addWidget(adaptive_initial_values, 4, 1, 1, 1);

        adaptive_projection = new QCheckBox(tab);
        adaptive_projection->setObjectName(QString::fromUtf8("adaptive_projection"));
        adaptive_projection->setLayoutDirection(Qt::RightToLeft);
        adaptive_projection->setChecked(true);

        gridLayout->addWidget(adaptive_projection, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 2, 0, 1, 1);

        uniform_button = new QPushButton(tab_2);
        uniform_button->setObjectName(QString::fromUtf8("uniform_button"));

        gridLayout_3->addWidget(uniform_button, 5, 1, 1, 1);

        uniform_area_iters = new QSpinBox(tab_2);
        uniform_area_iters->setObjectName(QString::fromUtf8("uniform_area_iters"));
        uniform_area_iters->setMaximumSize(QSize(16777215, 16777215));
        uniform_area_iters->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        uniform_area_iters->setMinimum(1);
        uniform_area_iters->setMaximum(100);
        uniform_area_iters->setValue(10);

        gridLayout_3->addWidget(uniform_area_iters, 2, 1, 1, 1);

        uniform_iters = new QSpinBox(tab_2);
        uniform_iters->setObjectName(QString::fromUtf8("uniform_iters"));
        uniform_iters->setMaximumSize(QSize(16777215, 16777215));
        uniform_iters->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        uniform_iters->setMinimum(1);
        uniform_iters->setMaximum(100);
        uniform_iters->setValue(10);

        gridLayout_3->addWidget(uniform_iters, 1, 1, 1, 1);

        uniform_edge_length = new QDoubleSpinBox(tab_2);
        uniform_edge_length->setObjectName(QString::fromUtf8("uniform_edge_length"));
        uniform_edge_length->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        uniform_edge_length->setDecimals(4);
        uniform_edge_length->setMaximum(1e+07);
        uniform_edge_length->setSingleStep(0.1);
        uniform_edge_length->setValue(0.1);

        gridLayout_3->addWidget(uniform_edge_length, 0, 1, 1, 1);

        uniform_initial_values = new QPushButton(tab_2);
        uniform_initial_values->setObjectName(QString::fromUtf8("uniform_initial_values"));

        gridLayout_3->addWidget(uniform_initial_values, 3, 1, 1, 1);

        uniform_projection = new QCheckBox(tab_2);
        uniform_projection->setObjectName(QString::fromUtf8("uniform_projection"));
        uniform_projection->setLayoutDirection(Qt::RightToLeft);
        uniform_projection->setChecked(true);

        gridLayout_3->addWidget(uniform_projection, 4, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        QWidget::setTabOrder(adaptive_iters, adaptive_button);
        QWidget::setTabOrder(adaptive_button, uniform_iters);
        QWidget::setTabOrder(uniform_iters, uniform_area_iters);
        QWidget::setTabOrder(uniform_area_iters, uniform_button);

        retranslateUi(RemesherTool);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RemesherTool);
    } // setupUi

    void retranslateUi(QWidget *RemesherTool)
    {
        RemesherTool->setWindowTitle(QApplication::translate("RemesherTool", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RemesherTool", "Error", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RemesherTool", "Min. edge length", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RemesherTool", "Max. edge length", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RemesherTool", "Iterations", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        adaptive_button->setToolTip(QApplication::translate("RemesherTool", "Start remeshing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adaptive_button->setStatusTip(QApplication::translate("RemesherTool", "Start remeshing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        adaptive_button->setWhatsThis(QApplication::translate("RemesherTool", "Start remeshing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        adaptive_button->setText(QApplication::translate("RemesherTool", "Remesh", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        adaptive_iters->setToolTip(QApplication::translate("RemesherTool", "Number of iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adaptive_iters->setStatusTip(QApplication::translate("RemesherTool", "Number of iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        adaptive_iters->setWhatsThis(QApplication::translate("RemesherTool", "Number of iterations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        adaptive_error->setToolTip(QApplication::translate("RemesherTool", "Maximal allowedd deviation from the original surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adaptive_error->setStatusTip(QApplication::translate("RemesherTool", "Maximal allowedd deviation from the original surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        adaptive_error->setWhatsThis(QApplication::translate("RemesherTool", "Maximal allowedd deviation from the original surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        adaptive_min_edge->setToolTip(QApplication::translate("RemesherTool", "Minimal ede length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adaptive_min_edge->setStatusTip(QApplication::translate("RemesherTool", "Minimal ede length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        adaptive_min_edge->setWhatsThis(QApplication::translate("RemesherTool", "Minimal ede length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        adaptive_max_edge->setToolTip(QApplication::translate("RemesherTool", "Maximum ede length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adaptive_max_edge->setStatusTip(QApplication::translate("RemesherTool", "Maximum ede length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        adaptive_max_edge->setWhatsThis(QApplication::translate("RemesherTool", "Maximum ede length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        adaptive_initial_values->setToolTip(QApplication::translate("RemesherTool", "Estimate good parameters for error and edge lengths", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adaptive_initial_values->setStatusTip(QApplication::translate("RemesherTool", "Estimate good parameters for error and edge lengths", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        adaptive_initial_values->setWhatsThis(QApplication::translate("RemesherTool", "Estimate good parameters for error and edge lengths", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        adaptive_initial_values->setText(QApplication::translate("RemesherTool", "Estimate parameters", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        adaptive_projection->setToolTip(QApplication::translate("RemesherTool", "Project new vertices onto surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        adaptive_projection->setStatusTip(QApplication::translate("RemesherTool", "Project new vertices onto surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        adaptive_projection->setWhatsThis(QApplication::translate("RemesherTool", "Project new vertices onto surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        adaptive_projection->setText(QApplication::translate("RemesherTool", "Projection", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("RemesherTool", "Adaptive", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("RemesherTool", "Edge length", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("RemesherTool", "Iterations", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("RemesherTool", "Area Iterations", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        uniform_button->setToolTip(QApplication::translate("RemesherTool", "Start remeshing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        uniform_button->setStatusTip(QApplication::translate("RemesherTool", "Start remeshing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        uniform_button->setWhatsThis(QApplication::translate("RemesherTool", "Start remeshing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        uniform_button->setText(QApplication::translate("RemesherTool", "Remesh", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        uniform_iters->setToolTip(QApplication::translate("RemesherTool", "Number of iterations for the algorithm", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        uniform_iters->setStatusTip(QApplication::translate("RemesherTool", "Number of iterations for the algorithm", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        uniform_iters->setWhatsThis(QApplication::translate("RemesherTool", "Number of iterations for the algorithm", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        uniform_edge_length->setToolTip(QApplication::translate("RemesherTool", "Average edge length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        uniform_edge_length->setStatusTip(QApplication::translate("RemesherTool", "Average edge length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        uniform_edge_length->setWhatsThis(QApplication::translate("RemesherTool", "Average edge length of the resulting mesh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        uniform_initial_values->setToolTip(QApplication::translate("RemesherTool", "Estimate good parameters for edge lengths", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        uniform_initial_values->setStatusTip(QApplication::translate("RemesherTool", "Estimate good parameters for edge lengths", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        uniform_initial_values->setWhatsThis(QApplication::translate("RemesherTool", "Estimate good parameters for edge lengths", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        uniform_initial_values->setText(QApplication::translate("RemesherTool", "Estimate Parameters", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        uniform_projection->setToolTip(QApplication::translate("RemesherTool", "Project new vertices onto surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        uniform_projection->setStatusTip(QApplication::translate("RemesherTool", "Project new vertices onto surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        uniform_projection->setWhatsThis(QApplication::translate("RemesherTool", "Project new vertices onto surface", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        uniform_projection->setText(QApplication::translate("RemesherTool", "Projection", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("RemesherTool", "Uniform", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RemesherTool: public Ui_RemesherTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
