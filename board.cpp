//Creation de la classe board pour le board game
#include <iostream>
#include "board.h"


//Surcharge du constructeur Board
Board::Board(){

  //initialise un board de chess avec des pointeurs null
  p = nullptr;

}

Board::~Board(){};
Board::Board(Piece * piece){
  p = piece;
}
