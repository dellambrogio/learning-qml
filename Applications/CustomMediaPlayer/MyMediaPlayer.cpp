#include "MyMediaPlayer.h"

#include <QFile>

MyMediaPlayer::MyMediaPlayer(QObject* parent, Flags flags)
    : QMediaPlayer(parent, flags)
    , pingpong("/home/data/sequences/rallye/WRC Spain - News Feed 1.mp4")
{
//    QFile pingpong("/home/data/sequences/rallye/WRC Spain - News Feed 1.mp4");

//    pingpong.open(QIODevice::ReadOnly);
//    setMedia(0, &pingpong);
//    play();
}

void MyMediaPlayer::playDemo()
{
//    QString strFile("/home/data/sequences/rallye/WRC Spain - News Feed 1.mp4");
//    QMediaPlayer::setMedia(QUrl::fromLocalFile(strFile));
//    QMediaPlayer::play();

    bool ret = pingpong.open(QIODevice::ReadOnly);
    QMediaPlayer::setMedia(0, &pingpong);

    Error err = error();

    QMediaPlayer::play();
}

void MyMediaPlayer::setVideoSurface(QAbstractVideoSurface* surface)
{
    qDebug() << "Changing surface";
    m_surface = surface;
    setVideoOutput(m_surface);
}

QAbstractVideoSurface* MyMediaPlayer::getVideoSurface()
{
    return m_surface;
}
