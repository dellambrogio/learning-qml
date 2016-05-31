//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include <QObject>
#include <QTimer>

class Signaler : public QObject
{
    Q_OBJECT
public:
    Signaler();

public slots:
    void increaseCounter();

signals:
    void counterChanged(int value);

private:
    int m_counter;
    QTimer m_timer;
};
