//Jade Braun

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    const float YEN_PER_DOLLAR = 98.93;
    const float EUROS_PER_DOLLAR = .74;
    
    float dollars, yen, euros;
    
    cout << "Enter the amount in US dollars" << endl;
    cin >> dollars;
    
    yen = dollars * YEN_PER_DOLLAR;
    euros = dollars * EUROS_PER_DOLLAR;
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << dollars << " dollars is " << yen << " yen" << endl;
    cout << dollars << " dollars is " << euros << " euros" << endl;
    
    return 0;
    
}

