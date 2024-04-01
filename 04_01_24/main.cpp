#include <iostream>
#include <limits>
#include <cctype>
#include "drink.h"

void resetStream();

int main()
{
    int x = 79;
    int *p = nullptr;
    p = &x;
    std::cout << &x << std::endl;
    std::cout << *p << std::endl;

    drink *d;
    int drinkSize;
    int drinkBase;
    int drinkTemp;
    std::string dairy;
    std::string flavor;
    char yN = 'Y';
    while (yN == 'Y')
    {
        std::cout << "Please choose the drink size:" << std::endl;
        for (int i = 0; i < ENUM_NUM; i++)
        {
            std::cout << i + 1 << ": " << sizeStr[i] << std::endl;
        }
        std::cin >> drinkSize;
        while (!std::cin || drinkSize < 1 || drinkSize > 3)
        {
            if (!std::cin)
            {
                resetStream();
            }
            std::cout << "You must choose a number from the list." << std::endl;
            std::cout << "Please choose the drink size:" << std::endl;
            for (int i = 0; i < ENUM_NUM; i++)
            {
                std::cout << i + 1 << ": " << sizeStr[i] << std::endl;
            }
            std::cin >> drinkSize;
        }

        std::cout << "Please choose the drink base:" << std::endl;
        for (int i = 0; i < ENUM_NUM; i++)
        {
            std::cout << i + 1 << ": " << baseStr[i] << std::endl;
        }
        std::cin >> drinkBase;
        while (!std::cin || drinkBase < 1 || drinkBase > 3)
        {
            if (!std::cin)
            {
                resetStream();
            }
            std::cout << "You must choose a number from the list." << std::endl;
            std::cout << "Please choose the drink base:" << std::endl;
            for (int i = 0; i < ENUM_NUM; i++)
            {
                std::cout << i + 1 << ": " << baseStr[i] << std::endl;
            }
            std::cin >> drinkBase;
        }
        std::cout << "Please choose the drink temperature:" << std::endl;
        for (int i = 0; i < ENUM_NUM; i++)
        {
            std::cout << i + 1 << ": " << tempStr[i] << std::endl;
        }
        std::cin >> drinkTemp;
        while (!std::cin || drinkTemp < 1 || drinkTemp > 3)
        {
            if (!std::cin)
            {
                resetStream();
            }
            std::cout << "You must choose a number from the list." << std::endl;
            std::cout << "Please choose the drink temperature:" << std::endl;
            for (int i = 0; i < ENUM_NUM; i++)
            {
                std::cout << i + 1 << ": " << tempStr[i] << std::endl;
            }
            std::cin >> drinkTemp;
        }
        std::cout << "Please enter a flavor for your drink: ";
        std::cin >> std::ws;
        std::getline(std::cin, flavor);
        std::cout << "What kind of dairy would you like? ";
        std::cin >> std::ws;
        std::getline(std::cin, dairy);
        d = new drink(bases[drinkBase - 1], temps[drinkTemp - 1], sizes[drinkSize - 1], dairy, flavor);
        // drink d(bases[drinkBase - 1], temps[drinkTemp - 1], sizes[drinkSize - 1], dairy, flavor);
        std::cout << d->tostring() << std::endl;
        std::cout << "Would you like another drink?";
        std::cin >> yN;
        yN = toupper(yN);
        while (yN != 'Y' && yN != 'N')
        {
            std::cout << "You did not enter y or n." << std::endl;
            std::cout << "Would you like another drink?";
            std::cin >> yN;
            yN = toupper(yN);
        }
    }

    std::cout << "The final drink is:" << std::endl;
    std::cout << d->tostring() << std::endl;
    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}