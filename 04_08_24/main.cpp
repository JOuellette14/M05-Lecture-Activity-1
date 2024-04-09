#include <iostream>
#include <limits>
#include "product.h"
#include "order.h"

void resetStream();
void displayProduct(product &p);

int main()
{
    std::string prodNum = "1234a";
    std::string descript = "My product";
    product p(prodNum, 3.99, descript);
    product r(prodNum + "b");
    product s(prodNum + "s", 8.99, "This product", 12, 20, 3);
    std::cout << p.tostring() << std::endl;
    drink d(COFFEE, HOT, LARGE, "Skim Milk", "Brown Sugar");
    std::cout << d.tostring() << std::endl;
    drink myDrink(TEA, ICE, SMALL, "none", "none", "Small Iced Tea", "tea1234");
    iceCream favIceCream;
    displayProduct(p);
    displayProduct(r);
    displayProduct(s);
    displayProduct(d);
    displayProduct(favIceCream);
    p = d;
    std::cout << p.tostring() << std::endl;
    product *ptr;
    ptr = new drink(d);
    std::cout << ptr->tostring() << std::endl;
    order myOrder;
    myOrder.addProduct(p);
    myOrder.addProduct(r);
    myOrder.addProduct(s);
    myOrder.addProduct(d);
    myOrder.addProduct(*ptr);

    for (int i = 0; i < 10; i++)
    {
        product scope(std::to_string(i) + "b");
        myOrder.addProduct(scope);
        std::cout << myOrder.tostring() << std::endl;
    }

    std::cout << myOrder.tostring() << std::endl;
    delete ptr;

    std::cout << myOrder.tostring() << std::endl;
    /* int drinkSize;
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
    drink customerDrink(bases[drinkBase - 1], temps[drinkTemp - 1], sizes[drinkSize - 1], dairy, flavor);
    std::cout << customerDrink.tostring() << std::endl; */
    /*     Please choose the drink size:
1: Small
2: Medium
3: Large
2
Please choose the drink base:
1: Coffee
2: Tea
3: Cream
1
Please choose the drink temperature:
1: Hot
2: Iced
3: Blended
2
Please enter a flavor for your drink: Raspberry
What kind of dairy would you like? Skim Milk
The customer drink:
Size: Medium
Base: Coffee
Temperature: Iced
Flavor: Raspberry
Dairy: Skim Milk
Price: $7.50
Would you like to change the drink? Please choose from the menu.
1. Change Size
2. Change Base
3. Change Temperature
4. Change Dairy
5. Change Flavor
6. No Changes
4
What kind of dairy would you like? Oat Milk
Would you like to change the drink? Please choose from the menu.
1. Change Size
2. Change Base
3. Change Temperature
4. Change Dairy
5. Change Flavor
6. No Changes
6
Size: Medium
Base: Coffee
Temperature: Iced
Flavor: Raspberry
Dairy: Oat Milk
Price: $8.75 */

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayProduct(product &p)
{
    std::cout << p.tostring() << std::endl;
}
