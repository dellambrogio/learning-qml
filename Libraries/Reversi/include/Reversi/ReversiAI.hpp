
#ifndef REVERSI_REVERSIAI_HPP
#define REVERSI_REVERSIAI_HPP

#include <memory>
#include <vector>

#include <Eigen/Dense>

#include <Reversi/Tile.hpp>

namespace rv
{
	class Reversi;

	class ReversiAI
	{
	public:
		ReversiAI(ETile tile, const std::shared_ptr<Reversi> game);

		bool makeNextMove();

		std::vector<Eigen::Vector2i> getNextBestMoves() const;

	private:
		const ETile m_tile;
		std::shared_ptr<Reversi> m_game;
	};
}

#endif
