//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include <QObject>
#include <QString>

// Exposing Methods (Including Qt Slots)
// Exposing Signals

class MessageBoard : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE bool postMessage(const QString &msg);

signals:
    void newMessagePosted(const QString &subject);

public slots:
    void refresh();
};
