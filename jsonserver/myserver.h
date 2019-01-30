#ifndef MYSERVER_H
#define MYSERVER_H

// используем протокол ТСР
#include <QTcpServer>

// и сокеты
#include <QTcpSocket>


class myserver : public QTcpServer {
    Q_OBJECT

public:
    myserver();
    ~myserver();

    // переменная отвечает за сокеты
    QTcpSocket* socket;
    // переменная отвечает за передаваемые данные (сюда их складывает)
    QByteArray Data;

public slots:
    // необходим для запуска сервера
    void startServer();

    // описание действий в случае присоединения нового клиента, SD - уникальный номер присоединения
    void incomingConnection(qintptr socketDescriptor);

    // готовность сокета читать полученные данные (это сокет)
    void sockReady();

    // действия при отключении клиента от сокета
    void sockDisc();
};



#endif // MYSERVER_H
