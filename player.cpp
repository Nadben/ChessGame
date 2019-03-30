#include "player.h"
#include "piece.h"



Player::Player(int type, int x, int y){
  string name = "";
  // make_heap(pieceCaptured.begin(),pieceCaptured.end());

  cout << "input the name of player " << type <<" : " ;
  cin >> name;


  m_type = type;
  m_name = name;
  m_points = 0;

  get<0>(kingPos) = x;
  get<1>(kingPos) = y;


  playerChecked = false;
  consecutiveCheck = 0;
  pieceCaptured;

}

Player::~Player(){}


//me permet d'acceder aux attributs private de mon objet player
string Player::_getPlayerName() const {
  return m_name;

}

int Player::_getPlayerType() const {
  return m_type;

}

vector<Piece*> Player::_getPieceCaptured() const{
  return pieceCaptured;
}

void Player::_setPieceCaptured(Piece* p){

  pieceCaptured.push_back(p);

  m_points += p->_getPiecePoints();

}

// this method will return the piece to the player if
// the condition are met and will also lose the points associated with
// the piece returned.
Piece* Player::_returnPlayerPieceCaptured(char p){
  //search for the corresponding piece and return it
  Piece* pieceReturned;

  int i = 0;
  for(auto it : pieceCaptured){
    if(it->_getPieceType() == p){
      pieceReturned = it;
      break;
    }
    i += 1;

  }

  pieceCaptured.erase(pieceCaptured.begin()+i);
  m_points -= pieceReturned->_getPiecePoints();

  return pieceReturned;

}


int Player::_getPlayerPoints(){
  return m_points;
}



void Player::_setPlayerKingPos(int toX, int toY){
  get<0>(kingPos) = toX;
  get<1>(kingPos) = toY;
}

tuple<int,int> Player::_getPlayerKingPos(){
  return kingPos;
}



void Player::_setPlayerStatus(){
  playerChecked = playerChecked == false ? true : false;
}

bool Player::_getPlayerStatus(){
  return playerChecked;
}

void Player::_incPlayerConsCheck(){
  consecutiveCheck += 1;
}

void Player::_resetPlayerConsCheck(){
  consecutiveCheck = 0;
}

int Player::_getPLayerConsCheck(){
  return consecutiveCheck;
}
