#include <iostream>

using namespace std;

int *getData(int &); //Fill the array
int *sort(const int *, int); //sort smallest to largest
int *reverse(const int *, int);//sort in reverse order
void prntDat(const int *, int); //print the array
int main(){
	
    int size;
    int *data;
    int *sorted;
    int *reversed;
    
    data = getData(size);
    
    sorted = sort(data, size);
    
    reversed = reverse(sorted, size);
    
    prntDat(reversed, size);
    
	return 0;
}

int *getData(int &size)
{
    //input size of array
    cin >> size;
    
    //dynamically allocate array
    int *array = new int[size];
    
    //fill array
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
        
        if(i == (size + 1) - 1)
        {
            cout << array[i];
            break;
        }
        cout << array[i] << " ";
    }
    cout << endl;
    
    return array;
}
int *sort(const int *array, int size)
{
    int temp;
    
    int *arr2 = new int[size];
    
    for(int i = 0; i < size; i++)
    {
        arr2[i] = array[i]; //copying array elements
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            temp = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp;
        }
    }
    
    return arr2;
}
int *reverse(const int *, int)
{
    
}
void prntDat(const int *, int)
{
    
}