
#pragma once

#include <QObject>
#include <QList>

#include "QQmlObjectListModel.h"
#include "AugData.h"

class SuperListController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> augmentations READ augmentations WRITE setAugmentations NOTIFY augmentationsChanged)

    Q_PROPERTY(QAbstractItemModel* augmentations2 READ augmentations2 NOTIFY augmentations2Changed)

public:
    SuperListController(QObject* parent = 0);

    QList<QObject*> augmentations() const;
    void setAugmentations(const QList<QObject*>& augmentations);

    QAbstractItemModel* augmentations2();

signals:
    void augmentationsChanged();
    void augmentations2Changed();

private:
    QList<QObject*> _augmentations;

    QQmlObjectListModel<AugData>* _augmentationsModel;
};
