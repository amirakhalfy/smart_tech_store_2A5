#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>
#include <list>
#include <iostream>
#include<vector>

using namespace std;


class Produit

{
public:
    Produit(){}
   ~Produit(){}
    Produit(int,int,int,QString,QString,QString,int,QString);

int getidproduit();
int getreference();
int getprix();
int getetat();
int getquantitec();

QString getnomproduit();
QString getquantite();
QString getdate();
QString gettype();

void setidproduit(int);
void setreference(int);
void setprix(int);
void setdate(QString);
void setnomproduit(QString);
void setquantite(QString);
void setetat(int);
void settype(QString);

bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int);
bool modifierProduit();
 QSqlQueryModel* rechercher(QString);
 QSqlQueryModel *triparnomAc();
  QSqlQueryModel * trieparnomDec();
  QSqlQueryModel * triepardateASC();
  QSqlQueryModel * etatenpanne();
  QSqlQueryModel * etatdetraitement();
  QSqlQueryModel * etatregler();
 QSqlQueryModel * afficherstat();
 QSqlQueryModel * ravitaillement();
 QSqlQueryModel * ajouteraust(int n);
 QSqlQueryModel *ajouteraustock();
 QSqlQueryModel * deletefromstock(int id);


 int  total_produit(int total){
     return total--;
 };

list<Produit> l;
protected:
 int id_produit,reference,prix,etat,quantite_c;
 QString nom_produit,quantite,date_ajout_produit,type;

};
class ravitaillement:public Produit{

public:
    ravitaillement(){}
    ~ravitaillement(){}

    ravitaillement(int a, int b, int c, QString d, QString, QString, int, QString, int);
int nombre;
QSqlQueryModel *ajouteraustoc();
void setnombre(int nombre){
 this->nombre=nombre;

}
int getnombre(){
  return nombre;

}








};

#endif // PRODUIT_H
