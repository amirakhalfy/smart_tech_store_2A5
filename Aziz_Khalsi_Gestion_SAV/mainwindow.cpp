#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SAV.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>

using std::uint8_t;
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpSAV.afficherSAV());

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
