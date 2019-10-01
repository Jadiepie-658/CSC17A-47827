#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
using namespace std;

int *expander(int *, int, int);

int main() {
    int array[10];
    int *size2;
    int size;
    int n;
    int i;

    cout << "Enter the size of the array" << endl;
    cin >> size;

    cout << "Input the integers into the array" << endl;
    for (i = 0; i < size; i++) {
        cin >> array[i];
    }

    size2 = expander(array, size, n);

    cout << "Array after doubling the array: ";
    for (i = 0; i < 2 * size; i++)
        cout << size2[i] << " ";
    return 0;
}
/*was having trouble with the .length function because I was trying  to 
 * get the length of the original array but it is an int* so it won't allow it
 * I tried my best though
 */

int *expander(int arr[], int size, int number) {
    int *newArr = NULL;
    int *temp = new int[arr.length()];
    for(int count = 0; count < arr.length(); count++)
    {
        temp[count] = arr[count];
    }
    int i;
    for (i = 0; i < number; i++) {
        int *newArr = new int[size * 2];
        for (int j = 0; j < size; j++) {
            //copies the elements of old array into new
            newArr[j] = arr[j];
            newArr[j + size] = 2 * temp[j];
        }

        delete[] arr; //delete old array

        size = size * 2;
        temp = new int[size];

        for (int count = 0; count < size; count++) {
            temp[count] = newArr[count];
        }

    }
    delete[] temp;

    return newArr; //return the pointer
}