#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size = 0;
    int array[1000];
    cout << "Enter the size of the array" << endl;
    cin >> size;
    
    cout << "Now enter the array numbers" << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
 
    for(int i = size - 1; i >= 0; i--)

    {
        cout << array[i] << " ";
    }
    return 0;
}

