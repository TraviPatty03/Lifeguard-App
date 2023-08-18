#include "Lifeguard.h"

Lifeguard::Lifeguard() {}


Lifeguard::Lifeguard(string num, int hour, int min, int guard) {

    name = num;
    cout << endl;

    setTime(hour, min, guard);
}

Lifeguard::Lifeguard(Lifeguard *temp) {
    name = temp->getName();
    timeHour = temp->getHour();
    timeMin = temp->getMin();
}

Lifeguard::~Lifeguard() {}

void Lifeguard::setName(string num) {
    this->name = num;
}

string Lifeguard::getName() {
    return name;
}

void Lifeguard::setTime(int hour, int min, int numofguards) {
    timeHour = hour;
    int tempMin = min;

    if (tempMin >= 60) {
        timeHour += tempMin / 60;
        tempMin %= 60;
    }

    switch (numofguards) {
        case 1:
        case 2:
            if (tempMin < 15) {
                timeMin = 0;
            } else if (tempMin < 45) {
                timeMin = 30;
            } else {
                timeHour++;
                timeMin = 0;
            }
            break;
        ;;
        case 3:
            if (tempMin < 10 || tempMin >= 50) {
                timeMin = 0;
            } else if (tempMin < 30) {
                timeMin = 20;
            } else {
                timeMin = 40;
            }
            break;
        ;;
        case 4:
        case 5:
        case 6:
            if (tempMin < 7 || tempMin >= 52) {
                timeMin = 0;
            } else if (tempMin < 22) {
                timeMin = 15;
            } else if (tempMin < 37) {
                timeMin = 30;
            } else {
                timeMin = 45;
            }
            break;
        ;;
    }
}

//Adds time for every guard, then updates the hours and min just in case
void Lifeguard::addTime(int min) {
    timeMin += min;
    setTime(timeHour, timeMin);
}

void Lifeguard::subtractTime(int min) {
    timeMin -= min;
    setTime(timeHour, timeMin);
}


//Named it "getTime" but it really just puts the time into a nice format for printing
string Lifeguard::getTime() {
    string temp;

    temp += to_string(timeHour);
    temp += ":";
    temp += to_string(timeMin);

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