//
// Created by walid on 10-Nov-22.
//

#ifndef XO_GAME_AI_PLAYER_H
#define XO_GAME_AI_PLAYER_H

#include <bits/stdc++.h>
#include "Board.h"

using namespace std;


class Point{
public:
    Point() = default;
    Point(short X ,short Y,short Val){
        x = X;
        y = Y;
        value = Val;
    }
    short x, y, value = 0;
};

class Player {
protected:
    short ID = 1;

    virtual Point takePointInput(Board & board);
    virtual bool isMoveValid(short x, short y, Board & board);
    bool isValidInput(auto tokens);
    static deque<string> stringTokenizer(string &);
public:
    Player();
    Player(short iD);
    virtual short getID();
    virtual void play(Board & board);
};


class AI : public Player{
protected:
    Point bestmove;
    short minMax(Board & board, short maxOrMin);
public:
    AI(Board&);
    AI();
    void play(Board & board) override;

    // minmax here
};

#endif //XO_GAME_AI_PLAYER_H
