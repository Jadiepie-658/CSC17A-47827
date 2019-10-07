#include <iostream>
#include<iomanip>
#include<cstdlib>


using namespace std;

int *getData(int &);
void prntData(int *, int);
float *median(int *, int);
void prntMed(float *);
int SIZE;

int main(){
    
    
    int *array;
    float *med;
    
    array = getData(SIZE);
    prntData(array, SIZE);
    
    med = median(array, SIZE);
    prntMed(med);
    
    delete [] array;
    delete [] med;

	return 0;
}


int *getData(int &size)
{
    
    cin >> size;
    
    
   int *array = new int[size];
    
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    
    return array;
}
void prntData(int *array, int size)
{
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
}
float *median(int *array, int size)
{
    
   float *med = new float[size + 2];
    float ans;
    
    int j = 2;
    for(int i = 0; i < size; i++)
    {//copy the elements of the array and type cast it
        med[j] = static_cast<float>(array[i]);
        j++;
    }
    //if the array is even
    if(size % 2 == 0)
    {
        ans = med[4] + med[5]; //need two steps because pointers can't be divided
        ans = ans / 2;
    }
    else
    {
        ans = (*(med + 2) + *(med + 6)) / 2;
    }
    
    med[0] = size + 2;
    
    med[1] = ans;
    
    return med;
}
void prntMed(float *med)
{
   
    cout << med[0] << " ";
    
    cout << showpoint << setprecision(3);
    
    for(int i = 1; i <= SIZE; i++)
    {
        cout << med[i] << " ";
    }
    cout << med[SIZE + 1];
    
}