
/*
design implementation:

Alpha Beta Pruning with memoization of best scores, 

ToDo list : 

          -Zobrist hashing
            - lookup() function that will look info on current position and return
                        its hashing code if position is found in table (before evaluation)
            - store() function that will store the info on current position if the state
                      wasn't found earlier in the table (after evaluation usually at the very end)
              
          -Quiescent search
            will need to use it for moves who seems rather interesting,
            it will perform a local search around that move to see if it's really a good
            move (need more info on how it should work)
            if there is a capture, then we do a quiescence search for all those captures

          

*/
#include "database.h"


class Player;
class Board;

class Skynet{

private:

public:


  Skynet();
  ~Skynet();


  //returns the best move
  vector<int> _alphaBeta(Game*, Board [SIZEROW][SIZECOL], Player, Player, Piece*, int, DataBase*);

  //search methods for alphabeta pruning
  int _minSearch(Game*,  Board [SIZEROW][SIZECOL], Player, Player, Piece*, int, int, int, bool, int, bool, DataBase*);
  int _maxSearch(Game*,  Board [SIZEROW][SIZECOL], Player, Player,Piece*, int, int, int, bool, int, bool, DataBase*);

  //compute the score
  int _costFun(Game*,  Board [SIZEROW][SIZECOL], int, bool, Player*, bool);

  //quiescence search method returns the score of the quiescent moves should replace alpha beta tho 
  int _quiescence(Game*, Board [SIZEROW][SIZECOL], int, int, int, bool, Player*, bool);

};
