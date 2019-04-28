// To do
// create a private attribute which would be the weight of the Pieces

class Piece{
private:

  int pieceTurn;
  char pieceType;
  bool firstMove;
  int piecePoints;
  bool isPromoted;
  int promotionMoves;

public:

  Piece();
  ~Piece();
  Piece(int,char,int);
  
  void _setPieceType(char);
  void _setPieceTurn(int);
  void _setFirstMove(bool);
  void _setPiecePromotion(bool);
  void _incPiecePromotionMoves(); //at make move if piece is promotted
  void _decPiecePromotionMoves(); //at undoMoves()

  char _getPieceType();
  int _getPieceTurn();
  bool _getFirstMove();// should change to  _getPieceFirstMove ....
  int _getPiecePoints();
  bool _getPiecePromotion();
  int _getPiecePromMoves();

};


//inheritance (optionnal but i will likely do it) ! gotta create family of pieces each of them holds their valid path on the board
