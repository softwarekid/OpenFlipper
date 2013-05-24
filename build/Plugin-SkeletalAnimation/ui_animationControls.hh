/********************************************************************************
** Form generated from reading UI file 'animationControls.ui'
**
** Created: Sat May 18 02:58:41 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATIONCONTROLS_H
#define UI_ANIMATIONCONTROLS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimationControls
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *cbAnimation;
    QLabel *label_2;
    QComboBox *cbMethod;
    QToolButton *pbAddAnimation;
    QToolButton *pbDeleteAnimation;
    QToolButton *pbEditAnimation;
    QSlider *hsFrame;
    QHBoxLayout *hlPlaybackControls;
    QGridLayout *glFrameCounter;
    QLabel *label_4;
    QLabel *lbFrameNumber;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbPlay;
    QPushButton *pbStop;
    QPushButton *pbPrevFrame;
    QPushButton *pbNextFrame;
    QHBoxLayout *hlAdvancedPlayback;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *cbSkipFrames;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpinBox *sbFPS;
    QGroupBox *skinningBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbAttachSkin;
    QPushButton *pbClearSkins;

    void setupUi(QWidget *AnimationControls)
    {
        if (AnimationControls->objectName().isEmpty())
            AnimationControls->setObjectName(QString::fromUtf8("AnimationControls"));
        AnimationControls->resize(467, 296);
        verticalLayout_2 = new QVBoxLayout(AnimationControls);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_3 = new QGroupBox(AnimationControls);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        cbAnimation = new QComboBox(groupBox_3);
        cbAnimation->setObjectName(QString::fromUtf8("cbAnimation"));
        cbAnimation->setEditable(false);

        gridLayout->addWidget(cbAnimation, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        cbMethod = new QComboBox(groupBox_3);
        cbMethod->setObjectName(QString::fromUtf8("cbMethod"));

        gridLayout->addWidget(cbMethod, 1, 1, 1, 1);

        pbAddAnimation = new QToolButton(groupBox_3);
        pbAddAnimation->setObjectName(QString::fromUtf8("pbAddAnimation"));

        gridLayout->addWidget(pbAddAnimation, 0, 3, 1, 1);

        pbDeleteAnimation = new QToolButton(groupBox_3);
        pbDeleteAnimation->setObjectName(QString::fromUtf8("pbDeleteAnimation"));

        gridLayout->addWidget(pbDeleteAnimation, 0, 5, 1, 1);

        pbEditAnimation = new QToolButton(groupBox_3);
        pbEditAnimation->setObjectName(QString::fromUtf8("pbEditAnimation"));
        pbEditAnimation->setContextMenuPolicy(Qt::DefaultContextMenu);

        gridLayout->addWidget(pbEditAnimation, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        hsFrame = new QSlider(groupBox_3);
        hsFrame->setObjectName(QString::fromUtf8("hsFrame"));
        hsFrame->setMaximum(0);
        hsFrame->setOrientation(Qt::Horizontal);
        hsFrame->setTickPosition(QSlider::TicksBelow);

        verticalLayout->addWidget(hsFrame);

        hlPlaybackControls = new QHBoxLayout();
        hlPlaybackControls->setObjectName(QString::fromUtf8("hlPlaybackControls"));
        glFrameCounter = new QGridLayout();
        glFrameCounter->setObjectName(QString::fromUtf8("glFrameCounter"));
        glFrameCounter->setSizeConstraint(QLayout::SetNoConstraint);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(0, 0));

        glFrameCounter->addWidget(label_4, 0, 0, 1, 1);

        lbFrameNumber = new QLabel(groupBox_3);
        lbFrameNumber->setObjectName(QString::fromUtf8("lbFrameNumber"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbFrameNumber->sizePolicy().hasHeightForWidth());
        lbFrameNumber->setSizePolicy(sizePolicy2);
        lbFrameNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glFrameCounter->addWidget(lbFrameNumber, 0, 1, 1, 1);


        hlPlaybackControls->addLayout(glFrameCounter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlPlaybackControls->addItem(horizontalSpacer_2);

        pbPlay = new QPushButton(groupBox_3);
        pbPlay->setObjectName(QString::fromUtf8("pbPlay"));
        pbPlay->setText(QString::fromUtf8("\342\226\266"));
        pbPlay->setFlat(false);

        hlPlaybackControls->addWidget(pbPlay);

        pbStop = new QPushButton(groupBox_3);
        pbStop->setObjectName(QString::fromUtf8("pbStop"));
        pbStop->setText(QString::fromUtf8("\342\226\240"));

        hlPlaybackControls->addWidget(pbStop);

        pbPrevFrame = new QPushButton(groupBox_3);
        pbPrevFrame->setObjectName(QString::fromUtf8("pbPrevFrame"));

        hlPlaybackControls->addWidget(pbPrevFrame);

        pbNextFrame = new QPushButton(groupBox_3);
        pbNextFrame->setObjectName(QString::fromUtf8("pbNextFrame"));

        hlPlaybackControls->addWidget(pbNextFrame);


        verticalLayout->addLayout(hlPlaybackControls);

        hlAdvancedPlayback = new QHBoxLayout();
        hlAdvancedPlayback->setObjectName(QString::fromUtf8("hlAdvancedPlayback"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlAdvancedPlayback->addItem(horizontalSpacer_3);

        cbSkipFrames = new QCheckBox(groupBox_3);
        cbSkipFrames->setObjectName(QString::fromUtf8("cbSkipFrames"));
        cbSkipFrames->setChecked(true);

        hlAdvancedPlayback->addWidget(cbSkipFrames);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, -1, -1);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        sbFPS = new QSpinBox(groupBox_3);
        sbFPS->setObjectName(QString::fromUtf8("sbFPS"));
        sbFPS->setMinimum(1);
        sbFPS->setMaximum(400);
        sbFPS->setValue(15);

        horizontalLayout->addWidget(sbFPS);


        hlAdvancedPlayback->addLayout(horizontalLayout);


        verticalLayout->addLayout(hlAdvancedPlayback);


        verticalLayout_2->addWidget(groupBox_3);

        skinningBox = new QGroupBox(AnimationControls);
        skinningBox->setObjectName(QString::fromUtf8("skinningBox"));
        horizontalLayout_2 = new QHBoxLayout(skinningBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbAttachSkin = new QPushButton(skinningBox);
        pbAttachSkin->setObjectName(QString::fromUtf8("pbAttachSkin"));
        pbAttachSkin->setEnabled(false);

        horizontalLayout_2->addWidget(pbAttachSkin);

        pbClearSkins = new QPushButton(skinningBox);
        pbClearSkins->setObjectName(QString::fromUtf8("pbClearSkins"));
        pbClearSkins->setEnabled(false);

        horizontalLayout_2->addWidget(pbClearSkins);


        verticalLayout_2->addWidget(skinningBox);


        retranslateUi(AnimationControls);
        QObject::connect(hsFrame, SIGNAL(sliderMoved(int)), lbFrameNumber, SLOT(setNum(int)));
        QObject::connect(hsFrame, SIGNAL(valueChanged(int)), lbFrameNumber, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(AnimationControls);
    } // setupUi

    void retranslateUi(QWidget *AnimationControls)
    {
        AnimationControls->setWindowTitle(QApplication::translate("AnimationControls", "controls", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("AnimationControls", "Animation control", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AnimationControls", "Animation:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AnimationControls", "Method:", 0, QApplication::UnicodeUTF8));
        pbAddAnimation->setText(QString());
        pbDeleteAnimation->setText(QString());
        pbEditAnimation->setText(QString());
        label_4->setText(QApplication::translate("AnimationControls", "Frame", 0, QApplication::UnicodeUTF8));
        lbFrameNumber->setText(QApplication::translate("AnimationControls", "0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbPlay->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbStop->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbPrevFrame->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pbPrevFrame->setText(QApplication::translate("AnimationControls", "|\342\227\200", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbNextFrame->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pbNextFrame->setText(QApplication::translate("AnimationControls", "\342\226\266|", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cbSkipFrames->setToolTip(QApplication::translate("AnimationControls", "<b>Frame Skipping</b><br>Skip frames if the deformation is too slow.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cbSkipFrames->setText(QApplication::translate("AnimationControls", "Frame skipping", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AnimationControls", "FPS", 0, QApplication::UnicodeUTF8));
        skinningBox->setTitle(QApplication::translate("AnimationControls", "Attached Skins", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbAttachSkin->setToolTip(QApplication::translate("AnimationControls", "<b>Attach mesh(es) to the skeleton</b><br>If the mesh is equipped with skin weights, the skeleton controls the deformation afterwards.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbAttachSkin->setText(QApplication::translate("AnimationControls", "Attach Skin to Skeleton", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbClearSkins->setToolTip(QApplication::translate("AnimationControls", "<b>Remove attached skins</b><br>Remove all attached skins from the skeleton", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbClearSkins->setText(QApplication::translate("AnimationControls", "Clear Skins", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnimationControls: public Ui_AnimationControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATIONCONTROLS_H
