// ============================================================================
//   Copyright (c) 2016 Nextcode
//   Nextcode, Zurich. All rights reserved.
//
//   Authors: Michele Dell'Ambrogio (m@nextcode.ch)
// ============================================================================

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "FileItem.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QWidget* widget = new QWidget(ui->scrollArea);
	widget->setGeometry(0, 0, ui->scrollArea->width(), 0);
	ui->scrollArea->setWidget(widget);
}

MainWindow::~MainWindow()
{
	Q_FOREACH(FileItem* item, m_fileItems)
	{
		qDebug() << item->filename();
	}

	delete ui;
}

void MainWindow::slotRemoveFileItem(FileItem *item)
{
	if (item)
	{
		m_fileItems.removeAll(item);
		delete item;

		doLayout();
	}
}

void MainWindow::slotAddFileItemAfter(FileItem *item)
{
	if (item)
	{
		int index = m_fileItems.indexOf(item);
		addFileItemAtIndex(++index);
	}
}

void MainWindow::on_actionNewFile_triggered()
{
	addFileItemAtIndex(m_fileItems.count());
}

void MainWindow::addFileItemAtIndex(int index)
{
	QWidget* widget = ui->scrollArea->takeWidget();

	FileItem* newFileItem = new FileItem(widget);
	connect(newFileItem, SIGNAL(signalAddFileItemAfter(FileItem*)), this, SLOT(slotAddFileItemAfter(FileItem*)));
	connect(newFileItem, SIGNAL(signalRemoveItem(FileItem*)), this, SLOT(slotRemoveFileItem(FileItem*)));

	m_fileItems.insert(index, newFileItem);

	ui->scrollArea->setWidget(widget);

	doLayout();
}

void MainWindow::doLayout()
{
	const int scrollWidth = ui->scrollArea->width();
	QWidget* widget = ui->scrollArea->takeWidget();

	int itemHeight = 0;

	for(int idx = 0; idx < m_fileItems.size(); ++idx)
	{
		itemHeight = m_fileItems[idx]->height();
		m_fileItems[idx]->setGeometry(0, idx*itemHeight, scrollWidth, itemHeight);
	}

	int scrollHeight = m_fileItems.count() * itemHeight;
	widget->resize(scrollWidth, scrollHeight);

	ui->scrollArea->setWidget(widget);
}
