//
// Created by robin on 11.06.20.
//

#ifndef GEN_CPP_REFACTORING_MOVIESTATE_HPP
#define GEN_CPP_REFACTORING_MOVIESTATE_HPP


class MovieState {
public:
    virtual double getPrice(int daysRented) = 0;
    virtual int getRenterPoints(int daysRented) = 0;
};


class MovieStateRelease : public MovieState {
public:
    double getPrice(int daysRented) override {
        return daysRented * 3;
    }

    int getRenterPoints(int daysRented) override {
        // add bonus for a two day new release rental
        return daysRented > 1 ? 1 : 0;
    }
};

class MovieStateChildren : public MovieState {
public:

    double getPrice(int daysRented) override {
        double price = 1.5;
        if (daysRented > 3 )
            price += (daysRented - 3 ) * 1.5;
        return price;
    }

    int getRenterPoints(int daysRented) override {
        return 0;
    }
};

class MovieStateRegular : public MovieState {
public:

    double getPrice(int daysRented) override {
        double price = 2;
        if (daysRented > 2)
            price += (daysRented - 2) * 1.5;
        return price;
    }

    int getRenterPoints(int daysRented) override {
        return 0;
    }
};

#endif //GEN_CPP_REFACTORING_MOVIESTATE_HPP
