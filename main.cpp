#include <iostream>

#include "Customer.h"
#include "MovieStateRegular.hpp"
#include "MovieStateChildren.hpp"
#include "MovieStateRelease.hpp"

int main() {

    Customer customer("Olivier");
    customer.addRental(Rental(Movie("Karate Kid", new MovieStateRegular()), 7));
    customer.addRental(Rental(Movie( "Avengers: Endgame",new MovieStateRelease()), 5));
    customer.addRental(Rental(Movie("Snow White", new MovieStateChildren()), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}