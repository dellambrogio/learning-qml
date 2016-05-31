//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}

