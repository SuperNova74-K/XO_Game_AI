//
// Created by walid on 10-Nov-22.
//

#ifndef XO_GAME_AI_PLAYER_H
#define XO_GAME_AI_PLAYER_H

#include <bits/stdc++.h>
using namespace std;


class Player {
private:
    short ID = 1;


    string takeInput();
    bool isMoveValid();
public:
    short getID();
    void play();
};


#endif //XO_GAME_AI_PLAYER_H
