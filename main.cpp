#include "Lifeguard.h"
#include "library.cpp"

using namespace std;

int main() {

    // Create a TimeData structure to hold the time values
    TimeData timeData;

    // Create a mutex to synchronize access to the TimeData structure
    std::mutex dataMutex;

    thread clockThread(updateClock, std::ref(timeData), std::ref(dataMutex));
    clockThread.detach();

    vector<Lifeguard> rotation;

    while (true) {

        string input = opt();

        if (input == "list") {
            list(rotation);
        } else if (input == "add") {
            add(rotation, timeData);
        } else if (input == "remove") {
            remove(rotation);
        } else if (input == "end") {
            break;
        }
    }


    clockThread.join();

    return 0;
}