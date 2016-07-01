
#include "Reversi/ReversiSimpleAI.hpp"

#include "Reversi/Reversi.hpp"

#include "RandomUtil.hpp"

namespace rv
{
	ReversiSimpleAI::ReversiSimpleAI(ETile tile, const std::shared_ptr<Reversi> game)
		: m_tile(tile)
		, m_game(game)
	{

	}

	ReversiSimpleAI::~ReversiSimpleAI()
	{

	}

	bool ReversiSimpleAI::makeNextMove()
	{
		const std::vector<Eigen::Vector2i> bestMoves = getNextBestMoves();

		if (bestMoves.empty())
		{
			return false;
		}
		else
		{
			Eigen::Vector2i move = *random_element(bestMoves.begin(), bestMoves.end());
			return m_game->makeMove(move(0), move(1), m_tile);
		}
	}

	std::vector<Eigen::Vector2i> ReversiSimpleAI::getNextBestMoves() const
	{
		std::vector<Eigen::Vector2i> bestMoves;
		unsigned maxWeight = 0;

		const std::vector<Eigen::Vector2i> validMoves = m_game->getValidMoves(m_tile);

		for (const Eigen::Vector2i &move : validMoves)
		{
			const unsigned weight = m_game->tilesToFlip(move(0), move(1), m_tile).size();
			if (weight == maxWeight)
			{
				bestMoves.push_back(move);
			}
			else if (weight >= maxWeight)
			{
				bestMoves.clear();
				bestMoves.push_back(move);
				maxWeight = weight;
			}
		}

		return bestMoves;
	}

}

