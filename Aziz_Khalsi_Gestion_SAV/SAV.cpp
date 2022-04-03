#include "SAV.h"
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

using namespace std;

SAV::SAV()
{

   id_SAV=0;
             nom="";
             prenom="";
             date_SAV="";
             description="";

}
SAV::SAV(int id_SAV, QString nom,  QString prenom , QString date_SAV , QString description)
{
            this->id_SAV=id_SAV;
            this->nom=nom;
            this->prenom=prenom;
            this->date_SAV=date_SAV;
            this->description=description;

}

void SAV::setid_SAV(int n){
    id_SAV=n;

}
void SAV::setprenom(QString n){
    prenom=n;
}
    void SAV::setnom(QString n){
        nom=n;
}

        void SAV::setdate_SAV(QString n){
            date_SAV=n;
    }
        void SAV::setdescription(QString n){
            description=n;
    }

        int SAV::getid_SAV(){
                return id_SAV;
            }
    QString SAV::getprenom(){
        return prenom;
    }
    QString SAV::getnom(){
        return nom;
    }

    QString SAV::getdate_SAV(){
        return date_SAV;
    }
    QString SAV::getdescription(){
        return description;
    }

    bool SAV::addSAV(){
        QSqlQuery query;
        query.prepare("INSERT INTO SAV (ID_SAV, NOM, PRENOM, DATE_SAV, DESCRIPTION)"
                      "VALUES(:ID_SAV, :NOM, :PRENOM, :DATE_SAV, :DESCRIPTION)");
        query.bindValue(":ID_SAV",id_SAV);
        query.bindValue(":NOM",nom);
        query.bindValue(":PRENOM",prenom);
        query.bindValue(":DATE_SAV",date_SAV);
        query.bindValue(":DESCRIPTION",description);


        return query.exec();
    }



    bool SAV::removeSAV(int id_SAV){
    QSqlQuery query;
    query.prepare("DELETE FROM SAV WHERE ID_SAV = :ID_SAV");
    query.bindValue(":ID_SAV", id_SAV);
    return    query.exec();
    }

    bool SAV::modifierSAV(QString nom,QString prenom,int id_SAV,QString date_SAV,QString description)
{ QSqlQuery query;
            query.prepare("update sav set nom=:nom,prenom=:prenom,date_SAV=:date_SAV,description=:description where id_SAV=:id_SAV");
            query.bindValue(":id_SAV",id_SAV);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
               query.bindValue(":date_SAV", date_SAV);
               query.bindValue(":description", description);

            return    query.exec();

    }

  QSqlQueryModel * SAV::afficherSAV()
  {

            QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from sav");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_SAV"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_SAV"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat"));


            return model;
        }


  QSqlQueryModel * SAV::trierAc()
    {
        QSqlQuery * q = new  QSqlQuery ();
                 QSqlQueryModel * model = new  QSqlQueryModel ();
                 q->prepare("SELECT * FROM SAV order by id_SAV ASC");
                 q->exec();
                 model->setQuery(*q);
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_SAV"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                  model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_SAV"));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("description"));
                    model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat"));

                 return model;

    }

    QSqlQueryModel * SAV::trierDec()
    {
              QSqlQuery * q = new  QSqlQuery ();
                     QSqlQueryModel * model = new  QSqlQueryModel ();
                     q->prepare("SELECT * FROM SAV order by id_SAV DESC");
                     q->exec();
                     model->setQuery(*q);
                     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_SAV"));
                    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_SAV"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("description"));
                        model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat"));

                     return model;
    }


    QSqlQueryModel * SAV::rechercher_SAV(int id_SAV)
       {
          QString res=QString::number(id_SAV);

              QSqlQuery qry;


               qry.prepare("SELECT* FROM SAV where id_SAV=:id_SAV");
               qry.bindValue(":id_SAV",res);
               qry.exec();
               QSqlQueryModel *model= new QSqlQueryModel;
          model->setQuery(qry);

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_SAV"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_SAV"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("description"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat"));



       return model ;
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
    QSqlQuery q1,q2,q3;
    qreal tot=0,c1=0,c2=0;

    q1.prepare("SELECT * FROM SAV");
    q1.exec();

    q2.prepare("SELECT * FROM SAV where(etat=0)");
    q2.exec();

    q3.prepare("SELECT * FROM SAV WHERE (etat=1)");
    q3.exec();


    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}

    c1=c1/tot;
    c2=c2/tot;


    // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("Sav traité");
            QBarSet *set1 = new QBarSet("Sav Non traité");

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
            pal.setColor(QPalette::Window, QRgb(0xffffff));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));

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

        q1.prepare("SELECT * FROM SAV");
        q1.exec();

        q2.prepare("SELECT * FROM SAV WHERE (etat=0 )");
        q2.exec();

        q3.prepare("SELECT * FROM SAV where(etat=1 )");
        q3.exec();


        while (q1.next()){tot++;}
        while (q2.next()){c1++;}
        while (q3.next()){c2++;}

        c1=c1/tot;
        c2=c2/tot;

        // Define slices and percentage of whole they take up
        QPieSeries *series = new QPieSeries();
        series->append("Sav traité",c1);
        series->append("Sav Non traité",c2);




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
