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

    // Starts the clock thread and detaches it so that the clock runs separately in the background
    thread clockThread(updateClock, std::ref(timeData), std::ref(dataMutex));
    clockThread.detach();

    // Create a vector to hold lifeguards in rotation
    vector<Lifeguard> rotation;

    // Flag to track if rotation has started
    bool rotationStarted = false;

    while (true)
    {
        // Get user input for operation
        string input = opt();

        if (input == "list")
        {
            // Call the function to list lifeguards in rotation
            list(rotation);
        }
        else if (input == "add")
        {
            // Call the function to add a lifeguard to rotation
            add(rotation, timeData, rotationStarted);
        }
        else if (input == "remove")
        {
            // Call the function to remove a lifeguard from rotation
            remove(rotation);
        }
        else if (input == "swap")
        {
            // Call the function to swap lifeguards in rotation
            swap(rotation);
        }
        else if (input == "end")
        {
            // Exit the program
            return 0;
        }
    }

    // The loop is infinite, so this point is never reached.
}