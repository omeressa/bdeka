
#pragma once
#include "Board.h"
#include <string>
#include <IllegalCharException.h>


class Player
{

public:
    char myChar;
    Player(){}
    Player(char c){
        if (c=='O' || c== 'X')
            myChar=c;
        else{
            throw IllegalCharException(c);

            /*
            IllegalCharException ex;
            ex.setInput(c);
            throw ex;*/
        }
    }
    void setChar(char c) {myChar = c;}
    char getChar(){return myChar;}
    virtual const string name() const =0;
    virtual const Coordinate play(const Board& board)=0 ;
};
