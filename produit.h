#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>
#include <list>
#include <iostream>

class Produit
{
public:
    Produit(){}
   ~Produit(){}
    Produit(int,int,int,QString,QString,QString);
int getidproduit();
int getreference();
int getprix();
QString getnomproduit();
QString getquantite();
QString getdate();
void setidproduit(int);
void setreference(int);
void setprix(int);
void setdate(QString);
void setnomproduit(QString);
void setquantite(QString);

bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int);
bool modifierProduit();
 QSqlQueryModel* rechercher(QString);
  QSqlQueryModel * tri_nomproduit();

private:
 int id_produit,reference,prix;
 QString nom_produit,quantite,date_ajout_produit;

};

#endif // PRODUIT_H
