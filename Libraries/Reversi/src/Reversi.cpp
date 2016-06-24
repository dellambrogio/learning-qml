
#include "Reversi/Reversi.hpp"

#include <stdexcept>

namespace rv
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

	bool Reversi::isValidMove(int x, int y, ETile tile) const
	{
		return ! tilesToFlip(x, y, tile).empty();
	}

	std::vector<Eigen::Vector2i> Reversi::getValidMoves(ETile tile) const
	{
		std::vector<Eigen::Vector2i> moves;

		for (int x=0; x<8; ++x)
		{
			for (int y=0; y<8; ++y)
			{
				if (isValidMove(x, y, tile))
					moves.push_back(Eigen::Vector2i(x, y));
			}
		}

		return moves;
	}

	std::vector<Eigen::Vector2i> Reversi::tilesToFlip(int x, int y, ETile tile) const
	{
		std::vector<Eigen::Vector2i> positions;

		if (! isOnBoard(x, y))
			return positions;

		if (m_tiles(x, y) != ETile::Unknown)
			return positions;

		for (int dx=-1; dx<=1; ++dx)
		{
			for (int dy=-1; dy<=1; ++dy)
			{
				if (dx==0 && dy==0)
					continue;

				int px = x + dx;
				int py = y + dy;

				std::vector<Eigen::Vector2i> _positions;
				bool myTileFound = false;

				while(isOnBoard(px, py) && !myTileFound)
				{
					if (m_tiles(px, py) == opponent(tile))
						_positions.push_back(Eigen::Vector2i(px, py));
					else if (m_tiles(px, py) == tile)
						myTileFound = true;
					else
						break;

					px += dx;
					py += dy;
				}

				if (myTileFound)
				{
					positions.insert(positions.end(), _positions.begin(), _positions.end());
				}
			}
		}

		return positions;
	}

	bool Reversi::makeMove(int x, int y, ETile tile)
	{
		const std::vector<Eigen::Vector2i> positions = tilesToFlip(x, y, tile);

		for (auto pos: positions)
		{
			m_tiles(pos(0), pos(1)) = tile;
		}

		return ! positions.empty();
	}

	const TMatrix &Reversi::getTiles() const
	{
		return m_tiles;
	}

	void Reversi::setTiles(const TMatrix &tiles)
	{
		m_tiles = tiles;
	}
}
