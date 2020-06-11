// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;

    int updateFrequentRenterPoint(int currentPoints) {
        // add frequent renter points
        ++currentPoints;

        // add bonus for a two day new release rental
        if ((getMovie().getPriceCode() == Movie::NEW_RELEASE)
             && getDaysRented() > 1 ) currentPoints++;

        return currentPoints;
    }

private:
    Movie _movie;
    int _daysRented;
};

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

#endif // RENTAL_H