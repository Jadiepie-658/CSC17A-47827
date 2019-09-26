//Jade Braun

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void String();
void Weather();

int main() {
    char key;
    String();
    Weather();
    cout << endl << "Press any key to exit the program" << endl;
    cin >> key;
    return 0;
}

void String() {
    string weather = "CCCSSSRRRSSRCRCSSRRSSCRSCRRS \n SSSSRCCRCRSSSSSRCRSSSSRCRSSRSRS \n SSSSSSSSSSSSCCSSRRRCCRRSSSSSSS";

    ofstream File;
    File.open("RainOrShine.txt");
    if (File.is_open()) {
        cout << "Creating file" << endl;
        File << weather;
        File.close();
    } else
        cout << "File creation failure" << endl;


}

void Weather() {
    char Weathers[3][30] = {0};
    int count[3][3] = {0};
    int rainiest = 0;
    string month[3] = {"June", "July", "August"};
    int forecast;
    int i, f;
    ifstream myfile;
    myfile.open("RainOrShine.txt");

    if (myfile.is_open()) {
        cout << "File Opened successfully" << endl;

        for (i = 0; i < 3; i++) {
            for (f = 0; f < 30; f++) {

                forecast = myfile.get();

                if (forecast != -1 && forecast != '\n') {
                    Weathers[i][f] = forecast;
                }
                if (Weathers[i][f] == 'R' || Weathers[i][f] == 'r') {
                    count[i][0]++;
                } else if (Weathers[i][f] == 'C' || Weathers[i][f] == 'c') {
                    count[i][1]++;
                } else if (Weathers[i][f] == 'S' || Weathers[i][f] == 's') {
                    count[i][2]++;
                }
            }
        }

        for (i = 1; i < 3; i++) {
            if (count[i][0] > count[rainiest][0]) {
                rainiest = i;
            }
        }


        cout << endl << "Month \t Rainy Days \t Cloudy Days \t Sunny Days" << endl;
        for (i = 0; i < 3; i++) {
            cout << month[i] << "\t " << count[i][0] << "\t\t" << count[i][1] << "\t\t" << count[i][2] << endl;
        }
        cout << endl << endl << "Month with the most rainy days: " << month[rainiest];
        myfile.close();
    }
    else cout << "File opening failure" << endl;

}