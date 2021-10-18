#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

#include <iostream>
#include <string>
#include <vector>

#include "commands_handler.h"
#include "communication_module.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QQuickStyle::setStyle("Material");

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  CommunicationModule communication_module("127.0.0.1", 1234);
  const std::vector<std::string> kCommands{"turnOn", "turnOff"};

  CommandsHandler commands_handler(
      kCommands,
      [&](const std::string command) {
        if (!communication_module.SendCommand(command.c_str()))
          std::cerr << "Sending error" << std::endl;
      },
      &app);
  engine.rootContext()->setContextProperty("commandsHandlerModel",
                                           &commands_handler);

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
