
#include "AppController.hpp"


AppController::AppController(QObject *parent)
	: QObject(parent)
{
}

// void AppController::setRootPath(const QString &path)
// {
// 	if (path != _fileModel->rootPath())
// 	{
// 		_fileModel->setRootPath(path);
// 		emit rootPathChanged();
// 	}
// }

// QString AppController::rootPath() const
// {
// 	return _fileModel->rootPath();
// }
