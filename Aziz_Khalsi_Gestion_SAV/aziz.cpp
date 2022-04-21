#include "aziz.h"
#include "ui_aziz.h"
#include "SAV.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>
#include <QMessageBox>
#include <QApplication>
#include<QSqlQueryModel>
#include <string>
#include <QTextStream>
#include "stat_combo.h"
#include <ui_stat_combo.h>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>
#include "remboursement.h"


using std::uint8_t;
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpSAV.afficherSAV());

    int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).
             //A.write_to_arduino("0");
             A.read_from_arduino();
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label2())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).
             //A.write_to_arduino("0");
             A.read_from_arduino();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    QString nom,prenom,date_SAV,description;
    int id_SAV;
    id_SAV=ui->lineEditCin->text().toInt();
        nom=ui->lineEdit_nom->text();
        prenom=ui->lineEdit_pren->text();
        description=ui->lineEdit_description->text();
        date_SAV=ui->lineEdit_DateSAV->text();



        SAV c(id_SAV,nom,prenom,date_SAV,description);

      bool test =  c.addSAV();
        if(test)
        {


        QMessageBox::information(nullptr, QObject::tr("ajouter un SAV"),
                          QObject::tr("SAV ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);



        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("ajouter un SAV"),
                          QObject::tr("Erreur ! SAV existant\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


        }


}



void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpSAV.afficherSAV());
}

void MainWindow::on_supprimer_clicked()
{
    QSqlQuery query2;
    int id_sav=ui->lineEditCin_supp->text().toInt();

    query2.prepare("select id_sav from sav where id_sav=:id_sav");
    query2.bindValue(":id_sav",id_sav);

    query2.exec();
    query2.next();
    int name=query2.value(0).toInt();


    if(name==id_sav && id_sav!=0)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("id existe\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    bool test=tmpSAV.removeSAV(id_sav);


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



void MainWindow::on_modifier_clicked()
{
    QSqlQuery query2;

    int id_SAV;
        QString nom,prenom,date_SAV,description;

        id_SAV=ui->lineEditCin_modif->text().toInt();

                nom=ui->lineEdit_nom_modif->text();
                prenom=ui->lineEdit_pren_modif->text();
                date_SAV=ui->lineEdit_DateSAV_modif->text();
                description=ui->lineEdit_description_modif->text();

        query2.prepare("SELECT id_SAV FROM SAV WHERE id_SAV = :id_SAV");
        query2.bindValue(":id_SAV",id_SAV);
        query2.exec();
        query2.next();
        int name=query2.value(0).toInt();
        cout<<name;

    bool test =tmpSAV.modifierSAV(nom,prenom,id_SAV,date_SAV,description);
    if(name==id_SAV && id_SAV!=0)
    {
        QMessageBox::critical(nullptr, QObject::tr("SAV existant"),
                          QObject::tr("SAV existant.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);



    if(test)
    {


    QMessageBox::information(nullptr, QObject::tr("modifier un SAV"),
                      QObject::tr("SAV modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("modifier une SAV"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("id non ex"),
                    QObject::tr("SAV n'existe pas.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }



}

void MainWindow::on_pushButton_TriASC_clicked()
{
    ui->tableView_tri->setModel(tmpSAV.trierAc());
}

void MainWindow::on_pushButton_TriDESC_clicked()
{
    ui->tableView_tri->setModel(tmpSAV.trierDec());
}

void MainWindow::on_rechercher_clicked()
{
    int id_SAV=ui->lineEdit_rechercher->text().toInt() ;
        ui->tableView_rechercher->setModel(tmpSAV.rechercher_SAV(id_SAV)) ;

}

void MainWindow::on_pushButton_5_clicked()
{

    QSqlQuery query,query2;
     int id_sav=ui->id->text().toInt();

     query2.prepare("select id_sav from sav where id_sav=:id_sav");
     query2.bindValue(":id_sav",id_sav);

     query2.exec();
     query2.next();
     int name=query2.value(0).toInt();

    query.prepare("update SAV set ETAT = 1 where ID_SAV=:id_sav");
    query.bindValue(":id_sav",id_sav);

    if(name==id_sav && id_sav!=0)
        A.write_to_arduino("1");


else
        A.write_to_arduino("0");


     query.exec();

}

void MainWindow::on_pushButton_6_clicked()
{
   stat_combo *s= new stat_combo();

         s->setWindowTitle("statistique ComboBox");
         s->choix_pie();
         s->show();
}


void MainWindow::on_ajouter_2_clicked()
{
    int id_sav,prix;
      QSqlQuery query2;
    id_sav=ui->lineEditcin->text().toInt();
    prix=ui->lineEditprix->text().toInt();


        remboursement c(prix,id_sav);
        query2.prepare("select id_sav from sav where id_sav=:id_sav");
        query2.bindValue(":id_sav",id_sav);

        query2.exec();
        query2.next();
        int name=query2.value(0).toInt();


        if(name==id_sav && id_sav!=0)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("id existe\n"
                                "click cancel to exit."),QMessageBox::Cancel);

           remboursement c(prix,id_sav);

          bool test =  c.addremboursement();


        if(test )
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectué\n"
                                "click cancel to exit."),QMessageBox::Cancel);

        }
        else
            QMessageBox::information(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout non effectué\n"
                                "click cancel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("id n'existe pas\n"
                                "click cancel to exit."),QMessageBox::Cancel);

        ui->tableView_remboursement->setModel(tmpremboursement.afficherremboursement());

}

void MainWindow::on_supprimer_2_clicked()
{
    QSqlQuery query2;
    int id_sav=ui->lineEditsupp_2->text().toInt();

    query2.prepare("select id_sav from sav where id_sav=:id_sav");
    query2.bindValue(":id_sav",id_sav);

    query2.exec();
    query2.next();
    int name=query2.value(0).toInt();


    if(name==id_sav && id_sav!=0)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("id existe\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    bool test=tmpremboursement.removeremboursement(id_sav);


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
    ui->tableView_remboursement->setModel(tmpremboursement.afficherremboursement());

}



void MainWindow::on_supprimer_3_clicked()
{
    ui->tableView_remboursement->setModel(tmpremboursement.afficherremboursement());

}
