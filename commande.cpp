#include "commande.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QSqlQueryModel>

#include "stat_combo.h"
#include "ui_stat_combo.h"
Commande::Commande(QString n,QString p,QString a,QString m,int q,float t)
{
    this->nom=n;
    this->prenom=p;
    this->adresse=a;
    this->mail=m;
    this->quantite=q;
    this->prix_tot=t;
}
bool Commande::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(quantite);
    QString res1 = QString::number(prix_tot);
    query.prepare("insert into COMMANDE(nom,prenom,adresse,mail,quantite,prix_tot)" "values(:nom, :prenom, :adresse, :mail, :quantite, :prix)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":mail",mail);
    query.bindValue(":prix",res1);
    query.bindValue(":quantite",res);
    return query.exec();



}
QSqlQueryModel* Commande::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("select* from COMMANDE");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMAND"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix_totale"));
  return model;

}
bool Commande::supprimer(int id)
{
 QSqlQuery query;

 query.prepare("delete from COMMANDE where ID_COMMAND= :id");
 query.bindValue(":id",id);
 return query.exec();
}
bool Commande::modifier(int id)
{

    QSqlQuery query;
    QString res = QString::number(quantite);
    QString res2 = QString::number(prix_tot);
    query.prepare("update COMMANDE set nom=:nom,prenom=:prenom,adresse=:adresse,mail=:mail,quantite=:quantite,prix_tot=:prix where ID_COMMAND=:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":mail",mail);
    query.bindValue(":prix",res2);
    query.bindValue(":quantite",res);
    return query.exec();


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
qreal tot=0,c1=0,c2=0,c3=0;

q1.prepare("SELECT * FROM commande");
q1.exec();

q2.prepare("SELECT * FROM commande where(etat=0)");
q2.exec();

q3.prepare("SELECT * FROM commande WHERE (etat=1)");
q3.exec();

q4.prepare("SELECT * FROM commande WHERE (etat=2 ) ");
q4.exec();

while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}
while (q4.next()){c3++;}

c1=c1/tot;
c2=c2/tot;
c3=c3/tot;


// Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("etat=0");
        QBarSet *set1 = new QBarSet("etat=1");
        QBarSet *set2 = new QBarSet("etat=2");

        // Assign values for each bar
        *set0 << c1;
        *set1 << c2;
        *set2 << c3;


        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        series->append(set0);
        series->append(set1);
        series->append(set2);


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
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM COMMANDE");
    q1.exec();

    q2.prepare("SELECT * FROM COMMANDE WHERE (etat=0 )");
    q2.exec();

    q3.prepare("SELECT * FROM COMMANDE where(etat=1 )");
    q3.exec();

    q4.prepare("SELECT * FROM COMMANDE WHERE(etat=2) ");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("etat=0",c1);
    series->append("etat=1",c2);
    series->append("etat=2",c3);




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

