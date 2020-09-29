//
//  Game.h
//  Proj1_BadBlood
//
//  Created by Mitchell McLinton on 9/1/20.
//  Copyright © 2020 Mitchell McLinton. All rights reserved.
//

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
using namespace std;

class Arena;   //Forward declaration of Arena

class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nVampires);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    string takePlayerTurn();
};

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

bool recommendMove(const Arena& a, int r, int c, int& bestDir);
int computeDanger(const Arena& a, int r, int c);


#endif /* GAME_INCLUDED */
