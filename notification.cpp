#include "notification.h"


void notification::notification_produit(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("notification.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("notification","produit réglé !",QSystemTrayIcon::Information,15000);

}


