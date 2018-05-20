#include <exception>
#include <iostream>
#include "Coordinate.hpp"


using namespace std;


Coordinate::Coordinate(){
    this->p='.';
}
Coordinate::Coordinate(uint i ,uint j){
    index_i = i;
    index_j = j;
}
Coordinate::Coordinate(char other){
    if(other != 'X' && other != 'O' && other != '.')
      throw IllegalCharException(other);
    this->p = other ;
}
void Coordinate::operator= (char other) {
    if (other != '.' && other != 'X' && other != 'O')
    throw IllegalCharException(other);
    this->p = other;}
Coordinate::operator char(){
    return this->p;
}

bool operator == (Coordinate const & x, char const & y){
    return x.p == y;
}

/** Stream **/

ostream& operator<< (ostream& os, const Coordinate& p) {
    os << p.p;
    return os;
}
/*
ostream& operator<< (ostream& out,Coordinate& s){
   return cout <<s.getIndexI()<<","<<s.getIndexJ()<<endl;
}


/**helping functions **/
char Coordinate::get_Point(){
    return this->p;   
}
void Coordinate::set_Point(char other){
    if (other != '.' && other != 'X' && other != 'O')
    throw IllegalCharException(other);
    this->p = other;
}
