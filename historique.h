#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QTimer>
#include <QDateTime>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QDebug>
class historique

{
public:
    historique();
    void write(QString);
    QString read();
private:
    QString mFilename;

};

#endif // HISTORIQUE_H
