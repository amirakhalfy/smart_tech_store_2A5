#include "client.h"
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDebug>
#include <QSqlRecord>
using namespace std;

Client::Client()
{
    cin=0;

             nom="";
             prenom="";

}
Client::Client(int cin, QString nom,  QString prenom)
{
    this->cin=cin;
            this->nom=nom;
            this->prenom=prenom;

}

void Client::setcin(int n){
    cin=n;

}
void Client::setprenom(QString n){
    prenom=n;
}
    void Client::setnom(QString n){
        nom=n;
}

    int Client::getcin(){
        return cin;
    }
    QString Client::getprenom(){
        return prenom;
    }
    QString Client::getnom(){
        return nom;
    }

    bool Client::addClient(){
        QSqlQuery query;
        query.prepare("INSERT INTO CLIENT (CIN, NOM, PRENOM)"
                      "VALUES(:CIN, :NOM, :PRENOM)");
        query.bindValue(":CIN",cin);
        query.bindValue(":NOM",nom);
        query.bindValue(":PRENOM",prenom);


        return query.exec();
    }



    bool Client::removeClient(int cin){
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE CIN = :CIN");
    query.bindValue(":CIN", cin);
    return    query.exec();
    }

    bool Client::modifierClient(QString nom,QString prenom,int cin)
{ QSqlQuery query;
            query.prepare("update client set nom=:nom,prenom=:prenom where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
            return    query.exec();

    }

  QSqlQueryModel * Client::afficherClient()
  {

            QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from client");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));

            return model;
        }

  QSqlQueryModel * Client::trierAc()
  {
      QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM CLIENT order by nom ASC");
               q->exec();
               model->setQuery(*q);
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));

               return model;

  }

  QSqlQueryModel * Client::trierDec()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM CLIENT order by NOM DESC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));

                   return model;
  }












