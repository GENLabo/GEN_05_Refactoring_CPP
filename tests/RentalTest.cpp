//
// Created by loic on 6/4/20.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Rental.hpp"

TEST(Rental, updateFrequentRenterPoint)
{
    Rental rental1(new Movie("Avatar 2", new MovieStateChildren), 15);
    EXPECT_EQ(rental1.updateFrequentRenterPoint(120), 121);

    Rental rental2(new Movie("Avatar 2", new MovieStateRegular), 15);
    EXPECT_EQ(rental2.updateFrequentRenterPoint(120), 121);

    Rental rental3(new Movie("Avatar 2", new MovieStateRelease), 15);
    EXPECT_EQ(rental3.updateFrequentRenterPoint(120), 122);
}
