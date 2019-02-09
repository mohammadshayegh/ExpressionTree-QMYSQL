#include "database.h"
#include <QDebug>


void dataBase::registerInDb(QString Text)
{
    QSqlQuery mysqlQuery ;
    const char* text = QStringToChar(Text);

    mysqlQuery.prepare("INSERT INTO `orders` (`text`) VALUES (:text);") ;
    mysqlQuery.bindValue(":text",text);

    /* Checknig database Datas
       Inserting Data in Database */

    if(mysqlQuery.exec())
    {
       qDebug()<<"Registered Successfully !" ;
    }
    else
    {
        qDebug()<<"error ocured !!";
    }
}

void dataBase::getFromDb(QComboBox *combo, QTableView *table)
{
    QSqlQuery mysqlQuery ;
    mysqlQuery.prepare("SELECT * FROM `orders`;");
    mysqlQuery.exec();

    if( mysqlQuery.size() > 0 )
    {
        QStandardItemModel* model = new QStandardItemModel;
        while(mysqlQuery.next())
        {
            //adding to ComboBox
            combo->addItem( mysqlQuery.value("text").toString() );

            //preparing data for adding to tabel
            QList<QStandardItem *> items; //list of data

            items.append(new QStandardItem(mysqlQuery.value("code").toString()));
            items.append(new QStandardItem(mysqlQuery.value("text").toString()));

            //setting row and column
            model->setColumnCount(2);
            model->appendRow(items);
        }
        table->setModel(model);
    }
    else
        qDebug() << " Nothing is in Database !  " ;
}

void dataBase::deleteFromDb(int code)
{
    QSqlQuery mysqlQuery ;

    mysqlQuery.prepare("DELETE FROM `orders` WHERE `orders`.`code` = :code;") ;
    mysqlQuery.bindValue(":code",code);

    /* Checknig database Datas
       Inserting Data in Database */

    if(mysqlQuery.exec())
    {
       qDebug()<<"deleted Successfully !" ;
    }
    else
    {
        qDebug()<<"nothing deleted !!";
    }
}

// Convert QString To char

const char* dataBase::QStringToChar(QString text)
{
    string strTxt = text.toStdString() ;    //Qstring To String Converter
    return dataBase::stringToChar(strTxt) ;
}

// DataBase Connector ( to MySQL )

void dataBase::dbConnector(string hostName, string hostUser, string hostPass, string dbName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");          // dataBase Type
    db.setHostName( stringToChar(hostName) );   // Name of chosen Host
    db.setUserName( stringToChar(hostUser) );   // Host UserName
    db.setPassword( stringToChar(hostPass) );   // Host password
    db.setDatabaseName( stringToChar(dbName) ); // String Converter

    if(!db.open())
        qDebug()<<"Error Ocured ! please Contact Us !";
}


// string to Char
char* dataBase::stringToChar(string text)
{
    char *CharedStr = new char[ text.length() + 1 ] ; // Getting Char-space From Heap
    strcpy(CharedStr , text.c_str()) ;              //Copying Data of two strings
    return CharedStr ;
}
