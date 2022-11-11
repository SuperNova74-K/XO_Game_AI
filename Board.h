//
// Created by walid on 10-Nov-22.
//

#ifndef XO_GAME_AI_BOARD_H
#define XO_GAME_AI_BOARD_H

#include <bits/stdc++.h>
using namespace std;

class Board {
private:
    // in Board Values...
    // -1, 0, 1 values are for minmax
    // 3 for X (Player 1)
    // 4 for O (Player 2)
    // 4 for empty
    vector<vector<short>>board{{5,5,5},{5,5,5},{5,5,5}};
    short slotsUsed = 0;
    short gameState = 0; // 0 is still in play, 1 is draw , 2 is win
    static char printableFormOf(short & x);
public:
    bool isDrawAssumingNotWin() const;
    bool isWin();
    short getGameState();
    void setGameState(short x);
    void print();
    void updateGameState();
    void useSlot();
    void freeSlot();
    vector<short>& operator[](int x);
};


#endif //XO_GAME_AI_BOARD_H
