#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void timerUpdate();
    void on_Exit_bt_clicked();

    void on_Run_bt_clicked();

    void on_Lock_bt_clicked();

    void on_Account_bt_clicked();

    void on_Start_bt_clicked();

    void on_Light_bt_clicked();

private:
    Ui::MainWindow *ui;
    void  openpicture();
    bool Run_bt = true;
    bool Start_bt = true;
    bool Light_bt = true;

};
#endif // MAINWINDOW_H
