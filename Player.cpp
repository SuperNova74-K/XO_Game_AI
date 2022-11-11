//
// Created by walid on 10-Nov-22.
//

#include "Player.h"

AI::AI() = default;

Player::Player() = default;

Point Player::takePointInput(Board & board) {
    bool validMove;
    bool validInputString;
    string userInput;
    deque<string>tokens;
    do {
        cout << "Player" << ID << ", please enter point coordinates [0:2] separated by space: ";
        getline(cin , userInput);

        tokens = stringTokenizer(userInput);
        validInputString = isValidInput(tokens);
        if(not validInputString){
            tokens.clear();
                cout << "Invalid Input..\n";
                cout << "Please Try Again..;\n";
                system("Pause");
        }else{
            validMove = isMoveValid(tokens[0][0] - '0', tokens[1][0] - '0', board);
            if(not validMove){
                tokens.clear();
                cout << "Invalid Move!\n";
                cout << "Try Again...\n";
                system("Pause");
            }
        }
    }while(not validInputString || not validMove);
    Point returnValue;
    returnValue.x = tokens[0][0] - '0';
    returnValue.y = tokens[1][0] - '0';
    returnValue.value = ID + 2; // if player 1 played they are going to put value 1+2 = 3 in board
    return returnValue;
}

bool Player::isMoveValid(short x, short y, Board & board) {
    if(board[x][y] == 3 || board[x][y] == 4){ // 3 means X played here, 4 is O
        return false;
    }
    return true;
}

deque<string> Player::stringTokenizer(string & input) {
    deque<string> answer;
    unsigned long long i = 0;
    while (i < input.size() && (input[i] == ' ' || input[i] == '\t')){
        i++;
    }

    string word;
    while(i < input.size()) {
        if(not (input[i] == ' ' || input[i] == '\t') && i < input.size()){
            while(not (input[i] == ' ' || input[i] == '\t') && i < input.size()){
                word += input[i];
                i++;
            }
            answer.push_back(word);
            word.clear();
        }else{
            i++;
        }
    }

    return answer;
}

bool Player::isValidInput(auto tokens) {
    if(tokens.size() != 2)
        return false;

    if(tokens[0].size() != 1 || tokens[1].size() != 1)
        return false;

    if(tokens[0][0] > '9' || tokens[0][0] < '0' | tokens[1][0] > '9' || tokens[1][0] < '0')
        return false;

    return true;
}

Player::Player(short iD) {
    ID = iD;
}

short Player::getID() {
    return ID;
}

void Player::play(Board &board) {
    Point choice = takePointInput(board);
    board[choice.x][choice.y] = ID + 2;
}

AI::AI(Board&) {

}

void AI::play(Board & board) {
    // AI always minimizes
    short bestScore = SHRT_MAX;
    Point bestMove;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(board[i][j] == 5){ // if slot is available try to minMax on it
                board[i][j] = 4;
                board.useSlot();

                short temp = minMax(board, true);
                if(temp < bestScore){
                    bestScore = temp;
                    bestMove.x = i;
                    bestMove.y = j;
                }

                board[i][j] = 5;
                board.freeSlot();
            }
        }
    }
    board[bestMove.x][bestMove.y] = 4;
}

short AI::minMax(Board board, bool isMaximize){
    // base case
    if(board.isWin()){
        if(isMaximize){
            return -1;
        }
        return 1;
    }else if(board.isDrawAssumingNotWin()){
        return 0;
    }

    if(isMaximize){
        short bestScore = SHRT_MIN;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(board[i][j] == 5){
                    board[i][j] = 3;
                    board.useSlot();

                    bestScore = max(bestScore, minMax(board, false));

                    board[i][j] = 5;
                    board.freeSlot();
                }
            }
        }
        return bestScore;
    }else{
        // here we minimze
        short bestScore = SHRT_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(board[i][j] == 5){
                    board[i][j] = 4;

                    board.useSlot();
                    bestScore = min(bestScore, minMax(board, true));

                    board.freeSlot();
                    board[i][j] = 5;
                }
            }
        }
        return bestScore;
    }
}
