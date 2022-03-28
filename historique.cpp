 #include "historique.h"
#include "produit.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include<QObject>
#include<QTableView>
#include<iostream>
#include <QString>



historique::historique()
{
mFilename="historique.txt";
}
QString historique::read()
{
QFile mFile(mFilename);
if (!mFile.open(QFile::ReadOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream in (&mFile);
QString text=mFile.readAll();
mFile.close();
return  text;
}
void historique::write(QString text)
{
    QString aux=read();

    QDateTime datetime = QDateTime::currentDateTime();
    QString date =datetime.toString();
    date+= " ";
    aux+=date;
    //int id_produit=P.getidproduit();

QFile mFile(mFilename);
if (!mFile.open(QFile::WriteOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream out (&mFile);

aux+=text;
out << aux << "\n";

mFile.flush();
mFile.close();
}
