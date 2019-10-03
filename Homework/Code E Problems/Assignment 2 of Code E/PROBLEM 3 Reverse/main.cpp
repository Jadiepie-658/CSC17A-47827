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
    
    delete [] data;
    delete[] sorted;
    delete [] reversed;
    
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
        
    }
    
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

   int startScan, minIndex; 
   int minElem; 
   
//sort example from the book but with pointers and their notations
   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minElem = arr2[startScan];
      
      for(int index = startScan + 1; index < size; index++)
      {
         if (*(arr2 + index) < minElem)
         {
            minElem = arr2[index];
            minIndex = index;
         }
      }
      arr2[minIndex] = arr2[startScan];
      arr2[startScan] = minElem;
      
   }
   
   
   for(int i =0; i<size-1; i++)
   {
       cout << arr2[i] << " ";
   }
    cout <<  arr2[size-1];
   
     cout << endl;
    
    return arr2;
}
int *reverse(const int *sorts, int size)
{
    int *revs = nullptr;
  revs = new int[size];
    
    for(int i = 0; i < size; i++)
    { //switches locations of the elements in the array
        revs[i + 1] = sorts[size - i - 1];
    }
    
    return revs;
}
void prntDat(const int *rev, int size)
{/*make sure the counter starts at 1 because you assigned the first value of the og array
  to the revs[1] not revs[0]
  */
  
    for(int i = 1; i < size; i++)
    {
        cout << rev[i] << " ";
    }
    cout << rev[size]; //for the spacing
}