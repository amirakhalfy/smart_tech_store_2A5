#include "SAV.h"
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDebug>
#include <QSqlRecord>
using namespace std;

SAV::SAV()
{

   id_SAV=0;
             nom="";
             prenom="";
             date_SAV="";
             description="";

}
SAV::SAV(int id_SAV, QString nom,  QString prenom , QString date_SAV , QString description)
{
            this->id_SAV=id_SAV;
            this->nom=nom;
            this->prenom=prenom;
            this->date_SAV=date_SAV;
            this->description=description;

}

void SAV::setid_SAV(int n){
    id_SAV=n;

}
void SAV::setprenom(QString n){
    prenom=n;
}
    void SAV::setnom(QString n){
        nom=n;
}

        void SAV::setdate_SAV(QString n){
            date_SAV=n;
    }
        void SAV::setdescription(QString n){
            description=n;
    }

        int SAV::getid_SAV(){
                return id_SAV;
            }
    QString SAV::getprenom(){
        return prenom;
    }
    QString SAV::getnom(){
        return nom;
    }

    QString SAV::getdate_SAV(){
        return date_SAV;
    }
    QString SAV::getdescription(){
        return description;
    }

    bool SAV::addSAV(){
        QSqlQuery query;
        query.prepare("INSERT INTO SAV (ID_SAV, NOM, PRENOM, DATE_SAV, DESCRIPTION)"
                      "VALUES(:ID_SAV, :NOM, :PRENOM, :DATE_SAV, :DESCRIPTION)");
        query.bindValue(":ID_SAV",id_SAV);
        query.bindValue(":NOM",nom);
        query.bindValue(":PRENOM",prenom);
        query.bindValue(":DATE_SAV",date_SAV);
        query.bindValue(":DESCRIPTION",description);


        return query.exec();
    }



    bool SAV::removeSAV(int id_SAV){
    QSqlQuery query;
    query.prepare("DELETE FROM SAV WHERE ID_SAV = :ID_SAV");
    query.bindValue(":ID_SAV", id_SAV);
    return    query.exec();
    }

    bool SAV::modifierSAV(QString nom,QString prenom,int id_SAV,QString date_SAV,QString description)
{ QSqlQuery query;
            query.prepare("update sav set nom=:nom,prenom=:prenom,date_SAV=:date_SAV,description=:description where id_SAV=:id_SAV");
            query.bindValue(":id_SAV",id_SAV);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
               query.bindValue(":date_SAV", date_SAV);
               query.bindValue(":description", description);
            return    query.exec();

    }

  QSqlQueryModel * SAV::afficherSAV()
  {

            QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from sav");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_SAV"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_SAV"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("description"));


            return model;
        }












