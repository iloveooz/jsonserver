#include "myserver.h"
// #include <QTcpServer>

myserver::myserver(){}
myserver::~myserver(){}

// запуск сервера
void myserver::startServer() {
    if (this->listen(QHostAddress::Any, 5555)) {
        qDebug() << "Listening...";
    }
    else {
        qDebug() << "Not listening!";
    }
}

void myserver::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(sockDisc()));

    qDebug() << socketDescriptor << "client connected";
    socket->write("You are connected!");

    qDebug() << "Send client connect status - YES!";
}

// готовность сервера получать данные
void myserver::sockReady() {
}

// дисконнект, на стороне сервера сообщение, что клиент отключился
void myserver::sockDisc() {
    qDebug() << "Client disconected.";
    socket->deleteLater();
}
