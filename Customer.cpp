// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "MovieStateChildren.hpp"
#include "MovieStateRelease.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using std::ostringstream;
using std::vector;

using namespace std;

TEST(Customer, statement) {
    Customer customer("René");
    customer.addRental(new Rental(new Movie("Karate Kid", new MovieStateRegular()), 7));
    customer.addRental(new Rental(new Movie( "Avengers: Endgame", new MovieStateRelease()), 5));
    customer.addRental(new Rental(new Movie("Snow White", new MovieStateChildren()), 3 ));
    EXPECT_EQ(customer.statement(), "Rental Record for René\n"
                                    "\tKarate Kid\t9.5\n"
                                    "\tAvengers: Endgame\t15\n"
                                    "\tSnow White\t1.5\n"
                                    "Amount owed is 26\n"
                                    "You earned 4 frequent renter points");
}

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for (Rental* rental : _rentals) {
        double thisAmount = 0;

        // determine amounts for each line
        thisAmount += rental->getMovie()->getPrice(rental->getDaysRented());

        frequentRenterPoints = rental->updateFrequentRenterPoint(frequentRenterPoints);

        // show figures for this rental
        result << "\t" << rental->getMovie()->getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}