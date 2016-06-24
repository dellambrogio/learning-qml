
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include <QList>

#include "GameController.hpp"
#include "Cell.hpp"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	
	GameController gameController;
	engine.rootContext()->setContextProperty("gameController", &gameController);

	QList<QObject*> cells;
	for (int idx=0; idx<64; ++idx)
	{
		cells.append(new Cell("red"));
	}

	engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(cells));

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}

