// Customer.cpp
#include <sstream>
#include "Customer.hpp"


using std::ostringstream;
using std::vector;

using namespace std;


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