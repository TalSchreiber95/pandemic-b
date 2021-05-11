#include "Virologist.hpp"

using namespace pandemic;

Player& Virologist::treat(City c){
    if (city != c) {
        if(!cards.contains(c)) {
            throw invalid_argument{"Execption: card's " + cityToString(c)+"doesn't exist"};
        }
        cards.erase(c);
    }
    else if (board[c] == 0) {
        throw invalid_argument{"Execption: not enough cubes in city " + cityToString(c)};

    }
    else if (board.is_cure_discoverd(c)) {
        board[c] = 0;
        return *this;
    }
    board[c]--;
    return *this;
}