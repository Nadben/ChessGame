

//fuck this is tough
/*
design implementation:

i'll start with a function that will do popular oppening move sets randomly,
once this is done, the alphabeta algorithm will kick in
and to get rid of the horizon effect ill check the quiescent algorithm and voila

*/

#include <tuple>

class Skynet : public Player{
private:
  // Game game; // the idea is that i could recycle some functions from the game



public:


  Skynet();
  ~Skynet();
  // _searchMinNodes

  //returns the score of that move
  int _alphaBeta(tuple<int,int>, int, int, int, bool);
  //compute the score
  int _costFun();


}
