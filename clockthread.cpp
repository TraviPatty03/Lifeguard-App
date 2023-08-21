#include <ctime>
#include <thread> // For thread
#include <atomic> // For atomic
#include <mutex>  // For mutex

using namespace std;

#ifndef LIFEGUARD_APP_CLOCKTHREAD_CPP
#define LIFEGUARD_APP_CLOCKTHREAD_CPP

// Structure to hold time data for synchronization between threads
struct TimeData {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Function to update the time data continuously in a separate thread
void updateClock(TimeData &timeData, std::mutex &dataMutex)
{
    while (true)
    {
        // Get the current system time
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        // Convert to local time
        tm localTime = *localtime(&currentTime);

        // Lock the mutex before updating the time values to avoid conflicts
        lock_guard<mutex> lock(dataMutex);

        // Update the time values in the shared TimeData structure
        timeData.year = localTime.tm_year + 1900;
        timeData.month = localTime.tm_mon + 1;
        timeData.day = localTime.tm_mday;
        timeData.hour = localTime.tm_hour;
        timeData.minute = localTime.tm_min;
        timeData.second = localTime.tm_sec;

        // Sleep for one second before updating the time data again
        this_thread::sleep_for(chrono::seconds(1));
    }
}

#endif // LIFEGUARD_APP_CLOCKTHREAD_CPP
