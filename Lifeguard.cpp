#include "Lifeguard.h"

// Constructor for Lifeguard class
Lifeguard::Lifeguard(string num, int hour, int min, int guard)
{
    name = num; // Initialize the lifeguard's name
    cout << endl;

    setShiftTime(hour, min); // Set the lifeguard's shift time
}

// Destructor for Lifeguard class
Lifeguard::~Lifeguard()
{
    // Destructor doesn't need additional actions for this class
}

// Setter for lifeguard's name
void Lifeguard::setName(string num)
{
    this->name = num; // Update the lifeguard's name
}

// Getter for lifeguard's name
string Lifeguard::getName() const
{
    return name; // Return the lifeguard's name
}

// Set lifeguard's shift time
void Lifeguard::setShiftTime(int hours, int minutes)
{
    timeHour = hours; // Set the lifeguard's shift hour
    timeMin = minutes; // Set the lifeguard's shift minute
}

// Getter for lifeguard's shift hour
int Lifeguard::getHour() const
{
    return timeHour; // Return the lifeguard's shift hour
}

// Getter for lifeguard's shift minute
int Lifeguard::getMin() const
{
    return timeMin; // Return the lifeguard's shift minute
}

// Add time to lifeguard's shift
void Lifeguard::addTime(int minutes)
{
    int totalMinutes = timeHour * 60 + timeMin; // Convert current time to total minutes
    totalMinutes += minutes; // Add the specified minutes

    timeHour = totalMinutes / 60; // Update the lifeguard's shift hour
    timeMin = totalMinutes % 60;  // Update the lifeguard's shift minute
}

// Subtract time from lifeguard's shift
void Lifeguard::subtractTime(int minutes)
{
    int totalMinutes = timeHour * 60 + timeMin; // Convert current time to total minutes
    totalMinutes -= minutes; // Subtract the specified minutes

    if (totalMinutes < 0)
    {
        totalMinutes += 24 * 60; // Add a day's worth of minutes to ensure positive value
    }

    timeHour = totalMinutes / 60; // Update the lifeguard's shift hour
    timeMin = totalMinutes % 60;  // Update the lifeguard's shift minute
}