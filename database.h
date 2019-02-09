#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <string.h>
#include <QTableView>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QStandardItemModel>

using namespace std;

class dataBase
{
public:
    void registerInDb(QString text);
    void getFromDb(QComboBox *combo, QTableView *table);
    void deleteFromDb(int code);
    const char* QStringToChar(QString text);
    void dbConnector(string hostName, string hostUser, string hostPass, string dbName);
    char* stringToChar(string text);

};

#endif // DATABASE_H
