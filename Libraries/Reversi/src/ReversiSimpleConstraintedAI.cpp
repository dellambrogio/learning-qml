
#include "Reversi/ReversiSimpleConstraintedAI.hpp"

#include "Reversi/Reversi.hpp"

#include "RandomUtil.hpp"

namespace rv
{
	ReversiSimpleConstraintedAI::ReversiSimpleConstraintedAI(ETile tile, const std::shared_ptr<Reversi> game)
		: m_tile(tile)
		, m_game(game)
	{
		m_strategicWeights.fill(1.f);

		// corners
		m_strategicWeights(0, 0) = 4.f;
		m_strategicWeights(0, 7) = 4.f;
		m_strategicWeights(7, 0) = 4.f;
		m_strategicWeights(7, 7) = 4.f;

		// centers
		for (int x=2; x<6; ++x)
			for (int y=2; y<6; ++y)
				m_strategicWeights(x, y) = 2.f;

		// around corner
		m_strategicWeights(1, 1) = 0.5f;
		m_strategicWeights(1, 0) = 0.5f;
		m_strategicWeights(0, 1) = 0.5f;

		m_strategicWeights(0, 6) = 0.5f;
		m_strategicWeights(1, 6) = 0.5f;
		m_strategicWeights(1, 7) = 0.5f;

		m_strategicWeights(6, 0) = 0.5f;
		m_strategicWeights(6, 1) = 0.5f;
		m_strategicWeights(7, 1) = 0.5f;

		m_strategicWeights(6, 6) = 0.5f;
		m_strategicWeights(7, 6) = 0.5f;
		m_strategicWeights(6, 7) = 0.5f;
	}

	ReversiSimpleConstraintedAI::~ReversiSimpleConstraintedAI()
	{

	}

	bool ReversiSimpleConstraintedAI::makeNextMove()
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

	std::vector<Eigen::Vector2i> ReversiSimpleConstraintedAI::getNextBestMoves() const
	{
		std::vector<Eigen::Vector2i> bestMoves;
		float maxWeight = 0;

		const std::vector<Eigen::Vector2i> validMoves = m_game->getValidMoves(m_tile);

		for (const Eigen::Vector2i &move : validMoves)
		{
			const unsigned sinpleWeight = m_game->tilesToFlip(move(0), move(1), m_tile).size();
			const float weight = sinpleWeight * m_strategicWeights(move(0), move(1));

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

