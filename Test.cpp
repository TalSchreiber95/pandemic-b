#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

TEST_CASE("Test OperationsExpert"){
    Board board;
    City r = City::Algiers;
    OperationsExpert player{board, r};
    CHECK_NOTHROW(player.build());
    r= City::Atlanta;
    CHECK_NOTHROW(player.build());
    r= City::Baghdad;
    CHECK_NOTHROW(player.build());
    r= City::Cairo;
    CHECK_NOTHROW(player.build());
    r= City::NewYork;
    CHECK_NOTHROW(player.build());
}
TEST_CASE("Test Dispatcher"){
    Board b;
    City c = City::Osaka;
    Dispatcher player{b, c};
    CHECK_NOTHROW(player.take_card(c));
    CHECK_NOTHROW(player.build());
    City c1 =City::Chicago;
    CHECK_THROWS(player.fly_direct(c1));
    CHECK_NOTHROW(player.take_card(c1));
    CHECK_THROWS(player.build());
    b.update_research_station(City::Chicago);
    CHECK_NOTHROW(player.fly_direct(c1));
    CHECK_NOTHROW(player.take_card(c1));
    CHECK_NOTHROW(player.build());
    
}

TEST_CASE("Test Virologist"){
    Board b;
    City c = City::Karachi;
    Virologist player{b, c};
    CHECK_THROWS(player.treat(c));
    player.take_card (c);
    CHECK_THROWS(player.treat(c));
    player.take_card(City::Santiago);
    b[City::Santiago]=6;
    CHECK_NOTHROW(player.treat(City::Santiago));
    c=City::Lagos;
    CHECK_THROWS(player.treat(c));

}

TEST_CASE("Test Researcher"){
    Board b;
    City c=City::Santiago;
    Researcher player{b, c};
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    player.take_card(c);
    player.take_card(City::BuenosAires);
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    player.take_card(City::Johannesburg);
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    player.take_card(City::Khartoum);
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    player.take_card(City::Kinshasa);
    CHECK_NOTHROW(player.discover_cure(Color::Yellow));
}
