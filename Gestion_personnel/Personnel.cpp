#include "Personnel.h"
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlRecord>
#include "stat_combo.h"
#include "ui_stat_combo.h"
using namespace std;

Personnel::Personnel()
{
             cin=0;
             nom="";
             prenom="";

}
Personnel::Personnel(int cin, QString nom,  QString prenom)
{
            this->cin=cin;
            this->nom=nom;
            this->prenom=prenom;

}

void Personnel::setcin(int n){
       cin=n;

}
void Personnel::setprenom(QString n){
       prenom=n;
}
    void Personnel::setnom(QString n){
        nom=n;
}

    int Personnel::getcin(){
        return cin;
    }
    QString Personnel::getprenom(){
        return prenom;
    }
    QString Personnel::getnom(){
        return nom;
    }

    bool Personnel::addPersonnel(){
        QSqlQuery query;
        QString res =QString::number(cin);
        query.prepare("INSERT INTO PERSONNEL (CIN, NOM, PRENOM)"
                      "VALUES(:CIN, :NOM, :PRENOM)");
        query.bindValue(":CIN",res);
        query.bindValue(":NOM",nom);
        query.bindValue(":PRENOM",prenom);


        return query.exec();
    }



    bool Personnel::removePersonnel(int cin){
    QSqlQuery query;

    query.prepare("DELETE FROM PERSONNEL WHERE CIN = :CIN");
    query.bindValue(":CIN", cin);

    return    query.exec();
    }

    bool Personnel::modifierPersonnel(QString nom,QString prenom,int cin)
{ QSqlQuery query;
            query.prepare("update PERSONNEL set nom=:nom,prenom=:prenom where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
            return    query.exec();

    }

  QSqlQueryModel * Personnel::afficherPersonnel()
  {

            QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from PERSONNEL");


            return model;
        }

  QSqlQueryModel * Personnel::rechercher_perso(int cin)
   {
      QString res=QString::number(cin);

          QSqlQuery qry;


           qry.prepare("SELECT* FROM PERSONNEL where cin=:cin");
           qry.bindValue(":cin",res);
           qry.exec();
           QSqlQueryModel *model= new QSqlQueryModel;
      model->setQuery(qry);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));



   return model ;
   }
  QSqlQueryModel * Personnel::rechercher_congee(int etat_congee)
   {


          QSqlQuery qry;


           qry.prepare("SELECT* FROM PERSONNEL where etat_congee=:etat_congee ");
           qry.bindValue(":etat_congee",etat_congee);
           qry.exec();
           QSqlQueryModel *model= new QSqlQueryModel;
      model->setQuery(qry);






   return model ;
   }
  QSqlQueryModel * Personnel::rechercher_perso_nom(QString nom)
   {

      QSqlQuery * q = new  QSqlQuery ();
         QSqlQueryModel * model= new QSqlQueryModel();



           q->prepare("SELECT* FROM PERSONNEL where nom LIKE '"+nom+"%'");

           q->exec();
              model->setQuery(*q);

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));



   return model ;
   }
  QSqlQueryModel * Personnel::trierAc()
  {
      QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM PERSONNEL order by cin ASC");
               q->exec();
               model->setQuery(*q);
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));

               return model;

  }

  QSqlQueryModel * Personnel::trierDec()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM PERSONNEL order by cin DESC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));

                   return model;
  }
  QSqlQueryModel * Personnel::triernom()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM PERSONNEL order by nom ASC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));

                   return model;
  }


  bool Personnel::add_prime_Personnel(int prime,int cin)
{ QSqlQuery query;
          query.prepare("update PERSONNEL set prime=:prime where cin=:cin");
          query.bindValue(":cin",cin);
           query.bindValue(":prime", prime);

          return    query.exec();

  }

  QSqlQueryModel * Personnel::stat()
  {



           QSqlQuery qry,qry1;



            qry1.prepare("SELECT avg(prime) FROM PERSONNEL  ");
            qry1.exec();

            QSqlQueryModel *model= new QSqlQueryModel;


        model->setQuery(qry1);



    return model ;






            return model;
        }
  QSqlQueryModel * Personnel::stat1()
  {



           QSqlQuery qry,qry1;


            qry.prepare("SELECT avg(salaire) FROM PERSONNEL  ");
            qry.exec();

            QSqlQueryModel *model= new QSqlQueryModel;
       model->setQuery(qry);





    return model ;






            return model;
        }
  bool Personnel::add_congee_Personnel(QDate congee_from,QDate congee_to,int cin)
{ QSqlQuery query;
          query.prepare("update PERSONNEL set etat_congee= 1,congee_from=:congee_from,congee_to=:congee_to where cin=:cin");

          query.bindValue(":cin",cin);
           query.bindValue(":congee_from", congee_from);
            query.bindValue(":congee_to", congee_to);
            query.bindValue(":etat_congee", etat_congee);
          return    query.exec();

  }
  bool Personnel::remove_congee_Personnel(int cin)
{ QSqlQuery query;
          query.prepare("update PERSONNEL set etat_congee= 0, congee_from= null,congee_to= null where cin=:cin");

          query.bindValue(":cin",cin);

          return    query.exec();

  }


  stat_combo::stat_combo(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::stat_combo)
  {
      ui->setupUi(this);
  }

  stat_combo::~stat_combo()
  {
      delete ui;
  }


  //bar chart
  void stat_combo::choix_bar()
  {
  QSqlQuery q1,q2,q3,q4;
  qreal tot=0,c1=0,c2=0;

  q1.prepare("SELECT * FROM PERSONNEL");
  q1.exec();

  q2.prepare("SELECT * FROM PERSONNEL where etat_congee= 0 ");
  q2.exec();

  q3.prepare("SELECT * FROM PERSONNEL where etat_congee= 1  ");
  q3.exec();



  while (q1.next()){tot++;}
  while (q2.next()){c1++;}
  while (q3.next()){c2++;}


  c1=c1/tot;
  c2=c2/tot;



  // Assign names to the set of bars used
          QBarSet *set0 = new QBarSet("non_congee=0");
          QBarSet *set1 = new QBarSet("congee=1");


          // Assign values for each bar
          *set0 << c1;
          *set1 << c2;



          // Add all sets of data to the chart as a whole
          // 1. Bar Chart
          QBarSeries *series = new QBarSeries();

          // 2. Stacked bar chart
          series->append(set0);
          series->append(set1);



          // Used to define the bar chart to display, title
          // legend,
          QChart *chart = new QChart();

          // Add the chart
          chart->addSeries(series);


          // Adds categories to the axes
         // QBarCategoryAxis *axis = new QBarCategoryAxis();



          // 1. Bar chart
         // chart->setAxisX(axis, series);

          // Used to change the palette
          QPalette pal = qApp->palette();

          // Change the color around the chart widget and text
          pal.setColor(QPalette::Window, QRgb(0xfffeff));
          pal.setColor(QPalette::WindowText, QRgb(0x404144));

          // Apply palette changes to the application
          qApp->setPalette(pal);


  // Used to display the chart

  chartView = new QChartView(chart,ui->label_stat);
  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->setMinimumSize(400,400);

  chartView->show();
  }

  //pie chart
      void stat_combo::choix_pie()
      {
      QSqlQuery q1,q2,q3;
      qreal tot=0,c1=0,c2=0;

      q1.prepare("SELECT * FROM PERSONNEL");
      q1.exec();

      q2.prepare("SELECT * FROM PERSONNEL where etat_congee= 0");
      q2.exec();

      q3.prepare("SELECT * FROM PERSONNEL where etat_congee= 1");
      q3.exec();



      while (q1.next()){tot++;}
      while (q2.next()){c1++;}
      while (q3.next()){c2++;}


      c1=c1/tot;
      c2=c2/tot;

       tot=c1+c2;
                                      QString a=QString("moins de 100 dt "+QString::number((c1)/tot,'f',2)+"%" );
                                      QString b=QString("entre 100et 999dt "+QString::number((c2)/tot,'f',2)+"%" );
                                      QPieSeries *series = new QPieSeries();
                                      series->append(a,c1);
                                      series->append(b,c2);

      // Define slices and percentage of whole they take up

      series->append("etat=0",c1);
      series->append("etat=1",c2);





      // Create the chart widget
      QChart *chart = new QChart();

      // Add data to chart with title and show legend
      chart->addSeries(series);
      chart->legend()->show();


      // Used to display the chart
      chartView = new QChartView(chart,ui->label_stat);
      chartView->setRenderHint(QPainter::Antialiasing);
      chartView->setMinimumSize(400,400);

      chartView->show();
      }


