#include<iostream>
using namespace std;

int mode(int [], int);
float mean(int [], int);
float median(int [], int);

int main()
{
    int size;
    int *array = new int[size];
    int mod;
    float means, med;
  
   
    cout << "Please enter the size of the array" << endl;
    cin >> size;
    
    cout << "Now enter the integers of the array" << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    
    mod = mode(array, size);
    means = mean(array, size);
   
    if(mod == -1)
    {
        cout << "No mode occurs" << endl;
    }
    else
    cout << "The mode of the array is " << mod << endl;
    cout << "The mean of the array is " << means << endl;
    median(array, size);
    delete[] array;
}
/*bug: only finds one , I understand the process of sorting and how I'd find the frequencies
 * of each number but I'm confused on how to output more than one mode
 * I also had trouble with the median function
 * */
int mode(int array[], int size)
{
  int mode = -1;
  int frequency;
  int count;
  for(int i = 0; i < size; i++)
  {
      frequency = array[i];
      count = 0;
              
              for(int j = 0; j < size; j++)
              {
                  if(frequency == array[j])
                  {
                      count++;
                  }
              }
      if(count > 1 && count > mode)
          mode = frequency;
}
  return mode;
}
float mean(int array[], int size)
{
    float sum = 0;
    float avg;
    
    for(int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    avg = sum / size;
    
    return avg;
}
float median(int array[], int size)
{
    int middle;
    float avg;
    float median;
    
    middle = size / 2;
    
    if(size % 2)
    {
         median = (array[middle] + array[middle + 1]) / 2.0;
         cout << "The median of the array is " << median << endl;
    }
    else
    {
        median = array[middle];
      
       cout << "The median of the array is " << median << endl;
    }
    return median;
}
