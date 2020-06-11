//
// Created by robin on 11.06.20.
//
/*
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Rental.h"
#include "../MovieStateRelease.hpp"

TEST(Rental, updateFrequentRenterPoint)
{
    // New release movie
    Rental rental(Movie( "Avengers: Endgame", new MovieStateRelease()), 5);
    EXPECT_EQ(2, rental.updateFrequentRenterPoint(0));

    // New release movie
    Rental rental2(Movie( "La soupe aux choux", new MovieStateRegular()), 10);
    EXPECT_EQ(1, rental2.updateFrequentRenterPoint(0));
}
 */