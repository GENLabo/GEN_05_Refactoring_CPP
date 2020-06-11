//
// Created by robin on 11.06.20.
//

#ifndef GEN_CPP_REFACTORING_MOVIESTATEREGULAR_HPP
#define GEN_CPP_REFACTORING_MOVIESTATEREGULAR_HPP

#include "MovieState.hpp"

class MovieStateRegular : public MovieState {
public:

    double getPrice(int daysRented) override {
        double price = 2;
        if (daysRented > 2)
            price += (daysRented - 2) * 1.5;
        return price;
    }
};

#endif //GEN_CPP_REFACTORING_MOVIESTATEREGULAR_HPP
