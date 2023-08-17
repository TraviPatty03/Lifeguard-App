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
    //Contructors
    Lifeguard();

    Lifeguard(string num, int hour, int min);

    Lifeguard(Lifeguard *temp);

    //Deconstructor
    ~Lifeguard();

    //Getter and Setters
    void setName(string num);

    string getName();

    void setTime(int hour, int min);

    void addTime(int min);

    void subtractTime(int min);

    string getTime();

    int getHour();

    int getMin();

    //Prints the lifeguard for the list...This just makes it easy
    string printLifeguard();

private:
    string name;
    int timeHour{};
    int timeMin{};
};


#endif //LIFEGUARD_APP_LIFEGUARD_H
