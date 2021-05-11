#include "OperationsExpert.hpp"

using namespace pandemic;


Player& OperationsExpert::build(){
    board.update_research_station(city);
    return *this;
}