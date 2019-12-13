
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QMovie>

#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //日期/时间显示
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    connect(timer,SIGNAL(timeout()),this,SLOT(openpicture()));
    timer->start(1000); //1000ms 触发一次
    QMovie *movie = new QMovie("../InspectionSystem/Yundee.gif");
    ui->LogoShow->setMovie(movie);
    movie->start();
    ui->LogoShow->show();
//    openpicture();
    //几个图标的初始化设定！！！
    ui->Lock_bt->setIcon( QIcon(":/images/images/lock.png"));
    ui->Lock_bt->setFlat(true);
    ui->Account_bt->setIcon( QIcon(":/images/images/Account.png"));
    ui->Account_bt->setFlat(true);
    ui->Start_bt->setIcon( QIcon(":/images/images/close.png"));
    ui->Start_bt->setFlat(true);
    ui->Light_bt->setIcon( QIcon(":/images/images/light_up.jpg"));
    ui->Light_bt->setFlat(true);
    ui->Run_bt->setStyleSheet("QPushButton{border-image: url(:/images/images/start.png)}");
    ui->Run_bt->setText("Start");
    ui->Run_bt->setFlat(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();

    QString str_date = time.toString("yyyy/MM/dd dddd");
    QString str_time = time.toString(" hh:mm:ss ");

    ui->date_label->setText(str_date);

    ui->Time_label->setText(str_time);

}

void MainWindow::openpicture()
{


    QGraphicsScene *scene_camera = new QGraphicsScene(this);
    QGraphicsScene *scene_date = new QGraphicsScene(this);
    ui->graphics_View->setScene(scene_camera);
    ui->date_view->setScene(scene_date);
    // 如下了两句代码 就是让图片随着sence的大小而改变
    scene_camera->addPixmap( QPixmap("../InspectionSystem/camera.png").scaled(ui->graphics_View->size()) );
    scene_date->addPixmap( QPixmap("../InspectionSystem/date.png").scaled(ui->date_view->size()));




}


void MainWindow::on_Exit_bt_clicked()
{

    switch(QMessageBox::question(this,tr("Quit"),
          tr("Are you sure to quit this application?"),
          QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
                    QApplication* app;
                    app->quit();

                    qDebug()<<"程序退出！";
        break;
    case QMessageBox::Cancel:

        break;
    default:
        break;
    }

}

void MainWindow::on_Run_bt_clicked()
{
    if(Run_bt)
    {
        ui->Run_bt->setStyleSheet("QPushButton{border-image: url(:/images/images/stop.png)}");
         ui->Run_bt->setText("Stop");
//       ui->Run_bt->setIcon( QIcon(":/images/images/stop.png"));
       Run_bt = false;
    }
    else
    {
        ui->Run_bt->setStyleSheet("QPushButton{border-image: url(:/images/images/start.png)}");
        ui->Run_bt->setText("Start");
//      ui->Run_bt->setIcon( QIcon(":/images/images/start.png"));
        Run_bt = true;
     }
}

void MainWindow::on_Lock_bt_clicked()
{
    //账户 界面锁定
}

void MainWindow::on_Account_bt_clicked()
{
    //账户切换
}

void MainWindow::on_Start_bt_clicked()
{

    if(Start_bt)
    {

       ui->Start_bt->setIcon( QIcon(":/images/images/open.png"));
       Start_bt = false;
    }
    else
    {
      ui->Start_bt->setIcon( QIcon(":/images/images/close.png"));
      Start_bt = true;
                                  }
}

void MainWindow::on_Light_bt_clicked()
{

    if(Light_bt)
    {

       ui->Light_bt->setIcon( QIcon(":/images/images/light_down.jpg"));
       Light_bt = false;
    }
    else
    {
      ui->Light_bt->setIcon( QIcon(":/images/images/light_up.jpg"));
      Light_bt = true;
                                  }

}
