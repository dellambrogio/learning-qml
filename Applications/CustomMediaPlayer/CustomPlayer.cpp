
#include "CustomPlayer.h"

#include <QFile>


CustomPlayer::CustomPlayer() : QObject()
{
    QFile pingpong("/home/data/sequences/rallye/WRC Spain - News Feed 1.mp4");

    pingpong.open(QIODevice::ReadOnly);
    cplayer.setMedia(0, &pingpong);
    cplayer.play();
}

QMediaObject* CustomPlayer::mediaObject() {
    return &cplayer;
}
