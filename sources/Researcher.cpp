#include "Researcher.hpp"

using namespace pandemic;


Player& Researcher::discover_cure(Color c){
    int count = 0;
    for(const auto& t : cards){
        if(Board::colorOf(t) == c){
            count++;
        }
    }
    if(count < CardLimit){
        throw invalid_argument{"Execption: there is only "+to_string(count)+" "+ colorToString(c) + " cards remaining " };
    }
    count = 1;
    for(auto it = cards.begin(); it != cards.end(); count++){
        if(count == CardLimit) { break; }
        if(Board::colorOf(*it) == c) {
            it = cards.erase(it);
        }
        else {
            ++it;
        }
    }
    board.mark_cured(c);
    return *this;
}