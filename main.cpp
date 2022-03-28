#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QSound>

#include <QSqlTableModel>
#include <QTranslator>
#include <QInputDialog>

#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
    QStringList languages;
    languages <<"arabic"<<"French";
    QString lang=QInputDialog::getItem(NULL,"select language","language",languages);
    if(lang=="arabic"){
        t.load(":/arabic.qm");

    }
   // else if(lang=="english"){

       // t.load(":/english.qm");

   // }
    if(lang!="French")
    {
        a.installTranslator(&t);
    }

    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
