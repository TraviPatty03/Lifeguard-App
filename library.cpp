#include "Lifeguard.h"
#include "clockthread.cpp"

#ifndef LIFEGUARD_APP_LIBRARY_CPP
#define LIFEGUARD_APP_LIBRARY_CPP

string opt();

void list(vector<Lifeguard> &rot);

void add(vector<Lifeguard> &rot, TimeData timeData, bool &firstLifeguardAdded);

void remove(vector<Lifeguard> &rot, int numofguards = 2);

void updateList(vector<Lifeguard> &rot, int numofguards = 2);

void ending();

void swap(vector<Lifeguard> &rot);

// Function to print the choices as well as grab their choice
string opt()
{
    string input;
    cout << "What do you want to do?\n"
            "  List rotation (list)\n"
            "  Add Lifeguard (add)\n"
            "  Remove lifeguard (remove)\n"
            "  Swap Lifeguards (swap)\n"
            "  End Program (end)\n";
    cin >> input;

    return input;
}


// Lists out the entire rotation
// Showing the name of the lifeguard and when they get on
void list(vector<Lifeguard> &rot)
{
    cout << endl;
    for (int i = 0; i < rot.size(); i++)
    {
        cout << rot[i].getName() << " - " << setw(2) << setfill('0') << rot[i].getHour() << ":" << setw(2)
             << setfill('0') << rot[i].getMin() << endl;
    }
    ending();
}

// Adds lifeguard to the rotation
// Set's when they go on as well
void add(vector<Lifeguard> &rot, TimeData timeData, bool &firstLifeguardAdded)
{

    cout << timeData.hour << " " << timeData.minute << endl;

    string name;

    cout << "What is the name of the lifeguard?" << endl;
    cin >> name;

    // Check for duplicate names
    for (Lifeguard guard: rot)
    {
        if (guard.getName() == name)
        {
            cout << "Error: Duplicate name. Lifeguard with this name already exists." << endl;
            ending();
            return; // Exit the function
        }
    }

    if (!firstLifeguardAdded)
    {
        int currentMinute = timeData.minute;
        int roundedMinute = (currentMinute < 30) ? 0 : 30;
        int shiftHour = currentMinute < 30 ? timeData.hour : timeData.hour + 1;

        Lifeguard temp(name, shiftHour, roundedMinute);
        rot.push_back(temp);

        firstLifeguardAdded = true;
    } else
    {
        Lifeguard temp(name); // Assuming constructor without shift time
        rot.push_back(temp);
        updateList(rot);
    }

    cout << endl;

    cout << "Added Lifeguard to the List" << endl;
    ending();
}

// Removes lifeguard from the rotation
void remove(vector<Lifeguard> &rot, int numofguards)
{
    string name;
    cout << "Who needs to be removed?" << endl;
    cin >> name;

    auto it = rot.begin();
    while (it != rot.end())
    {
        if (it->getName() == name)
        {
            it = rot.erase(it);
            cout << "Instance removed successfully." << endl;
            break; // Important: Exit the loop after erasing the element
        } else
        {
            ++it;
        }
    }

    int timeToSubtract = 0;
    if (numofguards <= 2)
    {
        timeToSubtract = 30;
    } else if (numofguards == 3)
    {
        timeToSubtract = 20;
    } else if (numofguards >= 4)
    {
        timeToSubtract = 15;
    }

    for (; it != rot.end(); ++it)
    {
        it->subtractTime(timeToSubtract); // method in Lifeguard class to subtract time
    }

    cout << endl;
    ending();
}

// Swaps Two guards based on the names
void swap(vector<Lifeguard> &rot)
{
    string name1, name2;

    cout << "Who are we swapping?" << endl;
    cin >> name1;

    cout << "Who is the other Lifeguard?" << endl;
    cin >> name2;

    int index1 = -1;
    int index2 = -1;

    for (int i = 0; i < rot.size(); i++)
    {
        if ((index1 != -1) && (index2 != -1))
        {
            break; // Both indices found, no need to continue searching
        }

        if (rot[i].getName() == name1 && index1 == -1)
        {
            index1 = i;
        }
        if (rot[i].getName() == name2 && index2 == -1)
        {
            index2 = i;
        }
    }

    if (index1 != -1 && index2 != -1)
    {
        string tempName = rot[index1].getName();
        rot[index1].setName(rot[index2].getName());
        rot[index2].setName(tempName);

        cout << "Names Swapped Successfully" << endl;
        ending();
    } else
    {
        cout << "One or both lifeguards not found." << endl;
    }
}

void updateList(vector<Lifeguard> &rot, int numofguards)
{
    if (numofguards > 1)
    {
        int timeIncrement = 30; // Default time increment for most guards

        if (numofguards == 3)
        {
            timeIncrement = 20; // Special time increment for the third guard
        } else if (numofguards >= 4)
        {
            timeIncrement = 15; // Special time increment for the fourth guard and beyond
        }

        int totalTimeIncrement = 0;

        for (Lifeguard &guard: rot)
        {
            guard.addTime(totalTimeIncrement); // Add the total time increment to each guard's shift time
            totalTimeIncrement += timeIncrement;
        }
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