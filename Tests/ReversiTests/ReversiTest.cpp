
#include <gtest/gtest.h>

#include <stdexcept>
#include <Reversi/Reversi.hpp>

using namespace rev;

TEST(BoardTest, Static)
{
	for (int x=0; x<8; ++x)
	{
		for (int y=0; y<8; ++y)
		{
			EXPECT_TRUE(Reversi::isOnBoard(x, y));
		}
	}

	EXPECT_FALSE(Reversi::isOnBoard(8, 8));
	EXPECT_FALSE(Reversi::isOnBoard(7, 8));
	EXPECT_FALSE(Reversi::isOnBoard(8, 7));
	EXPECT_FALSE(Reversi::isOnBoard(-1, 0));
	EXPECT_FALSE(Reversi::isOnBoard(-1, -1));
	EXPECT_FALSE(Reversi::isOnBoard(0, -1));

	EXPECT_TRUE(Reversi::isOnCorner(0, 0));
	EXPECT_TRUE(Reversi::isOnCorner(0, 7));
	EXPECT_TRUE(Reversi::isOnCorner(7, 0));
	EXPECT_TRUE(Reversi::isOnCorner(7, 7));

	for (int x=1; x<7; ++x)
	{
		for (int y=1; y<7; ++y)
		{
			EXPECT_FALSE(Reversi::isOnCorner(x, y));
		}
	}
}

TEST(BoardTest, Init)
{
	Reversi reversi;

	const TMatrix &tiles = reversi.getTiles();

	EXPECT_EQ(tiles(4, 4), ETile::White);
	EXPECT_EQ(tiles(5, 4), ETile::Black);
	EXPECT_EQ(tiles(4, 5), ETile::Black);
	EXPECT_EQ(tiles(5, 5), ETile::White);

}

//TEST(BoardTest, Simple)
//{
//	Reversi reversi;

//	int cblack = 0;
//	int cwhite = 0;

//	reversi.countStones(cblack, cwhite);
//	EXPECT_EQ(cblack, 2);
//	EXPECT_EQ(cwhite, 2);

//	reversi.setStone(5, 6, ETile::Black);
//	reversi.countStones(cblack, cwhite);
//	EXPECT_EQ(cblack, 4);
//	EXPECT_EQ(cwhite, 1);

//	ASSERT_THROW(reversi.setStone(5, 6, ETile::Black), std::runtime_error);
//}

