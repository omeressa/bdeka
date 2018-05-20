#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

#include "Board.h"

Board::Board(int _size){
    int i,j;
    this->_size = _size;
    board = new Coordinate*[_size];
    
    for(i = 0; i < _size; ++i){
    board[i] = new Coordinate[_size];
    }
    i=0;  
    /**
     * filling all board with dots ( . ) */
    for(i = 0; i < _size; i++) {
      for(j = 0; j <  _size; j++) {
          board[i][j] = '.';
        }
    }
}

uint Board::size() const{
    int ans = _size;
    return ans;
}

/** copy Constructor */
Board::Board(const Board& board) {
     this->_size = board._size;
     this->board = new Coordinate*[this->_size];
        
     for(int i = 0; i < board._size; i++)
        this->board[i] = new Coordinate[this->_size];
           int i,j;     
      for( i = 0; i < board._size; i++) {
         for( j = 0; j < board._size; j++) {
            this->board[i][j] = board.board[i][j];
        }
    }
}

/** Distrctor */
Board::~Board(){
    for(int i = 0; i <_size ; ++i)
       delete[] board[i];
       delete[] board;
}


Board& Board::operator= (char c) {
     if(c !='.' && c !='X' && c!= 'O')
     throw IllegalCharException(c);
       
     for(int i = 0; i < _size; i++)
        for(int j = 0; j < _size; j++)
           board[i][j] = c;
    return *this;
}

Board& Board::operator= (const Board& b) {
        this->~Board();
        _size = b._size;
        board = new Coordinate*[_size];
        
        for(int i = 0; i < _size; i++)
        board[i] = new Coordinate[_size];
        
        for(int i = 0; i < _size; i++)
                for(int j = 0; j < _size; j++)
                  board[i][j].set_Point(b.board[i][j].get_Point());
    return *this;
}


Coordinate& Board::operator[](const Coordinate& c)const{
    /*
        try {
        (c.getIndexI()>=_size||c.getIndexJ()>=_size);  // This should raise an exception
    } catch (const IllegalCoordinateException& ex) {
        cout << "IllegalCoordinateException"  << IllegalCoordinateException(c.getIndexI(),c.getIndexJ()) << endl;  // prints "Illegal coordinate: 3,4"
    }
    */
    
    if(c.getIndexI()>=_size||c.getIndexJ()>=_size){
        throw(IllegalCoordinateException(c.getIndexI(),c.getIndexJ()));
    }
    return board[c.getIndexI()][c.getIndexJ()];
}

ostream& operator << (ostream & os, const Board & board){
    for(int i = 0 ; i < board._size ; i++){
        for(int j = 0 ; j < board._size ; j++){
            os << board.board[i][j];
        }
        os << endl;
    }
    return os;
}












