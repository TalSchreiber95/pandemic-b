#include "Player.hpp"

using namespace pandemic;



Player& Player::drive(City c){
    if(city == c){
        throw std::invalid_argument{"Execption: local city is same to " + cityToString(c)};
    }
    if(!Board::is_connected(city, c)){ // if there is no connection throw exception
        throw invalid_argument{"Execption: " + cityToString(city) + " is not connected to " + cityToString(c)};
    }
    city = c;
    medicFunc();
    return *this;
}

Player& Player::fly_direct(City c){
    if(!cards.contains(c)){// if there is no card for this city throw execption
        throw invalid_argument{"Execption: card's " + cityToString(c)+" doesn'card exist"};
    }
    if(city == c){
        throw std::invalid_argument{"Execption: local city is same to " + cityToString(c)};
    }
    cards.erase(c); // erase target city
    city = c;
    medicFunc();
    return *this;
}

Player& Player::fly_charter(City c){
    if(cards.contains(city)){
        if(city == c){
            throw std::invalid_argument{"Execption: local city is same to " + cityToString(c)};
        } 
        cards.erase(city); // erase local city
        city = c;
        medicFunc();
        return *this;
    }

    throw invalid_argument{"Execption: card's " + cityToString(c)+" doesn'card exist"};

}

Player& Player::fly_shuttle(City c){
    if(!board.is_research_station(city) || !board.is_research_station(c)){
        throw invalid_argument{"Execption: " + cityToString(city) + " and " + cityToString(c) + " must both have research station."};
    }
    if(city == c){
        throw std::invalid_argument{"Execption: local city is same to " + cityToString(c)};
    } 
    city = c;
    medicFunc();
    return *this;
}

Player& Player::build(){
    if(!cards.contains(city)){
        throw invalid_argument{"Execption: research station faild, player must have a " + cityToString(city) + "'s card!"};
    }
    board.update_research_station(city);
    cards.erase(city);
    return *this;
}

Player& Player::discover_cure(Color c){
    if(!board.is_research_station(city)){
        throw invalid_argument{"Execption: city "+cityToString(city)+" must have research station!"};
    }
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

Player& Player::treat(City c){
    if (city != c) {
        throw invalid_argument{"Execption: Outside of city" + cityToString(c)};
    }
    if (board[c] == 0) {
        throw invalid_argument{"Execption: not enough cubes in city " + cityToString(c)};
    }
    if (board.is_cure_discoverd(c)) {
        board[c] = 0;
    }
    else {
        board[c]--;
    }
    return *this;
}

Player& Player::take_card(City c){
    cards.insert(c);
    return *this;
}