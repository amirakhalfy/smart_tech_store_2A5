#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QDate>

class Personnel
{
public:
    Personnel(int,QString,QString);
    void setcin(int n);
    void setprenom(QString n);
    void setnom(QString n);
    int getcin();
    QString getprenom();
    QString getnom();
    bool addPersonnel();
    QSqlQueryModel * afficherPersonnel();
    bool removePersonnel(int);
   bool modifierPersonnel(QString,QString,int);
   QSqlQueryModel * rechercher_perso(int cin);
   QSqlQueryModel * rechercher_perso_nom(QString nom);
   QSqlQueryModel *trierAc();
   QSqlQueryModel * trierDec();
   QSqlQueryModel * triernom();
   bool add_prime_Personnel(int prime,int cin);
   bool add_congee_Personnel(QDate congee_from,QDate congee_to,int cin);
    bool remove_congee_Personnel(int cin);
      QSqlQueryModel * rechercher_congee(int etat_congee);
      QSqlQueryModel * stat1();
void on_supprimer_3_clicked();
     QSqlQueryModel * stat();

   ~Personnel(){}

    Personnel();
private:
    QString  prenom,nom;
    int cin,prime,etat_congee,salaire;
     QDate congee_from,congee_to;

};

#endif // PERSONNEL_H
