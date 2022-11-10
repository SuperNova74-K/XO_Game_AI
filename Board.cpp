//
// Created by walid on 10-Nov-22.
//

#include "Board.h"

vector<short> & Board::operator[](int x) {
    return board[x];
}

short Board::getGameState() {
    return gameState;
}

void Board::updateGameState() {
    if(isWin()){
        gameState = 1;
    }else if(isDrawAssumingNotWin()){
        gameState = 2;
    }
}

void Board::useSlot() {
    slotsUsed++;
}

void Board::print() {
    cout << "_________\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << setw(2) << printableFormOf(board[i][j]);
            if(j!=2){
                cout << '|';
            }
        }
        cout << '\n';
    }
    cout << "_________\n";
}

char Board::printableFormOf(short & x) {
    if(x == 3){
        return 'X';
    }else if(x == 4){
        return 'O';
    }else{
        return ' ';
    }
}

bool Board::isWin() {
    if(slotsUsed < 5){ // yes, the least amount of slots needed for someone to win is 5
        return false;
    }
    short verticalConsecutive = 0;
    short lastVertical = board[0][0];

    short horizontalConsecutive = 0;
    short lastHorizontal = board[0][0];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            if(board[i][j] == lastHorizontal){
                horizontalConsecutive++;
                if(horizontalConsecutive == 3){
                    return true;
                }
            }else{
                horizontalConsecutive = 0;
            }

            if(board[j][i] == lastVertical){
                verticalConsecutive++;
                if(verticalConsecutive == 3) {
                    return true;
                }
            }else{
                verticalConsecutive = 0;
            }
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return true;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return true;
    }

    return false;
}

bool Board::isDrawAssumingNotWin() const {
    if(slotsUsed == 9){
        return true;
    }
    return false;
}
