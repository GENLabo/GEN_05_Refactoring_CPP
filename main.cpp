/*
 * Authors: Robin Demarta, Loïc Dessaules & Vitor Vaz Afonso
 */

#include <iostream>
#include "Customer.hpp"


int main() {

    Customer customer("Olivier");
    customer.addRental(new Rental(new Movie("Karate Kid", new MovieStateRegular()), 7));
    customer.addRental(new Rental(new Movie( "Avengers: Endgame",new MovieStateRelease()), 5));
    customer.addRental(new Rental(new Movie("Snow White", new MovieStateChildren()), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}