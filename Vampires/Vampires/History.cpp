//
//  History.cpp
//  Proj1_BadBlood
//
//  Created by Mitchell McLinton on 9/1/20.
//  Copyright © 2020 Mitchell McLinton. All rights reserved.
//

#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////
//  History implementation
///////////////////////////////////////////////////////////////////////////

History::History(int nRows, int nCols) {
    m_rows = nRows;
    m_cols = nCols;
    for (int r=1; r <= m_rows; r++)
        for (int c=1; c <= m_cols; c++)
            m_grid[r-1][c-1] = '.';
}

bool History::record(int r, int c) {
    if (r < 1 || r > m_rows)
        return false;
    if (c < 1 || c > m_cols)
        return false;
    
    switch (m_grid[r-1][c-1]) {
        case '.':
            m_grid[r-1][c-1] = 'A';
            break;
            
        case 'Z':
            break;
            
        default:
            m_grid[r-1][c-1] += 1;
            break;
    }
    return true;
}

void History::display() const {
    clearScreen();
    for (int r=1; r <= m_rows; r++) {
        for (int c=1; c <= m_cols; c++)
            cout << m_grid[r-1][c-1];
        cout << endl;
    }
    cout << endl;
}
