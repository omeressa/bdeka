
#pragma  once
#include "Player.h"

class Champion : public Player
{
public:
    const Coordinate play(const Board& board) override ;
    const string name() const override {
        return "OMAR";
    };
};
