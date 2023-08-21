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
    // Contructors
    Lifeguard(string num, int hour, int min, int guard = 2);

    // Deconstructor
    ~Lifeguard();

    // Getter and Setters
    void setName(string num);

    string getName() const;

    void setShiftTime(int hours, int minutes);

    int getHour() const;

    int getMin() const;

    void addTime(int minutes);

    void subtractTime(int minutes);

private:
    string name;
    int timeHour{};
    int timeMin{};
};


#endif //LIFEGUARD_APP_LIFEGUARD_H
