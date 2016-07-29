#include "AugData.h"

AugData::AugData(QString name, QObject* parent)
    : QObject(parent)
    , _name(name)
{

}

QString AugData::name() const
{
    return _name;
}

void AugData::setName(const QString& name)
{
    if (name != _name) {
        _name = name;
        emit nameChanged();
    }
}
