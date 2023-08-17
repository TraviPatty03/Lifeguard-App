#include "Lifeguard.h"
#include "clockthread.cpp"

#ifndef LIFEGUARD_APP_LIBRARY_CPP
#define LIFEGUARD_APP_LIBRARY_CPP

void printtime() {
    auto now = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(now);
    // Display the current time directly without formatting
    std::cout << std::ctime(&time);
}

string opt() {
    string input;
    cout << "What do you want to do?\n"
            "  List rotation (list)\n"
            "  Add Lifeguard (add)\n"
            "  Remove lifeguard (remove)\n"
            "  Swap Lifeguards (swap)\n";
    cin >> input;

    return input;
}

//void list(vector<Lifeguard> &rot) {
//    printtime();
//    cout << endl;
//    for (int i = 0; i < rot.size(); i++) {
//        cout << rot[i].printLifeguard() << endl;
//    }
//}

void list(vector<Lifeguard> &rot){
    char choice;

    while (true) {
        system("cls"); // Use "cls" instead of "clear" on Windows

        // Print your constantly updating list here
        printtime();
        for (int i = 0; i < rot.size(); i++) {
            cout << rot[i].printLifeguard() << endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));

        // Check for user input to exit
        if (std::cin.peek() != '\n') {
            std::cout << "Press 'x' to exit or any other key to continue: ";
            std::cin >> choice;
            if (choice == 'x' || choice == 'X') {
                break; // Exit the loop
            }
        }
    }
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

void swap(vector<Lifeguard> &rot){
    string name1, name2;
    int num1, num2;

    cout << "Who are we swapping?" << endl;
    cin >> name1;

    cout << "Who is the other Lifeguard?" << endl;
    cin >> name2;

    for(int i = 0; i < rot.size(); i++){
        if(rot[i].getName() == name1){
            num1 = i;
        }
        if(rot[i].getName() == name2){
            num2 = i;
        }
    }

    Lifeguard temp(rot[num1]);
    rot[num1] = rot[num2];
    rot[num2] = temp;
}

#endif //LIFEGUARD_APP_LIBRARY_CPP