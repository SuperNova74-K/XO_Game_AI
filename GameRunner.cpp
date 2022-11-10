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

    while (not board.isGameDone()){
        player1.play();

        if(board.isGameDone()){
            declareResult();
        }
        player2->play();

        if(board.isGameDone()){
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

bool GameRunner::isValidMenuUserInput(string &take) {
    if(take != "1" && take != "2" && take != "3"){
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
    if(board.isThereAWinner()){
        cout << "Congrats Player" << lastPlayer << "! You win!" << '\n';
        cout << "GG Player " << otherPlayer(lastPlayer) << '\n';
    }else{
        cout << "Draw!" << '\n';
        cout << "GG Players!" << '\n';
    }
}
