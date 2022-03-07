/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabAjouter;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_pren;
    QLineEdit *lineEdit_nom;
    QPushButton *ajouter;
    QPushButton *quitter_ajout;
    QLineEdit *lineEdit_DateSAV;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_description;
    QLineEdit *lineEditCin;
    QLabel *label_13;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QPushButton *quitter_affich;
    QPushButton *afficher;
    QTableView *tableView;
    QWidget *tab_3;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLineEdit *lineEditCin_supp;
    QPushButton *supprimer;
    QPushButton *quittersupp;
    QWidget *tab_5;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditCin_modif;
    QLineEdit *lineEdit_nom_modif;
    QPushButton *modifier;
    QPushButton *quitter_modif;
    QLabel *label_4;
    QLineEdit *lineEdit_typeSAV_modif;
    QLabel *label_10;
    QLineEdit *lineEdit_DateSAV_modif;
    QLabel *label_11;
    QLineEdit *lineEdit_description_modif;
    QLineEdit *lineEdit_pren_modif;
    QLabel *label_12;
    QWidget *tab_4;
    QWidget *tab_6;
    QWidget *tab_7;
    QWidget *tab_8;
    QWidget *tab_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabAjouter = new QTabWidget(centralwidget);
        tabAjouter->setObjectName(QStringLiteral("tabAjouter"));
        tabAjouter->setGeometry(QRect(40, 60, 661, 421));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 631, 301));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 110, 56, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 56, 16));
        lineEdit_pren = new QLineEdit(groupBox);
        lineEdit_pren->setObjectName(QStringLiteral("lineEdit_pren"));
        lineEdit_pren->setGeometry(QRect(70, 110, 113, 22));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(70, 80, 113, 22));
        ajouter = new QPushButton(groupBox);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(290, 240, 93, 28));
        quitter_ajout = new QPushButton(groupBox);
        quitter_ajout->setObjectName(QStringLiteral("quitter_ajout"));
        quitter_ajout->setGeometry(QRect(400, 240, 93, 28));
        lineEdit_DateSAV = new QLineEdit(groupBox);
        lineEdit_DateSAV->setObjectName(QStringLiteral("lineEdit_DateSAV"));
        lineEdit_DateSAV->setGeometry(QRect(70, 140, 113, 22));
        lineEdit_DateSAV->setMaxLength(8);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 140, 51, 20));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(220, 30, 61, 20));
        lineEdit_description = new QLineEdit(groupBox);
        lineEdit_description->setObjectName(QStringLiteral("lineEdit_description"));
        lineEdit_description->setGeometry(QRect(242, 61, 301, 131));
        lineEditCin = new QLineEdit(groupBox);
        lineEditCin->setObjectName(QStringLiteral("lineEditCin"));
        lineEditCin->setGeometry(QRect(70, 50, 113, 22));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 50, 56, 16));
        tabAjouter->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 40, 591, 301));
        quitter_affich = new QPushButton(groupBox_4);
        quitter_affich->setObjectName(QStringLiteral("quitter_affich"));
        quitter_affich->setGeometry(QRect(450, 240, 93, 28));
        afficher = new QPushButton(groupBox_4);
        afficher->setObjectName(QStringLiteral("afficher"));
        afficher->setGeometry(QRect(330, 240, 93, 28));
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 30, 501, 192));
        tabAjouter->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 40, 591, 301));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 70, 56, 16));
        lineEditCin_supp = new QLineEdit(groupBox_3);
        lineEditCin_supp->setObjectName(QStringLiteral("lineEditCin_supp"));
        lineEditCin_supp->setGeometry(QRect(100, 70, 113, 22));
        lineEditCin_supp->setMaxLength(8);
        supprimer = new QPushButton(groupBox_3);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(290, 240, 93, 28));
        quittersupp = new QPushButton(groupBox_3);
        quittersupp->setObjectName(QStringLiteral("quittersupp"));
        quittersupp->setGeometry(QRect(400, 240, 93, 28));
        tabAjouter->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 40, 591, 301));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 100, 56, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 70, 56, 16));
        lineEditCin_modif = new QLineEdit(groupBox_2);
        lineEditCin_modif->setObjectName(QStringLiteral("lineEditCin_modif"));
        lineEditCin_modif->setGeometry(QRect(80, 40, 113, 22));
        lineEdit_nom_modif = new QLineEdit(groupBox_2);
        lineEdit_nom_modif->setObjectName(QStringLiteral("lineEdit_nom_modif"));
        lineEdit_nom_modif->setGeometry(QRect(80, 70, 113, 22));
        modifier = new QPushButton(groupBox_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(290, 240, 93, 28));
        quitter_modif = new QPushButton(groupBox_2);
        quitter_modif->setObjectName(QStringLiteral("quitter_modif"));
        quitter_modif->setGeometry(QRect(400, 240, 93, 28));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 130, 51, 20));
        lineEdit_typeSAV_modif = new QLineEdit(groupBox_2);
        lineEdit_typeSAV_modif->setObjectName(QStringLiteral("lineEdit_typeSAV_modif"));
        lineEdit_typeSAV_modif->setGeometry(QRect(80, 130, 113, 22));
        lineEdit_typeSAV_modif->setMaxLength(8);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 160, 51, 20));
        lineEdit_DateSAV_modif = new QLineEdit(groupBox_2);
        lineEdit_DateSAV_modif->setObjectName(QStringLiteral("lineEdit_DateSAV_modif"));
        lineEdit_DateSAV_modif->setGeometry(QRect(80, 160, 113, 22));
        lineEdit_DateSAV_modif->setMaxLength(8);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(260, 20, 61, 20));
        lineEdit_description_modif = new QLineEdit(groupBox_2);
        lineEdit_description_modif->setObjectName(QStringLiteral("lineEdit_description_modif"));
        lineEdit_description_modif->setGeometry(QRect(260, 50, 301, 131));
        lineEdit_pren_modif = new QLineEdit(groupBox_2);
        lineEdit_pren_modif->setObjectName(QStringLiteral("lineEdit_pren_modif"));
        lineEdit_pren_modif->setGeometry(QRect(80, 100, 113, 22));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 40, 56, 16));
        tabAjouter->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabAjouter->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabAjouter->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabAjouter->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tabAjouter->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        tabAjouter->addTab(tab_9, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabAjouter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        ajouter->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        quitter_ajout->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "id_SAV", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_2), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        quitter_affich->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        afficher->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "id_SAV", Q_NULLPTR));
        lineEditCin_supp->setText(QString());
        supprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        quittersupp->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_3), QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        quitter_modif->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Type sav", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "id_SAV", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_5), QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_4), QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_6), QApplication::translate("MainWindow", "recherche", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_7), QApplication::translate("MainWindow", "stat", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_8), QApplication::translate("MainWindow", "traitement", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_9), QApplication::translate("MainWindow", "reboursement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
