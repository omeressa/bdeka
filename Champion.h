
#pragma  once
#include "Player.h"

class Champion : public Player
{
public:

        virtual const string name()const{return "omar";}
        virtual const Coordinate play(const Board& board) override;
        
};
