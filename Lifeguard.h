#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include <chrono>
#include <ctime>
#include <thread> // For thread
#include <atomic> // For atomic
#include <mutex>  // For mutex


#ifndef UNTITLED1_LIFEGUARD_H
#define UNTITLED1_LIFEGUARD_H

using namespace std;

class Lifeguard {
public:
    Lifeguard(string num, int hour, int min);

    void setName(string num);

    string getName();

    void setTime(int hour, int min);

    string getTime();

    int getHour();

    int getMin();

    string printLifeguard();

private:
    string name;
    string daytime;
    int timeHour;
    int timeMin;
};


#endif //UNTITLED1_LIFEGUARD_H
