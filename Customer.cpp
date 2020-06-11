// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"


using std::ostringstream;
using std::vector;

using namespace std;


string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for (const Rental& rental : _rentals) {
        double thisAmount = 0;

        // determine amounts for each line
        switch ( rental.getMovie().getPriceCode() ) {
            case Movie::REGULAR:
                thisAmount += 2;
                if ( rental.getDaysRented() > 2 )
                    thisAmount += ( rental.getDaysRented() - 2 ) * 1.5 ;
                break;
            case Movie::NEW_RELEASE:
                thisAmount += rental.getDaysRented() * 3;
                break;
            case Movie::CHILDRENS:
                thisAmount += 1.5;
                if ( rental.getDaysRented() > 3 )
                    thisAmount += ( rental.getDaysRented() - 3 ) * 1.5;
                break;
        }

        frequentRenterPoints = rental.updateFrequentRenterPoint(frequentRenterPoints);

        // show figures for this rental
        result << "\t" << rental.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}