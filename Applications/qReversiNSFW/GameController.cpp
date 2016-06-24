
#include "GameController.hpp"

#include <Reversi/Reversi.hpp>


GameController::GameController()
	: QObject()
	, m_currentPlayer(0)
	, m_numBlackStones(0)
	, m_numWhiteStones(0)
{
	for (int idx=0; idx<64; ++idx)
	{
		m_cells.append(new Cell("transparent"));
	}

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
	setCells();
}

void GameController::makeMove(int idx)
{
	const int x = idx % 8;
	const int y = std::floor(idx / 8);

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

		setCells();
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

void GameController::setCells()
{
	const rv::TMatrix &tiles = m_game->getTiles();

	for (int x=0; x<8; ++x)
	{
		for (int y=0; y<8; ++y)
		{
			const int idx = y*8+x;
			Cell* cell = static_cast<Cell*>(m_cells[idx]);

			if (tiles(x, y) == rv::ETile::White)
				cell->setColor("white");
			else if (tiles(x, y) == rv::ETile::Black)
				cell->setColor("black");
			else
				cell->setColor("transparent");
		}
	}

	emit cellsChanged();
}

const QList<QObject *> &GameController::getCells() const
{
	return m_cells;
}
