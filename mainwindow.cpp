#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QIntValidator>
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QTableView>
#include <QRegExpValidator>
#include<QSqlQuery>
#include<QMediaPlayer>
#include <QString>
#include <QDebug>
#include <QSqlRecord>
#include "historique.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabb->setModel(P.afficher());
ui->le_prix->setValidator(new QIntValidator(100, 999999999, this));
ui->le_quantite->setValidator(new QIntValidator(100, 999999, this));
ui->le_modifid->setValidator(new QIntValidator(100, 999999, this));
ui->le_prixmodif->setValidator(new QIntValidator(100, 999999, this));
ui->le_modifquantite->setValidator(new QIntValidator(100,999999,this));
ui->le_sup->setValidator(new QIntValidator(100,999999,this));
QRegExp rxnom("\\b[a-zA-Z]{2,10}\\b");
        QRegExpValidator *valinom =new QRegExpValidator(rxnom,this);
        ui->le_nom->setValidator(valinom);
        ui->le_modifnom->setValidator(valinom);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{    int id_produit=ui->le_id->text().toInt();

    int reference=ui->le_reference->text().toInt();
    int prix=ui->le_prix->text().toInt();
    QString nom_produit=ui->le_nom->text();
    QString quantite=ui->le_quantite->text();
    QString date_ajout_produit=ui->le_date->text();
    int etat=ui->le_etat->text().toInt();
    QString type=ui->le_type->text();


     Produit P(id_produit,reference,prix,date_ajout_produit,nom_produit,quantite,etat,type);
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
    QSqlQuery query2;
        int id_produit=ui->le_sup->text().toInt();

        query2.prepare("select id_produit from produits where id_produit=:id_produit AND ETAT!=0");
        query2.bindValue(":id_produit",id_produit);

        query2.exec();
        query2.next();
        int name=query2.value(0).toInt();


        if(name==id_produit)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("id existe\n"
                                "click cancel to exit."),QMessageBox::Cancel);

        bool test=P.supprimer(id_produit);


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

void MainWindow::on_pb_modifier_clicked()
{
    int id_produit=ui->le_modifid->text().toInt();
    int reference=ui->le_modifref->text().toInt();
    int prix=ui->le_prixmodif->text().toInt();
    QString date_ajout_produit=ui->le_modifdate->text();
    QString nom_produit=ui->le_modifnom->text();
    QString quantite=ui->le_modifquantite->text();
    int etat=ui->le_etatmodif->text().toInt();
    QString type=ui->le_modiftype->text();

     Produit P(id_produit,reference,prix,date_ajout_produit,nom_produit,quantite,etat,type);
     bool test =P.modifierProduit();
     QMessageBox msgbox;
     if(test)
        msgbox.setText("modification avec succés");


    else{
        msgbox.setText("echec de modification");
     }


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
    ui->tableView_tri->setModel(P.triparnomAc());
}

void MainWindow::on_triparnomdec_clicked()
{
     ui->tableView_tri->setModel(P.trieparnomDec());
}

void MainWindow::on_tripardate_clicked()
{
    ui->tableView_tri->setModel(P.triepardateASC());

}

void MainWindow::on_panne_clicked()
{
    ui->tabb_9->setModel(P.etatenpanne());
}

void MainWindow::on_regler_clicked()
{
    ui->tabb_9->setModel(P.etatregler());

}

void MainWindow::on_traiter_clicked()
{
    ui->tabb_9->setModel(P.etatdetraitement());

}

//void MainWindow::on_actionSon_triggered()

//{

 // son->play();
//}





void MainWindow::on_stat_clicked()
{
    s = new stat_combo();

      s->setWindowTitle("statistique ComboBox");
      s->choix_pie();
      s->show();
}










void MainWindow::on_pushButton_2_clicked()
{
    historique h;


        QString textajouter;
        int id_produit=ui->le_id->text().toInt();
        int reference=ui->le_reference->text().toInt();
        int prix=ui->le_prix->text().toInt();
        QString nom_produit=ui->le_nom->text();
        QString quantite=ui->le_quantite->text();
        QString date_ajout_produit=ui->le_date->text();
        int etat=ui->le_etat->text().toInt();
        QString type=ui->le_type->text();

                int x=0;

                  if (id_produit==0 )
                    {
                        qDebug () <<"Problem d'ajout dans la base!! ";
                              QMessageBox::critical(this,"Enregistrer","Verifier l'identifiant!");
                              x++;

                    }
                  if (reference==0 )
                    {
                        qDebug () <<"Problem d'ajout dans la base!! ";
                              QMessageBox::critical(this,"Enregistrer","Verifier l'identifiant!");
                              x++;

                    }
                  if (prix==0 )
                    {
                        qDebug () <<"Problem d'ajout dans la base!! ";
                              QMessageBox::critical(this,"Enregistrer","Verifier l'identifiant!");
                              x++;

                    }

                        if (nom_produit=="" )
                        {
                            qDebug () <<"Problem d'ajout dans la base!!";
                                  QMessageBox::critical(this,"Enregistrer","Verifier le nom!");
                                  x++;

                        }
                        if (quantite=="" )
                        {
                            qDebug () <<"Problem d'ajout dans la base!!";
                                  QMessageBox::critical(this,"Enregistrer","Verifier le nom!");
                                  x++;

                        }

                         if (date_ajout_produit=="" )
                         {
                             qDebug () <<"Problem d'ajout dans la base!!";
                                   QMessageBox::critical(this,"Enregistrer","verifier la date");
                                   x++;

                         }

                      if ((etat!=0)&&(etat!=1)&&(etat!=2))
                         {
                            QMessageBox::critical(this,"Enregistrer","verifier l'etat!");
                             x++;

                          }
                      if (type=="" )
                      {
                          qDebug () <<"Problem d'ajout dans la base!!";
                                QMessageBox::critical(this,"Enregistrer","verifier la date");
                                x++;

                      }


                if(x==0&&etat==0)
                {
                   Produit P(id_produit,reference,prix,nom_produit,quantite,date_ajout_produit,etat,type);
                  bool test=P.ajouter();
                  if(test)
                {

                QMessageBox::information(nullptr, QObject::tr("Ajouter un produit en panne "),
                                  QObject::tr("produit en panne Ajoutée.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                }
                 else
                      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit en panne"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                    }
                textajouter="L'ajout dans la base de donnees produits a ete effectuee de  avec succees id_produit ,";
                h.write(textajouter);
}


void MainWindow::on_pushButton_3_clicked()
{
    historique h;

    int verif=0;



    int id_produit=ui->le_id->text().toInt();
    qDebug()<< id_produit ;
    qDebug()<< id_produit ;
    verif= QMessageBox::question( this, "Confimation De la Suppression", "Question", QMessageBox::No | QMessageBox::Yes  );
    qDebug()<< verif ;


    if(verif==16384)
    {



    bool test=P.supprimer(id_produit);
    if(test)
    {
      //  MainWindow::makePlot();
        QMessageBox::information(nullptr, QObject::tr("Supprimer le produit en panne car il est reglé"),
                    QObject::tr("le produit qui a été en panne est  supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer le produit en panne car il est reglé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else if(verif==65536)
       {

           QMessageBox::information(nullptr, QObject::tr("Suppression est annulée"),
                       QObject::tr("Suppression est annulée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


    }
       QString textajouter;
       QModelIndex  modele =ui->tabb->currentIndex().sibling(ui->tabb->currentIndex().row(),0);
       QString value=modele.data().toString();
         qDebug () << value;
         qDebug()<< id_produit ;

       textajouter="La suppresion dans la base de donnees PRODUITS a ete effectuee avec succees";
       h.write(textajouter);
}




void MainWindow::on_pushButton_clicked()
{
    //export excel

        QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "test-bd", ui->tabb);

        //colums to export
        obj.addField(0, "id_produit", "char(20)");
        obj.addField(1, "reference", "char(20)");
        obj.addField(2, "prix", "char(20)");
        obj.addField(3, "etat", "char(20)");
        obj.addField(4, "nom_produit", "char(20)");
        obj.addField(5, "quantite", "char(20)");
        obj.addField(6, "date_ajout_produit", "char(20)");
        obj.addField(7, "type", "char(20)");



        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
    }


