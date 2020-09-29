//
//  Vampire.h
//  Proj1_BadBlood
//
//  Created by Mitchell McLinton on 9/1/20.
//  Copyright © 2020 Mitchell McLinton. All rights reserved.
//

#ifndef VAMPIRE_INCLUDED
#define VAMPIRE_INCLUDED

class Arena;   //Forward declaration of Arena

class Vampire
{
  public:
      // Constructor
    Vampire(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    void move();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
    int    m_idleTurnsRemaining;
};

#endif /* VAMPIRE_INCLUDED */
