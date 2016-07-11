
#pragma once

#include <QObject>
#include <QFileSystemModel>

class AppController : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath NOTIFY rootPathChanged)

public:
	explicit AppController(QObject* parent = 0);

	Q_INVOKABLE QAbstractItemModel* fileModel();

	void setRootPath(const QString& path);\
	QString rootPath() const;

signals:
	void rootPathChanged();

private:
	QFileSystemModel* _fileModel;
};
