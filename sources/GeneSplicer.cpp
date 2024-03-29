#include "GeneSplicer.hpp"

using namespace pandemic;

Player& GeneSplicer::discover_cure(Color c){
    if(!board.is_research_station(city)){
        throw invalid_argument{"Execption: city "+cityToString(city)+" must have research station!"};
    }
    if(cards.size() < CardLimit){
        throw invalid_argument{"Execption: there is only "+to_string(cards.size())+" "+ colorToString(c) + " cards remaining " };
    }
    int count = 1;
    for(auto card = cards.begin(); card != cards.end(); count++){
        if(count == CardLimit ){ break; }
        card = cards.erase(card);
    }
    board.mark_cured(c);
    return *this;
}