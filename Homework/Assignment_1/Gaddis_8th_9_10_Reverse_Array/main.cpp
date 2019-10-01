#include<iostream>
using namespace std;

int *reverse(int [], int); //function prototype

int main()
{
   //the problem doesn't ask for the user to input the size of the array so I just used a const
    const int SIZE = 10;
    int array[SIZE];
    int *reverseArr;
    
    
    cout << "Enter " << SIZE << " numbers for the array" << endl;
    
    for(int i = 0; i < SIZE; i++)
    {
        cin >> array[i];
        
    }
           
           
       cout << "Elements from the original array: ";
       for(int i = 0; i < SIZE; i++)
           cout << array[i] << " ";
       
       
       cout << endl;
       reverseArr = reverse(array, SIZE);
       cout << "Elements of the reversed array: ";
       for(int i = 0; i < SIZE; i++)
           cout << reverseArr[i] << " ";
               
       return 0;
               
}

int *reverse(int array[], int size)
{   //will store original array into new array
    int *arr2;
        //dynamically allocate the array
    arr2 = new int[size];
    
    int j = 0;
    for(int i = size - 1; i >= 0; i--)
    {//stores old array into new with reversed order
        arr2[j] = array[i];
        j++;
    }
    return arr2;

}