//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include <QObject>

class ReMessage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
public:
    void setText(const QString &a);
    QString getText() const;
signals:
    void textChanged();
private:
    QString m_text;
};
