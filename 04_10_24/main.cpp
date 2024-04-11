#include <iostream>
#include <limits>
#include <fstream>
#include "product.h"
#include "order.h"

void resetStream();
void displayProduct(product &p);
void createDrink(product *[], int);

// like, dislike(scared of), want to know more about (unsure about)

int main()
{

    clockType c(11, 56, 1, TWELVE, PM);
    clockType c2(13, 34, 2, TWENTYFOUR);

    if (c == c2)
        std::cout << "They are the same!" << std::endl;
    int x = 7;
    int y = x++;
    if (x == y)
        std::cout << "The numbers are equal" << std::endl;
    clockType c3 = c + c2;
    clockType c4 = c + 30;
    c4 = 30 + c;
    c += 56;
    c3 = ++c4;
    clockType c5 = c4++;
    c4++;
    std::cout << c << std::endl;
    std::ofstream out;
    out.open("clocks.txt");
    out << c << std::endl;
    out << c2 << std::endl;
    out << c3 << std::endl;
    out << c4 << std::endl;

    two(c);

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void createDrink(product *products[], int index)
{
    int drinkSize;
    int drinkBase;
    int drinkTemp;
    std::string dairy;
    std::string flavor;
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
    products[index] = new drink(bases[drinkBase - 1], temps[drinkTemp - 1], sizes[drinkSize - 1], dairy, flavor);
}
