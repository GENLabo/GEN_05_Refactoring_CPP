//
// Created by robin on 11.06.20.
//

#ifndef GEN_CPP_REFACTORING_MOVIESTATEREGULAR_HPP
#define GEN_CPP_REFACTORING_MOVIESTATEREGULAR_HPP
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "MovieState.hpp"
#include "Movie.hpp"

class MovieStateRegular : public MovieState {
public:

    double getPrice(int daysRented) override {
        double price = 2;
        if (daysRented > 2)
            price += (daysRented - 2) * 1.5;
        return price;
    }

    int getRenterPoints(int daysRented) override {
        return 0;
    }
};

TEST(MovieStateRegular, getPrice) {
    Movie movie("Avatar", new MovieStateRegular);
    EXPECT_EQ(movie.getPrice(10), 12);
}

TEST(MovieStateRegular, getRenterPoints) {
    Movie movie("Avatar 2", new MovieStateRegular);
    EXPECT_EQ(movie.getRenterPoints(50), 0);
}

#endif //GEN_CPP_REFACTORING_MOVIESTATEREGULAR_HPP
