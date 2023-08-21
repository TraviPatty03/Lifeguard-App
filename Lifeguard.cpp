#include "Lifeguard.h"

Lifeguard::Lifeguard(string num, int hour, int min, int guard)
{

    name = num;
    cout << endl;

    setShiftTime(hour, min);
}

Lifeguard::~Lifeguard()
{}

void Lifeguard::setName(string num)
{
    this->name = num;
}

string Lifeguard::getName() const
{
    return name;
}

void Lifeguard::setShiftTime(int hours, int minutes)
{
    timeHour = hours;
    timeMin = minutes;
}

//Added these so i could easily set rotation...might get rid of this
int Lifeguard::getHour() const
{
    return timeHour;
}

int Lifeguard::getMin() const
{
    return timeMin;
}

void Lifeguard::addTime(int minutes)
{
    int totalMinutes = timeHour * 60 + timeMin;
    totalMinutes += minutes;

    timeHour = totalMinutes / 60;
    timeMin = totalMinutes % 60;
}

void Lifeguard::subtractTime(int minutes)
{
    int totalMinutes = timeHour * 60 + timeMin;
    totalMinutes -= minutes;

    if (totalMinutes < 0)
    {
        totalMinutes += 24 * 60; // Add a day's worth of minutes
    }

    timeHour = totalMinutes / 60;
    timeMin = totalMinutes % 60;
}