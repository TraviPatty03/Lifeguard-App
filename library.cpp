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


//Prints the time
//curretnly not in use because i don't have a good place to put it yet
void printtime() {
    auto now = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(now);
    // Display the current time directly without formatting
    std::cout << std::ctime(&time);
}


//Function to print the choices as well as grab their choice
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


//Lists out the entire rotation
//Showing the name of the lifeguard and when they get on
void list(vector<Lifeguard> &rot) {
    cout << endl;
    for (int i = 0; i < rot.size(); i++) {
        cout << rot[i].printLifeguard() << endl;
    }
    ending();
}


//Adds lifeguard to the rotation
//Set's when they go on as well
void add(vector<Lifeguard> &rot, TimeData timeData) {
    string name;

    cout << "What is the name of the lifeguard?" << endl;
    cin >> name;
    Lifeguard temp(name, timeData.hour, timeData.minute);

    rot.push_back(temp);

    updateList(rot);

    cout << endl;

    cout << "Added Lifeguard to the List" << endl;
    ending();
}


//Removes lifeguard from the rotation
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
    ending();
}


//Swaps Two guards based on the names
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

//For the city of lakeland the last person to arrive gets on stand first. So the person added first would be last.
void updateList(vector<Lifeguard> &rot) {

    if(rot.size() > 1) {
        for (int i = 0; i < rot.size(); i++) {
            if (rot.size() <= 1) {
                break;
            }
            rot[i].addTime(30);
        }
        sortList(rot);
    }
}

void sortList(vector<Lifeguard> &rot) {
    for (int i = 0; i < rot.size() - 1; i++) {
        for (int j = 1; j < rot.size(); j++) {
            if (rot[j].getHour() < rot[i].getHour()) {
                SwapKnownLifeguards(rot, j, i);
            } else if ((rot[j].getHour() == rot[i].getHour()) && (rot[j].getMin() < rot[i].getMin())) {
                SwapKnownLifeguards(rot, j, i);
            }
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