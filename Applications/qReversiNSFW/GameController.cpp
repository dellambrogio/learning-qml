
#include "GameController.hpp"

#include "GameContext.hpp"

GameController::GameController()
	: QObject()
{

}

GameController::~GameController()
{

}

QDateTime GameController::getCurrentDateTime() const {
	return QDateTime::currentDateTime();
}

void GameController::newGame()
{
	m_game.reset(new GameContext);
}

void GameController::makeMove(int idx)
{
	if (m_game->makeMove(idx))
	{
		emit stateChanged();
	}
}
