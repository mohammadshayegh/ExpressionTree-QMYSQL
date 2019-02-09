#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QRect>
#include <QBrush>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void sendToMySql(QString data);
    ~Dialog();

private:
    Ui::Dialog *ui;

protected:
    void paintEvent(QPaintEvent *e);
private slots:
    void on_postO_Button_clicked();
    void on_inO_Button_clicked();
    void on_pushButton_clicked();
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void on_pushButton_2_clicked();
};

#endif // DIALOG_H
