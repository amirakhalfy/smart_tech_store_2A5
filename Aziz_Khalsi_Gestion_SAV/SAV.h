#ifndef SAV_H
#define SAV_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class SAV
{
public:
    SAV(int,QString,QString,QString,QString);
    void setid_SAV(int n);
    void setdate_SAV(QString n);
    void setdescription(QString n);
    void setnom(QString n);
    void setprenom(QString n);
    int getid_SAV();
    QString getdate_SAV();
    QString getdescription();
    QString getnom();
    QString getprenom();
    bool addSAV();
    QSqlQueryModel * afficherSAV();
    bool removeSAV(int);
   bool modifierSAV(QString,QString,int,QString,QString);
   ~SAV(){}
   QSqlQueryModel *trierAc();
      QSqlQueryModel * trierDec();
      QSqlQueryModel * rechercher_SAV(int id_SAV);
    SAV();
public:
    QString  nom,prenom,date_SAV,description;
    int id_SAV;

};

#endif // SAV_H
