#ifndef REMBOURSEMENT_H
#define REMBOURSEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class remboursement
{
    public:
 int prix,id_sav;

public :
  remboursement(int,int);
 void setprix_remboursement(int n);
 int getprix_remboursement();
 bool addremboursement();
 QSqlQueryModel * remboursementSAV();
  QSqlQueryModel * afficherremboursement();
 ~remboursement(){}
 remboursement();
};

#endif // REMBOURSEMENT_H
