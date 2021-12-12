#ifndef NOSKOW_H
#define NOSKOW_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class Noskow;
}

class Noskow : public QWidget
{
    Q_OBJECT

public:
    explicit Noskow(QWidget *parent = 0);
    ~Noskow();

private:
    Ui::Noskow *ui;
public slots:
    void recieveData(QString str);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // NOSKOW_H
