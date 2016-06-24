
#include "GameContext.hpp"


GameContext::GameContext()
	: m_reversi()
	, m_currentTile(rv::ETile::Black)
	, m_currentValidMoves()
{

}

const rv::Reversi &GameContext::reversi() const
{
	return m_reversi;
}

bool GameContext::makeMove(int idx)
{
	const int x = idx % 8;
	const int y = idx / 8;

	if (m_reversi.makeMove(x, y, m_currentTile))
	{
		m_currentTile = rv::Reversi::opponent(m_currentTile);
		m_currentValidMoves = m_reversi.getValidMoves(m_currentTile);

		if (m_currentValidMoves.empty())
		{
			m_currentTile = rv::Reversi::opponent(m_currentTile);
			m_currentValidMoves = m_reversi.getValidMoves(m_currentTile);

			if (m_currentValidMoves.empty())
			{
				m_currentTile = rv::ETile::Unknown;
			}
		}

		return true;
	}

	return false;
}

rv::ETile GameContext::currentTile() const
{
	return m_currentTile;
}

void GameContext::setCurrentTile(const rv::ETile &currentTile)
{
	m_currentTile = currentTile;
}

bool GameContext::gameIsFinished() const
{
	return m_currentTile == rv::ETile::Unknown;
}
