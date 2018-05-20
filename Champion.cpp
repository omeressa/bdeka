#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
    for (uint j=0; j<board.size(); ++j) {
        uint i = board.size()-1-j;
        Coordinate temp{i,j};
        i = board.size()-1;
        if(j==1 && board[{0,i}] == '.'){
            temp.setIndexI(0); temp.setIndexJ(board.size()-1);
        }
        if(board[temp]=='.') {return temp;}
    }
    return {0,0};
}
