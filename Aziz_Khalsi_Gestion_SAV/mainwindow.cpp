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
        date_SAV=ui->lineEdit_DateSAV->text();
        description=ui->lineEdit_description->text();
        ui->tableView->setModel(tmpSAV.afficherSAV());


        SAV c(id_SAV,nom,prenom,date_SAV,description);
        c.addSAV();


}

void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpSAV.afficherSAV());
}

void MainWindow::on_supprimer_clicked()
{
    int id_SAV=ui->lineEditCin_supp->text().toInt();
        tmpSAV.removeSAV(id_SAV);
        ui->tableView->setModel(tmpSAV.afficherSAV());

}

void MainWindow::on_modifier_clicked()
{
int id_SAV;
    QString nom,prenom,date_SAV,description;
id_SAV=ui->lineEditCin_modif->text().toInt();
        nom=ui->lineEdit_nom_modif->text();
        prenom=ui->lineEdit_pren_modif->text();
        date_SAV=ui->lineEdit_DateSAV_modif->text();
        description=ui->lineEdit_description_modif->text();

       tmpSAV.modifierSAV(nom,prenom,id_SAV,date_SAV,description);
       ui->tableView->setModel(tmpSAV.afficherSAV());

}


