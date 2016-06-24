
#include "Cell.hpp"

Cell::Cell(const QString &color)
	: m_color(color)
{

}

QString Cell::color() const
{
    return m_color;
}

void Cell::setColor(const QString &color)
{
	if (color != m_color) {
		m_color = color;
		emit colorChanged();
	}
}
