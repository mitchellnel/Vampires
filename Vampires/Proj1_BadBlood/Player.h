//
//  Player.h
//  Proj1_BadBlood
//
//  Created by Mitchell McLinton on 9/1/20.
//  Copyright © 2020 Mitchell McLinton. All rights reserved.
//

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <string>
using namespace std;

class Arena;   //Forward declaration of Arena

class Player
{
  public:
      // Constructor
    Player(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    string dropPoisonVial();
    string move(int dir);
    void   setDead();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};

#endif /* PLAYER_INCLUDED */
