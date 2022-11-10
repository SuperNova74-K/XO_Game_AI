//
// Created by walid on 10-Nov-22.
//

#ifndef XO_GAME_AI_BOARD_H
#define XO_GAME_AI_BOARD_H

#include <bits/stdc++.h>
using namespace std;

class Board {
private:
    vector<vector<short>>board{{0,0,0},{0,0,0},{0,0,0}};
    short slotsUsed = 0;

public:
    bool isDraw();
    int isThereAWinner(int lastPlayer);
    bool isGameDone();
    vector<short>& operator[](int x);
};


#endif //XO_GAME_AI_BOARD_H
