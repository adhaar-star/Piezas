/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
 using namespace std;

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, drop_X)
{
	Piezas unit_test;
	ASSERT_EQ(unit_test.dropPiece(0), X);
}

TEST(PiezasTest, drop_O)
{
	Piezas unit_test;
	unit_test.dropPiece(7);
	ASSERT_EQ(unit_test.dropPiece(0), O);
}


TEST(PiezasTest, drop_in_full_col)
{
	Piezas unit_test;
	unit_test.dropPiece(0);
	unit_test.dropPiece(0);
	unit_test.dropPiece(0);
	ASSERT_EQ(unit_test.dropPiece(0), Blank);
}
TEST(PiezasTest, drop_out_of_bounds)
{
	Piezas unit_test;
	ASSERT_EQ(unit_test.dropPiece(5), Invalid);
}



TEST(PiezasTest, piece_at_out_of_bounds)
{
	Piezas unit_test;
	ASSERT_EQ(unit_test.pieceAt(6,0), Invalid);
}

TEST(PiezasTest, piece_in_bounds)
{
	Piezas unit_test;
	unit_test.dropPiece(0);
	ASSERT_EQ(unit_test.pieceAt(BOARD_ROWS-1,0), X);
}





TEST(PiezasTest, game_not_over)
{
	Piezas unit_test;
//	unit_test.dropPiece(0);
	ASSERT_EQ(unit_test.gameState(), Invalid);
}

Test(PiezasTest, game_winner_X){
	Piezas test;
	 
    for(int i=BOARD_ROWS-1; i>0;i--){
		for(int j=0; j<BOARD_ROWS;j++){
        test.dropPiece(j);      
    }
	}
	 
	 ASSERT_EQ(test.gameState(), X);
	
}

