
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
    // check if eating path are not empty
    if(chessBoard[posX][posY].p->_getPieceType() != '-'){
      //check if it's an ennemy then push it into legalmoves
      if(chessBoard[posX][posY].p->_getPieceTurn() != turnOfPlayer){
        auto t = make_tuple(posX,posX);
        legalMoves->push_back(t);
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

void computingMoves(Board chessBoard[SIZEROW][SIZECOL],int x,int y, int turnOfPlayer,  vector<int>* position, vector<tuple<int,int>>* legalMoves, vector<tuple<int,int>>* threatPos, vector<tuple<int,int>>* kingOOW, bool endGame){

    bool threatFound = false;

    switch (tolower(chessBoard[x][y].p->_getPieceType())) {
      case 'p':{

        int mirror = turnOfPlayer == 1 ?  1 : -1;
        //mouvement
        // does the square in front is empty ? if yes make the tuple else
        if(chessBoard[(x+1*mirror)][y].p->_getPieceType() == '-'){
          auto t = make_tuple(x+1*mirror,y);
          legalMoves->push_back(t);
        }

        //have i consumed my first move?
        if(chessBoard[x][y].p->_getFirstMove() != false) {
          // does the square in front is empty ? if yes make the tuple else
          if(chessBoard[(x+2*mirror)][y].p->_getPieceType() == '-'){
            auto t = make_tuple(x+2*mirror,y);
            legalMoves->push_back(t);
          }
        }

        // check if eating path  are not empty
        if(chessBoard[(x+1*mirror)][y-1].p->_getPieceType() != '-'){
          //check if it's an ennemy
          if(chessBoard[(x+1*mirror)][y-1].p->_getPieceTurn() != turnOfPlayer){
            auto t = make_tuple(x+1*mirror,y-1);
            legalMoves->push_back(t);
          }
        }
        // check if eating path are not empty
        if(chessBoard[(x+1*mirror)][y+1].p->_getPieceType() != '-'){
          //check if it's an ennemy then push it into legalmoves
          if(chessBoard[(x+1*mirror)][y+1].p->_getPieceTurn() != turnOfPlayer){
            auto t = make_tuple(x+1*mirror,y+1);
            legalMoves->push_back(t);
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
        hardCodedMove(x, y-2, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x, y-2, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+1, y-1, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+1, y+1, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);
        hardCodedMove(x+1, y, temp, chessBoard, turnOfPlayer, threatPos, &threatFound);

        break;
      }
      //switch break
      break;

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

void Game::displayBoard(Board chessBoard[SIZEROW][SIZECOL], ostream & out) const{
  cout<< "         Y"<<endl;
  cout << "  0 1 2 3 4 5 6 7" << endl;
  for(int i = 0; i<SIZEROW; i++){
    cout<<i;
    cout<< ' ';
    for( int j = 0; j<SIZECOL; j++){
      cout<<chessBoard[i][j].p->_getPieceType();
      cout<< ' ';
    }
    cout<<i ;
    cout<<'\n';
  }
  cout << "  0 1 2 3 4 5 6 7" << endl;
  cout<< "         Y"<<endl;

}

vector<int> Game::askPlayerPiece(Board chessBoard[SIZEROW][SIZECOL], Player* player, vector<int>* v){

  int fromX, fromY;
  // To Do : make the input impossible to write anything else than ints between 0-7


  //to change for saying player name instead of himself
  cout<< "It's "<< player->_getPlayerName() << " turn to play, please input the coordinate"<<endl;
  cout<<"From X : ";
  cin>>fromX;
  cout<<"From Y : ";
  cin>>fromY;

  while(chessBoard[fromX][fromY].p->_getPieceTurn() != player->_getPlayerType()){
      cout<<"you cant't use this piece please choose something else"<<endl;
      cout<< "It's "<< player->_getPlayerName() << " turn to play, please input the coordinate"<<endl;
      cout<<"From X : ";
      cin>>fromX;
      cout<<"From Y : ";
      cin>>fromY;
  }

  cout<<"that is the piece you wanted : "<<chessBoard[fromX][fromY].p->_getPieceType()<< endl;

  //show the valid move they can do... if no move kindly ask to move something else.
  // legalMoves = isMoveLegal();


  v->push_back(fromX);
  v->push_back(fromY);


  return *v;
}

// shouldn't call player, i should call turnOfPlayer no castling or en passant
vector<tuple<int,int>> Game::legalMoves(Board chessBoard[SIZEROW][SIZECOL], int turnOfPlayer, vector<int>* position, vector<tuple<int,int>>* legalMoves){

  int x = position->at(0), y = position->at(1) ;
  /*well here comes the good stuff*/
  vector<tuple<int,int>> kingOOW;
  vector<tuple<int,int>> threatPos;

  int mirror = 1;

  //Have to take into account 1st moves for pions for all pions
  //rook can skip over pieces

  computingMoves(chessBoard, x, y, turnOfPlayer, position, legalMoves, &threatPos, &kingOOW, false);

  for(auto it : *legalMoves){
    cout<< get<0>(it)<<" : "<< get<1>(it)<<endl;
  }





  return *legalMoves;

}

// i shouldn't call the player
vector<int> Game::askPlayerMove(Board chessBoard[SIZEROW][SIZECOL],  vector<int>* v, vector<tuple<int,int>> legalMoves){
  int toX, toY;

  bool tupleFound = false;
  // cout<< v.at(0) << " " << v.at(1)<< endl;

  // To Do : make the input impossible to write anything else than ints between 0-7

  cout<<"To X : ";
  cin>>toX;
  cout<<"To Y : ";
  cin>>toY;

  // auto t = make_tuple(toX,toY);
  // find if t is in vector of tuples
  // auto it = find(legalMoves.begin(), legalMoves.end(), t);
  // got to make a for loop to make it work the iterator is not working
  for(auto it : legalMoves){
    if(get<0>(it) == toX and get<1>(it) == toY){
      tupleFound = true;
    }
  }

  // while loop to confirm that the inputs toX and toY are contained into the legalMoves
  while(tupleFound != true){
    cout<<"this is not a valid move please choose again : "<< endl;
    cout<<"To X : ";
    cin>>toX;
    cout<<"To Y : ";
    cin>>toY;

    // got to make a for loop to make it work
    for(auto it : legalMoves){
      if(get<0>(it) == toX and get<1>(it) == toY){
        tupleFound = true;
      }
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

  // update the new position of the king for the current player

  if(tolower(chessBoard[fromX][fromY].p->_getPieceType()) == 'r'){
    player->_setPlayerKingPos(toX,toY);
  }

  //make the first move false if true prior !
  if(chessBoard[fromX][fromY].p->_getFirstMove() != false){
    // cout<<"first Move done"<<endl;
    chessBoard[fromX][fromY].p->_setFirstMove();
  }

  Piece* temp = chessBoard[fromX][fromY].p;
  Piece* temp2 = chessBoard[toX][toY].p;


  // cout<<"derp"<<endl;
  // cout<<toX<<":"<<toY<<endl;
  // cout<<chessBoard[toX][toY].p->_getPieceTurn()<<"!="<<player->_getPlayerType()<<endl;
  // cout<<chessBoard[toX][toY].p->_getPieceType()<<"!="<< " - "<<endl;

  if(chessBoard[toX][toY].p->_getPieceTurn() != player->_getPlayerType()){
    if(chessBoard[toX][toY].p->_getPieceType() != '-'){
      player->_setPieceCaptured(temp2); // input into vec of piece captured
    }
  }




  //this is where the move is made note: i think &* is useless..
  chessBoard[toX][toY].p = &*temp;
  chessBoard[fromX][fromY].p = nonPiece;




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

  int turnOfPlayer;
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
  auto kingPos = player->_getPlayerKingPos();//return a tuple of value

  //we simulate the move on the Board
  //this is where the move is made
  chessBoard[toX][toY].p = &*temp;
  chessBoard[fromX][fromY].p = nonPiece;

  //need to switch the turnOfPlayer else i simulate the current player which is no bueno
  // simulation of all the ennemy pieces
  //change the player turn before going to the loops
  turnOfPlayer = player->_getPlayerType() == 1 ? 2 : 1;
  mirror = turnOfPlayer == 1 ?  1 : -1;

  // cout<<"seg fault here?"<<endl;
  for(int x = 0; x < SIZEROW; x++){
    for(int y = 0; y < SIZECOL; y++){

      // cout<<turnOfPlayer<<" :  "<<chessBoard[x][y].p->_getPieceTurn()<<endl;
      if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer){
        cout<<x<<" : "<< y<< endl;

        // we assign the position found
        positionTemp.push_back(x);
        positionTemp.push_back(y);
        computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &legalMoves, &threatPos, &kingOOW, false);

      }
      positionTemp.clear();
    }
  }

  // for (it : legalMoves){
  //   cout<<get<0>(it)<<" : "<< get<1>(it)<<endl;
  // }
  //
  // cout<<"your king position :"<< get<0>(kingPos)<<" : "<< get<1>(kingPos)<<endl;
  //
  // string test;
  // cin >> test;



  //once i have all the moves for all the possible pieces
  // i can search if the tuple kingpos is inside the vector of legal legalMoves
  // if it is then i can update the current player saying that he is in check
  auto found = find(legalMoves.begin(), legalMoves.end(), kingPos);

  if(found != legalMoves.end()){// not sure if this good
    // we set the status
    moveIsSafe = false;
    cout<< "The move isn't safe because your king will be checked."<< endl;
    cout<< "Please choose another move."<<endl;
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
  int mirror = 1;

  vector<tuple<int,int>> legalMoves;
  vector<int> positionTemp;
  // vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> kingOOW;
  positionTemp.push_back(x);
  positionTemp.push_back(y);

  //Have to take into account 1st moves for pions for all pions
  //rook can skip over pieces
  // cout<< positionTemp.at(0)<<":"<<positionTemp.at(1)<<endl;

  computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &legalMoves, threatPos, &kingOOW, false);


  // cout<<"or not"<<endl;
  //
  // for (it : legalMoves){
  //   cout<<get<0>(it)<<" : "<< get<1>(it)<<endl;
  // }
  //
  // cout<<"ennemy king position :"<< get<0>(kingPos)<<" : "<< get<1>(kingPos)<<endl;
  //
  // string test;
  // cin >> test;

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
      cout<<"the pieces you can choose from : " ;
      for(auto it : player->_getPieceCaptured()){
        cout<<it->_getPieceType();
        cout<<", ";
      }
      cout<<"which piece you want to return to the board : ";
      cin>>choice;
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

  // string test;


  // i evaluate the 50 checks rules then draw
  // i evaluate check mate


  // for the check mate i'll receive a vector of
  // position that threatens the current king that is isChecked
  // i'll then check for each piece of the current player if there
  // is a position that blocks that path
  // if there isn't i'll check the king if he can get out of the path
  // if he can't then it's checkmate (update private attribute in player)
  // return true for end of the game

  // cout<<"here"<<endl;
  // cout<<"the threat positions"<<endl;
  // for (auto it : *threatPos){
  //   cout<<get<0>(it)<<" : "<< get<1>(it)<<endl;
  // }
  //
  // cin >> test;


  if(threatPos->size() != 0 and moveIsChecking){
    for(int x = 0; x < SIZEROW; x++){
      for(int y = 0; y < SIZECOL; y++){
        // cout<<turnOfPlayer<<" :  "<<chessBoard[x][y].p->_getPieceTurn()<<endl;
        if(chessBoard[x][y].p->_getPieceTurn() == turnOfPlayer){
          // cout<<x<<" : "<< y<< endl;

          // we assign the position found
          positionTemp.push_back(x);
          positionTemp.push_back(y);
          computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &legalMoves, &threat, &kingOOW, true);

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
    //
    // cout<<"checked dude legal moves"<<endl;
    //
    // for (auto it : legalMoves){
    //   cout<<get<0>(it)<<" : "<< get<1>(it)<<endl;
    // }
    //
    //
    // cin >> test;
    //
    //
    // cout<<"king out of the way moves"<<endl;
    //
    // for (auto it : kingOOW){
    //   cout<<get<0>(it)<<" : "<< get<1>(it)<<endl;
    // }
    //
    // cin >> test;

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
              computingMoves(chessBoard, x, y, turnOfPlayer, &positionTemp, &ennemyLegalMoves, &threat, &kingOOW, false);

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
  cout<<gameOver<<endl;



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
