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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditCin;
    QLineEdit *lineEdit_pren;
    QLineEdit *lineEdit_nom;
    QPushButton *ajouter;
    QPushButton *quitter_ajout;
    QLabel *label_8;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QPushButton *afficher;
    QTableView *tableView;
    QWidget *tab_5;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditCin_modif;
    QLineEdit *lineEdit_pren_modif;
    QLineEdit *lineEdit_nom_modif;
    QPushButton *modifier;
    QWidget *tab_3;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLineEdit *lineEditCin_supp;
    QPushButton *supprimer;
    QWidget *tab_7;
    QWidget *tab_4;
    QWidget *tab_6;
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
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 110, 56, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 150, 56, 16));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setWordWrap(false);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 190, 56, 16));
        lineEditCin = new QLineEdit(groupBox);
        lineEditCin->setObjectName(QStringLiteral("lineEditCin"));
        lineEditCin->setGeometry(QRect(170, 110, 113, 22));
        lineEditCin->setMaxLength(8);
        lineEdit_pren = new QLineEdit(groupBox);
        lineEdit_pren->setObjectName(QStringLiteral("lineEdit_pren"));
        lineEdit_pren->setGeometry(QRect(170, 150, 113, 22));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(170, 190, 113, 22));
        ajouter = new QPushButton(groupBox);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(290, 240, 93, 28));
        ajouter->setStyleSheet(QLatin1String("selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.33 rgba(0, 0, 0, 255), stop:0.34 rgba(255, 30, 30, 255), stop:0.66 rgba(255, 0, 0, 255), stop:0.67 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.33 rgba(0, 0, 0, 255), stop:0.34 rgba(255, 30, 30, 255), stop:0.66 rgba(255, 0, 0, 255), stop:0.67 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255));"));
        ajouter->setFlat(false);
        quitter_ajout = new QPushButton(groupBox);
        quitter_ajout->setObjectName(QStringLiteral("quitter_ajout"));
        quitter_ajout->setGeometry(QRect(400, 240, 93, 28));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(-20, -30, 711, 461));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/272913746_990774311522570_960516843833593149_n.jpg")));
        tabAjouter->addTab(tab_2, QString());
        label_8->raise();
        groupBox->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 40, 591, 301));
        afficher = new QPushButton(groupBox_4);
        afficher->setObjectName(QStringLiteral("afficher"));
        afficher->setGeometry(QRect(230, 240, 93, 28));
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 30, 501, 192));
        tabAjouter->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 40, 591, 301));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 110, 56, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 150, 56, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 190, 56, 16));
        lineEditCin_modif = new QLineEdit(groupBox_2);
        lineEditCin_modif->setObjectName(QStringLiteral("lineEditCin_modif"));
        lineEditCin_modif->setGeometry(QRect(170, 110, 113, 22));
        lineEditCin_modif->setMaxLength(8);
        lineEdit_pren_modif = new QLineEdit(groupBox_2);
        lineEdit_pren_modif->setObjectName(QStringLiteral("lineEdit_pren_modif"));
        lineEdit_pren_modif->setGeometry(QRect(170, 150, 113, 22));
        lineEdit_nom_modif = new QLineEdit(groupBox_2);
        lineEdit_nom_modif->setObjectName(QStringLiteral("lineEdit_nom_modif"));
        lineEdit_nom_modif->setGeometry(QRect(170, 190, 113, 22));
        modifier = new QPushButton(groupBox_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(470, 260, 93, 28));
        tabAjouter->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 40, 591, 301));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 160, 56, 16));
        lineEditCin_supp = new QLineEdit(groupBox_3);
        lineEditCin_supp->setObjectName(QStringLiteral("lineEditCin_supp"));
        lineEditCin_supp->setGeometry(QRect(210, 160, 113, 22));
        lineEditCin_supp->setMaxLength(8);
        supprimer = new QPushButton(groupBox_3);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(450, 260, 93, 28));
        tabAjouter->addTab(tab_3, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabAjouter->addTab(tab_7, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabAjouter->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabAjouter->addTab(tab_6, QString());
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
        ajouter->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        ajouter->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        quitter_ajout->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        label_8->setText(QString());
        tabAjouter->setTabText(tabAjouter->indexOf(tab_2), QApplication::translate("MainWindow", "ADD", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        afficher->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab), QApplication::translate("MainWindow", "DISPLAY", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_5), QApplication::translate("MainWindow", "UPDATE", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        lineEditCin_supp->setText(QString());
        supprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_3), QApplication::translate("MainWindow", "DELETE", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_7), QApplication::translate("MainWindow", "RECHERCHE", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_4), QApplication::translate("MainWindow", "TRIE", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_6), QApplication::translate("MainWindow", "STAT", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_8), QApplication::translate("MainWindow", "CONGE", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_9), QApplication::translate("MainWindow", "PRIME DE RENDEMENT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
