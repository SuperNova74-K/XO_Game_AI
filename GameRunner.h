//
// Created by walid on 10-Nov-22.
//

#ifndef XO_GAME_AI_GAMERUNNER_H
#define XO_GAME_AI_GAMERUNNER_H


#include <bits/stdc++.h>
using namespace std;


class GameRunner {
private:
    short lastPlayer = 1;

    bool validMenuUserInput(string take);
public:
    void run();
};


#endif //XO_GAME_AI_GAMERUNNER_H
