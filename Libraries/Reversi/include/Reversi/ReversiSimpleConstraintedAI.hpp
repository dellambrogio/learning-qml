
#ifndef REVERSI_REVERSI_SIMPLE_CONSTRAINTED_AI_HPP
#define REVERSI_REVERSI_SIMPLE_CONSTRAINTED_AI_HPP

#include <memory>
#include <vector>

#include <Eigen/Dense>

#include <Reversi/Tile.hpp>

namespace rv
{
	class Reversi;

	class ReversiSimpleConstraintedAI
	{
	public:
		ReversiSimpleConstraintedAI(ETile tile, const std::shared_ptr<Reversi> game);

		bool makeNextMove();

		std::vector<Eigen::Vector2i> getNextBestMoves() const;

	private:
		const ETile m_tile;
		std::shared_ptr<Reversi> m_game;
	};
}

#endif
