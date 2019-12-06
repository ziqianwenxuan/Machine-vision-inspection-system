#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

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
    openpicture();
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
    qDebug()<<QString("显示图片");
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->date_view->setScene(scene);
    scene->addPixmap( QPixmap("1.png") );

    ui->date_view->show();
    qDebug()<<QString("图片没有显示");
}

void MainWindow::on_pushButton_clicked()
{
//    ui->label_2->setText(tr("Critical Message Box"));
//    qDebug()<<QString("12345");
    ui->textBrowser->setText(tr("Information Message Box"));
    QMessageBox::information(this,tr("Information"),tr("RUNING Test"));
    return;
}


