#include "produit.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QTableView>
#include<QList>
#include<vector>
#include "notification.h"


Produit::Produit(int id_produit,int reference,int prix,QString date_ajout_produit,QString nom_produit,QString quantite,int etat,QString type)
{
this->id_produit=id_produit;
this->reference=reference;
 this->prix=prix;
  this->date_ajout_produit=date_ajout_produit;
  this->nom_produit=nom_produit;
  this->quantite=quantite;
    this->etat=etat;
    this->type=type;


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
QString Produit::gettype(){
  return type;

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
int Produit::getetat(){

  return etat;
}
void Produit::setetat(int etat){
    this->etat=etat;
}
void Produit::settype(QString type){
    this->type=type;
}
int Produit::getquantitec(){
return quantite_c;
}

bool Produit::ajouter(){
  QSqlQuery query;
  QString id_string= QString::number(id_produit);
   QString refer_string= QString::number(reference);
   QString prix_string= QString::number(prix);
   QString etat_string= QString::number(etat);


       query.prepare("INSERT INTO PRODUITS (id_produit,reference,prix,date_ajout_produit,nom_produit,quantite,etat,type)"
                     "VALUES (:id_produit,:reference,:prix,:date_ajout_produit,:nom_produit,:quantite,:etat,:type)");
       query.bindValue(":id_produit",id_string);
       query.bindValue(":reference",refer_string);
       query.bindValue(":prix",prix_string);
       query.bindValue(":date",date_ajout_produit);
       query.bindValue(":nom_produit",nom_produit);
       query.bindValue(":quantite",quantite);
       query.bindValue(":etat",etat_string);
       query.bindValue(":quantite",quantite);
       query.bindValue(":type",type);


   return query.exec();

}
bool Produit::supprimer(int id_produit)
{
    QSqlQuery query;
         query.prepare(" DELETE from PRODUITS where (id_produit=:id_produit ANd ETAT!=0)");
       query.bindValue(0,id_produit);
       return query.exec();


}

QSqlQueryModel* Produit::afficher(){

 QSqlQueryModel* model =new QSqlQueryModel();
 model->setQuery("SELECT* FROM PRODUITS where etat!=0 and etat!=1");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("identifiant"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom_produit"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
 model->setHeaderData(6, Qt::Horizontal,QObject::tr("etat"));
 model->setHeaderData(7, Qt::Horizontal,QObject::tr("type"));


 return model;
}
bool Produit::modifierProduit()
{
   QSqlQuery query;
   QString id_string= QString::number(id_produit);
    QString refer_string= QString::number(reference);
    QString prix_string= QString::number(prix);
    QString etat_string= QString::number(etat);

   query.prepare("update PRODUITS set id_produit=:id_produit,reference=:reference,prix=:prix,date_ajout_produit=:date_ajout_produit,nom_produit=:nom_produit,quantite=:quantite,etat=:etat,type=:type where id_produit=:id_produit");
   query.bindValue(":id_produit",id_string);
   query.bindValue(":reference",refer_string);
   query.bindValue(":prix",prix_string);
   query.bindValue(":date_ajout_produit",date_ajout_produit);
   query.bindValue(":nom_produit",nom_produit);
   query.bindValue(":quantite",quantite);
   query.bindValue(":etat",etat_string);
   query.bindValue(":type",type);

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
model->setHeaderData(6, Qt::Horizontal,QObject::tr("etat"));
model->setHeaderData(7, Qt::Horizontal,QObject::tr("type"));

return model ;
}

QSqlQueryModel * Produit::triparnomAc()
  {
      QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM PRODUITS order by nom_produit ASC");
               q->exec();
               model->setQuery(*q);
               model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
               model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
               model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
               model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
               model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom du produit"));
               model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
               model->setHeaderData(6, Qt::Horizontal,QObject::tr("etat"));
               model->setHeaderData(7, Qt::Horizontal,QObject::tr("type"));

               return model;

  }

  QSqlQueryModel * Produit::trieparnomDec()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM Produits order by NOM_PRODUIT DESC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
                   model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
                   model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
                   model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
                   model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom du produit"));
                   model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
                   model->setHeaderData(6, Qt::Horizontal,QObject::tr("etat"));
                   model->setHeaderData(7, Qt::Horizontal,QObject::tr("type"));

                   return model;
  }

  QSqlQueryModel * Produit::triepardateASC()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM Produits order by date_ajout_produit ASC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
                   model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
                   model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
                   model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
                   model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom du produit"));
                   model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
                   model->setHeaderData(6, Qt::Horizontal,QObject::tr("etat"));
                   model->setHeaderData(7, Qt::Horizontal,QObject::tr("type"));

                   return model;
  }
  QSqlQueryModel * Produit::etatenpanne()
  {
      QSqlQueryModel * model= new QSqlQueryModel();
cout <<"le produit est en panne"<<endl;
      model->setQuery("SELECT * FROM PRODUITS where (etat=0)" );

model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom du produit"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("etat"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("type"));


      return model ;

      }
  QSqlQueryModel * Produit::etatdetraitement()
  {
      QSqlQueryModel * model= new QSqlQueryModel();
cout <<"le produit est en cours de traitement"<<endl;
      model->setQuery("SELECT * FROM PRODUITS where (etat=1)" );

model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom du produit"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("etat"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("type"));



      return model ;

      }


  QSqlQueryModel * Produit::etatregler()
  {
      QSqlQueryModel * model= new QSqlQueryModel();
cout <<"le produit est regler"<<endl;
      model->setQuery("SELECT * FROM PRODUITS where (etat=2)" );

model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prix"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom du produit"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("etat"));
model->setHeaderData(7, Qt::Horizontal,QObject::tr("type"));

QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
notifyIcon->setIcon(QIcon("notification.jpg"));
//notifyIcon->setVisible(1);
notifyIcon->show();
notifyIcon->showMessage("notification","produit réglé !",QSystemTrayIcon::Information,15000);
      return model ;

  }


 // QSqlQueryModel * Produit::ravitaillement()
 // { float nbr=0;
  //    QSqlQueryModel * model= new QSqlQueryModel();
  //    model->setQuery("SELECT * FROM commandes where (quantite_commande=0)" );
   //   nbr++;
//model->setHeaderData(0, Qt::Horizontal,QObject::tr("nom"));
//model->setHeaderData(1, Qt::Horizontal,QObject::tr("id_commande"));
//model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
//model->setHeaderData(3, Qt::Horizontal,QObject::tr("adresse"));
//model->setHeaderData(4, Qt::Horizontal,QObject::tr("mail"));
//model->setHeaderData(5, Qt::Horizontal,QObject::tr("quantite"));
//model->setHeaderData(6, Qt::Horizontal,QObject::tr("prix_total"));
      //return model ;

//


  ravitaillement::ravitaillement(int a,int b,int c,QString d,QString e,QString f,int g,QString h,int nombre):Produit(a,b,c, d,e,f,g,h){

      this->nombre=nombre;

  }


 // QSqlQueryModel * Produit::ajouteraustock()

 // {
    //  QSqlQuery * q = new  QSqlQuery ();
       //     QSqlQuery * q2 = new  QSqlQuery ();

       //  QSqlQueryModel * model= new QSqlQueryModel();

       //  q->prepare("SELECT  nom_produit,quantite,quantite_commande FROM produits,commandes WHERE produits.id_commande=commandes.id_commande and commandes.quantite_commande=0  ");
        // q2->prepare("UPDATE produits SET quantite=:s  where id_commande in (select id_commande from commandes where  quantite_commande=0) ");
        //  q2->bindValue(":s",30);
       //  q->exec();
        //  q2->exec();

        //  model->setQuery(*q);


        //  model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_produit"));
        //  model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
         // model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite_commande"));


        // return model ;

 // }

  QSqlQueryModel * Produit::ajouteraustock()

  {
      QSqlQuery * q = new  QSqlQuery ();
            QSqlQuery * q2 = new  QSqlQuery ();

         QSqlQueryModel * model= new QSqlQueryModel();

         q->prepare("SELECT  nom_produit,quantite_commande FROM produits,commandes WHERE produits.id_commande=commandes.id_commande and commandes.quantite_commande=0  ");
         q2->prepare("UPDATE commandes SET quantite_commande=quantite_commande+20  where id_commande in (select id_commande from commandes where  quantite_commande=0) ");
          q2->bindValue(":quantite_commande",quantite);
         q->exec();
          q2->exec();

          model->setQuery(*q);


          model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_produit"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite_commande"));


         return model ;

  }
  QSqlQueryModel * Produit::deletefromstock()

  {
      QSqlQuery * q = new  QSqlQuery ();
            QSqlQuery * q2 = new  QSqlQuery ();

         QSqlQueryModel * model= new QSqlQueryModel();

         q->prepare("SELECT  nom_produit,quantite_commande FROM produits,commandes WHERE produits.id_commande=commandes.id_commande and commandes.quantite_commande>0  ");
         q2->prepare("UPDATE commandes SET quantite_commande=quantite_commande-1  where id_commande in (select id_commande from commandes where  quantite_commande>0)");
          q2->bindValue(":quantite_commande",quantite);
         q->exec();
          q2->exec();

          model->setQuery(*q);


          model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_produit"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite_commande"));


         return model ;

  }

