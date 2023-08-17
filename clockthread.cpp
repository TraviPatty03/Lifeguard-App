#include <chrono>
#include <ctime>
#include <thread> // For thread
#include <atomic> // For atomic
#include <mutex>  // For mutex

#ifndef LIFEGUARD_APP_CLOCKTHREAD_CPP
#define LIFEGUARD_APP_CLOCKTHREAD_CPP

//Structure so i can use the TimeData in other threads
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

#endif //LIFEGUARD_APP_CLOCKTHREAD_CPP
