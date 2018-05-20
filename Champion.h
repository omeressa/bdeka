
#pragma  once
#include "Player.h"

class Champion : public Player
{
public:
/*
         const string name() const override {return "OMAR";};
         const Coordinate play(const Board& board) override ;
         */
        virtual const string name()const{return "omar";}
        virtual const Coordinate play(const Board& board) override;
};
