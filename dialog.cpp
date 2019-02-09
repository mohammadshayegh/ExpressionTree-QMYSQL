#include <QDebug>
#include <QStandardItemModel>
#include "dialog.h"
#include "ui_dialog.h"
#include "traversal.h"
#include "database.h"
#include "expressiontree.h"


int g = 0;
vector<int> v;
vector<char> cv;
int comboG = 1;
dataBase express;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    express.dbConnector("localhost" , "root" , "" , "qtdatabase");
    express.getFromDb(ui->comboBox_2,ui->tableView);
}

void Dialog::sendToMySql(QString data)
{
    express.registerInDb(data);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog:: paintEvent(QPaintEvent *e)
{
    int vSize = int(v.size()-1);
    int cvSize = int(cv.size()-1);

    if(g)
    {
        for( int i=vSize,j=cvSize;i>0;i = i-4,j--)
        {
            QPainter painter(this);QPoint p;

            p.setX(v[i-1]+6);p.setY(v[i]+15);
            QRect r1(v[i-1],v[i],20,20);

            if(v[i])
                painter.drawLine(v[i-1]+15,v[i],v[i-3]+15,v[i-2]+20);
            painter.drawEllipse(r1);
            painter.drawText(p,QString(cv[j]));
        }
        g=0;
    }
}

void Dialog::on_postO_Button_clicked()
{
    QString text = ui->lineEdit->text();
    string txt = text.toStdString();
    if(comboG)
    {
        ui->comboBox_2->addItem(text);
        sendToMySql(text);
        express.getFromDb(ui->comboBox_2,ui->tableView);
        comboG = 1 ;
    }
    else
        comboG = 1 ;

    //expression tree
    expressionTree a(txt,'p');
    node *r = a.getRoot();

    //integer Value of expression tree
    ui->lastVal_R->setText( QString::number( a.lastVal(r) ) );

    //traversals
    traversal t;
    //inOrder
    t.inOrder(r);
    ui->inO_R->setText(t.getIno());

    //preorder
    t.preOrder(r);
    ui->preO_R->setText(t.getPreO());

    //postorder
    t.postOrder(r);
    ui->postO_R->setText(t.getPostO());

    //parantheses inorder
    t.treeToParanthesesInfix(r);
    ui->label_5->setText(t.getPInO());


    int treeDepth = a.treeDepth(r) ;
    a.nodeLocator(r,nullptr,treeDepth,treeDepth*20+350,0);

    v = a.getPos();
    cv = a.getChar();
    on_pushButton_clicked();
    t.~traversal();
}

void Dialog::on_inO_Button_clicked()
{

    QString text = ui->lineEdit->text();
    string txt = text.toStdString();
    if(comboG)
    {
        ui->comboBox_2->addItem(text);
        sendToMySql(text);
        express.getFromDb(ui->comboBox_2,ui->tableView);
        comboG = 1 ;
    }
    else
        comboG = 1 ;

    //expression tree
    expressionTree a(txt,'i');
    node *r = a.getRoot();

    //integer Value of expression tree
    ui->lastVal_R->setText( QString::number( a.lastVal(r) ) );

    //traversals
    traversal t;
    //inOrder
    t.inOrder(r);
    ui->inO_R->setText(t.getIno());

    //preorder
    t.preOrder(r);
    ui->preO_R->setText(t.getPreO());

    //postorder
    t.postOrder(r);
    ui->postO_R->setText(t.getPostO());

    //parantheses inorder
    t.treeToParanthesesInfix(r);
    ui->label_5->setText(t.getPInO());

    //tree vu
    int treeDepth = a.treeDepth(r) ;
    a.nodeLocator(r,nullptr,treeDepth,treeDepth*20+350,0);
    v = a.getPos();
    cv = a.getChar();
    on_pushButton_clicked();

    t.~traversal();
}

void Dialog::on_pushButton_clicked()
{
    g=1;
    update();
}

void Dialog::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit->setText(arg1);
    comboG = 0 ;
}

void Dialog::on_pushButton_2_clicked()
{
    int p = ui->tableView->currentIndex().data().toString().toInt();
    express.deleteFromDb(p);
    express.getFromDb(ui->comboBox_2,ui->tableView);

}
