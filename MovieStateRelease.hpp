//
// Created by robin on 11.06.20.
//

#ifndef GEN_CPP_REFACTORING_MOVIESTATERELEASE_HPP
#define GEN_CPP_REFACTORING_MOVIESTATERELEASE_HPP

#include "MovieState.hpp"

class MovieStateRelease : public MovieState {
public:
    double getPrice(int daysRented) override {
        return daysRented * 3;
    }

    int getRenterPoints(int daysRented) override {
        // add bonus for a two day new release rental
        return daysRented > 1 ? 1 : 0;
    }
};

#endif //GEN_CPP_REFACTORING_MOVIESTATERELEASE_HPP
