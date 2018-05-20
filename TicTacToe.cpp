

#include "TicTacToe.h"
#include <string>
/**
*function to give the size of the game board
**/
TicTacToe::TicTacToe(int sizeOfBoard):game(sizeOfBoard){this->sizeOfBoard=sizeOfBoard;}

/**
*function to start the game
**/
void TicTacToe::play(Player &xPlayer, Player &oPlayer){
    this->game ='.';
    int size = sizeOfBoard*sizeOfBoard;
    int count = 0;
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    Coordinate temp(0,0);
    while(count < size){
        count++;
        try{
            temp.setCoordinate(xPlayer.play(game));
            if(game[temp]=='.')
                game[temp] = xPlayer.getChar();
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
        if(count < size){
            try{
                temp.setCoordinate(oPlayer.play(game));
                if(game[temp]=='.')
                    game[temp] = oPlayer.getChar();
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

/**
*bool function to check if the player won or not
**/
bool TicTacToe::isWinner(char c)
{
    bool ans = true;

    for(uint i = 0; i< sizeOfBoard ; i++){
        ans = true;
        //op 1
        for(uint j = 0; j<sizeOfBoard ; j++){
            if(game[{i,j}] != c){
                ans = false;
                break;
            }
        }
        if(ans)
            return true;
        ans = true;
        //op 2
        for(uint j = 0; j<sizeOfBoard ; j++){
            if(game[{j,i}] != c){
                ans = false;
                break;
            }
        }
        if(ans)
            return true;
    }
    ans = true;
    //op 3
    for(uint i = 0; i<sizeOfBoard ; i++){
        if(game[{i,i}] != c){
            ans = false;
            break;
        }
    }
    if(ans)
        return true;
    ans = true;
    //op 4
    for(uint i = 0; i<sizeOfBoard ; i++){
        if(game[{sizeOfBoard-i-1,i}] != c){
            ans = false;
            break;
        }
    }
    return ans;
}

