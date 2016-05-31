// ============================================================================
//   Copyright (c) 2016 Nextcode
//   Nextcode, Zurich. All rights reserved.
//
//   Authors: Michele Dell'Ambrogio (m@nextcode.ch)
// ============================================================================

#include "MainWindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QFile f(":qdarkstyle/style.qss");
	if (!f.exists())
	{
		qWarning() << "Unable to set stylesheet, file not found";
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}

	MainWindow w;
	w.show();

	return a.exec();
}
