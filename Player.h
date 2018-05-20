
#pragma once
#include "Board.h"
#include <string>
#include <exception>


class Player
{

public:
    char myChar;
    Player(){}
    Player(char c){
        if (c=='O' || c== 'X')
            myChar=c;
        else{
            IllegalCharException ex;
            ex.setInput(c);
            throw ex;
        }
    }
    void setChar(char c) {myChar = c;}
    char getChar(){return myChar;}
    virtual const string name() const =0;
    virtual const Coordinate play(const Board& board)=0 ;
};
