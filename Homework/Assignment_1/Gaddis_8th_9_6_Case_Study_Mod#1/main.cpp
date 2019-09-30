#include<iostream>

using namespace std;

void arrSelectSort(int *[], int);
void showArray(int*, int);
void showArrPtr(int *[], int);

int main()
{
    
    int size;
 
    
    cout << "How many donations do you want to put in?" << endl;
    cin >> size;
    
    int **arrPtr = new int*[size];
    int *donations = new int[size];
    
    
    cout << "Now enter the donations" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Donation " << i + 1 << ") ";
        cin >> *(donations + i);
        
   
    }
    for(int count = 0; count < size; count++)
    {
        arrPtr[count] = &donations[count];
       
    }
     arrSelectSort(arrPtr, size);
    cout << "The sorted donations are ";
    showArrPtr(arrPtr, size);
    
    
    cout << "The donations in their original order are ";
    showArray(donations, size);
    
    return 0;
    
}

void arrSelectSort(int *arr[], int size)
{
    int startScan, minIndex;
    int *minElem;
    
    for(startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minElem = arr[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if(*(arr[index]) < *minElem)
            {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

void showArray(int *arr, int size)
{
    for(int count = 0; count < size; count++)
    {
        cout << *(arr + count) << " ";
        
    }
}

void showArrPtr(int *arr[], int size)
{
    for(int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
                cout << endl;
}