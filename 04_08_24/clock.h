#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <sstream>
#include <iomanip>

class clockType
{
public:
    clockType(int h, int m, int s);

    void setTime(int, int, int);
    void getTime(int &, int &, int &) const;
    std::string to_string() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &) const;

private:
    int hr;
    int min;
    int sec;
};

#endif