
#ifndef QREVERSI_GAMECONTEXT_HPP
#define QREVERSI_GAMECONTEXT_HPP

#include <Reversi/Reversi.hpp>

class GameContext
{
public:
	GameContext();

	const rv::Reversi &reversi() const;

	bool makeMove(int idx);

	rv::ETile currentTile() const;
	void setCurrentTile(const rv::ETile &currentTile);

	bool gameIsFinished() const;

private:
	rv::Reversi m_reversi;
	rv::ETile m_currentTile;
	std::vector<Eigen::Vector2i> m_currentValidMoves;
};

#endif
