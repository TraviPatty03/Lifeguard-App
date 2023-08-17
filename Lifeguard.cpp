#include "Lifeguard.h"

Lifeguard::Lifeguard(){}


Lifeguard::Lifeguard(string num, int hour, int min) {

    name = num;
    cout << endl;

    setTime(hour, min);
}

Lifeguard::Lifeguard(Lifeguard *temp){
    name = temp->getName();
    timeHour = temp->getHour();
    timeMin = temp->getMin();
}

Lifeguard::~Lifeguard(){}

void Lifeguard::setName(string num) {
    this->name = num;
}

string Lifeguard::getName() {
    return name;
}

void Lifeguard::setTime(int hour, int min) {
    timeHour = hour;
    int tempMin = min;

    if (tempMin >= 60) {
        timeHour++;
        tempMin -= 60;
    }
    if (tempMin < 15) {
        timeMin = 0;
    } else if (tempMin >= 15 && tempMin < 45) {
        timeMin = 30;
    } else if (tempMin >= 45) {
        timeHour++;
        timeMin = 0;
    }


    if (timeHour >= 12) {
        timeHour -= 12;
        daytime = "PM";
    } else {
        daytime = "AM";
    }
}

//Adds time for every guard, then updates the hours and min just in case
void Lifeguard::addTime(int min){
    timeMin += min;
    setTime(timeHour, timeMin);
}


//Named it "getTime" but it really just puts the time into a nice format for printing
string Lifeguard::getTime() {
    string temp;

    temp += to_string(timeHour);
    temp += ":";
    temp += to_string(timeMin);
    temp += daytime;

    return temp;
}


//Added these so i could easily set rotation...might get rid of this
int Lifeguard::getHour() {
    return timeHour;
}

int Lifeguard::getMin() {
    return timeMin;
}

string Lifeguard::printLifeguard() {
    string temp;

    temp = getName() + ": " + getTime();

    return temp;
}