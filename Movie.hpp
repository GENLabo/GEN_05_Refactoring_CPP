// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include "MovieStateRegular.hpp"

class Movie {
public:
    explicit Movie( const std::string& title, MovieState* state);

    virtual ~Movie();

    std::string getTitle() const;
    double getPrice(int daysRented) const {
        return _state->getPrice(daysRented);
    }

    int getRenterPoints(int daysRented) const {
        return _state->getRenterPoints(daysRented);
    }

private:
    std::string _title;
    int _priceCode;
    MovieState* _state;
};

inline Movie::
Movie( const std::string& title, MovieState* state)
        : _title( title )
        , _state(state)
{}

inline std::string Movie::
getTitle() const { return _title; }

Movie::~Movie() {
    delete _state;
}

#endif // MOVIE_H