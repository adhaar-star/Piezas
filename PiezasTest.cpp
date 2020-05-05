/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
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
/*
Test(PiezasTest, dropInitial)
{
	Piezas unit_test;
	ASSERT_EQ(unit_test.dropPiece(0), X);
}

Test(PiezasTest, dropNext)
{
	Piezas unit_test;
	ASSERT_EQ(unit_test.dropPiece(0), O);
}

Test(PiezasTest, makeColumnfull)
{
	Piezas unit_test;
	ASSERT_EQ(unit_test.dropPiece(0), X);
}

Test(PiezasTest, BlankCheck)
{
	Piezas unit_test;
	ASSERT_EQ(unit_test.dropPiece(0), Blank);
}

Test(PiezasTest, dropOutofBonds)
{
	Piezas unit_test;
	ASSERT_EQ(unit_test.dropPiece(5), Invalid);
}

Test(PiezasTest, GameNotOver){
	Piezas unit_test;
	ASSERT_EQ(unit_test.gameState(), Invalid);
}

Test(PiezasTest, checkWinner){
	Piezas unit_test;
	 for(int j=0; j<BOARD_ROWS;j++){
    for(int i=0; i<BOARD_COLS;i++){
		if(board[i][j] == Blank)
        unit_test.dropPiece(X);      
    }
	 }
	 ASSERT_EQ(unit_test.gameState(), X);
	
}
*/
