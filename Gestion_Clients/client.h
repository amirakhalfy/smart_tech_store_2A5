#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class Client
{
public:
    Client(int,QString,QString);
    void setcin(int n);
    void setprenom(QString n);
    void setnom(QString n);
    int getcin();
    QString getprenom();
    QString getnom();
    bool addClient();
    QSqlQueryModel * afficherClient();
    bool removeClient(int);
   bool modifierClient(QString,QString,int);
   QSqlQueryModel *trierAc();
   QSqlQueryModel * trierDec();
   ~Client(){}

    Client();
public:
    QString  prenom,nom;
    int cin;

};

#endif // CLIENT_H
