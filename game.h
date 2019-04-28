#include <iostream>
#include <utility>
#include <array>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <tuple>
#include <map>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>

#include "board.h"
#include "player.h"
// #include "skynet.h"


class Game {
private:
public:

  Game();
  ~Game();

  // i should really pass the reference to the board
  //rather than the copy of it

  void initialiseBoard(list<Piece> &, Board [SIZEROW][SIZECOL]);
  void displayBoard(const Board [SIZEROW][SIZECOL], ostream & out = cout) const;
  vector<int> askPlayerPiece(Board [SIZEROW][SIZECOL], Player*, vector<int>*);
  vector<tuple<int,int>> legalMoves(Board [SIZEROW][SIZECOL], int, vector<int>*, vector<tuple<int,int>>*, Player*);
  vector<int> askPlayerMove(Board [SIZEROW][SIZECOL], vector<int>*, vector<tuple<int,int>>);

  //complicated one for sure
  bool isMoveSafe(Board [SIZEROW][SIZECOL], Player*, Piece*, vector<int>*, vector<tuple<int,int>>*, bool);
  bool isMoveChecking(Board [SIZEROW][SIZECOL], tuple<int,int>, vector<int>*, vector<tuple<int,int>>*, int);

  void movePiece(Board [SIZEROW][SIZECOL], vector<int>*, Piece*, Player* );
  void undoMove(Board [SIZEROW][SIZECOL], vector<int>*, Piece*, Piece*, Piece*, Player* );

  int updateTurnOfPlayer(Player*);
  void displayEatenPieces(Player*);
  void displayCheck(Player*, bool);
  void displayPlayerInfo(Player*);

  void pionSwitch(Board [SIZEROW][SIZECOL], Player*, Player*, int, vector<int>*);
  bool endGameEval(Board [SIZEROW][SIZECOL], bool, vector<tuple<int,int>>*, Player*, Piece*, int);

  bool PiecePromotion(Board [SIZEROW][SIZECOL], Player*, Player*, int, vector<int>*);
  void UndoPiecePromotion(Board [SIZEROW][SIZECOL], Player*, Player*, int, vector<int>*);

  // void ennemyLegalMoves(Board [SIZEROW][SIZECOL], int, vector<tuple<int,int>>*, Player*);

};
