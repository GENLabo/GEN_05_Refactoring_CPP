// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.hpp"
#include "MovieStateRelease.hpp"

class Rental {
public:
    Rental(Movie* movie, int daysRented );

    virtual ~Rental();

    int getDaysRented() const;
    const Movie* getMovie() const;

    int updateFrequentRenterPoint(int currentPoints) const {
        // add frequent renter points + eventual bonus
        currentPoints += 1 + getMovie()->getRenterPoints(getDaysRented());

        return currentPoints;
    }

private:
    Movie* _movie;
    int _daysRented;
};

inline Rental::
Rental(Movie* movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline Rental::
~Rental() {
    delete _movie;
}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie* Rental::
getMovie() const { return _movie; }

#endif // RENTAL_H