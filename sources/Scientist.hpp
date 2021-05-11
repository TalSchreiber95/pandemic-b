#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Scientist: public Player {
        int n;

        public:
            Scientist(Board& b, City c, int num): Player(b, c), n(num) {typeRole="Scientist";}
            Player& discover_cure(Color c) override;
    };
    
}