#include "udpclient.h"

UdpClient::UdpClient(QWidget *parent)
    : QTextEdit(parent)
{
    setWindowTitle("UdpClient");

    udp = new QUdpSocket(this);
    udp->bind(2424);
    connect(udp, SIGNAL(readyRead()), SLOT(slotProcessDatagram()));
}

UdpClient::~UdpClient()
{

}

void UdpClient::slotProcessDatagram()
{
    QByteArray baDatagram;
    do
    {
        baDatagram.resize(udp->pendingDatagramSize());
        udp->readDatagram(baDatagram.data(), baDatagram.size());
    }
    while(udp->hasPendingDatagrams());

    QDateTime dateTime;
    QDataStream in(&baDatagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_5);
    in >> dateTime;
    append("Received: " + dateTime.toString());
}
