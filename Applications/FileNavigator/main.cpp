
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQuickStyle>


#include <AppController.hpp>

int main(int argc, char *argv[])
{
	QGuiApplication::setApplicationName("FileNavigator");
	QGuiApplication::setOrganizationName("FileNavigator");
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QQuickStyle::setStyle("Material");

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	//AppController appController;
	//engine.rootContext()->setContextProperty("ctrl", &appController);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}

