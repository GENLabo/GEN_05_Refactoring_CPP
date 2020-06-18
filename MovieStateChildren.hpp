//
// Created by robin on 11.06.20.
//

#ifndef GEN_CPP_REFACTORING_MOVIESTATECHILDREN_HPP
#define GEN_CPP_REFACTORING_MOVIESTATECHILDREN_HPP
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "MovieState.hpp"

class MovieStateChildren : public MovieState {
public:

    double getPrice(int daysRented) override {
        double price = 1.5;
        if (daysRented > 3 )
            price += (daysRented - 3 ) * 1.5;
        return price;
    }

    int getRenterPoints(int daysRented) override {
        return 0;
    }
};

TEST(MovieStateChildren, getPrice) {
    Movie movie("Avatar", new MovieStateChildren);
    EXPECT_EQ(movie.getPrice(10), 12);
}

#endif //GEN_CPP_REFACTORING_MOVIESTATECHILDREN_HPP
