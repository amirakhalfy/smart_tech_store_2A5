#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Personnel.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>
#include "stat_combo.h"
#include <ui_stat_combo.h>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>

using std::uint8_t;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
    int cin;
        QString nom,prenom;
        cin=ui->lineEditCin->text().toInt();

        nom=ui->lineEdit_nom->text();
        prenom=ui->lineEdit_pren->text();
        ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

        Personnel P(cin,nom,prenom);

              bool test =  P.addPersonnel();
                if(test)
                {


                QMessageBox::information(nullptr, QObject::tr("ajouter un personnels"),
                                  QObject::tr("personnel ajouté.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                }
                  else{
                      QMessageBox::critical(nullptr, QObject::tr("ajouter une personnel"),
                                  QObject::tr("Erreur ! personnel existant\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                }

}


void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}

void MainWindow::on_supprimer_clicked()
{
    QSqlQuery query2;
    int cin=ui->lineEditCin_supp->text().toInt();



         query2.prepare("select cin from personnel where cin=:cin");
         query2.bindValue(":cin",cin);

         query2.exec();
         query2.next();
         int name=query2.value(0).toInt();


         if(name==cin && cin!=0)
         {
             QMessageBox::information(nullptr, QObject::tr("ok"),
                     QObject::tr("cin existe\n"
                                 "click cancel to exit."),QMessageBox::Cancel);

         bool test=tmpPersonnel.removePersonnel(cin);

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
                     QObject::tr("cin n'existe pas\n"
                                 "click cancel to exit."),QMessageBox::Cancel);

     }




void MainWindow::on_modifier_clicked()
{
    QSqlQuery query2;
    int cin;
        QString nom,prenom;

        cin=ui->lineEditCin_modif->text().toInt();
        nom=ui->lineEdit_nom_modif->text();
        prenom=ui->lineEdit_pren_modif->text();

       tmpPersonnel.modifierPersonnel(nom,prenom,cin);
       Personnel P(cin,nom,prenom);
       query2.prepare("SELECT CIN FROM personnel WHERE cin = :cin");
               query2.bindValue(":cin",cin);
               query2.exec();
               query2.next();
               int name=query2.value(0).toInt();

        bool test=tmpPersonnel.modifierPersonnel(nom,prenom,cin);

        if(name==cin && cin!=0)
          {
              QMessageBox::critical(nullptr, QObject::tr("cin existant"),
                                QObject::tr("perso existant.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);



          if(test)
          {


          QMessageBox::information(nullptr, QObject::tr("modifier un personnel"),
                            QObject::tr("personnel modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

          }
            else{
                QMessageBox::critical(nullptr, QObject::tr("modifier une personnel"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

          }
          }
          else {
              QMessageBox::critical(nullptr, QObject::tr("cin non exist"),
                          QObject::tr("personnel n'existe pas.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

          }

}
void MainWindow::on_rechercher_clicked()
{
      int  cin=ui->lineEdit_rechercher->text().toInt(); ;
        ui->tableView_rechercher->setModel(tmpPersonnel.rechercher_perso(cin)) ;

}
void MainWindow::on_pushButton_TriASC_clicked()
{
    ui->tableView_tri->setModel(tmpPersonnel.trierAc());
}

void MainWindow::on_pushButton_TriDESC_clicked()
{
    ui->tableView_tri->setModel(tmpPersonnel.trierDec());
}



void MainWindow::on_pushButton_TriASC_2_clicked()
{
    ui->tableView_tri->setModel(tmpPersonnel.triernom());

}

void MainWindow::on_rechercher_2_clicked()
{
    QString  nom=ui->lineEdit_rechercher_2->text() ;
      ui->tableView_rechercher->setModel(tmpPersonnel.rechercher_perso_nom(nom)) ;

}

void MainWindow::on_modifier_2_clicked()
{
    QSqlQuery query2;
    int cin,prime;


        cin=ui->lineEdit_pren_modif_3->text().toInt();
        prime=ui->lineEdit_pren_modif_2->text().toInt();


       tmpPersonnel.add_prime_Personnel(prime,cin);

       query2.prepare("SELECT CIN FROM personnel WHERE cin = :cin");
               query2.bindValue(":cin",cin);
               query2.exec();
               query2.next();

}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView_2->setModel(tmpPersonnel.stat());

}

void MainWindow::on_supprimer_2_clicked()
{
    QSqlQuery query2;
    int cin;
          QDate  congee_from,congee_to;


        cin=ui->lineEdit_cin22->text().toInt();
             congee_from=ui->dateEdit->date();
              congee_to=ui->dateEdit_2->date();


       tmpPersonnel.add_congee_Personnel(congee_from,congee_to,cin);

       query2.prepare("SELECT CIN FROM personnel WHERE cin = :cin");
               query2.bindValue(":cin",cin);
               query2.exec();
               query2.next();




                bool test=tmpPersonnel.add_congee_Personnel(congee_from,congee_to,cin);
                if(test)
                {
                    ui->tableView->setModel(tmpPersonnel.afficherPersonnel());
                    QMessageBox::critical(nullptr, QObject::tr("ADD"),
                                QObject::tr(" successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }
                else
                    QMessageBox::critical(nullptr, QObject::tr("ADD"),
                                QObject::tr("failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);



}


void MainWindow::on_supprimer_3_clicked()
{
    QSqlQuery query11,query2;
          int cin=ui->lineEditCin_supp_2->text().toInt();
          query2.prepare("SELECT CIN FROM personnel WHERE cin = :cin");
                  query2.bindValue(":cin",cin);
                  query2.exec();
                  query2.next();
         query11.prepare("update personnel set etat_congee= 0, congee_from= null,congee_to= null where cin=:cin");
         query11.bindValue(":cin",cin);


         query11.exec();
         query11.next();



   }

void MainWindow::on_rechercher_3_clicked()
{
    int  etat_congee=ui->lineEdit_rechercher_3->text().toInt(); ;
      ui->tableView_rechercher->setModel(tmpPersonnel.rechercher_congee(etat_congee)) ;
}
void MainWindow::on_pushButton_6_clicked()
{

        QSqlQueryModel * model= new QSqlQueryModel();
                                    model->setQuery("SELECT * FROM PERSONNEL where etat_congee= 0 ");
                                    float montant1=model->rowCount();
                                    model->setQuery("SELECT * FROM PERSONNEL where etat_congee= 1 ");
                                    float montant2=model->rowCount();

                                    float total=montant1+montant2;
                                    QString a=QString("personnel non congee "+QString::number(((montant1)/total)*100,'f',2)+"%" );
                                    QString b=QString("personnel congee "+QString::number(((montant2)/total)*100,'f',2)+"%" );
                                    QPieSeries *series = new QPieSeries();
                                    series->append(a,montant1);
                                    series->append(b,montant2);

            if (montant1!=0)
                            {QPieSlice *slice = series->slices().at(0);                
                             slice->setLabelVisible();
                             slice->setPen(QPen());}
                            if ( montant2!=0)
                            {

                                     QPieSlice *slice1 = series->slices().at(1);
                                     //slice1->setExploded();
                                     slice1->setLabelVisible();
                            }

                                    // Create the chart widget
                                    QChart *chart = new QChart();
                                    // Add data to chart with title and hide legend
                                    chart->addSeries(series);
                                    chart->setTitle("statistique "+ QString::number(total));
                                    chart->legend()->hide();
                                    // Used to display the chart
                                    QChartView *chartView = new QChartView(chart);
                                    chartView->setRenderHint(QPainter::Antialiasing);
                                    chartView->resize(1000,500);
                                    chartView->show();

                                    QPalette pal = qApp->palette();

                                    // Change the color around the chart widget and text
                                    pal.setColor(QPalette::Window, QRgb(0xFFFFFF));
                                    pal.setColor(QPalette::WindowText, QRgb(0xFFF0000));
                                    // Apply palette changes to the application
                                    qApp->setPalette(pal);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView_3->setModel(tmpPersonnel.stat1());
}

void MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery query,query2;
    query.prepare("update PERSONNEL set etat_congee= 2 where congee_to= SYSDATE");
    query.exec();
    query2.prepare("select  SYSDATE()");
    query.exec();

}
