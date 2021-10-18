#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include <string>
#include <vector>

#include "commands_handler.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QQuickStyle::setStyle("Material");

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  const std::vector<std::string> kCommands{"turnOn", "turnOff"};
  CommandsHandler commands_handler(kCommands, &app);

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
