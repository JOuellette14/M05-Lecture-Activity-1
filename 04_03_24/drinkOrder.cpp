#include "drinkOrder.h"

drinkOrder::drinkOrder()
{
    numDrinks = 0;
    drinks = new drink *[numDrinks + 1];
    drinks[0] = nullptr;
}

void drinkOrder::addDrink(drink &d)
{
    drinks[numDrinks] = new drink(d);
    drink **dcpy;
    dcpy = drinks;
    drinks = new drink *[++numDrinks + 1];
    for (int i = 0; i < numDrinks; i++)
    {
        drinks[i] = dcpy[i];
    }
    delete[] dcpy;
}

void drinkOrder::addDrinks(drink d[], int numD)
{
    /* for (int i = 0; i < numD; i++)
    {
        drinks[i] = d[i];
    }
    numDrinks = numD; */
}

drinkOrder::drinkOrder(const drinkOrder &otherOrder)
{
    this->numDrinks = otherOrder.numDrinks;
    this->drinks = new drink *[this->numDrinks + 1];
    for (int i = 0; i < numDrinks; i++)
    {
        this->drinks[i] = new drink(*(otherOrder.drinks[i]));
    }
}

drinkOrder::~drinkOrder()
{
    for (int i = 0; i < numDrinks; i++)
    {
        delete drinks[i];
    }
    delete[] drinks;
}

std::string drinkOrder::tostring() const
{
    std::ostringstream out;
    out << "This order has " << numDrinks << " drinks:" << std::endl;
    for (int i = 0; i < numDrinks; i++)
    {
        out << drinks[i]->tostring() << std::endl;
        out << std::setw(25) << std::setfill('-') << std::endl;
    }
    return out.str();
}
