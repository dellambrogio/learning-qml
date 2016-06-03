// ============================================================================
//   Copyright (c) 2016 Nextcode
//   Nextcode, Zurich. All rights reserved.
//
//   Authors: Michele Dell'Ambrogio (m@nextcode.ch)
// ============================================================================

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

class FileItem;

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void slotRemoveFileItem(FileItem* item);
	void slotAddFileItemAfter(FileItem* item);

private slots:
	void on_actionNewFile_triggered();

private:
	void addFileItemAtIndex(int index);
	void doLayout();

private:
	Ui::MainWindow *ui;
	QList<FileItem*> m_fileItems;
};

#endif // MAINWINDOW_H
