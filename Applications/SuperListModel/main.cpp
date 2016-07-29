
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "SuperListController.h"

int main(int argc, char *argv[])
{
	QGuiApplication::setApplicationName("SuperListModel");
	QGuiApplication::setOrganizationName("SuperListModel");
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

    SuperListController ctrl;
    engine.rootContext()->setContextProperty("ctrl", &ctrl);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}
