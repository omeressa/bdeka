
#pragma once
#include "Board.h"
#include "Player.h"

class TicTacToe{
public:
    Board game;
    int sizeOfBoard;
    Player* champion;

public:
    TicTacToe(int sizeOfBoard);
    Board board() const;
    Player& winner() const;
    void play(Player& xPlayer, Player& oPlayer);
    bool checkWinner(char c);

};
