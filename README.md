[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/3677/badge)](https://bestpractices.coreinfrastructure.org/projects/3677)

# Chess Game

I started this project to get back into C++ after a year. I would say it was a very very fulfilling project where i learned a ton, from move generation, to binary search trees, hash tables and of course some oop concepts that i forgot. 

### Design implementation

The design is fairly simple, I created the Board which has pieces objects instanciated on the board, each pieces Objects contains a few attributes that I can use later for move validation, in the menu you can play against a human, or against a Computer, the player on top is the one that starts first. If you want to play against the computer the computer will always start first... Also, I only coded the castling moves, but not the en passant, I might do it in the future... 

### Skynet

For the A.I. I went with the Alpha-Beta Pruning algorithm, it's a type of search algorithm that generates all the possible moves and computes the score at the root of the search tree, the search goes for 4 plys. I also implemented a custom database that saves all the states the table as encountered as well as some information about that state in the table (right now i save only the score returned at that state). It's commonly called a transposition table. I tested it a little bit and it seems to work fine. What i would realy like to do is to implement a killer heuristic moves which is said to be quite easy to do with enormous gains, a quiscence search, which will continue the search of a very interesting move a few plys more to see if that move is worth it (to get rid of the horizon problem). and that's it.

### How it works

It only works on linux machines, make sure you have g++11 installed for the compiler. I have included a make file (rather simplistic one hehe) so if you open your terminal, cd to the file where all the source code and the makefile is and type make in your terminal and it will compile it for you. if you want to run it just type ./main.out . 



general ToDo list:
  - En passant 
  - Refactoring 
  
 A.I. toDo list:
  - Quiescence search (for the horizon problem)
  - Killer moves heuristic
  - Random popular openings
 
