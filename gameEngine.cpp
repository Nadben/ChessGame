
#include "gameEngine.h"



gameEngine::gameEngine(){}

gameEngine::~gameEngine(){}

void gameEngine::launch(Game game, Board chessBoard[SIZEROW][SIZECOL], Player player1, Player player2 ){
    
    vector<int> position;
    vector<int> bestPos;
    vector<tuple<int, int>> threatPos;
    vector<tuple<int, int>> legalMoves;

    int turnOfPlayer = player1._getPlayerType();
    bool moveIsSafe = true;
    bool moveIsChecking = false;
    bool gameOver = false;

    tuple<int, int> kingPos;

    player1._setName('H');
    player2._setName('H');

    Piece nonPiece(0, '-', 0);
    game.displayBoard(chessBoard);


    while (gameOver != true)
    {

        //General To Do list :
        // - retrieve pieces once a pion reach the other end of the map depending on the player (Done)
        // - The game ending rules (50 consecutive checks and check mate) (technically done)
        // - castling and en passant
        // - A.I. minimax with alpha beta pruning with dynamic programation of best moves.
        // - reinforcing the dialog

        Player *player = turnOfPlayer == 1 ? &player1 : &player2;

        //display some information about the  current player
        game.displayPlayerInfo(player);
        game.displayCheck(player, moveIsChecking);
        game.displayEatenPieces(player);

        do
        {
        //ask the player which piece he wants to move
        position = game.askPlayerPiece(chessBoard, player, &position);

        //Compute the legalMoves no castling and no en passant yet.
        // if no legalMoves are detected and you are checked then it's checked mate
        legalMoves = game.legalMoves(chessBoard, turnOfPlayer, &position, &legalMoves, player);

        //display all the pussybilities

        //ask for the player move ofc if the player moves doesnt comply with legalMoves then asked to get another move
        position = game.askPlayerMove(chessBoard, &position, legalMoves);

        
        //check if the move is safe, if it isn't tell the player that he can't move there.
        moveIsSafe = game.isMoveSafe(chessBoard, player, &nonPiece, &position, &legalMoves, true);

        } while (moveIsSafe != true);


        //move the piece on the board if it's safe
        game.movePiece(chessBoard, &position, &nonPiece, player);
        game.pionSwitch(chessBoard, &player1, &player2, turnOfPlayer, &position);

        // check if the move get the other player checked..
        // get the position of the ennemy king
        turnOfPlayer == 1 ? kingPos = player2._getPlayerKingPos() : kingPos = player1._getPlayerKingPos();
        moveIsChecking = game.isMoveChecking(chessBoard, kingPos, &position, &threatPos, turnOfPlayer);

        turnOfPlayer = game.updateTurnOfPlayer(player);
        if (moveIsChecking)
        {
        Player *player = turnOfPlayer == 1 ? &player1 : &player2;
        gameOver = game.endGameEval(chessBoard, moveIsChecking, &threatPos, player, &nonPiece, turnOfPlayer);
        }
        system("clear");
        game.displayBoard(chessBoard);

        //flush the vectors (v ,legalMoves and threats)
        position.clear();
        legalMoves.clear();
        threatPos.clear();
    }
}

void gameEngine::launchSkynet(Game game,Skynet skynet, Board chessBoard[SIZEROW][SIZECOL], Player player1, Player player2){
    
    vector<int> position;
    vector<int> bestPos;
    vector<tuple<int, int>> threatPos;
    vector<tuple<int, int>> legalMoves;

    int turnOfPlayer = player1._getPlayerType();
    bool moveIsSafe = true;
    bool moveIsChecking = false;
    bool gameOver = false;

    tuple<int, int> kingPos;

    player1._setName('A');// Name of the computer
    player2._setName('H');// human Name

    Piece nonPiece(0, '-', 0);
    game.displayBoard(chessBoard);

    while (gameOver != true)
    {

        //General To Do list :
        // - retrieve pieces once a pion reach the other end of the map depending on the player (Done)
        // - The game ending rules (50 consecutive move without checks and check mate) (technically done)
        // - castling and en passant (castling done)
        // - A.I. minimax with alpha beta pruning with dynamic programation of best moves. (Not fully finished)
   

        Player *player = turnOfPlayer == 1 ? &player1 : &player2;

        //display some information about the  current player
        game.displayPlayerInfo(player);
        game.displayCheck(player, moveIsChecking);
        game.displayEatenPieces(player);

        if (turnOfPlayer == 1)
        {
        position = skynet._alphaBeta(&game, chessBoard, player1, player2, &nonPiece, turnOfPlayer);
        }

        // game.displayBoard(chessBoard);
        if (turnOfPlayer == 2)
        {
        do
        {
            //ask the player which piece he wants to move
            position = game.askPlayerPiece(chessBoard, player, &position);

            //Compute the legalMoves no castling and no en passant yet.
            // if no legalMoves are detected and you are checked then it's checked mate
            legalMoves = game.legalMoves(chessBoard, turnOfPlayer, &position, &legalMoves, player);
        
            //display all the pussybilities

            //ask for the player move ofc if the player moves doesnt comply with legalMoves then asked to get another move
            position = game.askPlayerMove(chessBoard, &position, legalMoves);

            
            //check if the move is safe, if it isn't tell the player that he can't move there.
            moveIsSafe = game.isMoveSafe(chessBoard, player, &nonPiece, &position, &legalMoves, true);

        } while (moveIsSafe != true);
        }

        //move the piece on the board if it's safe
        game.movePiece(chessBoard, &position, &nonPiece, player);
        game.pionSwitch(chessBoard, &player1, &player2, turnOfPlayer, &position);

        // check if the move get the other player checked..
        // get the position of the ennemy king
        turnOfPlayer == 1 ? kingPos = player2._getPlayerKingPos() : kingPos = player1._getPlayerKingPos();
        moveIsChecking = game.isMoveChecking(chessBoard, kingPos, &position, &threatPos, turnOfPlayer);

        turnOfPlayer = game.updateTurnOfPlayer(player);
        if (moveIsChecking)
        {
        Player *player = turnOfPlayer == 1 ? &player1 : &player2;
        gameOver = game.endGameEval(chessBoard, moveIsChecking, &threatPos, player, &nonPiece, turnOfPlayer);
        }
        system("clear");
        game.displayBoard(chessBoard);

        //flush the vectors (v ,legalMoves and threats)
        position.clear();
        legalMoves.clear();
        threatPos.clear();
    }

}





















