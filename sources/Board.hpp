#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>
using namespace std;
namespace pandemic {

    class Board {

        static map<City, set<City>> connections; // the set of the citys that connected to each city
        map<City, int> diseasBox;
        // bool medicine[4] = {0};
        set<Color> medicine;
        set<City> researchStations;

        public:
            Board() {}

            int& operator[](City c); // update diseasBox, for example board[City::HongKong]=2 means disease_cube[HongKong]=2
            bool is_clean(); // is the board clean from disease?
            static bool is_connected(City& c1, City& c2); // is there connection between those two cities?
            void update_research_station(City c); // place reseach station in this city
            bool is_research_station(City c);// is there any reseach station in this city?
            void mark_cured(Color c); // mark medicine's color that found.
            bool is_cure_discoverd(City c);  // is there any cure for color's disease that this city need?
            static Color colorOf(City c); // what the color's disease that this city got infected
            friend ostream& operator<<(ostream& out,const Board& b);
            inline void remove_cures(){ medicine.clear(); }
            inline void remove_stations(){ researchStations.clear(); }
    };
}
