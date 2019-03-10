#include "piece.h"

#define SIZECOL 8
#define SIZEROW 8


using namespace std;


class Board{
private:

public:
  Board(); //constructeur de mon objet Board avec pointeur nulle
  ~Board();
  Piece * p;//pointeur de piece
  Board(Piece *); // second constructeur de mon objet Board pointant vers mes pieces


};
