#include "database.h"
#include <iostream>
#include <random>
#include <limits>
#include <bits/stdc++.h> 

std::random_device rd;
std::mt19937_64 mt(rd());//64 bits mersenne twister generator
                        // seeding it with random seed from the OS entropy device

DataBase::DataBase(){
    initTable();
    initHashTable();

}
DataBase::~DataBase(){}

  
// Generates a Random number from 0 to 2^64-1 
unsigned long long int DataBase::randomInt() { 
    uniform_int_distribution <unsigned long long int> dist(0, UINT64_MAX); 
    return dist(mt); 
} 
  
// This function associates each piece with 
// a number 
int DataBase::indexOf(char piece){ 
    if (piece=='P') 
        return 0; 
    if (piece=='N') 
        return 1; 
    if (piece=='B') 
        return 2; 
    if (piece=='R') 
        return 3; 
    if (piece=='Q') 
        return 4; 
    if (piece=='K') 
        return 5; 
    if (piece=='p') 
        return 6; 
    if (piece=='n') 
        return 7; 
    if (piece=='b') 
        return 8; 
    if (piece=='r') 
        return 9; 
    if (piece=='q') 
        return 10; 
    if (piece=='k') 
        return 11; 
    else
        return -1; 
} 
  
// Initializes the table 
void DataBase::initTable(){ 
    for (int i = 0; i<8; i++) 
      for (int j = 0; j<8; j++) 
        for (int k = 0; k<12; k++) 
          zobristTable[i][j][k] = randomInt(); 
} 
  
// Computes the hash value of a given board 
unsigned long long int DataBase::computeHash(Board chessBoard[SIZEROW][SIZECOL]){ 
    unsigned long long int h = 0; 

    for (int i = 0; i < SIZEROW; ++i){ 
        for (int j = 0; j < SIZECOL; ++j){ 
            if (chessBoard[i][j].p->_getPieceType() != '-') { 
                int piece = indexOf(chessBoard[i][j].p->_getPieceType()); 
                h ^= zobristTable[i][j][piece]; 
            } 
        } 
    } 
    return h; 
} 


int DataBase::_getHashScore(unsigned long long int hashValue){
    unsigned long long int index = hashValue%tableSize;

    return hashTable[index]->score;
}


void DataBase::initHashTable(){
    for(auto i = 0; i < tableSize ; ++i){
        hashTable[i] = new item;
        hashTable[i]->zobKey = 0;
        hashTable[i]->score = 0;
        // hashTable[i]->alpha = 0;
        // hashTable[i]->beta = 0;
        // hashTable[i]->depth = 0;
        // hashTable[i]->next = NULL;
    }
}

bool DataBase::lookUp(unsigned long long int hashValue){
    //let's look up the hashvalue existance in the database

    bool found = false;
    unsigned long long int index = hashValue%tableSize;
    
    if(hashTable[index]->zobKey != 0){
        if(hashTable[index]->zobKey == hashValue)
            found = true;
    }

    return found;
  
//   return myTransposeMap[hashValue];
}

void DataBase::insert(unsigned long long int hashValue, int value){
    //Let's generate the index **I could implement a linked list
    unsigned long long int index = hashValue%tableSize;

    //we override the old items...
    hashTable[index]->zobKey = hashValue;
    hashTable[index]->score = value;
  

}

// unordered_map<unsigned long long int, int> DataBase::_getMap(){
//     return myTransposeMap;
// }

void DataBase::incHits(){
    hits++;
}

void DataBase::resetHits(){
    hits = 0;
}

unsigned long long int DataBase::_getHits(){
    return hits;
}