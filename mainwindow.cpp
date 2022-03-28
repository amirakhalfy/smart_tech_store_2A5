#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include <QApplication>
#include<QSqlQueryModel>
#include <string>
#include <iostream>

#include "stat_combo.h"
#include <ui_stat_combo.h>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_commande->setModel(cm.afficher());

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select nom from produit");
    ui->comboBox->setModel(model);
    ui->comboBox_2->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString prod= ui->comboBox->currentText();
     QSqlQuery query,query2,query3,query4;
     query.prepare("select PRIX from PRODUIT where NOM= :nom");
    query.bindValue(":nom",prod);
    query.exec();
    query.next();
    float prix=query.value(0).toFloat();


    int res=ui->lineEdit_quantite->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString mail=ui->lineEdit_mail->text();
    query2.prepare("select nom from COMMANDE where NOM=:nom");
    query2.bindValue(":nom",nom);

    query2.exec();
    query2.next();
    QString name=query2.value(0).toString();

    if(name==nom)
    {


        query3.prepare("select PRIX_TOT from COMMANDE where NOM= :nom");
       query3.bindValue(":nom",nom);
       query3.exec();
       query3.next();
       float prix_tot=query.value(0).toFloat();













        float somme=prix_tot+prix*res;
        cout<<somme;
        QString res2 = QString::number(somme);



        query4.prepare("update COMMANDE set prix_tot=:prix where NOM=:nom");

        query4.bindValue(":prix",res2);

        query4.bindValue(":nom",nom);

        query4.exec();


    }
    else
    {
    Commande C(nom,prenom,adresse,mail,res,prix*res);
    bool test=C.ajouter();
    if(test )
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajouter effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                QObject::tr("ajouter non effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query2;
    int id=ui->lineEdit_supp->text().toInt();

    query2.prepare("select id_command from COMMANDE where id_command=:id");
    query2.bindValue(":id",id);

    query2.exec();
    query2.next();
    int name=query2.value(0).toInt();
    cout<<name;


    if(name==id)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("id existe\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    bool test=cm.supprimer(id);







    if(test )
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("supprimer effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                QObject::tr("supprimer non effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);
}
    else
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("id n'existe pas\n"
                            "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{QString prod= ui->comboBox_2->currentText();

     QSqlQuery query,query2;
     query.prepare("select PRIX from PRODUIT where NOM= :nom");
    query.bindValue(":nom",prod);
    query.exec();
    query.next();
    float prix=query.value(0).toFloat();
cout<<prix;



    int id=ui->lineEdit_idmodif->text().toInt();
    int res=ui->lineEdit_55->text().toInt();
    QString nom=ui->lineEdit_1->text();
    QString prenom=ui->lineEdit_2->text();
    QString adresse=ui->lineEdit_3->text();
    QString mail=ui->lineEdit_4->text();
    Commande C(nom,prenom,adresse,mail,res,prix*res);



    bool test=C.modifier(id);
    if(test )
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("modifier effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                QObject::tr("modifier non effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    QString nom=ui->recherche->text();

    query.prepare("select* from COMMANDE where NOM= :nom");
    query.bindValue(":nom",nom);
    query.exec();

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMAND"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix_totale"));


     ui->tableView_recherche->setModel(model);


}

void MainWindow::on_tri_clicked()
{





    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select* from COMMANDE order by PRIX_TOT desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMAND"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix_totale"));


     ui->table_view_tri->setModel(model);


}

void MainWindow::on_tri_2_clicked()
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select* from COMMANDE order by PRIX_TOT ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMAND"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix_totale"));


     ui->table_view_tri_2->setModel(model);

}

void MainWindow::on_pushButton_5_clicked()
{

    QSqlQuery query;
     int id=ui->id->text().toInt();

    query.prepare("update COMMANDE set etat= 1 where ID_COMMAND=:id");
    query.bindValue(":id",id);

     query.exec();

}

void MainWindow::on_pushButton_6_clicked()
{
   stat_combo *s= new stat_combo();

         s->setWindowTitle("statistique ComboBox");
         s->choix_pie();
         s->show();
}
