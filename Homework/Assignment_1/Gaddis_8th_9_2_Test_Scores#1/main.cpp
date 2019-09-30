//Jade Braun

#include<iostream>

using namespace std;

void sortScores(int *, int);
float avgScores(int *, int);
void printScores(int *, int);

int main() {
    int *testScores;
    int size;
    int score;
    float avg;

    cout << "Enter the size of the array" << endl;
    cin >> size;

    testScores = new int[size]; //dynamically allocates the array

    cout << "Now enter the test scores into the array" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        cin >> score;

        //check for invalid inputs
        if (score < 0) {
            cout << "Invalid score. Please enter a valid positive score" << endl;
            cout << i + 1 << ") ";
            cin >> score;
        }
        testScores[i] = score;
    }

    sortScores(testScores, size);

    cout << "Sorted Scores: ";

    printScores(testScores, size);
    cout << endl;

    avg = avgScores(testScores, size);

    cout << "Average of the Scores: " << avg;

    return 0;
}

void sortScores(int *testScores, int size) {
    int *last = testScores + size; //gets the last location of the array

    for (int *first = testScores; first < last - 1; first++) {
        for (int *next = first + 1; next < last; next++)//for loop to go from starting position to next position
        {
            if (*next < *first) {//swap
                int temp = *first;
                *first = *next;
                *next = temp;
            }
        }
    }

}

float avgScores(int *testScores, int size) {
    int sum = 0;
    float avg;

    int *array = testScores;

    for (int i = 0; i < size; i++) {
        sum = sum + *array;
        array++;
    }
    //convert sum to a float
    avg = static_cast<float> (sum) / size;
    return avg;
}

void printScores(int *testScores, int size) {
    int *array = testScores;
    for (int i = 0; i < size; i++) {
        cout << *array << " ";
        array++; //increments array until it reaches the last location
    }
}


