#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QTextEdit>
#include <QUdpSocket>
#include <QDateTime>

class UdpClient : public QTextEdit
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = 0);
    ~UdpClient();

private slots:
    void slotProcessDatagram();

private:
    QUdpSocket *udp;
};

#endif // UDPCLIENT_H
