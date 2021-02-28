#include "mainwindow.h"
#include "customtabstyle.h"
#include "ui_mainwindow.h"

#include <QTabBar>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);

    ui->tabWidget_2->tabBar()->setStyle(new CustomTabStyle);

    const QString label_SheetStyle = "min-width: 30px; min-height: 30px;max-width:16px; max-height:16px;border-radius: 15px;border:1px solid black;background-image:url('D:\\Qt5.14.2\\exercise\\DingDingInterface\\image\\jianhao.jpg');";

    ui->label->setStyleSheet("min-width: 40px;"
                             "min-height: 40px;"
                             "max-width:16px; "
                             "max-height:16px;"
                             "border-radius: 20px;"
                             "border:1px solid black;"
                             "background-color:#0089FF"
                             );

//    QImage img =  QImage();

//    img.load("jianhao.jpg");

//    QPixmap pixmap = QPixmap::fromImage(img);

    QPixmap pixmap;

    pixmap.load("D:\\Qt5.14.2\\exercise\\DingDingInterface\\image\\jianhao.jpg");

    QPixmap fitpixmap = pixmap.scaled(40, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//使用scaled函数将图片适配label控件

    ui->label->setPixmap(fitpixmap);

}

MainWindow::~MainWindow()
{
    delete ui;
}

