//
// Created by robin on 11.06.20.
//

#ifndef GEN_CPP_REFACTORING_MOVIESTATE_HPP
#define GEN_CPP_REFACTORING_MOVIESTATE_HPP


class MovieState {
public:
    virtual double getPrice(int daysRented) = 0;
    virtual int getRenterPoints(int daysRented) = 0;
    virtual ~MovieState() {}
};

#endif //GEN_CPP_REFACTORING_MOVIESTATE_HPP
