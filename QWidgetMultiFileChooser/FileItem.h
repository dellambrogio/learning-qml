// ============================================================================
//   Copyright (c) 2016 Nextcode
//   Nextcode, Zurich. All rights reserved.
//
//   Authors: Michele Dell'Ambrogio (m@nextcode.ch)
// ============================================================================

#ifndef FILEITEM_H
#define FILEITEM_H

#include <QWidget>

namespace Ui {
	class FileItem;
}

class FileItem : public QWidget
{
	Q_OBJECT

public:
	explicit FileItem(QWidget *parent = 0);
	~FileItem();

	QString filename() const;

private slots:
	void on_pushButton_choose_clicked();
	void on_pushButton_add_clicked();
	void on_pushButton_remove_clicked();

signals:
	void signalAddFileItemAfter(FileItem*);
	void signalRemoveItem(FileItem*);

private:
	Ui::FileItem *ui;
};

#endif // FILEITEM_H
