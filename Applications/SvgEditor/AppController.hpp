
#pragma once

#include <QObject>

class AppController : public QObject
{
	Q_OBJECT

public:
	explicit AppController(QObject* parent = 0);

signals:

private:
};
