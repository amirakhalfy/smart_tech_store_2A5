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
 int  total_produit(int total){
     return total--;
 };

list<Produit> l;
private:
 int id_produit,reference,prix,etat;
 QString nom_produit,quantite,date_ajout_produit,type;

};
class statproduit:public Produit{

public:
    statproduit(){}
    ~statproduit(){}
   float pourcentagequantite;
   float pourcentageprix;






};

#endif // PRODUIT_H
