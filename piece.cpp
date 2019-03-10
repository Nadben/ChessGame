#include "piece.h"


Piece::Piece(){}
Piece::~Piece(){}
Piece::Piece(int x, char y, int z){

  firstMove = true;
  pieceTurn = x;
  pieceType = y;
  piecePoints = z;

}


void Piece::_setPieceType(char y){
  pieceType = y;
}

void Piece::_setPieceTurn(int x){
  pieceTurn = x;
}

void Piece::_setFirstMove(){
  firstMove = false;
}

char Piece::_getPieceType(){
  return pieceType;
}

int Piece::_getPieceTurn(){
  return pieceTurn;
}

bool Piece::_getFirstMove(){
  return firstMove;
}

int Piece::_getPiecePoints(){
  return piecePoints;
}
