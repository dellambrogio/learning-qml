
#include <QMediaPlayer>
#include <QFile>

class MyMediaPlayer: public QMediaPlayer
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ getVideoSurface WRITE setVideoSurface )

public:
    MyMediaPlayer(QObject * parent = 0, Flags flags = 0);

public slots:
    void playDemo();


    void setVideoSurface(QAbstractVideoSurface* surface);
    QAbstractVideoSurface* getVideoSurface();

private:
    QAbstractVideoSurface* m_surface;
    QFile pingpong;
};
