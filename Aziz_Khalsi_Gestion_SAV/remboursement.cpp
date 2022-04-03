#include "SAV.h"
#include "remboursement.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlRecord>
#include "stat_combo.h"
#include "ui_stat_combo.h"

remboursement::remboursement()
{
   prix=0;
   id_sav=0;

}
remboursement::remboursement(int prix ,int id_sav)
{
            this->prix=prix;
       this->id_sav=id_sav;


}

void remboursement::setprix_remboursement(int n){
    prix=n;

}

int remboursement::getprix_remboursement(){
        return prix;
    }

bool remboursement::addremboursement(){
    QSqlQuery query;
    query.prepare("INSERT INTO remboursement (prix , id_sav)"
                  "VALUES(:prix, :id_sav)");
    query.bindValue(":prix",prix);
    query.bindValue(":id_sav",id_sav);

    return query.exec();
}

QSqlQueryModel * remboursement::afficherremboursement()
{

          QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("select * from remboursement");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("prix"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_sav"));


          return model;
      }
