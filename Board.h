#ifndef BOARD_H
#define BOARD_H

#pragma once

#include <iostream>
#include "Coordinate.hpp"
#include "IllegalCoordinateException.h"

using namespace std;



class Board {
  
    private:
        

    public:
        int _size;
        Coordinate** board;
        Board(const int _size);
        Board(const Board& board); 
        ~Board();
        Board(){}

        uint size() const;
        
        Board& operator= (char c);
        Board& operator= (const Board& b);
        Coordinate& operator[](const Coordinate& c)const;


        friend ostream& operator<< (ostream& os,const Board& board);
        
};
#endif
