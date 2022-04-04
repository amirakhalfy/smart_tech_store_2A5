#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include <QMainWindow>
#include "stat_combo.h"
#include "smtp.h"
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include "exportexcelobject.h"
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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_5_clicked();

    void on_rechercher_clicked();

    void on_triparnom_clicked();

    void on_triparnomdec_clicked();

    void on_tripardate_clicked();

    void on_panne_clicked();

    void on_regler_clicked();

    void on_traiter_clicked();



    void on_stat_clicked();


        void on_pushButton_2_clicked();

        void on_pushButton_3_clicked();

        void on_le_id_cursorPositionChanged(int arg1, int arg2);

        void on_pushButton_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Produit P;
 stat_combo *s;
 int selected=0;
    QStringList files;
    ravitaillement r;

};
#endif // MAINWINDOW_H
