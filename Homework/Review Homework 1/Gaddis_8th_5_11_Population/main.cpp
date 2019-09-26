//Jade Braun

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int startPop = 0;
    float percent = 0.0;
   long int days = 0;
    cout << "What is the starting population of organisms" << endl;
    cin >> startPop;

    cout << "What is their average daily population increase as a percent" << endl;
    cin >> percent;

    cout << "How many days will the organisms reproduce for in this study" << endl;
    cin >> days;

    while (startPop < 2) {
        cout << "The starting number of organisms must be at least 2." << endl;
        cout << "What is the starting population of organisms" << endl;
        cin >> startPop;
    }

    while (percent < 0) {
        cout << "The average daily population increase needs to be a positive number" << endl;
        cout << "What is their average daily population increase as a percent" << endl;
        cin >> percent;
    }

    while (days < 1) {
        cout << "The amount of days the organisms multiply must be greater than 1" << endl;
        cout << "How many days will the organisms reproduce for in this study" << endl;
        cin >> days;
    }

    for (int i = 0; i != days; i++) {
        startPop = startPop + (startPop * percent);
        cout << "On day " << i + 1 << " the population was " << setprecision(0) << fixed << startPop << "." << endl;
    }
    return 0;

}