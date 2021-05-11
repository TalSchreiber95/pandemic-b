#include "Dispatcher.hpp"

using namespace pandemic;


Player& Dispatcher::fly_direct(City c){
    if(city == c){
        throw std::invalid_argument{"Execption: local city is same to " + cityToString(c)};
    }
    if(board.is_research_station(city)) {
        city = c;
        return *this;
    }
    return Player::fly_direct(c);
}