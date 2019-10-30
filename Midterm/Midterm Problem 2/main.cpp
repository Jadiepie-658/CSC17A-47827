#include<iostream>
#include<iomanip>
using namespace std;

struct Gross {
    char company[100]; //company name
    char add[100]; //address
    char name[100]; //worker name
    char boss[100]; //Authorized signature
    int work; //hours which worker worked
    float rate; //rate of hourly pay
    float total; //Total pay for the worker
};
void printCheck();

int main() {
    int emp;
    int i;
    string one[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string twenty[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    cout << "How many employees are you getting information from: ";
    cin >> emp;


    cin.ignore();
    cout << "What is the name of the company? " << endl;
    Gross *pay = new Gross[emp];
    cin.getline(pay->company, 100);

    cout << "What is the address of the company?" << endl;
    cin.getline(pay->add, 100);

    cout << "Who is signing the check?" << endl;
    cin.getline(pay->boss, 100);

    for (i = 0; i < emp; i++) //loop to get employees information
    {

        cout << "Employee #" << i + 1 << endl;
        cout << "Name: ";

        cin.getline(pay[i].name, 100);

        cout << "\nHours Worked: ";
        do {

            cin >> pay[i].work;

        } while (pay[i].work < 0);

        cout << "\nPay rate per hour: ";
        do {
            cin >> pay[i].rate;
        } while (pay[i].rate < 0);

        if (pay[i].work <= 40) {
            pay[i].total = (pay[i].rate * pay[i].work);

        }
        //if statement for the double pay
        if (pay[i].work > 40 && pay[i].work <= 50) {
            pay[i].total = (pay[i].rate * 40) + (2 * (pay[i].rate * (pay[i].work - 40)));
        }
        //if statement for the triple pay
        if (pay[i].work > 50) {
            pay[i].total = (((pay[i].rate * 40) + (pay[i].rate * 2)*(10)) + (pay[i].rate) * 3) * (pay[i].work - 50);

        }
        int thousand = pay[i].total / 1000;
        int hundred = (pay[i].total - thousand * 1000) / 100;
        int tens = ((pay[i].total - (thousand * 1000 + hundred * 100)) / 10);
        int ones = (pay[i].total - (thousand * 1000 + hundred * 100)) - tens * 10;
        int cents_tens = (pay[i].total - (thousand * 1000 + hundred * 100) - tens * 10 - ones) * 10;
        int cents_ones = (pay[i].total - (thousand * 1000 + hundred * 100) - tens * 10 - ones) * 100 - cents_tens * 10;
        cout << setprecision(2) << fixed;
        cout << "Company: " << pay ->company << endl;
        cout << "Address: " << pay->add << endl;
        cout << "Name: " << pay[i].name << endl;
        cout << "Amount: " << pay[i].total << endl;
        if(pay[i].total < 1.0)
            cout << "Zero dollars and " << twenty[cents_tens] << one[cents_ones] << " cents." << endl;
        else if(pay[i].total < 20)
            cout << one[ones] << " dollar and " << twenty[cents_tens] <<  one[cents_ones] << " cents." << endl;
        else if(pay[i].total < 100)
        {
            cout << twenty[tens] << "-" << one[ones] << " dollars and " << twenty[cents_tens] << one[cents_ones] << " cents.";
            
        }
        else if(pay[i].total < 1000)
        {
            cout << one[hundred] << " hundred and " << twenty[tens] <<  one[ones] << " dollars and " << twenty[cents_tens] <<  one[cents_ones] << " cents." << endl;
        }
        else if(pay[i].total < 10000)
        {
            cout << one[thousand] << "thousand " << one[hundred] << " hundred and " << twenty[tens] <<  one[ones] << " dollars and " << twenty[cents_tens] <<  one[cents_ones] << " cents." << endl;
        }
        cout << "Signed by: " << pay->boss << endl;
        cin.ignore();

    }



    delete[] pay;
}