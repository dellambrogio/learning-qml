#pragma once

#include <QObject>
#include <QString>
#include <QList>

class AugData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    AugData(QString name, QObject* parent=0);

    QString name() const;
    void setName(const QString& name);

signals:
    void nameChanged();

private:
    QString _name;
};
