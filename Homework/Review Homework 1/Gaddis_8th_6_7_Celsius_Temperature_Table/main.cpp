//Jade Braun

#include<iostream>
#include<iomanip>
using namespace std;
float CelsiusToFahr(float);

int main() {
    float celsius, fahrenheit = 0;
    int count = 20;


    cout << setprecision(2) << fixed << showpoint;



    for (int i = 1; i <= count; i++) {
        cout << "Enter a temperature to be converted from Fahrenheit to Celsius" << endl;
        cin >> fahrenheit;
        celsius = CelsiusToFahr(fahrenheit);

        cout << setw(20) << "Fahrenheit" << setw(20) << "Celsius" << endl;
        cout << setw(20) << fahrenheit << setw(20) << celsius << endl;

    }

    return 0;
}

float CelsiusToFahr(float F) {
    float C;
    C = 5 * (F - 32) / 9;

    return C;
}