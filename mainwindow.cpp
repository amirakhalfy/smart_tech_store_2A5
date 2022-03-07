#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QIntValidator>
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QTableView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabb->setModel(P.afficher());

ui->le_id->setValidator(new QIntValidator(100, 9999999, this));
ui->le_prix->setValidator(new QIntValidator(100, 999999999, this));
ui->le_quantite->setValidator(new QIntValidator(100, 999999, this));
ui->le_modifid->setValidator(new QIntValidator(100, 999999, this));
ui->le_prixmodif->setValidator(new QIntValidator(100, 999999, this));
ui->le_modifquantite->setValidator(new QIntValidator(100,999999,this));
ui->le_sup->setValidator(new QIntValidator(100,999999,this));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id_produit=ui->le_id->text().toInt();
    int reference=ui->le_reference->text().toInt();
    int prix=ui->le_prix->text().toInt();
    QString nom_produit=ui->le_nom->text();
    QString quantite=ui->le_quantite->text();
    QString date_ajout_produit=ui->le_date->text();

     Produit P(id_produit,reference,prix,date_ajout_produit,nom_produit,quantite);
     bool test=P.ajouter();
     QMessageBox msgbox;
     if(test)
        msgbox.setText("ajout avec succes");
     else
        msgbox.setText("echec d'ajout");
     msgbox.exec();
     ui->tabb->setModel(P.afficher());

}

void MainWindow::on_pb_supprimer_clicked()
{
    Produit P1 ; P1.setidproduit(ui->le_sup->text().toInt());
    bool test=P1.supprimer(P1.getidproduit());
    QMessageBox msgBox;
    if (test)
        msgBox.setText("suppression avec succés");
        else
     msgBox.setText("echec d'ajout");
     msgBox.exec();

}

void MainWindow::on_pb_modifier_clicked()
{
    int id_produit=ui->le_modifid->text().toInt();
    int reference=ui->le_modifref->text().toInt();
    int prix=ui->le_prixmodif->text().toInt();
    QString date_ajout_produit=ui->le_modifdate->text();
    QString nom_produit=ui->le_modifnom->text();
    QString quantite=ui->le_modifquantite->text();
     Produit P(id_produit,reference,prix,date_ajout_produit,nom_produit,quantite);
     bool test =P.modifierProduit();
     QMessageBox msgbox;
     if(test)
        msgbox.setText("modification avec succés");
     else
        msgbox.setText("echec de modification");
     msgbox.exec();
}



void MainWindow::on_pushButton_5_clicked()
{
    ui->tabb->setModel(P.afficher());

}



void MainWindow::on_rechercher_clicked()
{
    QString nom_produit=ui->nom->text();
    ui->tabb->setModel(P.rechercher(nom_produit)) ;

}

void MainWindow::on_triparnom_clicked()
{
    QString nom_produit=ui->triparnom_2->text();
    ui->tabb->setModel(P.tri_nomproduit()) ;
}
