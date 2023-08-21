#include "Lifeguard.h"
#include "library.cpp"
#include "clockthread.cpp"

using namespace std;

int main()
{

    // Create a TimeData structure to hold the time values
    TimeData timeData;

    // Create a mutex to synchronize access to the TimeData structure
    std::mutex dataMutex;

    // Starts the clock thread and detaches it so that the clock runs seperately in the background
    thread clockThread(updateClock, std::ref(timeData), std::ref(dataMutex));
    clockThread.detach();

    vector<Lifeguard> rotation;

    bool rotationStarted = false;

    while (true)
    {

        string input = opt();

        if (input == "list")
        {
            list(rotation);
        } else if (input == "add")
        {
            add(rotation, timeData, rotationStarted);
        } else if (input == "remove")
        {
            remove(rotation);
        } else if (input == "swap")
        {
            swap(rotation);
        } else if (input == "end")
        {
            return 0;
        }
    }
}