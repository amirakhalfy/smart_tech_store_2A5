/********************************************************************************
** Form generated from reading UI file 'stat_combo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_COMBO_H
#define UI_STAT_COMBO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_stat_combo
{
public:
    QLabel *label_stat;

    void setupUi(QDialog *stat_combo)
    {
        if (stat_combo->objectName().isEmpty())
            stat_combo->setObjectName(QStringLiteral("stat_combo"));
        stat_combo->resize(596, 448);
        label_stat = new QLabel(stat_combo);
        label_stat->setObjectName(QStringLiteral("label_stat"));
        label_stat->setGeometry(QRect(90, 30, 400, 400));

        retranslateUi(stat_combo);

        QMetaObject::connectSlotsByName(stat_combo);
    } // setupUi

    void retranslateUi(QDialog *stat_combo)
    {
        stat_combo->setWindowTitle(QApplication::translate("stat_combo", "Dialog", Q_NULLPTR));
        label_stat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class stat_combo: public Ui_stat_combo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_COMBO_H
