
#include "Reversi/Reversi.hpp"

#include <stdexcept>

namespace rev
{
	Reversi::Reversi()
	 : m_tiles()
	{
		m_tiles.fill(ETile::Unknown);
		m_tiles(4, 4) = ETile::White;
		m_tiles(5, 4) = ETile::Black;
		m_tiles(4, 5) = ETile::Black;
		m_tiles(5, 5) = ETile::White;
	}

	bool Reversi::isValidMove(int x, int y, ETile tile) const
	{
		return false;
	}

	bool Reversi::isOnBoard(int x, int y)
	{
		return x >=0 && x<8 && y >=0 && y<8;
	}

	bool Reversi::isOnCorner(int x, int y)
	{
		return (x == 0 && y == 0) || (x == 7 && y == 0) || (x == 0 && y == 7) || (x == 7 && y == 7);
	}

	ETile Reversi::opponent(ETile tile)
	{
		if (tile == ETile::White)
			return ETile::Black;
		else if (tile == ETile::Black)
			return ETile::White;
		else
			return tile;
	}

	std::map<ETile, int> Reversi::getScore() const
	{
		int black = 0;
		int white = 0;
		int unknown = 0;

		for (int x=0; x<8; ++x)
		{
			for (int y=0; y<8; ++y)
			{
				if (m_tiles(x, y) == ETile::White)
					white++;
				else if (m_tiles(x, y) == ETile::Black)
					black++;
				else
					unknown++;
			}
		}

		std::map<ETile, int> score;
		score[ETile::Unknown] = unknown;
		score[ETile::Black] = black;
		score[ETile::White] = white;

		return score;
	}

	std::vector<Eigen::Vector2i> Reversi::getValidMoves(ETile tile) const
	{
		std::vector<Eigen::Vector2i> moves;

		return moves;
	}

	bool Reversi::makeMove(int x, int y, ETile tile)
	{
		return false;
	}

	const TMatrix &Reversi::getTiles() const
	{
		return m_tiles;
	}

	void Reversi::setTiles(const TMatrix &tiles)
	{
		m_tiles = tiles;
	}

	/*
	void Reversi::setStone(int r, int c, ETile stone)
	{
		// check of place is empty
		if (m_board(r, c) != ETile::Unknown)
			throw std::runtime_error("cannot place stone");

		// check if one opponent is in the neighbor
		bool opponentNeighborFound = false;
		for (int dR=-1; dR<=1; ++dR)
		{
			for (int dC=-1; dC<=1; ++dC)
			{
				int pR = r + dR;
				int pC = c + dC;
				if (pR >=0 && pR<8 && pC >=0 && pC<8
						&& m_board(pR, pC) == opponent(stone))
				{
					opponentNeighborFound = true;
				}
			}
		}
		if (! opponentNeighborFound)
			throw std::runtime_error("cannot place stone, no opponent neighbor found");

		// change colors
		m_board(r, c) = stone;

		for (int dR=-1; dR<=1; ++dR)
		{
			for (int dC=-1; dC<=1; ++dC)
			{
				int pR = r + dR;
				int pC = c + dC;
				while(pR >=0 && pR<8 && pC >=0 && pC<8
							&& m_board(pR, pC) != ETile::Unknown
							&& m_board(pR, pC) != stone)
				{
					m_board(pR, pC) = stone;
					pR += dR;
					pC += dC;
				}
			}
		}
	}

	void Reversi::countStones(int &black, int &white) const
	{
		black = 0;
		white = 0;

		for (int r=0; r<8; ++r)
		{
			for (int c=0; c<8; ++c)
			{
				if (m_board(r, c) == ETile::White)
					white++;
				else if (m_board(r, c) == ETile::Black)
					black++;
			}
		}
	}

	const TMatrix &Reversi::matrix() const
	{
		return m_board;
	}

	ETile Reversi::opponent(const ETile stone)
	{
		if (stone == ETile::White)
			return ETile::Black;
		else if (stone == ETile::Black)
			return ETile::White;
		else
			return stone;
	}
	*/
}
