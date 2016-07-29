
#include "SuperListController.h"

#include "AugData.h"

SuperListController::SuperListController(QObject* parent)
    : QObject(parent)
{
    _augmentations.append(new AugData("qui", this));
    _augmentations.append(new AugData("quo", this));

    _augmentationsModel = new  QQmlObjectListModel<AugData>(0, "name");
    _augmentationsModel->append(new AugData("qui", this));
    _augmentationsModel->append(new AugData("quo", this));
}

QList<QObject*> SuperListController::augmentations() const
{
    return _augmentations;
}

void SuperListController::setAugmentations(const QList<QObject*>& augmentations)
{
    if (augmentations != _augmentations) {
        _augmentations = augmentations;
        emit augmentationsChanged();
    }
}

QAbstractItemModel* SuperListController::augmentations2()
{
    return _augmentationsModel;
}

void SuperListController::addNew()
{
    _augmentations.append(new AugData("qua", this));
    _augmentationsModel->append(new AugData("qua", this));
}
