//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>


#include "Message.h"
#include "ReMessage.h"
#include "MessageBoard.h"
#include "Signaler.h"


int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

    qmlRegisterType<ReMessage>("com.mycompany.messaging", 1, 0, "ReMessage");
    qmlRegisterType<Signaler>("com.mycompany.messaging", 1, 0, "Signaler");

	QQmlApplicationEngine engine;

    Message msg;
    engine.rootContext()->setContextProperty("msg", &msg);

    MessageBoard msgBoard;
    engine.rootContext()->setContextProperty("msgBoard", &msgBoard);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}

