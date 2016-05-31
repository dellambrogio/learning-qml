//=============================================================================
//  Copyright (c) 2014 Disney Enterprises, Inc.
//  Disney Research, Zurich. All rights reserved.
//
//  Author: Michele Dell'Ambrogio (mda@disneyresearch.com)
//=============================================================================

#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}

