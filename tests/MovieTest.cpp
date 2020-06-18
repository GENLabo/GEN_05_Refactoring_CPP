/*
 * Authors: Robin Demarta, Loïc Dessaules & Vitor Vaz Afonso
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Movie.hpp"

class MockMovieStateChildren : public MovieStateChildren {
    MOCK_METHOD(double, getPrice, (int daysRented), (const));
    MOCK_METHOD(int, getRenterPoints, (int daysRented), (const));
};

class MockMovieStateRegular : public MovieStateRegular {
    MOCK_METHOD(double, getPrice, (int daysRented), (const));
    MOCK_METHOD(int, getRenterPoints, (int daysRented), (const));
};

class MockMovieStateRelease : public MovieStateRelease {
    MOCK_METHOD(double, getPrice, (int daysRented), (const));
    MOCK_METHOD(int, getRenterPoints, (int daysRented), (const));
};

TEST(Movie, getPrice)
{
    Movie movie("The Incredibles", new MockMovieStateChildren);
    EXPECT_EQ(movie.getPrice(10), 12);

    Movie movie2("The Goonies", new MockMovieStateRegular);
    EXPECT_EQ(movie2.getPrice(10), 14);

    Movie movie3("The Joker", new MockMovieStateRelease);
    EXPECT_EQ(movie3.getPrice(10), 30);
}

TEST(Movie, getRenterPoints)
{
    Movie movie("The Incredibles", new MockMovieStateChildren);
    EXPECT_EQ(movie.getRenterPoints(10), 0);

    Movie movie2("The Goonies", new MockMovieStateRegular);
    EXPECT_EQ(movie2.getRenterPoints(10), 0);

    Movie movie3("The Joker", new MockMovieStateRelease);
    EXPECT_EQ(movie3.getRenterPoints(10), 1);
}
