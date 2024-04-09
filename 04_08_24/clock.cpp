#include "clock.h"

void clockType::setTime(int h, int m, int s)
{
    if (h >= 0 && h <= 23)
    {
        hr = h;
    }
    else
    {
        hr = 0;
    }
    if (m >= 0 && m <= 59)
    {
        min = m;
    }
    else
    {
        min = 0;
    }
    if (s >= 0 && s <= 59)
    {
        sec = s;
    }
    else
    {
        sec = 0;
    }
}

void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

std::string clockType::to_string() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    return out.str();
}

clockType::clockType(int h, int m, int s)
{
    setTime(h, m, s);
}

void clockType::incrementSeconds()
{
    if (++sec >= 60)
    {
        sec = sec % 60;
        incrementMinutes();
    }
}
void clockType::incrementMinutes()
{
    if (++min >= 60)
    {
        min = min % 60;
        incrementHours();
    }
}
void clockType::incrementHours()
{
    hr = ++hr % 24;
}
bool clockType::equalTime(const clockType &otherClock) const
{
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
}