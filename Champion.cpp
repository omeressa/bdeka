/*
#include "Champion.h"
const Coordinate Champion::play(const Board& board) {
    for (uint i=0; i<board.size(); ++i) {
        uint t = board.size()-1-i;
        Coordinate c{t,i};
        t = board.size()-1;
        if(i==1 && board[{0,t}] == '.'){
            c.setIndexI(0); c.setIndexJ(board.size()-1);
        }
        if(board[c]=='.') {
            return c;
        }
    }
    return {0,0};
}
*/
#include "Champion.h"

const Coordinate Champion::play(const Board& board){
    if(board[{0,board.size()-1}]=='.'){
        return {0,board.size()-1};
    }
    if(board[{board.size()-1,0}]=='.'){
        return {board.size()-1,0};
    }
    uint i = board.size()-1, j = 0;
    while(j<board.size()){
        Coordinate c{i,j};
	    if (board[c]=='.') {
			return c;
		}
        i--;
        j++; 
    }
    return {0,0};
}
