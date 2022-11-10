//
// Created by walid on 10-Nov-22.
//

#include "GameRunner.h"


void GameRunner::run() {
    string userChoice;
    bool validUserChoice = false;
    do {
        cout << "Hello Players!"
                "Please Choose one of the following choices:"
                "(1) Player VS Player."
                "(2) Player VS AI."
                "(3) Exit Program."
                "Enter Your Choice Here: ";

        getline(cin, userChoice);
        validUserChoice = isValidMenuUserInput(userChoice);

        if(not validUserChoice){
            cout << "Invalid Input!"
                    "Please Try Again...";
            systemPause();
            clearTerminal();
        }

    }while(not validUserChoice);

    if(userChoice == "3"){
        return;
    }

    if(userChoice == "2"){
        player2 = new AI;
    }else{
        player2 = new Player;
    }

    while (board.getGameState()){
        player1.play();
        board.useSlot();
        board.updateGameState();

        if(board.getGameState()){
            declareResult();
        }

        player2->play();
        board.useSlot();
        board.updateGameState();

        if(board.getGameState()){
            declareResult();
        }
    }
}
void GameRunner::clearTerminal() {
    system("CLS");
}

void GameRunner::systemPause() {
    system("Pause");
}

bool GameRunner::isValidMenuUserInput(string & input) {
    if(input != "1" && input != "2" && input != "3"){
        return false;
    }
    return true;
}

GameRunner::~GameRunner() {
    delete player2;
}

short GameRunner::otherPlayer(short &player) {
    if(player == 1){
        return 2;
    }
    return 1;
}



void GameRunner::declareResult() {
    if(board.getGameState() == 2){
        cout << "Congrats Player" << lastPlayer << "! You win!" << '\n';
        cout << "GG Player " << otherPlayer(lastPlayer) << '\n';
    }else{
        cout << "Draw!" << '\n';
        cout << "GG Players!" << '\n';
    }
}
