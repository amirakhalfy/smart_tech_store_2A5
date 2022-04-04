#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include <QApplication>
#include<QSqlQueryModel>
#include <string>
#include <iostream>
#include <QTextStream>
#include "stat_combo.h"
#include <ui_stat_combo.h>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>
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

    QSqlQueryModel* model2=new QSqlQueryModel();
    model2->setQuery("select ID_COMMAND from COMMANDE");
    ui->comboBox_id->setModel(model2);
    ui->comboBox_id2->setModel(model2);
    ui->comboBox_id3->setModel(model2);
    ui->comboBox_id4->setModel(model2);
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
        ui->table_commande->setModel(cm.afficher());
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
    int id= ui->comboBox_id3->currentText().toInt();

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
    {ui->table_commande->setModel(cm.afficher());
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




    int id= ui->comboBox_id4->currentText().toInt();
    int res=ui->lineEdit_55->text().toInt();
    QString nom=ui->lineEdit_1->text();
    QString prenom=ui->lineEdit_2->text();
    QString adresse=ui->lineEdit_3->text();
    QString mail=ui->lineEdit_4->text();
    int etat=ui->lineEdit_5->text().toInt();
    Commande C(nom,prenom,adresse,mail,res,prix*res);
    if(etat==0||etat==1)
{


    bool test=C.modifier(id);
    if(test )
    {query.prepare("update COMMANDE set etat=:etat where ID_COMMAND=:id");
        query.bindValue(":etat",etat);
        query.bindValue(":id",id);

        query.exec();
        ui->table_commande->setModel(cm.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("modifier effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                QObject::tr("modifier non effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                QObject::tr("etat non valid\n"
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
    model->setQuery("select* from COMMANDE  order by PRIX_TOT desc ");
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
{ int id= ui->comboBox_id2->currentText().toInt();

    QSqlQuery query;
    QSqlQuery query2;
    query2.prepare("SELECT etat FROM Commande where ID_COMMAND=:id ");
    query2.bindValue(":id",id);
    query2.exec();
    query2.next();
    int etat=query2.value(0).toInt();
    if(etat==1)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("commande deja annuler\n"
                                           "click cancel to exit."),QMessageBox::Cancel);


    }
else
    {
    query.prepare("update COMMANDE set etat= 1 where ID_COMMAND=:id");
    query.bindValue(":id",id);

     query.exec();
     QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("annuler avec succes\n"
                                        "click cancel to exit."),QMessageBox::Cancel);
     ui->table_commande->setModel(cm.afficher());

    }

}

void MainWindow::on_pushButton_6_clicked()
{
   stat_combo *s= new stat_combo();

         s->setWindowTitle("statistique ComboBox");
         s->choix_pie();
         s->show();
}

void MainWindow::on_pushButton_7_clicked()
{

     int id= ui->comboBox_id->currentText().toInt();

    QSqlQuery query;
    query.prepare("SELECT etat FROM Commande where ID_COMMAND=:id ");
    query.bindValue(":id",id);
    query.exec();
    query.next();
    int etat=query.value(0).toInt();
    if(etat==1)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("commande deja annuler\n"
                                           "click cancel to exit."),QMessageBox::Cancel);


    }
    else if(etat==2)
    {   QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("commande deja payee\n"
                                             "click cancel to exit."),QMessageBox::Cancel);}
    else
    {
        query.prepare("update COMMANDE set etat= 2 where ID_COMMAND=:id");
        query.bindValue(":id",id);

         query.exec();
ui->table_commande->setModel(cm.afficher());
    QSqlDatabase db;
                        QTableView table_commande;
                        QSqlQueryModel * Modal=new  QSqlQueryModel();

                        QSqlQuery qry;
                         qry.prepare("SELECT * FROM Commande where ID_COMMAND=:id ");
                         qry.bindValue(":id",id);
                         qry.exec();
                         Modal->setQuery(qry);
                         table_commande.setModel(Modal);



                         db.close();


                         QString strStream;
                         QTextStream out(&strStream);


                         const int rowCount = table_commande.model()->rowCount();
                         const int columnCount =  table_commande.model()->columnCount();


                         const QString strTitle ="Document";


                         out <<  "<html>\n"
                                 "<img src='C:/Users/Akram/Pictures/R.png' height='120' width='120'/>"
                             "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 "<img src='C:/Users/Akram/Pictures/R.png.png'>"
                             <<  QString("<title>%1</title>\n").arg(strTitle)
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #b80b32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("COMMANDE")
                            <<"<br>"

                            <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                         out << "<thead><tr bgcolor=#f0f0f0>";
                         for (int column = 0; column < columnCount; column++)
                             if (!table_commande.isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(table_commande.model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!table_commande.isColumnHidden(column)) {
                                     QString data = table_commande.model()->data(table_commande.model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                                 "<br><br>"
                                 <<"<br>"
                                 <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                             out << "<thead><tr bgcolor=#f0f0f0>";

                                 out <<  "</table>\n"

                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;
                         QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                         if (dialog->exec() == QDialog::Accepted) {

                             QLabel lab;
                              QPixmap pixmap("C:/Users/Akram/Pictures/R.png");
                             lab.setPixmap(pixmap);
                             QPainter painter(&lab);
                             //QPrinter printer(QPrinter::PrinterResolution);

                             //pixmap.load("aze.png");
                            // painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                            // painter.drawPixmap(10,10,50,50, pixmap);

                             document->print(&printer);
                         }


                         printer.setOutputFormat(QPrinter::PdfFormat);
                         printer.setPaperSize(QPrinter::A4);
                         printer.setOutputFileName("Document.pdf");
                         printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                         delete document;
    }
}





