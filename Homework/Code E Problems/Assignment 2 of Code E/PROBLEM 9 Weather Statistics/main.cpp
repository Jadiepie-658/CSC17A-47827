#include<iostream>
#include<string>
#include<cmath>
#include <iomanip>
#include<cstdlib>

using namespace std;

struct Weather {
    string month, monthTemp;
    float rain, total;
    int highTemp, lowTemp, avg, bothTemp;
    
  
};

void weathDat(Weather [], int);
void avg(Weather [], int);
void both(Weather [], int);
void print(Weather [], int);

int main() {
    int size = 10;
    Weather info[size];
    float average;

    weathDat(info, size);

    avg(info, size);

    both(info, size);

    print(info, size);

    return 0;

}

void weathDat(Weather rainy[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> rainy[i].month; //input the month
        cin >> rainy[i].rain;


        do {
            cin >> rainy[i].lowTemp;

        } while (rainy[i].lowTemp < -100 || rainy[i].lowTemp > 140);

        do {
            cin >> rainy[i].highTemp;
        } while (rainy[i].highTemp < -100 || rainy[i].highTemp > 140);
    }

}

void avg(Weather rainy[], int size)
{
    float aveg = 0;
    for(int i = 0; i < size; i++)
    {
        aveg = aveg + rainy[i].rain;
        
    }
    rainy[0].total = (aveg / size) + .7;
    
}

void both(Weather rainy[], int size)
{
    int high = rainy[0].highTemp;
    int low = rainy[0].lowTemp;
    int count;
    
    for(int i = 0; i < size; i++)
    {
        if(rainy[i].lowTemp < low)
        {
            low = rainy[i].lowTemp;
            count = i;
        }
    }
    rainy[0].monthTemp = rainy[count].month;
    rainy[0].bothTemp = low;
    
    for(int i = 0; i < size; i++)
    {
        if(high < rainy[i].highTemp)
        {
            high = rainy[i].highTemp;
            rainy[1].monthTemp = rainy[i].month;
        }
    }
    
    rainy[1].bothTemp = high;
}

void print(Weather rainy[], int size)
{
  cout << showpoint << fixed << setprecision(1);
    cout << "Average Rainfall " << rainy[0].total << " inches/month" << endl
     << "Lowest  Temperature " << rainy[0].monthTemp << "  " << rainy[0].bothTemp << " Degrees Fahrenheit" << endl
     << "Highest Temperature " << rainy[1].monthTemp << "  " << rainy[1].bothTemp << " Degrees Fahrenheit" << endl  
     << "Average Temperature for the year "  << int(round(ceil(rainy[0].bothTemp + rainy[1].bothTemp)/2))<<" Degrees Fahrenheit" << endl;
    //the ceil function returns the smallest possible integer value which is greater than or equal to the given argument
    //requires the cmath directive
}