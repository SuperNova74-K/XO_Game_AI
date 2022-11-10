//
// Created by walid on 10-Nov-22.
//

#ifndef XO_GAME_AI_GAMERUNNER_H
#define XO_GAME_AI_GAMERUNNER_H


#include <bits/stdc++.h>
#include "Player.h"
#include "Board.h"
using namespace std;


class GameRunner {
private:
    short lastPlayer = 1;
    Player player1;
    Player* player2;
    Board board;
    bool isValidMenuUserInput(string& take);
    static void  clearTerminal();
    static void  systemPause();
    static short otherPlayer(short & player);
    void declareResult();

public:
    void run();
    ~GameRunner();
};


#endif //XO_GAME_AI_GAMERUNNER_H
