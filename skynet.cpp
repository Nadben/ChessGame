


#include "skynet.h"
#include <algorithm.h>

using namespace std;


Skynet::Skynet(){}
~Skynet::Skynet(){}




/*
i'll receive the board and i'll recursively play all the position
until i reach a leaf, ill then compute the score and retropropagate
it up to the root, with pruning ill be able to branch out some
of the search tree so it will be faster to get an answer, ill start
with a depth of 2 to test things out first.
*/

/*
steps:
  1-  retrieve ennemy legalMoves for currPosition
  2-  retrieve all current possible moves
  3-  ok so for all current possible moves, the ennemy legal moves shouldn't be
      different.
  4-  but then when we are evaluating the second ply we re_evaluate the ennemy possible move
  5-  and we retrieve all the possible moves for us
  6-  but then we are at the 3rd and final ply we reevaluate the  current possible moves
  7-  we re_evaluate the ennemy legal moves and compute the costFun

*/



int Skynet::_alphaBeta(Board chessBoard[SIZEROW][SIZECOL], int depth, int alpha, int beta, bool maximising){

  // all my initial vectors and stuff that ill be using for the "fake games" i'll be doing below
  vector<int> position;
  vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> legalMoves;
  bool moveIsSafe = true;
  bool moveIsChecking = false;
  bool gameOver = false;
  tuple<int, int> kingPos;

  // if we hit the 0 depth or if we hit an end of game (mate or check mate) then we return the score
  if(depth == 0 ){
    return _costFun();
  }

  if(maximising){
    maxValue = -999999;

    // for every position calculate the legal moves of the max player
    for(int x = 0; x < SIZECOL; ++x){ // from x
      for(int y = 0; y < SIZEROW; ++y){// from y
        //we have to get only the position where there is the current playe pieces
        if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer){
          // compute the legalmoves
          legalMoves = game.legalMoves(chessBoard, turnOfPlayer, &position, &legalMoves);
          //if legal moves is not empty then for each legalMoves make the move;
          if(legalMoves.size() != 0){
            for(auto it : legalMoves){
              int toX = get<0>(it);
              int toY = get<1>(it);
              position.push_back(toX);
              position.push_back(toY);
              //check if the move is safe
              auto moveIsSafe = game.isMoveSafe(chessBoard, player, &nonPiece, &position, &legalMoves, true);

              //if move not safe go with another legalMoves

              //make the move
              game.movePiece(chessBoard, &position, &nonPiece, player);






              // recursively call _alphaBeta
              maxValue = max(maxValue, _alphaBeta(chessBoard, depth-1, alpha, beta, false));
              if(alpha >= maxValue){
                return maxValue;
              }
              beta = max(beta, maxValue);
            }else{
              // we skip this move since we dont have any legalMoves computed for this move
              continue;
            }
          }
        }
      }
    }
  }

















  else{
    maxValue = 999999;

    // for every position calculate the legal moves of the max player
    for(int x = 0; x < SIZECOL; ++x){ // from x
      for(int y = 0; y < SIZEROW; ++y){// from y
        //we have to get only the position where there is the current playe pieces
        if(chessBoard[x][y].p == turnOfPlayer){
          // compute the legalmoves
          auto legalMoves = game.legalMoves(chessBoard, turnOfPlayer, &position, &legalMoves);
          //if legal moves is not empty then for each legalMoves make the move;
          if(legalMoves.size() != 0){
            for(auto it : legalMoves){
              int toX = get<0>(it);
              int toY = get<1>(it);
              auto position.push_back(toX);
              auto position.push_back(toY);
              //check if the move is safe
              auto moveIsSafe = game.isMoveSafe(chessBoard, player, &nonPiece, &position, &legalMoves, true);
              //make the move
              game.movePiece(chessBoard, &position, &nonPiece, player);
              // recursively call _alphaBeta
              maxValue = min(maxValue, _alphaBeta(chessBoard, depth-1, alpha, beta, false));
              if(alpha >= maxValue){
                return maxValue;
              }
              beta = min(beta, maxValue);
            }else{
              // we skip this move since we dont have any legalMoves computed for this move
              continue;
            }
          }
        }
      }
    }
  }

}


Skynet::_costFun(){

}
