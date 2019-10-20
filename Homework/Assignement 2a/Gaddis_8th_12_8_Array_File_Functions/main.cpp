#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;


void arrayToFile(string , int *, int);
void fileToArray(string, int *, int);

int main()
{
    int size = 10;
    string file = "fileName.txt";
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[size];
    
    arrayToFile(file, array1, size);
    fileToArray(file, array2, size);
}

void arrayToFile(string fileName, int *array, int size)
{
    ofstream outFile;
    
    outFile.open(fileName.c_str(), ios::out | ios::binary);
    outFile << "The numbers we write from the file are: ";
    for(int i = 0; i < size; i++)
    {
        
       outFile << array[i] << " ";
    }
    for(int i = 0; i < size; i++)
    {
     outFile << array[i] << " ";   
    }
    cout << endl;
    outFile.close();
}

void fileToArray(string fileName, int *arr, int size)
{
    ifstream inFile;
    //I'm to lazy today to create ofstream variable to put the cout message in to the file.
    inFile.open(fileName.c_str(), ios::binary|ios::in);
    cout << "Numbers read from the file";
    for(int i = 0; i < size; i++)
    {
        inFile >> arr[i];
    }
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    inFile.close();

}