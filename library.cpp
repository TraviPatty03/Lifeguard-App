#include "Lifeguard.h"
#include "clockthread.cpp"

#ifndef LIFEGUARD_APP_LIBRARY_CPP
#define LIFEGUARD_APP_LIBRARY_CPP

void printtime();

string opt();

void list(vector<Lifeguard> &rot);

void add(vector<Lifeguard> &rot, TimeData timeData);

void remove(vector<Lifeguard> &rot);

void updateList(vector<Lifeguard> &rot);

void sortList(vector<Lifeguard> &rot);

void SwapKnownLifeguards(vector<Lifeguard> &rot, int num1, int num2);

void ending();

void swap(vector<Lifeguard> &rot);

// Prints the time
// currently not in use because i don't have a good place to put it yet
void printtime() {
    auto now = chrono::system_clock::now();

    time_t time = chrono::system_clock::to_time_t(now);

    // Display the current time directly without formatting
    cout << ctime(&time);
}


// Function to print the choices as well as grab their choice
string opt() {
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
void list(vector<Lifeguard> &rot) {
    cout << endl;
    for (int i = 0; i < rot.size(); i++) {
        cout << setw(2) << rot[i].printLifeguard() << endl;
    }
    ending();
}


// Adds lifeguard to the rotation
// Set's when they go on as well
void add(vector<Lifeguard> &rot, TimeData timeData) {
    string name;

    cout << "What is the name of the lifeguard?" << endl;
    cin >> name;

    // Check for duplicate names
    for (Lifeguard guard: rot) {
        if (guard.getName() == name) {
            cout << "Error: Duplicate name. Lifeguard with this name already exists." << endl;
            ending();
            return; // Exit the function
        }
    }

    Lifeguard temp(name, timeData.hour, timeData.minute);

    rot.push_back(temp);

    updateList(rot);

    cout << endl;

    cout << "Added Lifeguard to the List" << endl;
    ending();
}


// Removes lifeguard from the rotation
void remove(vector<Lifeguard> &rot) {
    string name;
    cout << "Who needs to be removed?" << endl;
    cin >> name;

    auto it = rot.begin();
    while (it != rot.end()) {
        if (it->getName() == name) {
            it = rot.erase(it);
            cout << "Instance removed successfully." << endl;
            break; // Important: Exit the loop after erasing the element
        } else {
            ++it;
        }
    }

    // Subtract 30 from all instances that occurred after the removed instance
    for (; it != rot.end(); ++it) {
        it->subtractTime(30); // method in Lifeguard class to subtract time
    }

    cout << endl;
    ending();
}

// Swaps Two guards based on the names
void swap(vector<Lifeguard> &rot) {
    string name1, name2;
    int num1, num2;

    cout << "Who are we swapping?" << endl;
    cin >> name1;

    cout << "Who is the other Lifeguard?" << endl;
    cin >> name2;

    for (int i = 0; i < rot.size(); i++) {
        if (rot[i].getName() == name1) {
            num1 = i;
        }
        if (rot[i].getName() == name2) {
            num2 = i;
        }
    }

    Lifeguard temp(rot[num1]);
    rot[num1] = rot[num2];
    rot[num2] = temp;

    cout << "Swap Sucessfull" << endl;
    ending();
}

// Updates everything
void updateList(vector<Lifeguard> &rot) {
    int numofguards = rot.size();

    if (numofguards > 1) {
        int adjustmentTime = 0;

        if (numofguards == 3) {
            adjustmentTime = 20;
        } else if (numofguards >= 4) {
            adjustmentTime = 15;
        } else {
            adjustmentTime = 30;
        }

        for (Lifeguard &guard: rot) {
            guard.addTime(adjustmentTime);
        }

        sortList(rot);
    }
}

void sortList(vector<Lifeguard> &rot) {
    int n = rot.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (rot[j].getHour() < rot[minIndex].getHour() ||
                (rot[j].getHour() == rot[minIndex].getHour() && rot[j].getMin() < rot[minIndex].getMin())) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            SwapKnownLifeguards(rot, i, minIndex);
        }
    }
}

void SwapKnownLifeguards(vector<Lifeguard> &rot, int num1, int num2) {
    Lifeguard temp(rot[num1]);
    rot[num1] = rot[num2];
    rot[num2] = temp;
}

// Use _getch() from conio.h to hold program till you press enter
void ending() {
    cout << "**Press Enter to Continue**";
    _getch();
    cout << endl;
}

#endif //LIFEGUARD_APP_LIBRARY_CPP