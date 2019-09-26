//Jade Braun

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main() {
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim",
        "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
        "Looney, Joe", "Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike Gordon", "Holland, Beth"};

    return 0;

    string sort;
    int i, j;

    
    for (i = 0; i < NUM_NAMES - 1; i++) {
        for (j = i + 1; j < NUM_NAMES; j++) {
            if (names[i] > names[j]) {
                sort = names[i];
                names[i] = names[j];
                names[j] = sort;
            }
        }
    }

    string last, first, full;
cout << "Enter the last name of the person you're looking for" << endl;
    cin >> last;
    cout << "Enter the first name of the person you're looking for" << endl;
    cin >> first;
    

    full = last + ", " + first;

    cout << full << endl;

    int low = 0, mid, high = NUM_NAMES - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (full < names[mid]) {
            high = mid - 1;
        } else {
            if (full > names[mid]) {
                low = mid + 1;
            } else
                low = high + 1;
        }
    }
    if (full == names[mid])
        cout << "Name was found" << endl;
    else
        cout << "Name not found" << endl;
    return 0;
}

