#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>


class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
void closeConnection();

};
#endif // CONNECTION_H

