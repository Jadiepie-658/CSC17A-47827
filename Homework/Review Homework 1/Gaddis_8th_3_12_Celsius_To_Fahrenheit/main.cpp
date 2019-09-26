//Jade Braun

#include<iostream>

using namespace std;

int main() {
    float F, C;

    cout << "Please input a temperature" << endl;
    cin >> C;
    
    F = ((9 * C) / 5) + 32;

    cout << "The temperature in Celsius " << C << " is " << F << " in Fahrenheit" << endl;

    return 0;
}