
// to do add player attribute pieces captured**
#include <iostream>
#include <string>
#include <vector>
#include <tuple>


//forward definition of class piece so i can use the vector of
//piece
class Piece;

using namespace std;

//add  attribute player is checked
//add attribute points


class Player{

private:
  string m_name;
  int m_type;
  vector<Piece*> pieceCaptured;
  bool playerChecked;
  int m_points;
  int consecutiveCheck;
  tuple<int, int> kingPos;
  tuple<int, int> rookPos;



public:
  Player(int,int,int);
  ~Player();
  // vector<Piece*> pieceCaptured;
  string _getPlayerName() const;
  int _getPlayerType() const; //either human or AI
  vector<Piece*> _getPieceCaptured() const;
  void _setPieceCaptured(Piece*);
  int _getPlayerPoints();
  Piece* _returnPlayerPieceCaptured(char);

  tuple<int,int> _getPlayerKingPos();
  void _setPlayerKingPos(int,int);


  //player is playerChecked
  void _setPlayerStatus();
  bool _getPlayerStatus();

  //consecutive check
  void _incPlayerConsCheck();
  void _resetPlayerConsCheck();
  int _getPLayerConsCheck();


};
