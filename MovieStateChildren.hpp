//
// Created by robin on 11.06.20.
//

#ifndef GEN_CPP_REFACTORING_MOVIESTATECHILDREN_HPP
#define GEN_CPP_REFACTORING_MOVIESTATECHILDREN_HPP

#include "MovieState.hpp"

class MovieStateChildren : public MovieState {
public:
    double getPrice(int daysRented) override {
        double price = 1.5;
        if (daysRented > 3 )
            price += (daysRented - 3 ) * 1.5;
        return price;
    }
};

#endif //GEN_CPP_REFACTORING_MOVIESTATECHILDREN_HPP
