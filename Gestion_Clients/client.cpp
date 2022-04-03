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
               q->prepare("SELECT * FROM CLIENTS order by nom_clt ASC");
               q->exec();
               model->setQuery(*q);
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("id commande"));


               return model;

  }

  QSqlQueryModel * Client::trierDec()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM CLIENTS order by NOM_CLT DESC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("id commande"));


                   return model;
  }


  QSqlQueryModel * Client::rechercher_client(QString nom)
   {
      QSqlQuery * q = new  QSqlQuery ();
   QSqlQueryModel * model= new QSqlQueryModel();

   q->prepare("SELECT * FROM clients WHERE  nom_clt LIKE '"+nom+"%'");
   q->exec();
   model->setQuery(*q);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("id commande"));



   return model ;
   }

  QSqlQueryModel * Client::classification1()
  {
      QSqlQuery * q1 = new  QSqlQuery ();
      QSqlQuery * q2 = new  QSqlQuery ();

   QSqlQueryModel * model= new QSqlQueryModel();

   q1->prepare("SELECT  nom_clt, prenom_clt,score FROM clients,commandes WHERE clients.id_commande=commandes.id_commande and commandes.prix_tot>=0 and commandes.prix_tot<=500  ");
   q2->prepare("UPDATE clients SET score=:s  where id_commande in (select id_commande from commandes where prix_tot>=0 and prix_tot<=500) ");
    q2->bindValue(":s",10);


   q1->exec();
   q2->exec();

   model->setQuery(*q1);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("score"));



   return model ;

  }

  QSqlQueryModel * Client::classification2()
  {
              QSqlQuery * q = new  QSqlQuery ();
              QSqlQuery * q2 = new  QSqlQuery ();
           QSqlQueryModel * model= new QSqlQueryModel();

           q->prepare("SELECT  nom_clt, prenom_clt,score FROM clients,commandes WHERE clients.id_commande=commandes.id_commande and commandes.prix_tot>=500 and commandes.prix_tot<=1500  ");


           q2->prepare("UPDATE clients SET score=:s  where id_commande in (select id_commande from commandes where prix_tot>=500 and prix_tot<=1500) ");
            q2->bindValue(":s",20);
            q->exec();
            q2->exec();
            model->setQuery(*q);
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("score"));


           return model ;

  }


  QSqlQueryModel * Client::classification3()
  {
      QSqlQuery * q = new  QSqlQuery ();
      QSqlQuery * q2 = new  QSqlQuery ();

   QSqlQueryModel * model= new QSqlQueryModel();

   q->prepare("SELECT  nom_clt, prenom_clt,score FROM clients,commandes WHERE clients.id_commande=commandes.id_commande and commandes.prix_tot>=1500  ");
   q2->prepare("UPDATE clients SET score=:s  where id_commande in (select id_commande from commandes where  prix_tot>=1500) ");
    q2->bindValue(":s",30);
   q->exec();
    q2->exec();

    model->setQuery(*q);


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("score"));


   return model ;


  }


 QSqlQueryModel * Client::classer()
 {
     QSqlQuery * q = new  QSqlQuery ();
     QSqlQueryModel * model= new QSqlQueryModel();
     q->prepare("SELECT  nom_clt, prenom_clt,categorie FROM clients , produits , commandes  where clients.produit = commandes.id_produit and commandes.id_produit=produits.id_produit  order by produits.categorie ");

     q->exec();
     model->setQuery(*q);



     model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
     return model;
 }




