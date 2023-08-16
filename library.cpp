#include "Lifeguard.h"

struct TimeData {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Function to update the time data continuously
void updateClock(TimeData &timeData, std::mutex &dataMutex) {
    while (true) {
        // Get the current system time
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        // Convert to local time
        std::tm localTime = *std::localtime(&currentTime);

        // Lock the mutex before updating the time values
        std::lock_guard<std::mutex> lock(dataMutex);

        // Update the time values in the shared TimeData structure
        timeData.year = localTime.tm_year + 1900;
        timeData.month = localTime.tm_mon + 1;
        timeData.day = localTime.tm_mday;
        timeData.hour = localTime.tm_hour;
        timeData.minute = localTime.tm_min;
        timeData.second = localTime.tm_sec;

        // Sleep for one second before updating the time data again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void printtime() {
    auto now = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(now);
    // Display the current time directly without formatting
    std::cout << std::ctime(&time);
}

string opt() {
    printtime();
    string input;
    cout << "What do you want to do?\nList rotation\nAdd Lifeguard\nRemove lifeguard" << endl;
    cin >> input;

    return input;
}

void list(vector<Lifeguard> &rot) {
    for (int i = 0; i < rot.size(); i++) {
        cout << rot[i].printLifeguard() << endl;
    }
    cout << endl;
}

void add(vector<Lifeguard> &rot, TimeData timeData) {

    if (rot.size() == 0) {
        string name;

        cout << "What is the name of the lifeguard?" << endl;
        cin >> name;
        Lifeguard temp(name, timeData.hour, timeData.minute);

        rot.push_back(temp);

        cout << endl;
    } else {
        string name;
        int hour;
        int minutes;

        cout << "What is the name of the lifeguard?" << endl;
        cin >> name;
        if (timeData.hour >= 12) {
            hour = rot[(rot.size() - 1)].getHour() + 12;
        }
        minutes = rot[(rot.size() - 1)].getMin();
        minutes += 30;
        Lifeguard temp(name, hour, minutes);

        rot.push_back(temp);

        cout << endl;
    }
}

void remove(vector<Lifeguard> &rot) {
    string name;
    cout << "Who needs to be removed?" << endl;
    cin >> name;

    for (auto it = rot.begin(); it != rot.end(); ++it) {
        if (it->getName() == name) {
            rot.erase(it);
            std::cout << "Instance removed successfully." << std::endl;
            break; // Important: Exit the loop after erasing the element
        }
    }
    cout << endl;
}