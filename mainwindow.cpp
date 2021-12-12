#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDate"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myform = new Noskow();
    connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(onButtonSend()));
    connect(this, SIGNAL(sendData(QString)), myform, SLOT(recieveData(QString)));
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
    if(!filename.isEmpty()){
        ui->lineEdit_4->setText(filename);
        QImage image1(filename);
        ui->label_5->setPixmap(QPixmap::fromImage(image1));
    }
}

QDate dt1(1900, 1, 1);
QDate dt2(2007, 1, 1);


void MainWindow::on_pushButton_clicked()
{

    if(!ui->lineEdit->text().isEmpty() & !ui->lineEdit_2->text().isEmpty() & !ui->lineEdit_3->text().isEmpty() & !ui->lineEdit_4->text().isEmpty() & (ui->radioButton->isChecked() || ui->radioButton_2->isChecked())
            & dt1.toString("yyyy")<ui->dateEdit->date().toString("yyyy") && dt2.toString("yyyy") > ui->dateEdit->date().toString("yyyy") ){
QString st = ui->lineEdit_4->text()+"*"+ui->lineEdit->text()+
        "\n"+ ui->lineEdit_2->text() + "\n" + ui->lineEdit_3->text() + "\n" + ui->dateEdit->text();
if(ui->radioButton->isChecked()==true) st+="\nпол: мужской";
    else st+="\nпол: женский";

emit sendData(st);
myform->show();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
