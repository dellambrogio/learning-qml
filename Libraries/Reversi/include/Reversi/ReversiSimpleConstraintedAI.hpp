
#ifndef REVERSI_REVERSI_SIMPLE_CONSTRAINTED_AI_HPP
#define REVERSI_REVERSI_SIMPLE_CONSTRAINTED_AI_HPP

#include <memory>
#include <vector>

#include <Eigen/Dense>

#include <Reversi/Tile.hpp>

#include <Reversi/ReversiAI.hpp>

namespace rv
{
	class Reversi;

	class ReversiSimpleConstraintedAI : public ReversiAI
	{
	public:
		ReversiSimpleConstraintedAI(ETile tile, const std::shared_ptr<Reversi> game);
		virtual ~ReversiSimpleConstraintedAI();

		virtual bool makeNextMove();

		virtual std::vector<Eigen::Vector2i> getNextBestMoves() const;

	private:
		const ETile m_tile;
		std::shared_ptr<Reversi> m_game;
		Eigen::Matrix<float, 8, 8> m_strategicWeights;
	};
}

#endif
