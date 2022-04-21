#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "client.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_afficher_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();


    void on_pushButton_TriASC_clicked();

    void on_pushButton_TriDESC_clicked();

    void on_pushButton_pdf_clicked();

    void on_rechercher_clicked();


    void on_class1_clicked();

    void on_class2_clicked();

    void on_class3_clicked();



    void on_pushButton_classer_clicked();

    void on_nb_clicked();

    void on_verif_clicked();

private:
    Ui::MainWindow *ui;
    Client tmpclient;
    arduino A;
    QByteArray data;
};
#endif // MAINWINDOW_H
