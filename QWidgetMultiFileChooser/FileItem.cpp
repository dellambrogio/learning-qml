// ============================================================================
//   Copyright (c) 2016 Nextcode
//   Nextcode, Zurich. All rights reserved.
//
//   Authors: Michele Dell'Ambrogio (m@nextcode.ch)
// ============================================================================

#include "FileItem.h"
#include "ui_FileItem.h"

#include <QFileDialog>

FileItem::FileItem(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::FileItem)
{
	ui->setupUi(this);
}

FileItem::~FileItem()
{
	delete ui;
}

QString FileItem::filename() const
{
	return ui->label_filename->text();
}

void FileItem::on_pushButton_choose_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Choose a File"));
	ui->label_filename->setText(fileName);
}

void FileItem::on_pushButton_add_clicked()
{
	emit signalAddFileItemAfter(this);
}

void FileItem::on_pushButton_remove_clicked()
{
	emit signalRemoveItem(this);
}
