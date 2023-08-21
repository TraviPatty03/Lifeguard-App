#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <conio.h>


#ifndef LIFEGUARD_APP_LIFEGUARD_H
#define LIFEGUARD_APP_LIFEGUARD_H

using namespace std;

class Lifeguard {
public:
    // Constructor with initial values
    Lifeguard(string num, int hour, int min, int guard = 2);

    // Destructor
    ~Lifeguard();

    // Setter for lifeguard's name
    void setName(string num);

    // Getter for lifeguard's name
    string getName() const;

    // Set lifeguard's shift time
    void setShiftTime(int hours, int minutes);

    // Getter for lifeguard's shift hour
    int getHour() const;

    // Getter for lifeguard's shift minute
    int getMin() const;

    // Add time to lifeguard's shift
    void addTime(int minutes);

    // Subtract time from lifeguard's shift
    void subtractTime(int minutes);

private:
    string name;    // Lifeguard's name
    int timeHour; // Lifeguard's shift hour
    int timeMin;  // Lifeguard's shift minute
};


#endif //LIFEGUARD_APP_LIFEGUARD_H
