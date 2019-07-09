/********************************************************************************
** Form generated from reading UI file 'camsetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMSETDIALOG_H
#define UI_CAMSETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamsetDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_id;
    QLineEdit *id;
    QHBoxLayout *horizontalLayout_1;
    QLabel *label_1;
    QLineEdit *lineEditwid;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_high;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEdit_fps;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_exp;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_bri;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEdit_sat;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *lineEdit_hue;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLineEdit *lineEdit_con;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QLabel *lblOriginal;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonstart;
    QPushButton *pushButtonstop;

    void setupUi(QDialog *CamsetDialog)
    {
        if (CamsetDialog->objectName().isEmpty())
            CamsetDialog->setObjectName(QStringLiteral("CamsetDialog"));
        CamsetDialog->resize(755, 522);
        buttonBox = new QDialogButtonBox(CamsetDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(360, 460, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(CamsetDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(530, 20, 201, 421));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 201, 331));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 10);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_id = new QLabel(verticalLayoutWidget);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setMinimumSize(QSize(36, 0));

        horizontalLayout_2->addWidget(label_id);

        id = new QLineEdit(verticalLayoutWidget);
        id->setObjectName(QStringLiteral("id"));
        id->setMinimumSize(QSize(0, 25));
        id->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_2->addWidget(id);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        horizontalLayout_1->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_1->setContentsMargins(-1, -1, -1, 0);
        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setMinimumSize(QSize(36, 0));

        horizontalLayout_1->addWidget(label_1);

        lineEditwid = new QLineEdit(verticalLayoutWidget);
        lineEditwid->setObjectName(QStringLiteral("lineEditwid"));
        lineEditwid->setMinimumSize(QSize(0, 25));
        lineEditwid->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_1->addWidget(lineEditwid);


        verticalLayout->addLayout(horizontalLayout_1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(36, 0));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_high = new QLineEdit(verticalLayoutWidget);
        lineEdit_high->setObjectName(QStringLiteral("lineEdit_high"));
        lineEdit_high->setMinimumSize(QSize(0, 25));
        lineEdit_high->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_5->addWidget(lineEdit_high);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(36, 0));

        horizontalLayout_8->addWidget(label_8);

        lineEdit_fps = new QLineEdit(verticalLayoutWidget);
        lineEdit_fps->setObjectName(QStringLiteral("lineEdit_fps"));
        lineEdit_fps->setMinimumSize(QSize(0, 25));
        lineEdit_fps->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_8->addWidget(lineEdit_fps);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(36, 0));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_exp = new QLineEdit(verticalLayoutWidget);
        lineEdit_exp->setObjectName(QStringLiteral("lineEdit_exp"));
        lineEdit_exp->setMinimumSize(QSize(0, 25));
        lineEdit_exp->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_7->addWidget(lineEdit_exp);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(36, 0));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_bri = new QLineEdit(verticalLayoutWidget);
        lineEdit_bri->setObjectName(QStringLiteral("lineEdit_bri"));
        lineEdit_bri->setMinimumSize(QSize(0, 25));
        lineEdit_bri->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_6->addWidget(lineEdit_bri);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(36, 0));

        horizontalLayout_9->addWidget(label_9);

        lineEdit_sat = new QLineEdit(verticalLayoutWidget);
        lineEdit_sat->setObjectName(QStringLiteral("lineEdit_sat"));
        lineEdit_sat->setMinimumSize(QSize(0, 25));
        lineEdit_sat->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_9->addWidget(lineEdit_sat);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(36, 0));

        horizontalLayout_10->addWidget(label_10);

        lineEdit_hue = new QLineEdit(verticalLayoutWidget);
        lineEdit_hue->setObjectName(QStringLiteral("lineEdit_hue"));
        lineEdit_hue->setMinimumSize(QSize(0, 25));
        lineEdit_hue->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_10->addWidget(lineEdit_hue);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(36, 0));

        horizontalLayout_12->addWidget(label_12);

        lineEdit_con = new QLineEdit(verticalLayoutWidget);
        lineEdit_con->setObjectName(QStringLiteral("lineEdit_con"));
        lineEdit_con->setMinimumSize(QSize(0, 25));
        lineEdit_con->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_12->addWidget(lineEdit_con);


        verticalLayout->addLayout(horizontalLayout_12);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 359, 131, 51));
        pushButton_3->setMinimumSize(QSize(0, 40));
        groupBox_2 = new QGroupBox(CamsetDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 20, 501, 421));
        lblOriginal = new QLabel(groupBox_2);
        lblOriginal->setObjectName(QStringLiteral("lblOriginal"));
        lblOriginal->setGeometry(QRect(10, 20, 481, 341));
        lblOriginal->setMaximumSize(QSize(800, 800));
        lblOriginal->setAutoFillBackground(true);
        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 370, 491, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 2, 10, 2);
        pushButtonstart = new QPushButton(horizontalLayoutWidget);
        pushButtonstart->setObjectName(QStringLiteral("pushButtonstart"));
        pushButtonstart->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(pushButtonstart);

        pushButtonstop = new QPushButton(horizontalLayoutWidget);
        pushButtonstop->setObjectName(QStringLiteral("pushButtonstop"));
        pushButtonstop->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(pushButtonstop);


        retranslateUi(CamsetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CamsetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CamsetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CamsetDialog);
    } // setupUi

    void retranslateUi(QDialog *CamsetDialog)
    {
        CamsetDialog->setWindowTitle(QApplication::translate("CamsetDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("CamsetDialog", "SET", 0));
        label_id->setText(QApplication::translate("CamsetDialog", "ID\357\274\232", 0));
        label_1->setText(QApplication::translate("CamsetDialog", "WIDTH\357\274\232", 0));
        label_5->setText(QApplication::translate("CamsetDialog", "HIGHT\357\274\232", 0));
        label_8->setText(QApplication::translate("CamsetDialog", "FPS\357\274\232  ", 0));
        label_7->setText(QApplication::translate("CamsetDialog", "EXPO:  ", 0));
        label_6->setText(QApplication::translate("CamsetDialog", "BRIGHT:", 0));
        label_9->setText(QApplication::translate("CamsetDialog", "SATURA:", 0));
        label_10->setText(QApplication::translate("CamsetDialog", "HUE:", 0));
        label_12->setText(QApplication::translate("CamsetDialog", "CONTRAST", 0));
        pushButton_3->setText(QApplication::translate("CamsetDialog", "\346\240\207\345\256\232", 0));
        groupBox_2->setTitle(QApplication::translate("CamsetDialog", "IMG", 0));
        lblOriginal->setText(QString());
        pushButtonstart->setText(QApplication::translate("CamsetDialog", "START", 0));
        pushButtonstop->setText(QApplication::translate("CamsetDialog", "STOP", 0));
    } // retranslateUi

};

namespace Ui {
    class CamsetDialog: public Ui_CamsetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMSETDIALOG_H
