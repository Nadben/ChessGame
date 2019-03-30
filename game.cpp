
#include "game.h"

void hardCodedMove(int posX, int posY, vector<tuple<int,int>>* legalMoves, Board chessBoard[SIZEROW][SIZECOL],
                   int turnOfPlayer, vector<tuple<int,int>>* threat, bool* threatFound){


  if(0 <= posX and posX <= 7 and 0 <= posY and posY <= 7){
    //first
    if(chessBoard[posX][posY].p->_getPieceType() == '-'){
      auto t = make_tuple(posX,posY);
      legalMoves->push_back(t);
      //possible threat path for king
      if(*threatFound == false){
        threat->push_back(t);
      }
    }
    // check if eating path  are not empty
    if(chessBoard[posX][posY].p->_getPieceType() != '-'){
      //check if it's an ennemy
      if(chessBoard[posX][posY].p->_getPieceTurn() != turnOfPlayer){
        auto t = make_tuple(posX,posY);
        legalMoves->push_back(t);
        if(tolower(chessBoard[posX][posY].p->_getPieceType()) != 'r' and *threatFound == false ){
          //it wasn't a threat we erase the path
          threat->clear();
        }else{
          //the threat path was found
          *threatFound = true;
        }
      }
    }
  }
}

void hardCodedMoveTFQ(int stepX, int stepY, vector<tuple<int,int>>* legalMoves, Board chessBoard[SIZEROW][SIZECOL],
                      int turnOfPlayer, char type, vector<int>* position, string direction, vector<tuple<int,int>>* threat,
                      bool* threatFound){

  int x = position->at(0), y = position->at(1) ;

  if(type == 'f' or type == 'q'){
    int numberOfStep = stepY <= stepX ? stepY : stepX;

    if(direction == "forward right"){
      for(int i = 1 ; i <= numberOfStep  ; i++){
        if((x-i) >= 0 and (y+i) <= 7 ) {
          if(chessBoard[x-i][y+i].p->_getPieceType() == '-'){
            auto t = make_tuple(x-i,y+i);
            legalMoves->push_back(t);
            //possible threat path for king
            if(*threatFound == false){
              threat->push_back(t);
            }
          }

          //check if it's an ennemy
          if(chessBoard[x-i][y+i].p->_getPieceType() != '-'){
            if(chessBoard[x-i][y+i].p->_getPieceTurn() != turnOfPlayer ){
              auto t = make_tuple(x-i,y+i);
              legalMoves->push_back(t);
              // check for threat to king
              if(tolower(chessBoard[x-i][y+i].p->_getPieceType()) != 'r' and *threatFound == false ){
                //it wasn't a threat we erase the path
                threat->clear();
              }else{
                //the threat path was found
                *threatFound = true;
              }
              //stop the iteration
              break;
            }
          }


          //check if it's an ennemy
          if(chessBoard[x-i][y+i].p->_getPieceType() != '-'){
            //if it isn't stop iteration
            if(chessBoard[x-i][y+i].p->_getPieceTurn() == turnOfPlayer){
              //stop the iteration
              break;
            }
          }
        }else{break;}
      }
    }

    if(direction == "forward left"){
      for(int i = 1 ; i <= numberOfStep  ; i++){
        if((x-i) >= 0 and (y-i) >= 0 ) {
          if(chessBoard[x-i][y-i].p->_getPieceType() == '-'){
            auto t = make_tuple(x-i,y-i);
            legalMoves->push_back(t);
            //possible threat path for king
            if(*threatFound == false){
              threat->push_back(t);
            }
          }

          //check if it's an ennemy
          if(chessBoard[x-i][y-i].p->_getPieceType() != '-'){
            if(chessBoard[x-i][y-i].p->_getPieceTurn() != turnOfPlayer){
              auto t = make_tuple(x-i,y-i);
              legalMoves->push_back(t);
              if(tolower(chessBoard[x-i][y-i].p->_getPieceType()) != 'r' and *threatFound == false ){
                //it wasn't a threat we erase the path
                threat->clear();
              }else{
                //the threat path was found
                *threatFound = true;
              }
              //stop the iteration
              break;
            }
          }

          //check if it's an ennemy
          if(chessBoard[x-i][y-i].p->_getPieceType() != '-'){
            //if it isn't stop iteration
            if(chessBoard[x-i][y-i].p->_getPieceTurn() == turnOfPlayer){
              //stop the iteration
              break;
            }
          }
        }else{break;}
      }
    }

    if(direction == "backward right"){
      for(int i = 1 ; i <= numberOfStep  ; i++){
        if((x + i) <= 7 and (y + i) <= 7) {
          if(chessBoard[x+i][y+i].p->_getPieceType() == '-'){
            auto t = make_tuple(x+i,y+i);
            legalMoves->push_back(t);
            //possible threat path for king
            if(*threatFound == false){
              threat->push_back(t);
            }
          }

          //check if it's an ennemy
          if(chessBoard[x+i][y+i].p->_getPieceType() != '-'){
            if(chessBoard[x+i][y+i].p->_getPieceTurn() != turnOfPlayer){
              auto t = make_tuple(x+i,y+i);
              legalMoves->push_back(t);
              if(tolower(chessBoard[x+i][y+i].p->_getPieceType()) != 'r' and *threatFound == false ){
                //it wasn't a threat we erase the path
                threat->clear();
              }else{
                //the threat path was found
                *threatFound = true;
              }
              //stop the iteration
              break;
            }
          }

          //check if it's an ennemy
          if(chessBoard[x+i][y+i].p->_getPieceType() != '-'){
            //if it isn't stop iteration
            if(chessBoard[x+i][y+i].p->_getPieceTurn() == turnOfPlayer){
              //stop the iteration
              break;
            }
          }
        }else{break;}
      }
    }

    if(direction == "backward left"){
      for(int i = 1 ; i <= numberOfStep  ; i++){
        if((x + i) <= 7 and (y - i) >= 0) {
          if(chessBoard[x+i][y-i].p->_getPieceType() == '-'){
            auto t = make_tuple(x+i,y-i);
            legalMoves->push_back(t);
            //possible threat path for king
            if(*threatFound == false){
              threat->push_back(t);
            }
          }

          //check if it's an ennemy
          if(chessBoard[x+i][y-i].p->_getPieceType() != '-'){
            if(chessBoard[x+i][y-i].p->_getPieceTurn() != turnOfPlayer){
              auto t = make_tuple(x+i,y-i);
              legalMoves->push_back(t);
              if(tolower(chessBoard[x+i][y-i].p->_getPieceType()) != 'r' and *threatFound == false ){
                //it wasn't a threat we erase the path
                threat->clear();
              }else{
                //the threat path was found
                *threatFound = true;
              }
              //stop the iteration
              break;
            }
          }

          //check if it's an ennemy
          if(chessBoard[x+i][y-i].p->_getPieceType() != '-'){
            //if it isn't stop iteration
            if(chessBoard[x+i][y-i].p->_getPieceTurn() == turnOfPlayer){
              //stop the iteration
              break;
            }
          }
        }else{break;}
      }
    }

  }

  if(type == 't' or type == 'q'){

    if(direction == "forward"){
      for(int i = 1; i <= stepX; i++){
        if(chessBoard[x-i][y].p->_getPieceType() == '-'){
          auto t = make_tuple(x-i,y);
          legalMoves->push_back(t);
          //possible threat path for king
          if(*threatFound == false){
            threat->push_back(t);
          }
        }

        //check if it's an ennemy
        if(chessBoard[x-i][y].p->_getPieceType() != '-'){
          if(chessBoard[x-i][y].p->_getPieceTurn() != turnOfPlayer){
            auto t = make_tuple(x-i,y);
            legalMoves->push_back(t);
            if(tolower(chessBoard[x-i][y].p->_getPieceType()) != 'r' and *threatFound == false ){
              //it wasn't a threat we erase the path
              threat->clear();
            }else{
              //the threat path was found
              *threatFound = true;
            }
            //stop the iteration
            break;
          }
        }

        //check if it's an ennemy
        if(chessBoard[x-i][y].p->_getPieceType() != '-'){
          //if it isn't stop iteration
          if(chessBoard[x-i][y].p->_getPieceTurn() == turnOfPlayer){
            //stop the iteration
            break;
          }
        }
      }
    }

    if(direction == "backward"){
      for(int i = 1; i < stepX; i++){
        if(chessBoard[x+i][y].p->_getPieceType() == '-'){
          auto t = make_tuple(x+i,y);
          legalMoves->push_back(t);
          //possible threat path for king
          if(*threatFound == false){
            threat->push_back(t);
          }
        }

        //check if it's an ennemy
        if(chessBoard[x+i][y].p->_getPieceType() != '-'){
          if(chessBoard[x+i][y].p->_getPieceTurn() != turnOfPlayer){
            auto t = make_tuple(x+i,y);
            legalMoves->push_back(t);
            if(tolower(chessBoard[x+i][y].p->_getPieceType()) != 'r' and *threatFound == false ){
              //it wasn't a threat we erase the path
              threat->clear();
            }else{
              //the threat path was found
              *threatFound = true;
            }
            //stop the iteration
            break;
          }
        }

        //check if it's an ennemy
        if(chessBoard[x+i][y].p->_getPieceType() != '-'){
          //if it isn't stop iteration
          if(chessBoard[x+i][y].p->_getPieceTurn() == turnOfPlayer){
            //stop the iteration
            break;
          }
        }
      }
    }

    if(direction == "left"){
      for(int i = 1; i <= stepY; i++){
        if(chessBoard[x][y-i].p->_getPieceType() == '-'){
          auto t = make_tuple(x,y-i);
          legalMoves->push_back(t);
          //possible threat path for king
          if(*threatFound == false){
            threat->push_back(t);
          }
        }

        //check if it's an ennemy
        if(chessBoard[x][y-i].p->_getPieceType() != '-'){
          if(chessBoard[x][y-i].p->_getPieceTurn() != turnOfPlayer){
            auto t = make_tuple(x,y-i);
            legalMoves->push_back(t);
            if(tolower(chessBoard[x][y-i].p->_getPieceType()) != 'r' and *threatFound == false ){
              //it wasn't a threat we erase the path
              threat->clear();
            }else{
              //the threat path was found
              *threatFound = true;
            }
            //stop the iteration
            break;
          }
        }

        //check if it's an ennemy
        if(chessBoard[x][y-i].p->_getPieceType() != '-'){
          //if it isn't stop iteration
          if(chessBoard[x][y-i].p->_getPieceTurn() == turnOfPlayer){
            //stop the iteration
            break;
          }
        }
      }
    }

    if(direction == "right"){
      for(int i = 1; i < stepY; i++){
        if(chessBoard[x][y+i].p->_getPieceType() == '-'){
          auto t = make_tuple(x,y+i);
          legalMoves->push_back(t);
          //possible threat path for king
          if(*threatFound == false){
            threat->push_back(t);
          }
        }

        //check if it's an ennemy
        if(chessBoard[x][y+i].p->_getPieceType() != '-'){
          if(chessBoard[x][y+i].p->_getPieceTurn() != turnOfPlayer){
            auto t = make_tuple(x,y+i);
            legalMoves->push_back(t);
            if(tolower(chessBoard[x][y+i].p->_getPieceType()) != 'r' and *threatFound == false ){
              //it wasn't a threat we erase the path
              threat->clear();
            }else{
              //the threat path was found
              *threatFound = true;
            }
            //stop the iteration
            break;
          }
        }

        //check if it's an ennemy
        if(chessBoard[x][y+i].p->_getPieceType() != '-'){
          //if it isn't stop iteration
          if(chessBoard[x][y+i].p->_getPieceTurn() == turnOfPlayer){
            //stop the iteration
            break;
          }
        }
      }
    }
  }
}



void computingMoves(Board chessBoard[SIZEROW][SIZECOL],int x,int y, int turnOfPlayer,  vector<int>* position, vector<tuple<int,int>>* legalMoves,
                    vector<tuple<int,int>>* threatPos, vector<tuple<int,int>>* kingOOW, Player* player, bool endGame){

    bool threatFound = false;

    switch (tolower(chessBoard[x][y].p->_getPieceType())) {
      case 'p':{

        int mirror = turnOfPlayer == 1 ?  1 : -1;
        //mouvement
        // does the square in front is empty ? if yes make the tuple else
        if((x + 1*mirror) >= 0 and (x + 1*mirror) <= 7 and (y) >= 0 and (y) <= 7){
          if(chessBoard[(x+1*mirror)][y].p->_getPieceType() == '-'){
            auto t = make_tuple(x+1*mirror,y);
            legalMoves->push_back(t);
          }
        }

        //have i consumed my first move?
        if((x + 1*mirror) >= 0 and (x + 1*mirror) <= 7 and (y) >= 0 and (y) <= 7){
          if(chessBoard[x][y].p->_getFirstMove() != false) {
            // does the square in front is empty ? if yes make the tuple else
            if(chessBoard[(x+1*mirror)][y].p->_getPieceType() == '-'){
              auto t = make_tuple(x+2*mirror,y);
              legalMoves->push_back(t);
            }
          }
        }

        // check if eating path  are not empty
        if((x + 1*mirror) >= 0 and (x + 1*mirror) <= 7 and (y-1) >= 0 and (y-1) <= 7){
          if(chessBoard[(x+1*mirror)][y-1].p->_getPieceType() != '-'){
            //check if it's an ennemy
            if(chessBoard[(x+1*mirror)][y-1].p->_getPieceTurn() != turnOfPlayer){
              auto t = make_tuple(x+1*mirror,y-1);
              legalMoves->push_back(t);
            }
          }
        }
        // check if eating path are not empty
        if((x + 1*mirror) >= 0 and (x + 1*mirror) <= 7 and (y+1) >= 0 and (y+1) <= 7){
          if(chessBoard[(x+1*mirror)][y+1].p->_getPieceType() != '-'){
            //check if it's an ennemy then push it into legalmoves
            if(chessBoard[(x+1*mirror)][y+1].p->_getPieceTurn() != turnOfPlayer){
              auto t = make_tuple(x+1*mirror,y+1);
              legalMoves->push_back(t);
            }
          }
        }

        break;
      }

      case 't':{

        hardCodedMoveTFQ(x, y, legalMoves, chessBoard, turnOfPlayer, 't', position,"forward", threatPos, &threatFound);// forward
        hardCodedMoveTFQ(SIZECOL - x, y, legalMoves, chessBoard, turnOfPlayer, 't', position, "backward", threatPos, &threatFound);// backward
        hardCodedMoveTFQ(x, y, legalMoves, chessBoard, turnOfPlayer, 't', position, "left", threatPos, &threatFound);// left
        hardCodedMoveTFQ(x, SIZECOL - y, legalMoves, chessBoard, turnOfPlayer, 't', position, "right", threatPos, &threatFound);// right

        break;
      }

      case 'f':{

        hardCodedMoveTFQ(x, SIZECOL - y, legalMoves, chessBoard, turnOfPlayer, 'f', position, "forward right", threatPos, &threatFound); // forward right
        hardCodedMoveTFQ(x, y, legalMoves, chessBoard, turnOfPlayer, 'f', position, "forward left", threatPos, &threatFound);// forward left
        hardCodedMoveTFQ(SIZECOL - x, SIZECOL - y, legalMoves, chessBoard, turnOfPlayer, 'f', position, "backward right", threatPos, &threatFound);// backward right
        hardCodedMoveTFQ(SIZECOL - x, y, legalMoves, chessBoard, turnOfPlayer, 'f', position,"backward left", threatPos, &threatFound);// backward left

        //end
        break;
      }

      case 'q':{

        hardCodedMoveTFQ(x, SIZECOL - y, legalMoves, chessBoard, turnOfPlayer, 'q', position,"forward right", threatPos, &threatFound); // forward right
        hardCodedMoveTFQ(x, y, legalMoves, chessBoard, turnOfPlayer, 'q', position, "forward left", threatPos, &threatFound);// forward left
        hardCodedMoveTFQ(SIZECOL - x, SIZECOL - y, legalMoves, chessBoard, turnOfPlayer, 'q', position, "backward right", threatPos, &threatFound);// backward right
        hardCodedMoveTFQ(SIZECOL - x, y, legalMoves, chessBoard, turnOfPlayer, 'q', position, "backward left", threatPos, &threatFound);// backward left
        hardCodedMoveTFQ(x, y, legalMoves, chessBoard, turnOfPlayer, 'q', position,"forward", threatPos, &threatFound);// forward
        hardCodedMoveTFQ(SIZECOL - x, y, legalMoves, chessBoard, turnOfPlayer, 'q', position, "backward", threatPos, &threatFound);// backward
        hardCodedMoveTFQ(x, y, legalMoves, chessBoard, turnOfPlayer, 'q', position, "left", threatPos, &threatFound);// left
        hardCodedMoveTFQ(x, SIZECOL - y, legalMoves, chessBoard, turnOfPlayer, 'q', position, "right", threatPos, &threatFound);// right

        //end
        break;
      }

      case 'c':{

        //that's a special Mofo
        // 8 positions to check

        hardCodedMove(x-1, y+2, legalMoves, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x-2, y+1, legalMoves, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x-2, y-1, legalMoves, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x-1, y-2, legalMoves, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+1, y-2, legalMoves, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+2, y-1, legalMoves, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+2, y+1, legalMoves, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+1, y+2, legalMoves, chessBoard, turnOfPlayer, threatPos, &threatFound);

        break;
      }

      case 'r':{
        //that's the hardest mofo

        vector<tuple<int,int>>* temp;
        endGame == true ? temp = kingOOW : temp = legalMoves ;

        hardCodedMove(x-1, y-1, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x-1, y+1, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x-1, y, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x, y-1, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x, y+1, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+1, y-1, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+1, y+1, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+1, y, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);




        break;
      }
      //switch break
      break;

    }
}
void castling(Board chessBoard[SIZEROW][SIZECOL], Player* player, vector<tuple<int,int>>* legalMoves, int turnOfPlayer){
  /*   
    The king and the chosen rook are on the player's first rank.[3]
    Neither the king nor the chosen rook has previously moved.
    There are no pieces between the king and the chosen rook.
    The king is not currently in check.
    The king does not pass through a square that is attacked by an enemy piece.[4]
    The king does not end up in check. (True of any legal move.)
  */
  vector<int> positionTemp;
  vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> kingOOW;
  vector<tuple<int,int>> ennemyLM;
  vector<tuple<int,int>> castlePathLeft;
  vector<tuple<int,int>> castlePathRight;
  vector<tuple<int,int>>::iterator found;


  tuple<int,int> rookLeft;
  tuple<int,int> rookRight;
  
  
  if(player->_getPlayerType() == 1){
    rookLeft  = make_tuple(0,0);
    rookRight = make_tuple(0,7);
  }else if(player->_getPlayerType() == 2){
    rookLeft  = make_tuple(7,0);
    rookRight = make_tuple(7,7);
  }


  for(int i = get<1>(player->_getPlayerKingPos())-1 ; i >= 0 ; --i){
    if(chessBoard[get<0>(player->_getPlayerKingPos())][i].p->_getPieceType() == '-'){
      //check if any of those tiles can be attacked by the ennemy. 
      castlePathLeft.push_back(make_tuple(get<0>(player->_getPlayerKingPos()),i));
    }else if(tolower(chessBoard[get<0>(player->_getPlayerKingPos())][i].p->_getPieceType()) == 't'){
      castlePathLeft.push_back(make_tuple(get<0>(player->_getPlayerKingPos()),i));
      break;
    }else{
      break;
    }
  }

  
  //right vector path for rook
  for(int i = get<1>(player->_getPlayerKingPos())+1 ; i < SIZEROW ; ++i){
    if(chessBoard[get<0>(player->_getPlayerKingPos())][i].p->_getPieceType() == '-'){
      //check if any of those tiles can be attacked by the ennemy. 
      castlePathRight.push_back(make_tuple(get<0>(player->_getPlayerKingPos()),i));
    }else if(tolower(chessBoard[get<0>(player->_getPlayerKingPos())][i].p->_getPieceType()) == 't'){
      castlePathRight.push_back(make_tuple(get<0>(player->_getPlayerKingPos()),i));
      break;
    }else{
      break;
    }
  }

  if(castlePathLeft.size() == 4 or castlePathRight.size() == 3){
      //compute all ennemy legal moves
    turnOfPlayer = turnOfPlayer == 1 ? 2 : 1 ;
    for(int x = 0; x < SIZEROW; x++){
      for(int y = 0; y < SIZECOL; y++){
        if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer and chessBoard[x][y].p->_getPieceType() != '-'){

          // we assign the position found
          positionTemp.push_back(x);
          positionTemp.push_back(y);
          computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &ennemyLM, &threatPos, &kingOOW, player, false);

        }
        positionTemp.clear();
      }
    }

    for (auto it: castlePathLeft){
      // cout<<get<0>(it)<<":"<<get<1>(it)<<endl;
      found = find(ennemyLM.begin(), ennemyLM.end(), it);
    }
    if(found == ennemyLM.end()){// not sure if this good
      //no ennemy in the way. 
      if(tolower(chessBoard[get<0>(rookLeft)][get<1>(rookLeft)].p->_getPieceType()) == 't' and castlePathLeft.size() == 4){
        if(chessBoard[get<0>(rookLeft)][get<1>(rookLeft)].p->_getFirstMove() == true){
          //input left rook pos in legalMoves
          legalMoves->push_back(rookLeft);
        }
      }
    }
    for (auto it: castlePathRight){
      found = find(ennemyLM.begin(), ennemyLM.end(), it);
    }
    if(found == ennemyLM.end()){// not sure if this good
      //no ennemy in the way.
      if(tolower(chessBoard[get<0>(rookRight)][get<1>(rookRight)].p->_getPieceType()) == 't' and castlePathRight.size() == 3){
        if(chessBoard[get<0>(rookRight)][get<1>(rookRight)].p->_getFirstMove() == true){
          //input left rook pos in legalMoves
          legalMoves->push_back(rookRight);
        }
      }
    }
  }


}

Game::Game(){}
Game::~Game(){}

void Game::initialiseBoard(list<Piece> & listOfPiece, Board chessBoard[SIZEROW][SIZECOL] ){

  int i = 0;
  int temp = 0 ;
  for(auto it = listOfPiece.begin();it !=  listOfPiece.end(); ++it){

      if(i < 8){
        chessBoard[1][i].p = &*it;
      }

      if(i >= 8 && i < 16){
        temp = i - 8;
        chessBoard[0][temp].p = &*it;
      }

      if(i >= 16 && i < 24){
        temp = i - 16;
        chessBoard[6][temp].p = &*it;
      }

      if(i >= 24 && i < 32){
        temp = i - 24;
        chessBoard[7][temp].p = &*it;
      }

      if(i == 32){
        for(int k = 2; k<=5; k++){
          for(int l = 0; l<SIZEROW; l++){
              chessBoard[k][l].p = &*it;

          }
        }
      }

      i+=1;
    }



}

void Game::displayBoard(const Board chessBoard[SIZEROW][SIZECOL], ostream & out) const{
  cout<<'\n';  
  // cout<< "         Y"<<endl;
  // cout << "  0 1 2 3 4 5 6 7" << endl;
  for(int i = 0; i<SIZEROW; i++){
    cout<<i;
    cout<< ' ';
    for( int j = 0; j<SIZECOL; j++){
      cout<<chessBoard[i][j].p->_getPieceType();
      cout<< ' ';
    }
    // cout<<i ;
    cout<<'\n';
  }
  cout << "  0 1 2 3 4 5 6 7" << endl;
  // cout<< "         Y"<<endl;

}

vector<int> Game::askPlayerPiece(Board chessBoard[SIZEROW][SIZECOL], Player* player, vector<int>* v){

  int fromX, fromY;
  // To Do : make the input impossible to write anything else than ints between 0-7


  while(1){
    cout<<"please input the coordinate"<<endl;
    cout<<"You have to input a number between 0 to 7" << endl;
    cout<<"From X : ";
    if(cin>>fromX and fromX >= 0 and fromX <= 7){
      cout<<"From Y : ";
      if(cin>>fromY and fromY >= 0 and fromY <= 7 and chessBoard[fromX][fromY].p->_getPieceTurn() == player->_getPlayerType()){
        break;
      }else{
        cout<<"Invalid input, please use numerical value."<<endl;
        cin.clear();
        while(cin.get() != '\n');//clear the buffer
      }
    }else{
      cout<<"Invalid input, please use numerical value."<<endl;
      cin.clear();
      while(cin.get() != '\n');// clear the buffer
    }
  }

  cout<<"that is the piece you wanted : "<<chessBoard[fromX][fromY].p->_getPieceType()<< endl;
  cout<<chessBoard[fromX][fromY].p->_getFirstMove()<<endl;

  v->push_back(fromX);
  v->push_back(fromY);


  return *v;
}

// no castling or en passant
vector<tuple<int,int>> Game::legalMoves(Board chessBoard[SIZEROW][SIZECOL], int turnOfPlayer, vector<int>* position,
                                        vector<tuple<int,int>>* legalMoves, Player* player){

  int x = position->at(0), y = position->at(1) ;

  vector<tuple<int,int>> kingOOW;
  vector<tuple<int,int>> threatPos;


  int mirror = 1;

  computingMoves(chessBoard, x, y, turnOfPlayer, position, legalMoves, &threatPos, &kingOOW, player, false);
  
  if(chessBoard[get<0>(player->_getPlayerKingPos())][get<1>(player->_getPlayerKingPos())].p->_getFirstMove() == true 
      and player->_getPlayerStatus() == false and tolower(chessBoard[x][y].p->_getPieceType()) == 'r'){
    // cout<<"here"<<endl;
    castling(chessBoard, player, legalMoves, turnOfPlayer);
  }


  // for(auto it : *legalMoves){
  //   cout<<"Legal Moves : " <<"("<<get<0>(it)<<" : "<< get<1>(it)<<")"<<endl;
  // }

  return *legalMoves;

}

// i shouldn't call the player
vector<int> Game::askPlayerMove(Board chessBoard[SIZEROW][SIZECOL],  vector<int>* v, vector<tuple<int,int>> legalMoves){
  int toX, toY;

  bool tupleFound = false;
  // cout<< v.at(0) << " " << v.at(1)<< endl;

  // To Do : make the input impossible to write anything else than ints between 0-7

  while(1){
    cout<<"To X : ";
    if(cin>>toX and toX >= 0 and toX <= 7){
      cout<<"To Y : ";
      if(cin>>toY and toY >= 0 and toY <= 7){
        for(auto it : legalMoves){
          if(get<0>(it) == toX and get<1>(it) == toY){
            tupleFound = true;
          }
        }
        if(tupleFound == true){
          break;
        }
      }else{
        cout<<"Invalid input, please use numerical value."<<endl;
        cin.clear();
        while(cin.get() != '\n');//clear the buffer
      }
    }else{
      cout<<"Invalid input, please use numerical value."<<endl;
      cin.clear();
      while(cin.get() != '\n');// clear the buffer
    }
  }

  cout<<"this is where you want to go : "<<chessBoard[toX][toY].p->_getPieceType()<< endl;

  v->push_back(toX);
  v->push_back(toY);

  return *v;
}

void Game::movePiece(Board chessBoard[SIZEROW][SIZECOL], vector<int>* v, Piece* nonPiece, Player* player){

  //check where i want to go and put the reference
  int fromX = v->at(0); //row
  int fromY = v->at(1); //col
  int toX = v->at(2);
  int toY = v->at(3);

  Piece* fromPiece = chessBoard[fromX][fromY].p;
  Piece* toPiece = chessBoard[toX][toY].p;


  // update the new position of the king for the current player
  if(tolower(fromPiece->_getPieceType()) == 'r'){
    player->_setPlayerKingPos(fromX,fromY-2);
    if(tolower(toPiece->_getPieceType())=='t'){
      //we are doing the castling 
      if(fromY - toY > 0){
        //big castle
        chessBoard[fromX][fromY-2].p = &*fromPiece;
        chessBoard[fromX][fromY].p = nonPiece; 
        chessBoard[toX][toY+3].p = &*toPiece;
        chessBoard[toX][toY].p = nonPiece; 
      }else if (fromY - toY < 0){
        //small castle
        chessBoard[fromX][fromY+2].p = &*fromPiece;
        chessBoard[fromX][fromY].p = nonPiece; 
        chessBoard[toX][toY-2].p = &*toPiece;
        chessBoard[toX][toY].p = nonPiece; 
      }
    }else{
      chessBoard[toX][toY].p = &*fromPiece;
      chessBoard[fromX][fromY].p = nonPiece;
    }
  }else{
    //this is where the move is made note: i think &* is useless..
    chessBoard[toX][toY].p = &*fromPiece;
    chessBoard[fromX][fromY].p = nonPiece;
  }
  
  //make the first move false if true prior !
  if(fromPiece->_getFirstMove() == true){
    // cout<<"first Move done"<<endl;
    fromPiece->_setFirstMove(false);
  }

  if(toPiece->_getPieceTurn() != player->_getPlayerType()){
    if(toPiece->_getPieceType() != '-'){
      player->_setPieceCaptured(toPiece); // input into vec of piece captured
    }
  }


}

void Game::undoMove(Board chessBoard[SIZEROW][SIZECOL], vector<int>* v, Piece* fromPiece, Piece* toPiece, Piece* nonPiece, Player* player){

  //check where i want to go and put the reference
  int fromX = v->at(0); //row
  int fromY = v->at(1); //col
  int toX = v->at(2);
  int toY = v->at(3);

  // update the new position of the king for the current player

 

  //make the first move true if false prior !
  if(tolower(fromPiece->_getPieceType()) == 'p' and fromX == 1 or fromX == 6){
    // cout<<"first Move reverted"<<endl;
    fromPiece->_setFirstMove(true);
  }
  if(tolower(fromPiece->_getPieceType()) == 'r' ){
    if(fromX == 0 and fromY == 4 or fromX == 7 and fromY == 4){
      fromPiece->_setFirstMove(true);
    }
  }

  if(tolower(fromPiece->_getPieceType()) == 't' ){
    if(fromX == 0 and fromY == 0 or fromX == 7 and fromY == 7 or 
       fromX == 0 and fromY == 7 or fromX == 7 and fromY == 0){
         fromPiece->_setFirstMove(true);
    }
  }
  
    //undo the player piece captured
  if(toPiece->_getPieceTurn() != player->_getPlayerType()){
    if(toPiece->_getPieceType() != '-'){
      player->_returnPlayerPieceCaptured(toPiece->_getPieceType());
    }
  }  

  if(tolower(fromPiece->_getPieceType()) == 'r'){
    player->_setPlayerKingPos(fromX,fromY);
    if(tolower(toPiece->_getPieceType()) == 't'){
      //we are doing the castling 
      // cout<<"Castling"<<endl;

      if(fromY - toY > 0){
        //big castle
        chessBoard[fromX][fromY-2].p = nonPiece;
        chessBoard[fromX][fromY].p = &*fromPiece; 
        chessBoard[toX][toY+3].p = nonPiece;
        chessBoard[toX][toY].p = &*toPiece; 
      }else if (fromY - toY < 0){
        //small castle
        chessBoard[fromX][fromY+2].p = nonPiece;
        chessBoard[fromX][fromY].p = &*fromPiece; 
        chessBoard[toX][toY-2].p = nonPiece;
        chessBoard[toX][toY].p = &*toPiece; 
      }
      // displayBoard(chessBoard);
    }else{
      chessBoard[toX][toY].p = &*toPiece;
      chessBoard[fromX][fromY].p = &*fromPiece;
    }
  }else{
    //this is where the move is made note: i think &* is useless..

    
    chessBoard[toX][toY].p = &*toPiece;
    chessBoard[fromX][fromY].p = &*fromPiece;
  }

  // //undo the move
  // chessBoard[toX][toY].p = &*toPiece;
  // chessBoard[fromX][fromY].p = &*fromPiece;

}


int Game::updateTurnOfPlayer(Player* player){

  if(player->_getPlayerType() == 1){
    return 2;
  }
  else {
    return 1;
  }

}

void Game::displayEatenPieces(Player* player){

  cout<<"you have : ";
  for(auto it : player->_getPieceCaptured()){
    cout<<it->_getPieceType();
    cout<<", ";
  }
  cout<<" Piece captured."<<endl;

}

void Game::displayCheck(Player* player, bool moveIsChecking){
  if(moveIsChecking == true){
    cout<<"Check !"<<endl;
    //if player was previously checked increment numberoftime he was checked
    //else switch his status.

    if(player->_getPlayerStatus() != true){
      player->_setPlayerStatus();// puts his status on true
      player->_incPlayerConsCheck();
    }
    else { player->_incPlayerConsCheck(); }

  }

  if(moveIsChecking != true){
    //if player was previously checked reset check counter
    //And switch his status.
    if(player->_getPlayerStatus() == true){
      player->_setPlayerStatus();// puts his status on false
      player->_resetPlayerConsCheck();
    }
  }

  cout<< "Number of consecutive check: " <<player->_getPLayerConsCheck()<<endl;
}

//Simulation !

bool Game::isMoveSafe(Board chessBoard[SIZEROW][SIZECOL], Player* player, Piece* nonPiece, vector<int>* position, vector<tuple<int,int>>* lm , bool moveIsSafe){

  int turnOfPlayer = player->_getPlayerType();
  int fromX = position->at(0); //row
  int fromY = position->at(1); //col
  int toX = position->at(2);
  int toY = position->at(3);
  int mirror = 1;

  // we check if the move is safe first.
  //check where i want to go and put the reference
  vector<int> positionTemp;
  vector<tuple<int,int>> legalMoves;
  vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> kingOOW;

  Piece* temp = chessBoard[fromX][fromY].p;
  Piece* temp2 = chessBoard[toX][toY].p;

  // update the new position of the king for the current player
  // if the piece chosen is of type king
  if(tolower(chessBoard[fromX][fromY].p->_getPieceType()) == 'r'){
    player->_setPlayerKingPos(toX,toY);
  }

  //we simulate the move on the Board
  //this is where the move is made
  chessBoard[toX][toY].p = &*temp;
  chessBoard[fromX][fromY].p = nonPiece;

  auto kingPos = player->_getPlayerKingPos();//return a tuple of value

  //need to switch the turnOfPlayer else i simulate the current player which is no bueno
  // simulation of all the ennemy pieces != turnOfPlayer
  // change the player turn before going to the loops
  turnOfPlayer = player->_getPlayerType() == 1 ? 2 : 1;


  // cout<<"seg fault here?"<<endl;
  for(int x = 0; x < SIZEROW; x++){
    for(int y = 0; y < SIZECOL; y++){

      // cout<<turnOfPlayer<<" :  "<<chessBoard[x][y].p->_getPieceTurn()<<endl;
      if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer and chessBoard[x][y].p->_getPieceType() != '-'){
        // cout<<x<<" : "<< y<< endl;

        // we assign the position found
        positionTemp.push_back(x);
        positionTemp.push_back(y);
        computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &legalMoves, &threatPos, &kingOOW, player, false);

      }
      positionTemp.clear();
    }
  }

  //once i have all the moves for all the possible pieces
  // i can search if the tuple kingpos is inside the vector of legal legalMoves
  // if it is then i can update the current player saying that he is in check
  // cout<<"ennemy possible moves"<<endl;
  // for(auto it:legalMoves){
  //   cout<<get<0>(it)<<" : "<<get<1>(it)<<endl;
  // }
  //
  // cout<<"current king position"<<endl;
  // cout<<get<0>(kingPos)<<" : "<<get<1>(kingPos)<<endl;

  auto found = find(legalMoves.begin(), legalMoves.end(), kingPos);

  if(found != legalMoves.end()){// not sure if this good
    // we set the status
    moveIsSafe = false;
    // cout<< "The move isn't safe because your king will be checked."<< endl;
    // cout<< "Please choose another move."<<endl;
    // we clear the vectors of position and legalMoves
    position->clear();
    lm->clear();
    // system("clear");

  }


  //we cancel the move
  chessBoard[toX][toY].p = &*temp2;
  chessBoard[fromX][fromY].p = &*temp;



  return moveIsSafe;
}

// no need to call the player
bool Game::isMoveChecking(Board chessBoard[SIZEROW][SIZECOL], tuple<int,int> kingPos, vector<int>* v, vector<tuple<int,int>>* threatPos, int turnOfPlayer){

  bool isChecked = false;
  int x = v->at(2), y = v->at(3) ;// current position of the current player move

  vector<tuple<int,int>> legalMoves;
  vector<int> positionTemp;
  // vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> kingOOW;
  positionTemp.push_back(x);
  positionTemp.push_back(y);
  Player* player;

  computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &legalMoves, threatPos, &kingOOW, player, false);

  // search the ennemy king position in the legalmoves
  auto found = find(legalMoves.begin(), legalMoves.end(), kingPos);

  // we found the king !
  if(found != legalMoves.end()){
    isChecked = true;
  }


  return isChecked;


}

void Game::pionSwitch(Board chessBoard[SIZEROW][SIZECOL], Player* player1, Player* player2, int turnOfPlayer, vector<int>* position ){

  int toX = position->at(2);
  int toY = position->at(3);
  // we get other player's piece
  Player* player = turnOfPlayer == 1 ? player2 : player1;

  if(tolower(chessBoard[toX][toY].p->_getPieceType()) == 'p'){
    if(toX == 7 or toX == 0){
      char choice;
      Piece* pieceReturned;
      cout<<"the pieces you can choose from : " <<endl;
      for(auto it : player->_getPieceCaptured()){
        cout<<it->_getPieceType();
        cout<<", ";
      }
      while(1){
        cout<<"which piece you want to return to the board : ";
        if(cin>>choice){
          break;
        }else {
          cout<<"invalid input"<<endl;
          cin.clear();
          while(cin.get() != '\n');// clear the buffer
        }
      }

      if(turnOfPlayer == 2){
        choice = toupper(choice);
      }
      pieceReturned = player->_returnPlayerPieceCaptured(choice);
      chessBoard[toX][toY].p = pieceReturned;
    }
  }
}

void Game::skynetPieceSwitch(Board chessBoard[SIZEROW][SIZECOL], Player* player1, Player* player2, int turnOfPlayer, vector<int>* position){
  int toX = position->at(2);
  int toY = position->at(3);
  int index;
  char choice;
  // we get other player's piece
  Player* player = turnOfPlayer == 1 ? player2 : player1;

  if(tolower(chessBoard[toX][toY].p->_getPieceType()) == 'p'){
    if(toX == 7 or toX == 0){
      int value;
      Piece* pieceReturned;
      value = player->_getPieceCaptured()[0]->_getPiecePoints();
      for(auto i=0 ; i < player->_getPieceCaptured().size(); i++){
        if(value < player->_getPieceCaptured()[i]->_getPiecePoints()){
          value = player->_getPieceCaptured()[i]->_getPiecePoints();
          // at index
          index = i;
        }
      }

      if(turnOfPlayer == 2){
        choice = toupper(player->_getPieceCaptured()[index]->_getPieceType());
      }else{
        choice = player->_getPieceCaptured()[index]->_getPieceType();
      }
      pieceReturned = player->_returnPlayerPieceCaptured(choice);
      chessBoard[toX][toY].p = pieceReturned;
    }
  }
}


bool Game::endGameEval(Board chessBoard[SIZEROW][SIZECOL], bool moveIsChecking, vector<tuple<int,int>>* threatPos, Player* player, int turnOfPlayer){


  // we check if the move is safe first.
  //check where i want to go and put the reference
  vector<int> positionTemp;
  vector<tuple<int,int>> threat;
  vector<tuple<int,int>> legalMoves;
  vector<tuple<int,int>> ennemyLegalMoves;
  vector<tuple<int,int>> kingOOW;
  int mirror = 1;
  bool gameOver = false;
  std::vector<tuple<int,int>>::iterator found;


  // for the check mate i'll receive a vector of
  // position that threatens the current king that is isChecked
  // i'll then check for each piece of the current player if there
  // is a position that blocks that path
  // if there isn't i'll check the king if he can get out of the path
  // if he can't then it's checkmate (update private attribute in player)
  // return true for end of the game


  if(threatPos->size() != 0 and moveIsChecking){
    for(int x = 0; x < SIZEROW; x++){
      for(int y = 0; y < SIZECOL; y++){
        // cout<<turnOfPlayer<<" :  "<<chessBoard[x][y].p->_getPieceTurn()<<endl;
        if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer){
          // cout<<x<<" : "<< y<< endl;

          // we assign the position found
          positionTemp.push_back(x);
          positionTemp.push_back(y);
          computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &legalMoves, &threat, &kingOOW, player, true);

        }
        positionTemp.clear();
      }
    }
    // cout<<"here"<<endl;

    //so i get a vector of legal moves and a vector if my king can get out of the way.
    //if the test to block the move is not good
    //if the king position is not empty i'll compute every ennemy
    //move inside a vector of ennemylegalmoves and ill check if
    // any position for the king is not inside the vector .

    //check for a piece that can block the threat
    for(auto it : legalMoves){
      found = find(threatPos->begin(), threatPos->end(), it);
      if(found != threatPos->end()){
        break;
      }
    }
    if(found == threatPos->end()){
      if(kingOOW.size() == 0){
        gameOver = true;
      }
      else{
        //compute every position possible for the ennemy
        //we change the turnOfPlayer
        turnOfPlayer = turnOfPlayer == 1 ? 2 : 1;
        for(int x = 0; x < SIZEROW; x++){
          for(int y = 0; y < SIZECOL; y++){
            // cout<<turnOfPlayer<<" :  "<<chessBoard[x][y].p->_getPieceTurn()<<endl;
            if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer and chessBoard[x][y].p->_getPieceType() != '-'){
              // cout<<x<<" : "<< y<< endl;

              // we assign the position found
              positionTemp.push_back(x);
              positionTemp.push_back(y);
              computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &ennemyLegalMoves, &threat, &kingOOW, player, false);

            }
            positionTemp.clear();
          }
        }
        //we undo the change
        turnOfPlayer = turnOfPlayer == 1 ? 2 : 1;

      }
      // check if kingoow is not inside ennemyLegalMoves
      // cout<<"out of here"<<endl;
      for(auto it : kingOOW){
        found = find(ennemyLegalMoves.begin(), ennemyLegalMoves.end(), it);
        continue;//continue until a move is not inside or if all the moves are iterated over..
      }
      // if all the moves are found inside, then it's gameOver else it isn't
      if(found != ennemyLegalMoves.end()){
        gameOver = true;
      }
      else{
        gameOver = false;
      }
    }
    else{
      gameOver = false;
    }
  }

  // cout<<"here"<<endl;
  // cout<<gameOver<<endl;

  //for the 50 checks rules
  // i'll just check whether the player has 50 consecutiveCheck
  // return true for end of the game

  if(moveIsChecking and gameOver != false){
    if(player->_getPLayerConsCheck() == 50 ){
      gameOver = true;
    }
  }

  return gameOver;

}
void Game::displayPlayerInfo(Player* player){
  cout<<"\n";
  cout<< "It's "<< player->_getPlayerName()<<" turn to play !"<<endl;
}