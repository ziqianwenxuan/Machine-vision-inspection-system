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
    timer->start(1000); //1000ms 触发一次
    QMovie *movie = new QMovie("../InspectionSystem/Yundee.gif");
    ui->LogoShow->setMovie(movie);
    movie->start();
    ui->LogoShow->show();
    openpicture();
//   ui->Run_bt->setGeometry(77,69,300,300);
   ui->Run_bt->setGeometry(70,70,200,200);
   ui->Run_bt->setStyleSheet("QPushButton{font-size:80px;\
                                   color:yellow;\
                              background-color:rgba(0,255,0,200);\
                                     border-radius:100px;\
                                       }");


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();

    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");

    ui->dateTime->setText(str);

}


void MainWindow::openpicture()
{

    QGraphicsScene *scene_camera = new QGraphicsScene(this);
    QGraphicsScene *scene_date = new QGraphicsScene(this);
    ui->graphics_View->setScene(scene_camera);
    ui->date_view->setScene(scene_date);

    scene_camera->addPixmap( QPixmap("../InspectionSystem/camera.png").scaled(ui->graphics_View->size()) );
    scene_date->addPixmap( QPixmap("../InspectionSystem/date.png") );

//    ui->date_view->resize(ui->date_view->width() + 10, ui->date_view->height() + 10);
//    ui->date_view->show();

}

void MainWindow::on_pushButton_clicked()
{
//    ui->label_2->setText(tr("Critical Message Box"));
//    qDebug()<<QString("12345");
    ui->textBrowser->setText(tr("Information Message Box"));
    QMessageBox::information(this,tr("Information"),tr("RUNING Test"));
    return;
}



void MainWindow::on_Exit_bt_clicked()
{
    if( QMessageBox::question(this,tr("Quit"), tr("Are you sure to quit this application?"),QMessageBox::Yes, QMessageBox::No )== QMessageBox::Yes);

    {
            QApplication* app;
            app->quit();

            qDebug()<<"程序退出！";
        }

}

void MainWindow::on_Run_bt_clicked()
{
    if(this->ui->Run_bt->text()=="START"){

        ui->Run_bt->setStyleSheet("QPushButton{font-size:80px;\
                                        color:yellow;\
                                   background-color:rgba(255,0,0,200);\
                                          border-radius:100px;\
                                            }");
        this->ui->Run_bt->setText("STOP");
    }else {
    ui->Run_bt->setStyleSheet("QPushButton{font-size:80px;\
                                color:yellow;\
                           background-color:rgba(0,255,0,200);\
                                  border-radius:100px;\
                                    }");

        this->ui->Run_bt->setText("START");
                                  }

}
