#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include <QMediaPlayer>
#include <QFile>
#include <QVideoWidget>

#include <QApplication>

#include "MyMediaPlayer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MyMediaPlayer* myplayer = new MyMediaPlayer();

    engine.rootContext()->setContextProperty("myplayer", myplayer);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}




//int main(int argc, char *argv[])
//{
//    QGuiApplication app(argc, argv);

//    QMediaPlayer cplayer;

//    //QFile pingpong("/home/data/sequences/basketball/EUROLEAGUE_Basketball/20160603_Basketball_Highlights.mp4");
//    QFile pingpong("/home/data/sequences/rallye/WRC Spain - News Feed 1.mp4");

//    pingpong.open(QIODevice::ReadOnly);
//    cplayer.setMedia(0, &pingpong);
//    cplayer.play();

//    QQmlApplicationEngine engine;

//    engine.rootContext()->setContextProperty("cplayer", &cplayer);

//    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

//    return app.exec();
//}







//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);

//    QMediaPlayer cplayer;

//    //QFile pingpong("/home/data/sequences/basketball/EUROLEAGUE_Basketball/20160603_Basketball_Highlights.mp4");
//    QFile pingpong("/home/data/sequences/rallye/WRC Spain - News Feed 1.mp4");

//    pingpong.open(QIODevice::ReadOnly);
//    cplayer.setMedia(0, &pingpong);
//    cplayer.play();

//    QVideoWidget* videoWidget = new QVideoWidget;
//    cplayer.setVideoOutput(videoWidget);
//    videoWidget->show();

//    cplayer.play();

//    app.exec();
//}
