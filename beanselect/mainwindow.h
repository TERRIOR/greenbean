#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controlthread.h"
#include <qmessagebox.h>
#include <QMainWindow>
#include <qfile>
#include <QtCore>
#include "qtimer.h"
#include <QMainWindow>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QAbstractButton>
#include "cvcamera_g.h"
#ifdef RASPI
#include "piserialconnect.h"
#else
#include "serialconnect.h"
#endif
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief initform 初始化ui
     */
    void initform();
    /**
     * @brief opencam 打开相机
     */
    void opencam();
    /**
     * @brief closecam 关闭相机
     */
    void closecam();
    /**
     * @brief initcom 初始化串口，显示名字
     */
    void initcom();
    void opencom();
    void openimg();
    void closeimg();
private slots:
    void closecom();
    void updategui();
    void on_pushButton_min_clicked();
    void on_pushButton_max_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_pause_toggled(bool checked);

    void on_pushButton_4_clicked();

private:
    //serialconnect Serialconnect;
    Ui::MainWindow *ui;
    QRect location;
    bool m_bmode=false;
    QTimer *tmrTimer=NULL;
    QTimer *pTimer=NULL;
    bool max;
    controlthread* conthread=NULL;

};

#endif // MAINWINDOW_H
