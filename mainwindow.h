#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <Qdir>
#include <QPushButton>
#include "noskow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:

    Ui::MainWindow *ui;
    Noskow *myform;

signals:
    void sendData(QString str);


};




#endif // MAINWINDOW_H
