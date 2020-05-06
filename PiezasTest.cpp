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
/*

Test(PiezasTest, make_column_full)
{
	Piezas test;
	ASSERT_EQ(test.dropPiece(0), X);
}

Test(PiezasTest, BlankCheck)
{
	Piezas test;
	ASSERT_EQ(test.dropPiece(0), Blank);
}

Test(PiezasTest, dropOutofBonds)
{
	Piezas test;
	ASSERT_EQ(test.dropPiece(5), Invalid);
}

Test(PiezasTest, GameNotOver){
	Piezas test;
	ASSERT_EQ(test.gameState(), Invalid);
}

Test(PiezasTest, checkWinner){
	Piezas test;
	 for(int j=0; j<BOARD_ROWS;j++){
    for(int i=0; i<BOARD_COLS;i++){
		if(board[i][j] == Blank)
        test.dropPiece(X);      
    }
	 }
	 ASSERT_EQ(test.gameState(), X);
	
}
*/
