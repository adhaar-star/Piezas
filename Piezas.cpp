#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
using namespace std;

Piezas::Piezas()
{
 
    turn = X;
    board.resize(BOARD_ROWS);


    for(unsigned i=0; i<board.size();i++){
       board[i].resize(BOARD_COLS);
    }
    reset();
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
     for(unsigned i=0; i<board.size();i++){
         for(unsigned j=0; j<board[i].size();j++){

board[i][j] = Blank;
         }
     }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece return_value;
    
      return_value = Blank; //default value

    if(column>=BOARD_COLS){
         
    return_value = Invalid;
    }
   
  
for(unsigned i=BOARD_ROWS-1;i>0;i--){
  if(board[i][column]==Blank){
        
       board[i][column] = turn;
     
    return_value =  board[i][column];
  }
        
   }
     
     
     if(turn==X){
        turn = O;
    }
    else{
        turn = X;
    }
    return return_value;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row>= BOARD_ROWS || column >= BOARD_COLS)
    return Invalid;

    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  

     int X_horizontal_count = 0;
        int X_vertical_count = 0;
      int O_horizontal_count = 0;
        int O_vertical_count = 0;


    for( unsigned i = 0; i < BOARD_ROWS; i++ )
    {
        for( unsigned j = 0; j < BOARD_COLS; j++ )
        {
            if( board[i][j] == Blank)
                return Invalid;
        }
    }
// Horizontal X count
     for(unsigned i=0; i<board.size();i++){
         bool check_all = true;
         for(unsigned j=0; j<board[i].size();j++){
      if(board[i][j]==O)
  check_all = false;
         }
         if(check_all==true)
         X_horizontal_count++;
     }

     // Horizontal O count
     for(unsigned i=0; i<board.size();i++){
         bool check_all = true;
         for(unsigned j=0; j<board[i].size();j++){
      if(board[i][j]==X)
  check_all = false;
         }
         if(check_all==true)
         O_horizontal_count++;
     }

// Vertical X count
     for(unsigned j=0; j<BOARD_COLS;j++){
           bool check_all = true;
    for(unsigned i=0; i<BOARD_ROWS;i++){
        if(board[i][j]==O)
  check_all = false;
         }
          if(check_all==true)
         X_vertical_count++;
    }

     // Vertical O count
     for(unsigned j=0; j<BOARD_COLS;j++){
           bool check_all = true;
    for(unsigned i=0; i<BOARD_ROWS;i++){
        if(board[i][j]==X)
  check_all = false;
         }
          if(check_all==true)
         O_vertical_count++;
    }

//Getting winner 
    if(X_horizontal_count<O_horizontal_count){
        return O;
    }
    else if(O_horizontal_count<X_horizontal_count){
        return X;
    }
    else {

 if(X_vertical_count<O_vertical_count){
        return O;
    }
    else if(O_vertical_count<X_vertical_count){
        return X;
    }
    else{
        return Blank;
    }
        
    }

    
}