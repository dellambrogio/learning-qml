
#ifndef QREVERSI_CELL_HPP
#define QREVERSI_CELL_HPP

#include <QObject>
#include <QString>

class Cell : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)

public:
	explicit Cell(const QString &color);

	QString color() const;
	void setColor(const QString &color);

signals:
	void colorChanged();

private:
	QString m_color;

};

#endif
