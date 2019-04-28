#include "piece.h"


Piece::Piece(){}
Piece::~Piece(){}
Piece::Piece(int x, char y, int z){

  firstMove = true;
  pieceTurn = x;
  pieceType = y;
  piecePoints = z;
  isPromoted = false;
  promotionMoves = 0;

}


void Piece::_setPieceType(char y){
  pieceType = y;
}

void Piece::_setPieceTurn(int x){
  pieceTurn = x;
}

void Piece::_setFirstMove(bool doneFirstMove){
  firstMove = doneFirstMove;
}

void Piece::_setPiecePromotion(bool promote){
  isPromoted = promote;
}

void Piece::_incPiecePromotionMoves(){
  promotionMoves++;
}

void Piece::_decPiecePromotionMoves(){
  promotionMoves--;
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

bool Piece::_getPiecePromotion(){
  return isPromoted;
}

int Piece::_getPiecePromMoves(){
  return promotionMoves;
}
