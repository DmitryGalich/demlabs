#ifndef COMMUNICATION_MODULE
#define COMMUNICATION_MODULE

#include <memory>

#include <QDataStream>
#include <QObject>
#include <QTcpSocket>

class CommunicationModule : public QObject {
  Q_OBJECT

public:
  CommunicationModule(const QString host_address, const int port_number,
                      QObject *parent = nullptr);
  virtual ~CommunicationModule() override = default;

  bool SendCommand(const QString &command);

private:
  std::unique_ptr<QTcpSocket> tcp_socket_;
};

#endif
