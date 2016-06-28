
#include "ReversiController/CellData.hpp"

CellData::CellData(const QString &color)
	: m_color(color)
{

}

QString CellData::color() const
{
	return m_color;
}

void CellData::setColor(const QString &color)
{
	if (color != m_color) {
		m_color = color;
		emit colorChanged();
	}
}
