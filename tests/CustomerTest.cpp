//
// Created by loic on 6/4/20.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Customer.hpp"

TEST(Customer, statement)
{
    EXPECT_EQ(1, 1);
    Customer customer("René");
    customer.addRental(new Rental(new Movie("Karate Kid",new MovieStateRegular()), 7));
    customer.addRental(new Rental(new Movie( "Avengers: Endgame", new MovieStateRelease()), 5));
    customer.addRental(new Rental(new Movie("Snow White", new MovieStateChildren()), 3 ));

    EXPECT_EQ(customer.getName(), "René");

    EXPECT_EQ(customer.statement(), "Rental Record for René\n"
                                    "\tKarate Kid\t9.5\n"
                                    "\tAvengers: Endgame\t15\n"
                                    "\tSnow White\t1.5\n"
                                    "Amount owed is 26\n"
                                    "You earned 4 frequent renter points");
}
