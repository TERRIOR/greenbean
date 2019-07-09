/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_close;
    QPushButton *pushButton_min;
    QPushButton *pushButton_max;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *lblOriginal;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_pause;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_4;
    QComboBox *com;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_6);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_8);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton_close = new QPushButton(centralWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(30, 30));
        pushButton_close->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon);

        gridLayout_5->addWidget(pushButton_close, 0, 3, 1, 1);

        pushButton_min = new QPushButton(centralWidget);
        pushButton_min->setObjectName(QStringLiteral("pushButton_min"));
        pushButton_min->setMinimumSize(QSize(30, 30));
        pushButton_min->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/minus-sign-on-a-square-outline.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_min->setIcon(icon1);

        gridLayout_5->addWidget(pushButton_min, 0, 1, 1, 1);

        pushButton_max = new QPushButton(centralWidget);
        pushButton_max->setObjectName(QStringLiteral("pushButton_max"));
        pushButton_max->setMinimumSize(QSize(30, 30));
        pushButton_max->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/expand-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_max->setIcon(icon2);

        gridLayout_5->addWidget(pushButton_max, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 0, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(560, 0));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lblOriginal = new QLabel(groupBox);
        lblOriginal->setObjectName(QStringLiteral("lblOriginal"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(lblOriginal->sizePolicy().hasHeightForWidth());
        lblOriginal->setSizePolicy(sizePolicy2);
        lblOriginal->setAutoFillBackground(true);

        gridLayout_2->addWidget(lblOriginal, 1, 0, 1, 2);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 4, 0, 1, 1);

        pushButton_stop = new QPushButton(groupBox_2);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));

        gridLayout->addWidget(pushButton_stop, 6, 0, 1, 1);

        pushButton_pause = new QPushButton(groupBox_2);
        pushButton_pause->setObjectName(QStringLiteral("pushButton_pause"));
        pushButton_pause->setEnabled(true);
        pushButton_pause->setCheckable(true);

        gridLayout->addWidget(pushButton_pause, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(15);
        com = new QComboBox(groupBox_2);
        com->setObjectName(QStringLiteral("com"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(com->sizePolicy().hasHeightForWidth());
        com->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(com, 4, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 2, 0, 1, 4);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 4);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 3, 0, 1, 4);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 4, 1, 1, 1);


        gridLayout->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245wifi", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "\344\270\252\344\272\272\344\270\255\345\277\203", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "\350\256\255\347\273\203\346\250\241\345\274\217", 0));
        pushButton_close->setText(QString());
        pushButton_min->setText(QString());
        pushButton_max->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\221\225\347\226\265\350\261\206\345\233\276\345\203\217", 0));
        lblOriginal->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\255\233\351\200\211\344\277\241\346\201\257", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        pushButton_stop->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237", 0));
        pushButton_pause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\221\225\347\226\265\350\261\206\357\274\232", 0));
        label->setText(QApplication::translate("MainWindow", "\345\267\262\347\255\233\351\200\211\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\347\221\225\347\226\265\347\216\207\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\245\275\350\261\206\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
