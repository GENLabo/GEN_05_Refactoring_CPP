//
// Created by loic on 6/4/20.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Movie.hpp"

TEST(Movie, getPrice)
{
    Movie movie("The Incredibles", new MovieStateChildren);
    EXPECT_EQ(movie.getPrice(10), 12);

    Movie movie2("The Goonies", new MovieStateRegular);
    EXPECT_EQ(movie2.getPrice(10), 14);

    Movie movie3("The Joker", new MovieStateRelease);
    EXPECT_EQ(movie3.getPrice(10), 30);
}
