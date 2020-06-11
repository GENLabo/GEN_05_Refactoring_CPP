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
};

#endif //GEN_CPP_REFACTORING_MOVIESTATERELEASE_HPP
