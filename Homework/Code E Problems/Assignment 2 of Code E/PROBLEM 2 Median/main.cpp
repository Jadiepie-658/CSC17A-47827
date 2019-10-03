#include <iostream>
#include <iomanip>

using namespace std;
int *getData(int &);
void prntDat(int *, int);
float *median(int *, int);
int maximum(int arr, int arr2);

int main(){
	int n;
        int array[n];
        float median[n * 2];
        
        cin >> n;
        
        *getData(n);
        
        prntDat(array, n);
        
        
	return 0;
}

int *getData(int &size)
{
    int *array = new int[size];
    
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    return size, array;
    
    
}

void prntDat(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}
int maximum(int arr, int arr2)
{
    return arr < arr2? arr : arr2;
}
float *median(int *array, int size)
{
    int i = 0, j = 0;
    int size2 = size * 2;
    float *med = new float[size2];
    int min_index = 0;
    int max_index = size;
    float median;
    
    while(min_index <= max_index)
    {
        i = (min_index + max_index) / 2;
        j = ((size + size2 + 1) / 2) - i;
        
        if(i < size && med[j - 1] > array[i])
        {
            min_index = i + 1;
        }
        
        else if(i > 0 && j < size2 && med[j] < array[i -1])
        {
            max_index = i - 1;
        }
        else
        {
            if(i == 0)
            {
                median = med[j - 1];
            }
            else if(j == 0)
                median = array[i - 1];
            
            else
                median = maximum(array[i - 1], med[j - 1]);
                break;
        }
    }
    
    if((size + size2) % 2 == 1)
        return median;
    
    if(i == size)
        return (median + med[j]) / 2.0;
   
    if(j == size2)
        return (median + array[i]) / 2.0;
    
}