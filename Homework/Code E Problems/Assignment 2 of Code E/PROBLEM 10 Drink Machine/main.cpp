#include<iostream>
#include<string>

using namespace std;

struct Machine {
    string name;
    int cost;
    int num;
};

void drinkDat(Machine [], int);
void menu(Machine [], int);

int main() {
const int size = 5;
    Machine bev[size];

    drinkDat(bev, size);

    menu(bev, size);

    return 0;
}

void drinkDat(Machine array[], int size) {
    array[0].name = "Cola";
    array[0].cost = 75;
    array[0].num = 20;

    array[1].name = "Root Beer";
    array[1].cost = 75;
    array[1].num = 20;

    array[2].name = "Lemon-Lime";
    array[2].cost = 75;
    array[2].num = 20;

    array[3].name = "Grape Soda";
    array[3].cost = 80;
    array[3].num = 20;

    array[4].name = "Cream Soda";
    array[4].cost = 80;
    array[4].num = 20;
}

void menu(Machine array[], int size) {
    string option;
    int price = 0; //need to initialize variables with 0 
    int change = 0;
    int total = 0;


    do {
        cout << "Cola       " << array[0].cost << "  " << array[0].num << endl
                << "Root Beer  " << array[1].cost << "  " << array[1].num << endl
                << "Lemon-Lime " << array[2].cost << "  " << array[2].num << endl
                << "Grape Soda " << array[3].cost << "  " << array[3].num << endl
                << "Cream Soda " << array[4].cost << "  " << array[4].num << endl
                << "Quit" << endl;

        getline(cin, option);

        if (option == "Quit" || option == "quit") {
            cout << total << endl;
            exit(0); //ends the program
        } else
            do {
                cin >> price;
            } while (price >= 100 || price < 0);

        cin.ignore();

        total = total + price;

        if (option == "Cola") {
            array[0].num = array[0].num - 1;

            change = price - array[0].cost;
            array[0].num;

            cout << change << endl;

            total = total - change;
        } else if (option == "Root Beer") {
            array[1].num = array[1].num - 1;

            change = price - array[1].cost;
            array[1].num;
            cout << change << endl;

            total = total - change;
        } else if (option == "Lemon-Lime") {
            array[2].num = array[2].num - 1;

            change = price - array[2].cost;
            array[2].num;
            cout << change << endl;

            total = total - change;
        } else if (option == "Grape Soda") {
            array[3].num = array[3].num - 1;

            change = price - array[3].cost;
            array[3].num;
            cout << change << endl;

            total = total - change;
        } else if (option == "Cream Soda") {
            array[4].num = array[4].num - 1;

            change = price - array[4].cost;
            array[4].num;
            cout << change << endl;

            total = total - change;
        } else
            cout << "Please enter the name of the soda" << endl;
    } while (option != "Quit" || option != "quit");
}