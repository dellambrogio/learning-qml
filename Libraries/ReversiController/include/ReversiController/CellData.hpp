
#ifndef REVERSICONTROLLER_CELLDATA_HPP
#define REVERSICONTROLLER_CELLDATA_HPP

#include <QObject>
#include <QString>

class CellData : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(bool isValidMove READ isValidMove WRITE setIsValidMove NOTIFY isValidMoveChanged)

public:
	explicit CellData(const QString &color);

	QString color() const;
	void setColor(const QString &color);

	bool isValidMove() const;
	void setIsValidMove(bool isValidMove);

signals:
	void colorChanged();
	void isValidMoveChanged();

private:
	QString m_color;
	bool m_isValidMove;
};

#endif
