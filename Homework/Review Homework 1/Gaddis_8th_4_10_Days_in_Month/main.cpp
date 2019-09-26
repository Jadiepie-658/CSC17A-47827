//Jade Braun

#include<iostream>
#include<string>

using namespace std;

int main() {
    int month, year;
    cout << "Enter a month using numbers 1 - 12" << endl;
    cin >> month;

    cout << endl;

    cout << "Enter a year " << endl;
    cin >> year;



    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            cout << "This month has 29 days";
        } else {
            cout << "This month has 28 days";
        }
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        cout << "This month has 31 days";
    } else {
        cout << "This month has 30 days";

    }
    return 0;
}