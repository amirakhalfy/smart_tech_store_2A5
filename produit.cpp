#include "produit.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QTableView>
#include<QList>



Produit::Produit(int id_produit,int reference,int prix,QString date_ajout_produit,QString nom_produit,QString quantite)
{
this->id_produit=id_produit;
this->reference=reference;
 this->prix=prix;
  this->date_ajout_produit=date_ajout_produit;
  this->nom_produit=nom_produit;
  this->quantite=quantite;
}

int Produit::getidproduit(){
   return id_produit;

}
int Produit::getreference(){
  return reference;

}
int Produit::getprix(){

  return prix;
}

QString Produit::getnomproduit(){
 return nom_produit;
}
QString Produit::getquantite(){
  return quantite;

}
QString Produit::getdate(){
  return date_ajout_produit;

}
void Produit::setidproduit(int id_produit){
    this->id_produit=id_produit;
}
void Produit:: setreference(int reference){
    this->reference=reference;
}
void Produit::setprix(int prix){
 this->prix=prix;

}
void Produit::setnomproduit(QString nom_produit){
    this->nom_produit=nom_produit;
}
void Produit::setdate(QString date_ajout_produit){
    this->date_ajout_produit=date_ajout_produit;
}
void Produit::setquantite(QString quantite){
    this->quantite=quantite;
}

bool Produit::ajouter(){
  QSqlQuery query;
  QString id_string= QString::number(id_produit);
   QString refer_string= QString::number(reference);
   QString prix_string= QString::number(prix);

       query.prepare("INSERT INTO PRODUITS (id_produit,reference,prix,date_ajout_produit,nom_produit,quantite)"
                     "VALUES (:id_produit,:reference,:prix,:date_ajout_produit,:nom_produit,:quantite)");
       query.bindValue(":id_produit",id_string);
       query.bindValue(":reference",refer_string);
       query.bindValue(":prix",prix_string);
       query.bindValue(":date",date_ajout_produit);
       query.bindValue(":nom_produit",nom_produit);
       query.bindValue(":quantite",quantite);
   return query.exec();

}
bool Produit::supprimer(int id_produit)
{
    QSqlQuery query;
         query.prepare(" DELETE from PRODUITS where id_produit=:id_produit");
       query.bindValue(0,id_produit);
       return query.exec();


}

QSqlQueryModel* Produit::afficher(){

 QSqlQueryModel* model =new QSqlQueryModel();
 model->setQuery("SELECT* FROM PRODUITS");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom_produit"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
 return model;
}
bool Produit::modifierProduit()
{
   QSqlQuery query;
   QString id_string= QString::number(id_produit);
    QString refer_string= QString::number(reference);
    QString prix_string= QString::number(prix);
   query.prepare("update PRODUITS set id_produit=:id_produit,reference=:reference,prix=:prix,date_ajout_produit=:date_ajout_produit,nom_produit=:nom_produit,quantite=:quantite where id_produit=:id_produit");
   query.bindValue(":id_produit",id_string);
   query.bindValue(":reference",refer_string);
   query.bindValue(":prix",prix_string);
   query.bindValue(":date_ajout_produit",date_ajout_produit);
   query.bindValue(":nom_produit",nom_produit);
   query.bindValue(":quantite",quantite);
return query.exec();

}



QSqlQueryModel * Produit::rechercher(QString nom_produit)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM PRODUITS WHERE  nom_produit LIKE '%"+nom_produit+"%'" );

model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom du produit"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
return model ;
}
QSqlQueryModel *Produit::tri_nomproduit()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  PRODUIT ORDER BY nom_produit");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom du produit"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
return model;
}
