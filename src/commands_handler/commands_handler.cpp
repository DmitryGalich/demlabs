#include "commands_handler.h"

CommandsHandler::CommandsHandler(
    const std::vector<std::string> &commands,
    const std::function<void(const std::string &command)> sendCommandCallback,
    QObject *parent)
    : QAbstractListModel(parent), kCommands_(commands),
      kSendCommandCallback_(sendCommandCallback) {}

CommandsHandler::~CommandsHandler() {}

int CommandsHandler::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return kCommands_.size();
}

QVariant CommandsHandler::data(const QModelIndex &index, int role) const {
  if (index.row() < 0 || (index.row() >= kCommands_.size()))
    return QVariant();

  if (role == CommandRole)
    return QString::fromStdString(kCommands_.at(index.row()));

  return QVariant();
}

QHash<int, QByteArray> CommandsHandler::roleNames() const {
  QHash<int, QByteArray> roles;

  roles[CommandRole] = "command";

  return roles;
}

void CommandsHandler::sendCommand(QString command) {
  kSendCommandCallback_(command.toStdString());
}
