#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "gameEngine.h"


using namespace std;

char choice_menu();



int main()
{
  gameEngine start;
  Game game; //game
  Skynet skynet;
  
  Player player1(1, 0, 4); // white
  Player player2(2, 7, 4); // black

  Board chessBoard[SIZEROW][SIZECOL]; 

  Piece nonPiece(0, '-', 0);

  Piece p1(1, 'p', 1);
  Piece p2(1, 'p', 1);
  Piece p3(1, 'p', 1);
  Piece p4(1, 'p', 1);
  Piece p5(1, 'p', 1);
  Piece p6(1, 'p', 1);
  Piece p7(1, 'p', 1);
  Piece p8(1, 'p', 1);
  Piece p9(1, 't', 5);
  Piece p10(1, 'c', 3);
  Piece p11(1, 'f', 3);
  Piece p12(1, 'q', 10);
  Piece p13(1, 'r', 4);
  Piece p14(1, 'f', 3);
  Piece p15(1, 'c', 3);
  Piece p16(1, 't', 5);

  Piece p17(2, 'P', 1);
  Piece p18(2, 'P', 1);
  Piece p19(2, 'P', 1);
  Piece p20(2, 'P', 1);
  Piece p21(2, 'P', 1);
  Piece p22(2, 'P', 1);
  Piece p23(2, 'P', 1);
  Piece p24(2, 'P', 1);
  Piece p25(2, 'T', 5);
  Piece p26(2, 'C', 3);
  Piece p27(2, 'F', 3);
  Piece p28(2, 'Q', 10);
  Piece p29(2, 'R', 4);
  Piece p30(2, 'F', 3);
  Piece p31(2, 'C', 3);
  Piece p32(2, 'T', 5);

  //creation of a list of pointer to a Piece
  list<Piece> listOfPiece;

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

  char choice = choice_menu();
  switch (choice)
  {
  case 'H':
    start.launch(game, chessBoard, player1, player2);
    break;
  case 'A':
    start.launchSkynet(game, skynet, chessBoard, player1, player2);
    break;
  
  default:
    break;
  }


}


char choice_menu(){
	cout << "Hello and welcome in the chess game of death !\n"<<endl;
	char choice;
	do {
		cout << "Choose a game mode :\n"<< "H - Play against a Hooman\n" << "A - Play against Skynet\n" <<endl;
		cin >> choice;
		choice=toupper(choice);
	} while(choice != 'H' && choice != 'A');
	return choice;
}