#ifndef COMMANDS_HANDLER
#define COMMANDS_HANDLER

#include <QAbstractListModel>
#include <QObject>

class CommandsHandler : public QAbstractListModel {
  Q_OBJECT

public:
  enum Roles { CommandRole = Qt::UserRole + 1 };

  CommandsHandler(const std::vector<std::string> &commands,
                  QObject *parent = nullptr);
  virtual ~CommandsHandler() override;

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

protected:
  const std::vector<std::string> &kCommands_;

  QHash<int, QByteArray> roleNames() const override;
};

#endif
