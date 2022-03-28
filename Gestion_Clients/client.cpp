#include "client.h"
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

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
        query.prepare("INSERT INTO CLIENTS (CIN, NOM_CLT, PRENOM_CLT)"
                      "VALUES(:CIN, :NOM_CLT, :PRENOM_CLT)");
        query.bindValue(":CIN",cin);
        query.bindValue(":NOM_CLT",nom);
        query.bindValue(":PRENOM_CLT",prenom);


        return query.exec();
    }



    bool Client::removeClient(int cin){
    QSqlQuery query;

    query.prepare("DELETE FROM CLIENTS WHERE CIN = :CIN");
    query.bindValue(":CIN", cin);
    return    query.exec();

    }

    bool Client::modifierClient(QString nom,QString prenom,int cin)
{
      QSqlQuery query;
      query.prepare("SELECT CIN FROM CLIENTS WHERE CIN = :CIN ");
      query.exec();

            query.prepare("update clients set nom_clt=:nom,prenom_clt=:prenom where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
            return    query.exec();

    }

  QSqlQueryModel * Client::afficherClient()
  {

            QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from clients");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

            return model;
        }

  QSqlQueryModel * Client::trierAc()
  {
      QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM CLIENTS order by nom ASC");
               q->exec();
               model->setQuery(*q);
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

               return model;

  }

  QSqlQueryModel * Client::trierDec()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM CLIENTS order by NOM DESC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

                   return model;
  }


  QSqlQueryModel * Client::rechercher_client(QString nom)
   {
      QSqlQuery * q = new  QSqlQuery ();
   QSqlQueryModel * model= new QSqlQueryModel();

   q->prepare("SELECT * FROM clients WHERE  nom LIKE '"+nom+"%'");
   q->exec();
   model->setQuery(*q);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));



   return model ;
   }

  QSqlQueryModel * Client::classification1()
  {
      QSqlQuery * q = new  QSqlQuery ();
   QSqlQueryModel * model= new QSqlQueryModel();

   q->prepare("SELECT cin, nom_clt, prenom_clt,prix_tot FROM clients,commandes WHERE clients.id_commande=commandes.id_commande and commandes.prix_tot>=0 and commandes.prix_tot<=500  ");
   q->exec();
   model->setQuery(*q);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


   return model ;

  }

  QSqlQueryModel * Client::classification2()
  {
              QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model= new QSqlQueryModel();

           q->prepare("SELECT cin, nom_clt, prenom_clt,prix_tot FROM clients,commandes WHERE clients.id_commande=commandes.id_commande and commandes.prix_tot>=500 and commandes.prix_tot<=1500  ");
           q->exec();
           model->setQuery(*q);


           model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


           return model ;

  }


  QSqlQueryModel * Client::classification3()
  {
      QSqlQuery * q = new  QSqlQuery ();
   QSqlQueryModel * model= new QSqlQueryModel();

   q->prepare("SELECT cin, nom_clt, prenom_clt,prix_tot FROM clients,commandes WHERE clients.id_commande=commandes.id_commande and commandes.prix_tot>=1500  ");
   q->exec();
   model->setQuery(*q);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


   return model ;


  }







