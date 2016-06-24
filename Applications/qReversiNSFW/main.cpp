
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "GameController.hpp"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	
	GameController gameController;
	engine.rootContext()->setContextProperty("gameController", &gameController);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}

