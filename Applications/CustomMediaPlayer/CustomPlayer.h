
#include <QObject>
#include <QMediaPlayer>


class CustomPlayer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QMediaObject* mediaObject READ mediaObject NOTIFY mediaObjectChanged)

public:
    CustomPlayer();

    QMediaObject* mediaObject();

signals:
    void mediaObjectChanged();

private:
    QMediaPlayer cplayer;
};
