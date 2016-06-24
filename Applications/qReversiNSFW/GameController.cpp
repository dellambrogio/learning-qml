
#include "GameController.hpp"

#include <Reversi/Reversi.hpp>


GameController::GameController()
	: QObject()
	, m_currentPlayer(0)
	, m_numBlackStones(0)
	, m_numWhiteStones(0)
{
	newGame();
}

GameController::~GameController()
{

}

void GameController::newGame()
{
	m_game.reset(new rv::Reversi);

	setCurrentPlayer(rv::ETile::Black);
	setCurrentValidMoves(QVector<int>());
	setNumBlackStones(0);
	setNumWhiteStones(0);
}

void GameController::makeMove(int idx)
{
	const int x = idx % 8;
	const int y = idx / 8;

	rv::ETile currentTile = static_cast<rv::ETile>(m_currentPlayer);
	std::vector<Eigen::Vector2i> validMoves;

	if (m_game->makeMove(x, y, currentTile))
	{
		currentTile = rv::Reversi::opponent(currentTile);
		validMoves = m_game->getValidMoves(currentTile);

		if (validMoves.empty())
		{
			currentTile = rv::Reversi::opponent(currentTile);
			validMoves = m_game->getValidMoves(currentTile);

			if (validMoves.empty())
			{
				currentTile = rv::ETile::Unknown;
			}
		}

		setCurrentPlayer(currentTile);
		QVector<int> currentValidMoves;
		for (const Eigen::Vector2i& move: validMoves)
		{
			currentValidMoves.push_back(move(0)+move(1)*8);
		}
		setCurrentValidMoves(currentValidMoves);

		std::map<rv::ETile, int> score = m_game->getScore();
		setNumBlackStones(score[rv::ETile::Black]);
		setNumWhiteStones(score[rv::ETile::White]);
	}
}

int GameController::getCurrentPlayer() const
{
	return m_currentPlayer;
}

void GameController::setCurrentPlayer(int currentPlayer)
{
	if (currentPlayer != m_currentPlayer) {
		m_currentPlayer = currentPlayer;
		emit currentPlayerChanged();
	}
}

const QVector<int> &GameController::getCurrentValidMoves() const
{
	return m_currentValidMoves;
}

void GameController::setCurrentValidMoves(const QVector<int> &currentValidMoves)
{
	if (currentValidMoves != m_currentValidMoves) {
		m_currentValidMoves = currentValidMoves;
		emit currentValidMovesChanged();
	}
}

int GameController::getNumBlackStones() const
{
	return m_numBlackStones;
}

void GameController::setNumBlackStones(int numBlackStones)
{
	if (numBlackStones != m_numBlackStones) {
		m_numBlackStones = numBlackStones;
		emit numBlackStonesChanged();
	}
}

int GameController::getNumWhiteStones() const
{
	return m_numWhiteStones;
}

void GameController::setNumWhiteStones(int numWhiteStones)
{
	if (numWhiteStones != m_numWhiteStones) {
		m_numWhiteStones = numWhiteStones;
		emit numWhiteStonesChanged();
	}
}
