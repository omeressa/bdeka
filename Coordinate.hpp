#pragma once
#include <iostream>
#include "IllegalCharException.h"

using namespace std;

class Coordinate {
  
      private:
    
        char p;
        int index_i;
        int index_j;

    public:
        Coordinate();
        Coordinate(char Char);
        Coordinate(uint i,uint j);
        void operator=(char c);
        friend bool operator == (Coordinate const &, char const &);
        void set_Point(char c);
        char get_Point();
        operator char();
        int const getIndexI()const {return index_i;}
        int const getIndexJ()const{return index_j;}
        void setCoordinate(Coordinate c);
        friend ostream& operator<< (ostream& , const Coordinate&);
   };
