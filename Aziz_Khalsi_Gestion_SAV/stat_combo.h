#ifndef STAT_COMBO_H
#define STAT_COMBO_H
#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_combo;
}

class stat_combo : public QDialog
{
    Q_OBJECT

public:
    explicit stat_combo(QWidget *parent = nullptr);
    ~stat_combo();

    QChartView *chartView ;
    void choix_bar();
    void choix_pie();

private:
    Ui::stat_combo *ui;
};

#endif // STAT_COMBO_H
