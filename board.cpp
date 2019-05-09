#include <iostream>
#include "board.h"



Board::Board(){

  //initialise a pointer to a piece once a board object is created
  p = nullptr;

}

Board::~Board(){};
Board::Board(Piece * piece){
  p = piece;
}
