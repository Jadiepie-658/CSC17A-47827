#include <iostream>

using namespace std;

int *getData(int &); //Read the array
int *augment(const int *, int); //Augment and copy the original array
void prntAry(const int *, int); //Print the array


int main(){
	
	int size;
	int *data;
	int *change;
	
	data = getData(size);
	
	change = augment(data, size);
	
	prntAry(change, size);
	
	return 0;
}

int *getData(int &size)
{
    //input size
    cin >> size;
    
    //create dynamically allocated array
    int *array = new int [size];
    
    //input numbers into integer array
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
        
    }
    for(int i = 0; i < size; i++)
    {
        if(i == size - 1)
        {
            cout << array[i];
            break;
        }
        cout << array[i] << " ";
    }
    cout << endl;
    
  return array;  //return the array

    
    
}
int *augment(const int *arr, int size)
{
    int *arr2 = new int[size + 1]; //creating new dynamic allocated array
    
    arr2[0] = 0; //place 0 in first element
    
    for(int i = 0; i < size; i++)
    {
        arr2[i + 1] = arr[i]; //copying elements of original array into second position of new array
    }
    
    return arr2; //return new array
}


void prntAry(const int *change, int size)
{
    for(int i = 0; i < size + 1; i++)
    {
        if(i == (size + 1) - 1) //need if statement to get spacing correct
        {
            cout << change[i];
            break;
        }
        cout << change[i] << " ";
        
    }
}