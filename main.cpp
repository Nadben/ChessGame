#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "main.h"

using namespace std;

int main() {

  Game game;

  Player player1(1,0,4);// white
  Player player2(2,7,4);// black

  int turnOfPlayer = player1._getPlayerType();

  Board chessBoard[SIZEROW][SIZECOL]; //je cree mon objet chessBoard de type Board qui est initialiser avec des pointeur de piece

  Piece nonPiece (NULL,'-', 0);

  Piece p1(1,'p', 1);
  Piece p2(1,'p', 1);
  Piece p3(1,'p', 1);
  Piece p4(1,'p', 1);
  Piece p5(1,'p', 1);
  Piece p6(1,'p', 1);
  Piece p7(1,'p', 1);
  Piece p8(1,'p', 1);
  Piece p9(1,'t', 5);
  Piece p10(1,'c', 3);
  Piece p11(1,'f', 3);
  Piece p12(1,'q', 10);
  Piece p13(1,'r', 4);
  Piece p14(1,'f', 3);
  Piece p15(1,'c', 3);
  Piece p16(1,'t', 5);

  Piece p17(2,'P', 1);
  Piece p18(2,'P', 1);
  Piece p19(2,'P', 1);
  Piece p20(2,'P', 1);
  Piece p21(2,'P', 1);
  Piece p22(2,'P', 1);
  Piece p23(2,'P', 1);
  Piece p24(2,'P', 1);
  Piece p25(2,'T', 5);
  Piece p26(2,'C', 3);
  Piece p27(2,'F', 3);
  Piece p28(2,'Q', 10);
  Piece p29(2,'R', 4);
  Piece p30(2,'F', 3);
  Piece p31(2,'C', 3);
  Piece p32(2,'T', 5);


  //creation of a list of pointer to a Piece
  list<Piece> listOfPiece;

  // player1._setPieceCaptured(&p1);


  //init all the Pieces in a list of Pieces
  listOfPiece.push_back(p1);
  listOfPiece.push_back(p2);
  listOfPiece.push_back(p3);
  listOfPiece.push_back(p4);
  listOfPiece.push_back(p5);
  listOfPiece.push_back(p6);
  listOfPiece.push_back(p7);
  listOfPiece.push_back(p8);
  listOfPiece.push_back(p9);
  listOfPiece.push_back(p10);
  listOfPiece.push_back(p11);
  listOfPiece.push_back(p12);
  listOfPiece.push_back(p13);
  listOfPiece.push_back(p14);
  listOfPiece.push_back(p15);

  listOfPiece.push_back(p16);
  listOfPiece.push_back(p17);
  listOfPiece.push_back(p18);
  listOfPiece.push_back(p19);
  listOfPiece.push_back(p20);
  listOfPiece.push_back(p21);
  listOfPiece.push_back(p22);
  listOfPiece.push_back(p23);
  listOfPiece.push_back(p24);
  listOfPiece.push_back(p25);
  listOfPiece.push_back(p26);
  listOfPiece.push_back(p27);
  listOfPiece.push_back(p28);
  listOfPiece.push_back(p29);
  listOfPiece.push_back(p30);
  listOfPiece.push_back(p31);
  listOfPiece.push_back(p32);

  listOfPiece.push_back(nonPiece);

  // init all the Pieces on the chessBoard
  game.initialiseBoard(listOfPiece, chessBoard);
  game.displayBoard(chessBoard);

  // create vector of positions
  vector<int> position;
  vector<tuple<int,int>> threatPos;
  vector<tuple<int,int>> legalMoves;
  bool moveIsSafe = true;
  bool moveIsChecking = false;
  bool gameOver = false;
  tuple<int, int> kingPos;


  while(gameOver != true){

    //General To Do list :
    // - retrieve pieces once a pion reach the other end of the map depending on the player (Done)
    // - The game ending rules (50 consecutive checks and check mate)
    // - castling and en passant
    // - A.I. minimax with alpha beta pruning with dynamic programation of best moves.

    Player* player = turnOfPlayer == 1 ? &player1 : &player2 ;


    //display some information about the  current player
    game.displayCheck(player, moveIsChecking);
    game.displayEatenPieces(player);




    do{
      //ask the player which piece he wants to move
      // cout<<"askPlayerPiece in"<<endl;
      position = game.askPlayerPiece(chessBoard, player, &position);
      // cout<<"askPlayerPiece out"<<endl;

      //Compute the legalMoves no castling and no en passant yet.
      // if no legalMoves are detected and you are checked then it's checked mate
      // cout<<"legal moves in"<<endl;
      legalMoves = game.legalMoves(chessBoard, turnOfPlayer, &position, &legalMoves);
      // cout<<"legal moves out"<<endl;

      //display all the pussybilities

      //ask for the player move ofc if the player moves doesnt comply with legalMoves then asked to get another move
      // cout<<"askPlayerMove in"<<endl;
      position = game.askPlayerMove(chessBoard, &position, legalMoves);
      // cout<<"askPlayerMove out"<<endl;


      //check if the move is safe, if it isn't tell the player that he can't move there.
      // cout<<"isMoveSafe in"<<endl;
      moveIsSafe = game.isMoveSafe(chessBoard, player, &nonPiece, &position, &legalMoves, true);
      // cout<<"isMoveSafe out"<<endl;

    }while(moveIsSafe != true);


    //move the piece on the board if it's safe
    game.movePiece(chessBoard, &position, &nonPiece, player);
    game.pionSwitch(chessBoard, &player1, &player2, turnOfPlayer, &position);


    // check if the move get the other player checked..
    // get the position of the ennemy king
    turnOfPlayer == 1 ? kingPos = player2._getPlayerKingPos() : kingPos = player1._getPlayerKingPos();
    moveIsChecking = game.isMoveChecking(chessBoard, kingPos, &position, &threatPos, turnOfPlayer);

    // cout<<"hello"<<endl;
    // cout<<"the threat positions"<<endl;
    // for (auto it : threatPos){
    //   cout<<get<0>(it)<<" : "<< get<1>(it)<<endl;
    // }

    turnOfPlayer = game.updateTurnOfPlayer(player);
    if(moveIsChecking){
      // cout<<"hello"<<endl;

      gameOver = game.endGameEval(chessBoard, moveIsChecking, &threatPos, player, turnOfPlayer);

    }


    system("clear");


    game.displayBoard(chessBoard);

    //flush the vectors (v and legalMoves and threats)
    position.clear();
    legalMoves.clear();
    threatPos.clear();
    // game.evalEnd();


  }








}
