

#include "TicTacToe.h"
#include <string>

TicTacToe::TicTacToe(int sizeOfBoard):game(sizeOfBoard){
    this->sizeOfBoard=sizeOfBoard;
}


void TicTacToe::play(Player &xPlayer, Player &oPlayer)
{
    this->game ='.'; // initial empty board
    int s = sizeOfBoard*sizeOfBoard;
    int count = 0;
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    Coordinate c(0,0);
    while(count < s){
        count++;
        try{
            c.setCoordinate(xPlayer.play(game));
            if(game[c]=='.')
                game[c] = xPlayer.getChar();
            else{
                champion = &oPlayer; return;
            }
        }
        catch(const string& msg) {
            champion = &oPlayer; return;
        }

        if(isWinner('X')) {
            champion = &xPlayer; return;
        }
        count++;
        if(count < s){
            try{
                c.setCoordinate(oPlayer.play(game));
                if(game[c]=='.')
                    game[c] = oPlayer.getChar();
                else{
                    champion = &xPlayer; return;
                }
            }
            catch(const string& msg) {
                champion = &xPlayer; return;
            }

            if(isWinner('O')) {
                champion= &oPlayer; return;
            }
        }
    }
    champion = &oPlayer;
}
bool TicTacToe::isWinner(char c)
{
    bool winning = true;

    for(uint i = 0; i< sizeOfBoard ; i++)
    {
        winning = true;
        for(uint j = 0; j<sizeOfBoard ; j++)
        {
            if(game[{i,j}] != c){
                winning = false;
                break;
            }
        }
        if(winning)
            return true;

        winning = true;
        for(uint j = 0; j<sizeOfBoard ; j++)
        {
            if(game[{j,i}] != c){
                winning = false;
                break;
            }
        }
        if(winning)
            return true;
    }

    winning = true;
    for(uint i = 0; i<sizeOfBoard ; i++)
    {
        if(game[{i,i}] != c){
            winning = false;
            break;
        }
    }
    if(winning)
        return true;
    winning = true;
    for(uint i = 0; i<sizeOfBoard ; i++)
    {
        if(game[{sizeOfBoard-i-1,i}] != c){
            winning = false;
            break;
        }
    }
    return winning;
}

/*
Board TicTacToe::board() const{
    return game;
}


Player& TicTacToe::winner() const
{
    return *champion;
}*/
