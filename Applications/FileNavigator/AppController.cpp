
#include "AppController.hpp"


AppController::AppController(QObject *parent)
	: QObject(parent)
	, _fileModel(new QFileSystemModel(this))
{
	//model->setFilter(QDir::NoDotAndDotDot | QDir::Files);
	//model->setRootPath("C:/Images");
}

QAbstractItemModel *AppController::fileModel()
{
	return _fileModel;
}

void AppController::setRootPath(const QString &path)
{
	if (path != _fileModel->rootPath())
	{
		_fileModel->setRootPath(path);
		emit rootPathChanged();
	}
}

QString AppController::rootPath() const
{
	return _fileModel->rootPath();
}
