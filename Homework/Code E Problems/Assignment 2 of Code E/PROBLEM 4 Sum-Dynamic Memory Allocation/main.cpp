#include <iostream>

using namespace std;

int *getData(int &);
int *sumAry(const int *, int);
void prntAry(const int *, int);

int main(){
	
	int size;
	int *data; // to retrieve array
    int *add; //to get sum data array
    
    data = getData(size);
    
    add = sumAry(data, size);
    
    prntAry(add, size);
    
	return 0;
}

int *getData(int &size)
{
    //input size
    cin >> size;
    
    //create dynamically allocated array
    int *array = new int[size];
    
    //input values of the integer array
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
        
        if(i == size - 1)
        {
            cout << array[i];
            break;
        }
        cout << array[i];
    }
    cout << endl;
    
    return array;
}
int *sumAry(const int *arr, int size)
{
    //new dynamically allocated array
    int *arr2 = new int[size];
    int count = 0;
    
    //copy first array to second array
    for(int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    for(int i = 0; i < size; i++)
    {
        count = count + arr[i]; //adding each number to each other in the array
        arr2[i] = count; //assigns new array with the sum array
    }
    
    cout << endl;
    
    return arr2; //return new array
}
void prntAry(const int *sum, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(i == size - 1) //need if statement for correct spacing
        {
            cout << sum[i];
            break;
        }
        cout << sum[i] << " ";
    }
}


