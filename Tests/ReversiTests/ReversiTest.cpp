
#include <gtest/gtest.h>

#include <stdexcept>
#include <algorithm>

#include <Reversi/Reversi.hpp>

using namespace rv;

TEST(ReversiTest, Static)
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

	EXPECT_EQ(Reversi::opponent(ETile::Black), ETile::White);
	EXPECT_EQ(Reversi::opponent(ETile::White), ETile::Black);
	EXPECT_EQ(Reversi::opponent(ETile::Unknown), ETile::Unknown);
}

TEST(ReversiTest, Init)
{
	Reversi reversi;

	const TMatrix &tiles = reversi.getTiles();

	EXPECT_EQ(tiles(3, 3), ETile::White);
	EXPECT_EQ(tiles(4, 3), ETile::Black);
	EXPECT_EQ(tiles(3, 4), ETile::Black);
	EXPECT_EQ(tiles(4, 4), ETile::White);

	std::map<ETile, int> score = reversi.getScore();

	EXPECT_EQ(score[ETile::Unknown], 60);
	EXPECT_EQ(score[ETile::Black], 2);
	EXPECT_EQ(score[ETile::White], 2);
}

TEST(ReversiTest, isValidMove)
{
	Reversi reversi;

	EXPECT_FALSE(reversi.isValidMove(0, 0, ETile::Black));
	EXPECT_FALSE(reversi.isValidMove(8, 8, ETile::Black));
	EXPECT_FALSE(reversi.isValidMove(0, 0, ETile::White));
	EXPECT_FALSE(reversi.isValidMove(8, 8, ETile::White));

	EXPECT_TRUE(reversi.isValidMove(2, 3, ETile::Black));
	EXPECT_TRUE(reversi.isValidMove(3, 2, ETile::Black));
	EXPECT_TRUE(reversi.isValidMove(4, 5, ETile::Black));
	EXPECT_TRUE(reversi.isValidMove(5, 4, ETile::Black));

	EXPECT_FALSE(reversi.isValidMove(2, 3, ETile::White));
	EXPECT_FALSE(reversi.isValidMove(3, 2, ETile::White));
	EXPECT_FALSE(reversi.isValidMove(4, 5, ETile::White));
	EXPECT_FALSE(reversi.isValidMove(5, 4, ETile::White));

	EXPECT_TRUE(reversi.isValidMove(2, 4, ETile::White));
	EXPECT_TRUE(reversi.isValidMove(4, 2, ETile::White));
	EXPECT_TRUE(reversi.isValidMove(3, 5, ETile::White));
	EXPECT_TRUE(reversi.isValidMove(5, 3, ETile::White));

	EXPECT_FALSE(reversi.isValidMove(2, 4, ETile::Black));
	EXPECT_FALSE(reversi.isValidMove(4, 2, ETile::Black));
	EXPECT_FALSE(reversi.isValidMove(3, 5, ETile::Black));
	EXPECT_FALSE(reversi.isValidMove(5, 3, ETile::Black));
}

TEST(ReversiTest, validMoves)
{
	Reversi reversi;

	std::vector<Eigen::Vector2i> blacks = reversi.getValidMoves(ETile::Black);

	EXPECT_EQ(blacks.size(), 4);

	EXPECT_EQ(std::count(blacks.begin(), blacks.end(), Eigen::Vector2i(0, 0)), 0);
	EXPECT_EQ(std::count(blacks.begin(), blacks.end(), Eigen::Vector2i(2, 3)), 1);
	EXPECT_EQ(std::count(blacks.begin(), blacks.end(), Eigen::Vector2i(3, 2)), 1);
	EXPECT_EQ(std::count(blacks.begin(), blacks.end(), Eigen::Vector2i(4, 5)), 1);
	EXPECT_EQ(std::count(blacks.begin(), blacks.end(), Eigen::Vector2i(5, 4)), 1);
}

TEST(ReversiTest, tilesToFlip)
{
	Reversi reversi;

	const std::vector<Eigen::Vector2i> blacks = reversi.tilesToFlip(2, 3, ETile::Black);
	EXPECT_EQ(blacks.size(), 1);
	EXPECT_EQ(blacks[0], Eigen::Vector2i(3, 3));

	const std::vector<Eigen::Vector2i> whites = reversi.tilesToFlip(2, 4, ETile::White);
	EXPECT_EQ(whites.size(), 1);
	EXPECT_EQ(whites[0], Eigen::Vector2i(3, 4));
}
