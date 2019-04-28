


#include "skynet.h"
// int i=0;

using namespace std;


Skynet::Skynet(){}
Skynet::~Skynet(){}

/*
i'll receive the board and i'll recursively play all the position
until i reach a leaf, ill then compute the score and retropropagate
it up to the root, with pruning ill be able to branch out some
of the search tree so it will be faster to get an answer, ill start
with a depth of 2 to test things out first.
*/


//we should pass the players copy as well as the board copy now we have all the things we need to do the goddamn algorithm
vector<int> Skynet::_alphaBeta(Game* game, Board chessBoard[SIZEROW][SIZECOL], Player player1, Player player2, Piece* nonPiece, int turnOfPlayer){

  // all my initial vectors and stuff that ill be using for the "fake games" i'll be doing below
  vector<int> position;
  vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> legalMoves;
  tuple<int, int> kingPos;
  vector<int> bestPos;
  vector<int> value;

  bool moveIsSafe = true;
  bool moveIsChecking = false;
  bool gameOver = false;
  bool wasNotPromoted = false;

  int alpha = -999999;
  int beta = 999999 ;
  int maxValue = -999999;
  int depth = 4;
  int oldValue = 0;
  int currBest = 0;
  int oldCurrBest = 0;

  Player* player = turnOfPlayer == 1 ? &player1 : &player2 ;

  // cout<<"fuckoff1"<<endl;
  // for every position calculate the legal moves of the max player
  for(int x = 0; x < SIZECOL; ++x){ // from x
    for(int y = 0; y < SIZEROW; ++y){// from y
      position.clear();
      legalMoves.clear();
      position.push_back(x);
      position.push_back(y);


      //we have to get only the position where there is the current playe pieces
      if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer){
        // compute the legalmoves
        legalMoves = game->legalMoves(chessBoard, turnOfPlayer, &position, &legalMoves, player);
        //if legal moves is not empty then for each legalMoves make the move;
        if(legalMoves.size() != 0){
          for(auto it : legalMoves){
            int toX = get<0>(it);
            int toY = get<1>(it);
            position.push_back(toX);
            position.push_back(toY);
            Piece* fromPiece = chessBoard[x][y].p;
            Piece* toPiece = chessBoard[toX][toY].p;
            //check if the move is safe
            moveIsSafe = game->isMoveSafe(chessBoard, player, nonPiece, &position, &legalMoves, true);

            //if move is safe then do the move
            if(moveIsSafe){

              game->movePiece(chessBoard, &position, nonPiece, player);
              wasNotPromoted = game->PiecePromotion(chessBoard, &player1, &player2, turnOfPlayer, &position);

              turnOfPlayer == 1 ? kingPos = player2._getPlayerKingPos() : kingPos = player1._getPlayerKingPos();
              moveIsChecking = game->isMoveChecking(chessBoard, kingPos, &position, &threatPos, turnOfPlayer);

              if(moveIsChecking){
                player = turnOfPlayer == 1 ? &player2 : &player1 ;
                gameOver = game->endGameEval(chessBoard, moveIsChecking, &threatPos, player, nonPiece, 2);
                player = turnOfPlayer == 1 ? &player1 : &player2 ;

              }

              //else i call the min search for that position

              maxValue = _minSearch(game, chessBoard, player1, player2, nonPiece, depth-1, alpha, beta, false, 2, gameOver);

              value.push_back(maxValue);

              currBest = value[0] ;
              for(auto it : value){
                if(it > currBest){
                  currBest = it;
                }
              }
              
              if(currBest != oldCurrBest){
                bestPos.clear(); //clear vector to input current best move
                bestPos.push_back(x);
                bestPos.push_back(y);
                bestPos.push_back(toX);
                bestPos.push_back(toY);
              }
              oldCurrBest = currBest;

                
              game->undoMove(chessBoard, &position, fromPiece, toPiece, nonPiece, player);
              if(wasNotPromoted){
                game->UndoPiecePromotion(chessBoard, &player1, &player2, turnOfPlayer, &position);
              }

              position.pop_back();
              position.pop_back();

            }else{
              position.push_back(x);
              position.push_back(y);
            }
          }
        }
      }
    }



  }

  return bestPos;

}



//  input  : generic information concerning the game
//  output : the best possible move
int Skynet::_minSearch(Game* game, Board chessBoard[SIZEROW][SIZECOL],Player player1, Player player2, Piece* nonPiece, int depth, int alpha, int beta,
                        bool maximising, int turnOfPlayer, bool gameOver){

  // all my initial vectors and stuff that ill be using for the "fake games" i'll be doing below

  vector<int> position;
  vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> legalMoves;
  bool moveIsSafe = true;
  bool moveIsChecking = false;
  bool wasNotPromoted = false;
  tuple<int, int> kingPos;


  Player* player = turnOfPlayer == 1 ? &player1 : &player2 ;
  // cout<<"fuckoff2"<<endl;


  // if we hit the 0 depth or if we hit an end of game (mate or check mate) then we return the score
  if(depth == 0 or gameOver == true){
    return _costFun(game, chessBoard, turnOfPlayer, maximising, player, gameOver);
  }

  if(!maximising){
    int maxValue = 999999;

    
    for(int x = 0; x < SIZECOL; ++x){ // from x
      for(int y = 0; y < SIZEROW; ++y){// from y
        position.clear();
        legalMoves.clear();
        position.push_back(x);
        position.push_back(y);
        // cout<<"fuckoff2"<<endl;

        //we have to get only the position where there is the current playe pieces
        if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer){
          // compute the legalmoves
          legalMoves = game->legalMoves(chessBoard, turnOfPlayer, &position, &legalMoves, player);
          //if legal moves is not empty then for each legalMoves make the move;
          if(legalMoves.size() != 0){
            for(auto it : legalMoves){
              int toX = get<0>(it);
              int toY = get<1>(it);
              position.push_back(toX);
              position.push_back(toY);
              Piece* fromPiece = chessBoard[x][y].p;
              Piece* toPiece = chessBoard[toX][toY].p;

              // cout<<"the"<<endl;

              //check if the move is safe
              moveIsSafe = game->isMoveSafe(chessBoard, player, nonPiece, &position, &legalMoves, true);

              //if move is safe then do the move
              if(moveIsSafe){
                // cout<<"fuck"<<endl;
              
                game->movePiece(chessBoard, &position, nonPiece, player);
                wasNotPromoted = game->PiecePromotion(chessBoard, &player1, &player2, turnOfPlayer, &position);

                // cout<<"is"<<endl;

                turnOfPlayer == 1 ? kingPos = player2._getPlayerKingPos() : kingPos = player1._getPlayerKingPos();
                moveIsChecking = game->isMoveChecking(chessBoard, kingPos, &position, &threatPos, turnOfPlayer);

                // turnOfPlayer = game->updateTurnOfPlayer(player);
                if(moveIsChecking){
                  // i+=1;
                  // cout<<i<<endl;
                  // cout<<"this"<<endl;
                  // turnOfPlayer = game->updateTurnOfPlayer(player);
                  player = turnOfPlayer == 1 ? &player2 : &player1 ;
                  gameOver = game->endGameEval(chessBoard, moveIsChecking, &threatPos, player, nonPiece, 1);
                  player = turnOfPlayer == 1 ? &player1 : &player2 ;

                }
                // if the move is a game over i compute the score for the move immediately
                //else i call the max search for that position
                // cout<<"shit"<<endl;

                maxValue = min(maxValue, _maxSearch(game, chessBoard, player1, player2, nonPiece, depth-1, alpha, beta, true, 1, gameOver));
                // cout<<"?????"<<endl;

                //undo the move and undo the piece promotion
                game->undoMove(chessBoard, &position, fromPiece, toPiece, nonPiece, player);
                if(wasNotPromoted){
                  game->UndoPiecePromotion(chessBoard, &player1, &player2, turnOfPlayer, &position);
                }

                if(alpha >= maxValue){
                  return maxValue;
                }
                
                beta = min(beta, maxValue);

                position.pop_back();
                position.pop_back();


              }else{
                position.push_back(x);
                position.push_back(y);
              }
            }
          }
        }
      }
    }
    return maxValue;
  }
}



int Skynet::_maxSearch(Game* game, Board chessBoard[SIZEROW][SIZECOL], Player player1, Player player2, Piece* nonPiece, int depth, int alpha, int beta,
                        bool maximising, int turnOfPlayer, bool gameOver){

  // all my initial vectors and stuff that ill be using for the "fake games" i'll be doing below

  vector<int> position;
  vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> legalMoves;
  bool moveIsSafe = true;
  bool moveIsChecking = false;
  bool wasNotPromoted = false;
  tuple<int, int> kingPos;

  Player* player = turnOfPlayer == 1 ? &player1 : &player2 ;

  // cout<<"fuckoff3"<<endl;


  // if we hit the 0 depth or if we hit an end of game (mate or check mate) then we return the score
  if(depth == 0 or gameOver == true){
    // cout<<"the"<<endl;
    return _costFun(game, chessBoard, turnOfPlayer, maximising, player, gameOver);
  }

  if(maximising){
    int maxValue = -999999;
    // cout<<"the"<<endl;


    for(int x = 0; x < SIZECOL; ++x){ // from x
      for(int y = 0; y < SIZEROW; ++y){// from y
        position.clear();
        legalMoves.clear();
        position.push_back(x);
        position.push_back(y);
              // cout<<"fuckfuck"<<endl;

        //we have to get only the position where there is the current playe pieces
        if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer){
          // compute the legalmoves
          legalMoves = game->legalMoves(chessBoard, turnOfPlayer, &position, &legalMoves, player);
          //if legal moves is not empty then for each legalMoves make the move;
              // cout<<"chiasse"<<endl;

          if(legalMoves.size() != 0){
            for(auto it : legalMoves){
              int toX = get<0>(it);
              int toY = get<1>(it);
              position.push_back(toX);
              position.push_back(toY);

              Piece* fromPiece = chessBoard[x][y].p;
              Piece* toPiece = chessBoard[toX][toY].p;
              //check if the move is safe
              moveIsSafe = game->isMoveSafe(chessBoard, player, nonPiece, &position, &legalMoves, true);

              //if move is safe then do the move
              if(moveIsSafe){
                // cout<<"fuck"<<endl;

                game->movePiece(chessBoard, &position, nonPiece, player);
                wasNotPromoted = game->PiecePromotion(chessBoard, &player1, &player2, turnOfPlayer, &position);


                // custom pion switch for this player
                turnOfPlayer == 1 ? kingPos = player2._getPlayerKingPos() : kingPos = player1._getPlayerKingPos();
                moveIsChecking = game->isMoveChecking(chessBoard, kingPos, &position, &threatPos, turnOfPlayer);
                // cout<<"is"<<endl;

                // turnOfPlayer = game->updateTurnOfPlayer(player);
                if(moveIsChecking){
                  player = turnOfPlayer == 1 ? &player2 : &player1 ;
                  gameOver = game->endGameEval(chessBoard, moveIsChecking, &threatPos, player, nonPiece, 2);
                  player = turnOfPlayer == 1 ? &player1 : &player2 ;
                  // cout<<"this"<<endl;

                }
                // if the move is a game over i compute the score for the move immediately

                // cout<<"shit"<<endl;

                //else i call the max search for that position
                maxValue = max(maxValue, _minSearch(game, chessBoard, player1, player2, nonPiece, depth-1, alpha, beta, false, 2, gameOver));
                //undo the move

                game->undoMove(chessBoard, &position, fromPiece, toPiece, nonPiece, player);
                if(wasNotPromoted){
                  game->UndoPiecePromotion(chessBoard, &player1, &player2, turnOfPlayer, &position);
                }

                // game->displayBoard(chessBoard);

                if( maxValue >= beta){
                  return maxValue;
                }
                
                alpha = max(alpha, maxValue);

                position.pop_back();
                position.pop_back();

              }else{
                position.push_back(x);
                position.push_back(y);
              }
            }
          }
        }
      }
    }
    return maxValue;
  }
}


int Skynet::_costFun(Game* game, Board chessBoard[SIZEROW][SIZECOL], int turnOfPlayer, bool maximising, Player* player, bool gameOver){
  //calculate the mobility and material score

  int whiteMobility = 0;
  int blackMobility = 0;  
  int whiteMaterial = 0;
  int blackMaterial = 0;
  int score = 0;
  int bonus = 0;
  int white = 1; //shoudl define 
  int black = 2;
  // game->displayBoard(chessBoard);
  // cout<<"hein"<<endl;
  // cout<<gameOver<<endl;


  vector<tuple<int,int>> legalMoves;
  vector<int> position;

  for(int x = 0 ; x < SIZEROW; ++x){//position from x
    for(int y = 0; y < SIZECOL; ++y){//position from y
      position.clear();
      legalMoves.clear();
      position.push_back(x);
      position.push_back(y);
      // cout<<"hein2"<<endl;
      if(chessBoard[x][y].p->_getPieceTurn() == white and chessBoard[x][y].p->_getPieceType() != '-'){
        whiteMaterial += 1*chessBoard[x][y].p->_getPiecePoints();
        // cout<<"hein33"<<endl;

        legalMoves = game->legalMoves(chessBoard, 1, &position, &legalMoves, player);
        // cout<<"hein3"<<endl;

        whiteMobility += legalMoves.size();
      }
      if(chessBoard[x][y].p->_getPieceTurn() == black and chessBoard[x][y].p->_getPieceType() != '-'){
        // cout<<turnOfPlayer<<endl;
        // cout<<x<<":"<<y<<endl;
        
        blackMaterial += 1*chessBoard[x][y].p->_getPiecePoints();
        // cout<<"hein44"<<endl;
        legalMoves = game->legalMoves(chessBoard, 2, &position, &legalMoves, player);
        // cout<<"hein4"<<endl;

        blackMobility += legalMoves.size();
      }
    }
  }

  if(gameOver){
    bonus = 10;
  }

  score = (whiteMaterial-blackMaterial) + (whiteMobility-blackMobility) + bonus;
  // cout<<"what happenned"<<endl;

  return score;


}






int Skynet::_quiescence(Game* game, Board chessBoard[SIZEROW][SIZECOL],int alpha, int beta, int turnOfPlayer, bool maximising, Player* player, bool gameOver){

}

