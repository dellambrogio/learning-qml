
#include "Reversi/ReversiAI.hpp"

#include "Reversi/Reversi.hpp"

template <typename I>
I random_element(I begin, I end)
{
	const unsigned long n = std::distance(begin, end);
	const unsigned long rmax = RAND_MAX;
	const unsigned long divisor = (rmax + 1) / n;

	unsigned long k;
	do { k = std::rand() / divisor; } while (k >= n);

	std::advance(begin, k);
	return begin;
}

namespace rv
{
	ReversiAI::ReversiAI(ETile tile, const std::shared_ptr<Reversi> game)
		: m_tile(tile)
		, m_game(game)
	{

	}

	bool ReversiAI::makeNextMove()
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

	std::vector<Eigen::Vector2i> ReversiAI::getNextBestMoves() const
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

