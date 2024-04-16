#include <iostream>
#include <random>
#include <vector>
#include "clock.h"
#include "drink.h"

template <class t>
t magicTemplate(t val1, t val2);

int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    int x = distribution(generator);
    int y = distribution(generator);
    int z = magicTemplate<int>(x, y);

    std::uniform_real_distribution<double> distributionf(1, 50);
    double xf = distributionf(generator);
    double yf = distributionf(generator);
    double zf = magicTemplate<double>(xf, yf);

    std::cout << "z = " << z << std::endl;
    std::cout << "zf = " << zf << std::endl;
    clockType a(distribution(generator), distribution(generator), distribution(generator), TWELVE, PM);
    clockType b(distribution(generator), distribution(generator), distribution(generator), TWENTYFOUR);
    clockType c = magicTemplate<clockType>(a, b);
    std::cout << "c = " << c << std::endl;

    std::vector<clockType> clocks;
    clocks.push_back(a);
    clocks.push_back(clockType(1, 1, 1));
    for (int i = 0; i < clocks.size(); i++)
    {
        std::cout << clocks[i] << std::endl;
    }
    for (std::vector<clockType>::iterator it = clocks.begin(); it != clocks.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    for (auto it = clocks.begin(); it != clocks.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    drink d(COFFEE, HOT, SMALL, "", "");
    drink::baseToStr.at(static_cast<baseType>(47));
    drink e(COFFEE, HOT, SMALL, "", "");
    return 0;
}

template <class t>
t magicTemplate(t val1, t val2)
{
    t answer = val1 + val2;
    /*  if (val1 >= val2)
         answer = answer * val1;
     else
         answer = answer * val2; */
    return answer;
}
