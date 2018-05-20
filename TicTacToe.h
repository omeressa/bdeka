
#pragma once
#include "Board.h"
#include "Player.h"

class TicTacToe{
public:
    Board game;
    int sizeOfBoard;
    Player* champion;
    
    TicTacToe(int sizeOfBoard);
    void play(Player& xPlayer, Player& oPlayer);
    bool isWinner(char c);
    Board board() const{return game;};
    Player& winner() const{return *champion;};
};
