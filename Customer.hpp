/*
 * Authors: Robin Demarta, Loïc Dessaules & Vitor Vaz Afonso
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>

#include "Rental.hpp"


class Customer {
public:
    Customer();
    explicit Customer( const std::string& name );

    void addRental(Rental* arg );
    std::string getName() const;
    std::string statement();

private:
    std::string _name;
    std::vector<Rental*> _rentals;
};

inline Customer::
Customer() {}

inline Customer::
Customer( const std::string& name )
        : _name( name ) {}

inline void Customer::
addRental(Rental* arg) { _rentals.push_back(arg); }

inline std::string Customer::
getName() const { return _name; }

#endif // CUSTOMER_H