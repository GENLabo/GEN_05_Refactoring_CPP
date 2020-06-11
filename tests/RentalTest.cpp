//
// Created by robin on 11.06.20.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Rental.h"

TEST(Rental, updateFrequentRenterPoint)
{
    // New release movie
    Rental rental(Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5);
    EXPECT_EQ(2, rental.updateFrequentRenterPoint(0));

    // New release movie
    Rental rental2(Movie( "La soupe aux choux", Movie::REGULAR ), 10);
    EXPECT_EQ(1, rental2.updateFrequentRenterPoint(0));
}