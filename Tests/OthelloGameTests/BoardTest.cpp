
#include <gtest/gtest.h>

#include <stdexcept>
#include <OthelloGame/Board.hpp>

TEST(BoardTest, Simple)
{
	oth::Board board;

	int cblack = 0;
	int cwhite = 0;

	board.countStones(cblack, cwhite);
	EXPECT_EQ(cblack, 2);
	EXPECT_EQ(cwhite, 2);

	board.setStone(5, 6, EStone::Black);
	board.countStones(cblack, cwhite);
	EXPECT_EQ(cblack, 4);
	EXPECT_EQ(cwhite, 1);

	ASSERT_THROW(board.setStone(5, 6, EStone::Black), std::runtime_error);
}
