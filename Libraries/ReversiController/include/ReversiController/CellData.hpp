
#ifndef REVERSICONTROLLER_CELLDATA_HPP
#define REVERSICONTROLLER_CELLDATA_HPP

#include <QObject>
#include <QString>

class CellData : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)

public:
	explicit CellData(const QString &color);

	QString color() const;
	void setColor(const QString &color);

signals:
	void colorChanged();

private:
	QString m_color;

};

#endif
