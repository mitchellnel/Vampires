//
//  History.h
//  Proj1_BadBlood
//
//  Created by Mitchell McLinton on 9/1/20.
//  Copyright © 2020 Mitchell McLinton. All rights reserved.
//

#ifndef HISTORY_INCLUDED
#define HISTORY_INCLUDED

#include "globals.h"

class Arena;    //Forward declaration of Arena

class History {
    public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
    private:
        char m_grid[MAXROWS][MAXCOLS];
        int m_rows;
        int m_cols;
};

#endif /* HISTORY_INCLUDED */
