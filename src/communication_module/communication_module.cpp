#include "communication_module.h"

#include <iostream>

CommunicationModule::CommunicationModule(const QString host_address,
                                         const int port_number, QObject *parent)
    : QObject(parent) {
  tcp_socket_.reset(new QTcpSocket(this));
  tcp_socket_->connectToHost(host_address, port_number,
                             QTcpSocket::OpenModeFlag::WriteOnly);
}

bool CommunicationModule::SendCommand(const QString &command) {
  if (!tcp_socket_)
    return false;

  QByteArray arrBlock;
  QDataStream out(&arrBlock, QIODevice::WriteOnly);
  out << quint16(0) << command;

  out.device()->seek(0);
  out << quint16(arrBlock.size() - sizeof(quint16));

  if (tcp_socket_->state() != QTcpSocket::ConnectedState)
    return false;

  return tcp_socket_->write(arrBlock);
}
