
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include <ReversiController/ReversiController.hpp>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	ReversiController gameController;
	engine.rootContext()->setContextProperty("gameController", &gameController);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}

