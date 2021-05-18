#include "Researcher.hpp"

using namespace pandemic;


Player& Researcher::discover_cure(Color c){
    int count = 0;
    for(const auto& card : cards){
        if(Board::colorOf(card) == c){
            count++;
        }
    }
    if(count < CardLimit){
        throw invalid_argument{"Execption: there is only "+to_string(count)+" "+ colorToString(c) + " cards remaining " };
    }
    count = 1;
    for(auto card = cards.begin(); card != cards.end(); count++){
        if(count == CardLimit) { break; }
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