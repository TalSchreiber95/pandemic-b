#include "Scientist.hpp"

using namespace pandemic;

Player& Scientist::discover_cure(Color c) {
    if(!board.is_research_station(city)){
        throw invalid_argument{"Execption: city "+cityToString(city)+" must have research station!"};
    }
    int count = 0;
    for(const auto& card : cards){
        if(Board::colorOf(card) == c){
            count++;
        }
    }
    if(count < n){
        throw invalid_argument{"Execption: there is only "+to_string(count)+" "+ colorToString(c) + " cards remaining " };
    }
    count = 1;
    for(auto card = cards.begin(); card != cards.end(); count++){
        if(count == n) { break; }
        if(Board::colorOf(*card) == c) {
            card = cards.erase(card);
        }
        else {
            ++card;
        }
    }
    board.mark_cured(c);
    return *this;
}