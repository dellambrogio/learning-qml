
#ifndef REVERSI_REVERSI_AI_HPP
#define REVERSI_REVERSI_AI_HPP

#include <vector>

#include <Eigen/Dense>

#include <Reversi/ReversiAI.hpp>

namespace rv
{
	class ReversiAI
	{
	public:
		virtual ~ReversiAI() {}

		virtual bool makeNextMove() = 0;

		virtual std::vector<Eigen::Vector2i> getNextBestMoves() const = 0;

	protected:

	};
}

#endif
