
#ifndef OTHELLO_GAME_BOARD_HPP
#define OTHELLO_GAME_BOARD_HPP

#include <Eigen/Dense>
#include <OthelloGame/Stone.hpp>

namespace oth
{
	class Board
	{
	public:
		typedef Eigen::Matrix<EStone, 8, 8> TMatrix;

	public:
		Board();

		void init();

		void setStone(const int r, const int c, const EStone stone);

		void countStones(int &black, int &white) const;

		const TMatrix &matrix() const;

		static EStone opponent(const EStone stone);

	private:
		TMatrix m_board;
	};
}

#endif
