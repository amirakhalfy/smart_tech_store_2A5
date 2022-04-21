#include "client.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"





using std::uint8_t;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
    ui->tableView->setModel(tmpclient.afficherClient());


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
    int cin;
        QString nom,prenom;
        cin=ui->lineEditCin->text().toInt();

nom=ui->lineEdit_nom->text();
        prenom=ui->lineEdit_pren->text();
       // ui->tableView->setModel(tmpclient.afficherClient());


        Client c(cin,nom,prenom);

      bool test =  c.addClient();
        if(test)
        {


        QMessageBox::information(nullptr, QObject::tr("ajouter un client"),
                          QObject::tr("client ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
      A.write_to_arduino("1");
        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("ajouter une client"),
                          QObject::tr("Erreur ! Client existant\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    A.write_to_arduino("0");
        }


}

void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpclient.afficherClient());

}

void MainWindow::on_supprimer_clicked()
{
    QSqlQuery query2;

    int cin=ui->lineEditCin_supp->text().toInt();
    query2.prepare("SELECT CIN FROM CLIENTS WHERE cin = :cin");
    query2.bindValue(":cin",cin);
    query2.exec();
    query2.next();
    int name=query2.value(0).toInt();
    cout<<name;

    if(name==cin && cin!=0)
    {
        QMessageBox::information(nullptr, QObject::tr("cin existant"),
                          QObject::tr("client existant.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);



     bool test=  tmpclient.removeClient(cin);


        if(test)
        {


        QMessageBox::information(nullptr, QObject::tr("supprimer un client"),
                          QObject::tr("client supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        A.write_to_arduino("3");


        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("supprimer une client"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
              A.write_to_arduino("0");


        }
        }
    else {
        QMessageBox::critical(nullptr, QObject::tr("id non ex"),
                    QObject::tr("client n'existe pas.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }


}

void MainWindow::on_modifier_clicked()
{
    QSqlQuery query2;

    int cin;
        QString nom,prenom;

        cin=ui->lineEditCin_modif->text().toInt();
        nom=ui->lineEdit_nom_modif->text();
        prenom=ui->lineEdit_pren_modif->text();
        query2.prepare("SELECT CIN FROM CLIENTS WHERE cin = :cin");
        query2.bindValue(":cin",cin);
        query2.exec();
        query2.next();
        int name=query2.value(0).toInt();
        cout<<name;

    bool test = tmpclient.modifierClient(nom,prenom,cin);
    if(name==cin && cin!=0)
    {
        QMessageBox::information(nullptr, QObject::tr("cin existant"),
                          QObject::tr("client existant.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);



    if(test)
    {


    QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                      QObject::tr("client modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    A.write_to_arduino("2");


    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("modifier une client"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
          A.write_to_arduino("0");


    }
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("id non ex"),
                    QObject::tr("client n'existe pas.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }



}


void MainWindow::on_pushButton_TriASC_clicked()
{
    ui->tableView_tri->setModel(tmpclient.trierAc());
}

void MainWindow::on_pushButton_TriDESC_clicked()
{
    ui->tableView_tri->setModel(tmpclient.trierDec());
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QSqlDatabase db;
                    QTableView table_client;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT cin, nom_clt as nom, prenom_clt as prenom, score FROM CLIENTS ");
                     qry.exec();
                     Modal->setQuery(qry);
                     table_client.setModel(Modal);



                     db.close();


                     QString strStream;
                     QTextStream out(&strStream);


                     const int rowCount = table_client.model()->rowCount();
                     const int columnCount =  table_client.model()->columnCount();


                     const QString strTitle ="Clients";


                     out <<  "<html>\n"
                             "<img src='C:/Users/ASUS/Documents/kiosqueK/logocin.png' height='120' width='120'/>"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             "<img src='e-care.png'>"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des clients")
                        <<"<br>"

                        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!table_client.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(table_client.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!table_client.isColumnHidden(column)) {
                                 QString data = table_client.model()->data(table_client.model()->index(row, column)).toString().simplified();
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
                          QPixmap pixmap(":/img/aze.png");
                         lab.setPixmap(pixmap);
                         QPainter painter(&lab);
                         //QPrinter printer(QPrinter::PrinterResolution);

                         //pixmap.load("aze.png");
                         //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                         //painter.drawPixmap(10,10,50,50, pixmap);

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/produit.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                     delete document;
}

void MainWindow::on_rechercher_clicked()
{
    QString nom=ui->lineEdit_rechercher->text() ;
        ui->tableView_rechercher->setModel(tmpclient.rechercher_client(nom)) ;

}



void MainWindow::on_class1_clicked()
{
    ui->tableView_class->setModel(tmpclient.classification1()) ;

}

void MainWindow::on_class2_clicked()
{
    ui->tableView_class->setModel(tmpclient.classification2()) ;

}

void MainWindow::on_class3_clicked()
{
    ui->tableView_class->setModel(tmpclient.classification3()) ;

}



void MainWindow::on_pushButton_classer_clicked()
{
    ui->tableView_cla->setModel(tmpclient.classer()) ;

}

void MainWindow::on_nb_clicked()
{

}

void MainWindow::on_verif_clicked()
{
    Client d ;

    int cin;
    data=A.read_from_arduino();
    cin=ui->lineEdit->placeholderText().toInt();

    cin=data.toInt();

                bool test=d.chercher(cin);

                if(test)
                {
                    QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                            QObject::tr("client existe\n"
                                                        "Cliquez sur cancel Pour Quitter."), QMessageBox::Cancel);
                ui->statusbar->showMessage("recherche terminée");
               }
                else
                {  QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                        QObject::tr("Echec.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);}




}
