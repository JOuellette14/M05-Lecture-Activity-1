#ifndef DRINKORDER_H
#define DRINKORDER_H
#include "drink.h"
#include <string>
#include <sstream>

class drinkOrder
{

public:
    drinkOrder();
    drinkOrder(const drinkOrder &otherOrder);
    void addDrink(drink &);
    void addDrinks(drink **, int);
    ~drinkOrder();
    std::string tostring() const;

private:
    drink **drinks;
    int numDrinks;
};

#endif