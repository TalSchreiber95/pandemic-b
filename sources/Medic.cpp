#include "Medic.hpp"

using namespace pandemic;

Player& Medic::treat(City c) {
    if (city != c) {
        throw invalid_argument{"Execption: Outside of city" + cityToString(c)};
    }
    if (board[c] == 0) {
        throw invalid_argument{"Execption: not enough cubes in city " + cityToString(c)};
    }
    board[c] = 0;
    return *this;
}
void Medic::medicFunc(){
    if(board.is_cure_discoverd(city)) {
            board[city] = 0;
        }
}