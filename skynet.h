

//fuck this is tough
/*
design implementation:

i'll start with a function that will do popular oppening move sets randomly,
once this is done, the alphabeta algorithm will kick in
and to get rid of the horizon effect ill check the quiescent algorithm and voila

*/
#include "game.h"


class Player;
class Board;

class Skynet{

private:

public:


  Skynet();
  ~Skynet();
  // _searchMinNodes

  //returns the best move
  vector<int> _alphaBeta(Game*, Board [SIZEROW][SIZECOL], Player, Player, Piece*, int);

  //search methods for alphabeta pruning
  int _minSearch(Game*,  Board [SIZEROW][SIZECOL], Player, Player, Piece*, int, int, int, bool, int, bool);
  int _maxSearch(Game*,  Board [SIZEROW][SIZECOL], Player, Player,Piece*, int, int, int, bool, int, bool);

  //compute the score
  int _costFun(Game*,  Board [SIZEROW][SIZECOL], int, bool, Player*);

};
