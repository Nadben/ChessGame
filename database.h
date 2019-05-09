#include <unordered_map>
#include "game.h"


using namespace std; 




class DataBase{
private:

  // std::unordered_map <unsigned long long int, int> myTransposeMap;

  static const unsigned long int tableSize = 180000;

  struct item{

    unsigned long long int zobKey;
    int score;
    //future implementation
    // int alpha = 0;
    // int beta = 0;
    // int depth = 0;
    // item* next;
  };

  item* hashTable[tableSize];
  unsigned long long int zobristTable[SIZEROW][SIZECOL][12]; 
  unsigned long long int hits = 0;
  

public:

  DataBase();
  ~DataBase();

  unsigned long long int randomInt();
  int indexOf(char);
  void initTable();
  unsigned long long int computeHash(Board [SIZEROW][SIZECOL]); // receive the whole board object information
  int _getHashScore(unsigned long long int);
  void initHashTable();
  bool lookUp(unsigned long long int);
  void insert(unsigned long long int , int);
  // unordered_map<unsigned long long int, int> _getMap();
  void incHits();
  void resetHits();
  unsigned long long int _getHits();

};