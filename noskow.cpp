#include "noskow.h"
#include "ui_noskow.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

Noskow::Noskow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Noskow)
{
    ui->setupUi(this);
}

void Noskow::recieveData(QString str)
{
    QStringList lst = str.split("*");
    ui->textEdit->setText(lst.at(1)+"\n"+lst.at(0));
    if(lst.size()>1) {QImage image1(lst.at(0));
        ui->label->setPixmap(QPixmap::fromImage(image1));
    }
}

void Noskow::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button->text()== "Reset")
    {
        ui->textEdit->clear();
        ui->label->clear();
    }
    if(button->text()=="Save")
    {
        QString m_strFileName;
        QString str= QFileDialog::getSaveFileName(0, m_strFileName);
        if(!str.isEmpty())
        {
            m_strFileName = str;
            if(m_strFileName.isEmpty())
            {
                return;
            }
            QFile file(m_strFileName);
            if(file.open(QIODevice::WriteOnly))
            {
                QTextStream(&file)<<ui->textEdit->toPlainText();
                file.close();
            }
            QMessageBox::information(0, "Инфо", "Сохранение прошло успешно");
        }
    }
    if(button->text()=="Open")
    {
        QString m_strFileName;
        QString str = QFileDialog::getOpenFileName();
        if(str.isEmpty())
        {
            return;
        }

        QFile file(str);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            ui->textEdit->setPlainText(stream.readAll());
            file.close();

            QStringList inf = ui->textEdit->toPlainText().split("\n");
            QImage image2(inf.at(5));
            ui->label->setPixmap(QPixmap::fromImage(image2));
            m_strFileName = str;
        }

    }
}

Noskow::~Noskow()
{
    delete ui;
}
