#include "Lifeguard.h"
#include "clockthread.cpp"

#ifndef LIFEGUARD_APP_LIBRARY_CPP
#define LIFEGUARD_APP_LIBRARY_CPP

string opt();

void list(vector<Lifeguard> &rot);

void add(vector<Lifeguard> &rot, TimeData timeData);

void AddByName(vector<Lifeguard>& rot, TimeData timeData, string name);

void remove(vector<Lifeguard> &rot, int numofguards = 2);

void UpdateList(vector<Lifeguard>& rot, TimeData timeData, int numofguards = 1);

void ending();

void swap(vector<Lifeguard> &rot);

// Function to print the choices as well as grab their choice
string opt()
{
    string input;

    // Display the available choices
    cout << "What do you want to do?\n"
            "  List rotation (list)  "
            "  End Program (end)\n"
            "  Update List (update)  "
            "  Swap Lifeguards (swap)\n"
            "  Add Lifeguard (add)  "
            "  Remove lifeguard (remove)\n";

    // Get the user's choice
    cin >> input;

    return input;
}


// Lists out the entire rotation
// Showing the name of the lifeguard and when they get on
void list(vector<Lifeguard> &rot)
{
    cout << endl;

    // Iterate through the rotation and display lifeguard information
    for (Lifeguard & i : rot)
    {
        // Display the lifeguard's name and their shift start time
        cout << i.getName() << " - " << setw(2) << setfill('0') << i.getHour() << ":" << setw(2)
             << setfill('0') << i.getMin() << endl;
    }

    // Call the ending function
    ending();
}

// Add a new lifeguard to the rotation
void add(vector<Lifeguard>& rot, TimeData timeData) {
    string name;

    // Prompt user for lifeguard's name
    cout << "What is the name of the lifeguard?" << endl;
    cin >> name;

    // Check for duplicate name
    for (const Lifeguard& guard : rot) {
        if (guard.getName() == name) {
            cout << "Error: Duplicate name. Lifeguard with this name already exists." << endl;
            ending();
            return;
        }
    }

    // Calculate rounded minute and hour
    int roundedMinute = (timeData.minute < 15) ? 0 : (timeData.minute < 45) ? 30 : 0;
    int roundedHour = (timeData.minute >= 45) ? timeData.hour + 1 : timeData.hour;

    // Create a new lifeguard instance and add it to the rotation
    Lifeguard temp(name, roundedHour, roundedMinute);
    rot.push_back(temp);

    // If there's more than one lifeguard, adjust their times
    if (rot.size() > 1) {
        for (int i = 0; i < rot.size() - 1; i++) {
            rot[rot.size() - 1].addTime(30);
        }
    }

    // Display success message
    cout << "Added Lifeguard to the List" << endl;

    // Call the ending function
    ending();
}

// Add a new lifeguard to the rotation
void AddByName(vector<Lifeguard>& rot, TimeData timeData, string name)
{

    // Check for duplicate name
    for (const Lifeguard &guard: rot)
    {
        if (guard.getName() == name)
        {
            cout << "Error: Duplicate name. Lifeguard with this name already exists." << endl;
            ending();
            return;
        }
    }

    // Calculate rounded minute and hour
    int roundedMinute = (timeData.minute < 15) ? 0 : (timeData.minute < 45) ? 30 : 0;
    int roundedHour = (timeData.minute >= 45) ? timeData.hour + 1 : timeData.hour;

    // Create a new lifeguard instance and add it to the rotation
    Lifeguard temp(name, roundedHour, roundedMinute);
    rot.push_back(temp);

    // If there's more than one lifeguard, adjust their times
    if (rot.size() > 1)
    {
        for (int i = 0; i < rot.size() - 1; i++)
        {
            rot[rot.size() - 1].addTime(30);
        }
    }
}

// Removes lifeguard from the rotation
void remove(vector<Lifeguard>& rot, int numofguards) {
    string name;

    // Prompt user for lifeguard's name to remove
    cout << "Who needs to be removed?" << endl;
    cin >> name;

    // Iterate through the rotation to find and remove the lifeguard
    auto it = rot.begin();
    while (it != rot.end()) {
        if (it->getName() == name) {
            it = rot.erase(it);  // Erase the lifeguard from the rotation
            cout << "Instance removed successfully." << endl;
            break; // Important: Exit the loop after erasing the element
        } else {
            ++it;
        }
    }

    // Determine the time to subtract based on the number of guards
    int timeToSubtract = 0;
    if (numofguards <= 2) {
        timeToSubtract = 30;
    } else if (numofguards == 3) {
        timeToSubtract = 20;
    } else if (numofguards >= 4) {
        timeToSubtract = 15;
    }

    // Iterate through the remaining lifeguards to subtract time
    for (; it != rot.end(); ++it) {
        it->subtractTime(timeToSubtract); // method in Lifeguard class to subtract time
    }

    cout << endl;

    // Call the ending function
    ending();
}

void UpdateList(vector<Lifeguard>& rot, TimeData timeData, int numofguards) {
    if (rot.empty()) {
        cout << "Rotation is empty." << endl;
        return;
    }

    Lifeguard removedGuard = rot.front(); // Store the first lifeguard
    rot.erase(rot.begin()); // Remove the first lifeguard from the rotation

    // Determine the time to subtract based on the number of guards
    int timeToSubtract = 0;
    if (numofguards <= 2) {
        timeToSubtract = 30;
    } else if (numofguards == 3) {
        timeToSubtract = 20;
    } else if (numofguards >= 4) {
        timeToSubtract = 15;
    }

    // Subtract time from the remaining lifeguards
    for (Lifeguard &guard : rot) {
        guard.subtractTime(timeToSubtract); // Subtract time from each remaining guard
    }


    AddByName(rot, timeData, removedGuard.getName());

    cout << "Updated the rotation." << endl;

    ending();
}

// Swaps Two guards based on the names
void swap(vector<Lifeguard>& rot) {
    string name1, name2;

    cout << "Who are we swapping?" << endl;
    cin >> name1;

    cout << "Who is the other Lifeguard?" << endl;
    cin >> name2;

    int index1 = -1;
    int index2 = -1;

    // Find the indices of the lifeguards to be swapped
    for (int i = 0; i < rot.size(); i++) {
        if ((index1 != -1) && (index2 != -1)) {
            break; // Both indices found, no need to continue searching
        }

        if (rot[i].getName() == name1 && index1 == -1) {
            index1 = i;
        }
        if (rot[i].getName() == name2 && index2 == -1) {
            index2 = i;
        }
    }

    // If both lifeguards are found, swap their names
    if (index1 != -1 && index2 != -1) {
        string tempName = rot[index1].getName();
        rot[index1].setName(rot[index2].getName());
        rot[index2].setName(tempName);

        cout << "Guards Swapped Successfully" << endl;
        ending();
    } else {
        cout << "One or both lifeguards not found." << endl;
    }
}

// Use _getch() from conio.h to hold program till you press enter
void ending()
{
    cout << "**Press Enter to Continue**";
    _getch();
    cout << endl;
}

#endif //LIFEGUARD_APP_LIBRARY_CPP