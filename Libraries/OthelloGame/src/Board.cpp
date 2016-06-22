
#include "OthelloGame/Board.hpp"

#include <stdexcept>

namespace oth
{
	Board::Board()
	 : m_board()
	{
		init();
	}

	void Board::init()
	{
		m_board.fill(EStone::Unknown);
		m_board(4, 4) = EStone::White;
		m_board(5, 4) = EStone::Black;
		m_board(4, 5) = EStone::Black;
		m_board(5, 5) = EStone::White;
	}

	void Board::setStone(const int r, const int c, const EStone stone)
	{
		// check of place is empty
		if (m_board(r, c) != EStone::Unknown)
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
							&& m_board(pR, pC) != EStone::Unknown
							&& m_board(pR, pC) != stone)
				{
					m_board(pR, pC) = stone;
					pR += dR;
					pC += dC;
				}
			}
		}
	}

	void Board::countStones(int &black, int &white) const
	{
		black = 0;
		white = 0;

		for (int r=0; r<8; ++r)
		{
			for (int c=0; c<8; ++c)
			{
				if (m_board(r, c) == EStone::White)
					white++;
				else if (m_board(r, c) == EStone::Black)
					black++;
			}
		}
	}

	const Board::TMatrix &Board::matrix() const
	{
		return m_board;
	}

	EStone Board::opponent(const EStone stone)
	{
		if (stone == EStone::White)
			return EStone::Black;
		else if (stone == EStone::Black)
			return EStone::White;
		else
			return stone;
	}
}
