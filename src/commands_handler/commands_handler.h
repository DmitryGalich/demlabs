#ifndef COMMANDS_HANDLER
#define COMMANDS_HANDLER

#include <QAbstractListModel>
#include <QObject>

#include <functional>

class CommandsHandler : public QAbstractListModel {
  Q_OBJECT

public:
  enum Roles { CommandRole = Qt::UserRole + 1 };

  CommandsHandler(
      const std::vector<std::string> &commands,
      const std::function<void(const std::string &command)> sendCommandCallback,
      QObject *parent = nullptr);
  virtual ~CommandsHandler() override;

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

protected:
  QHash<int, QByteArray> roleNames() const override;

  Q_INVOKABLE void sendCommand(QString command);

private:
  const std::vector<std::string> &kCommands_;
  const std::function<void(const std::string &command)> kSendCommandCallback_;
};

#endif
