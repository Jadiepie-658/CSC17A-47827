#include <iostream>

using namespace std;

int **getData(int &rows, int &cols);
void prntDat(const int* const *, int, int);
void destroy(int **, int, int);
int sum(const int* const *, int, int);

int main()
{
    int row;
    int col;
    int **array;
    int sums;
    
   array = getData(row, col);
   
   prntDat(array, row, col);
   
   
   sums = sum(array, row, col);
   cout << sums;
   
   destroy(array, row, col);
    
    
    
}

int **getData(int &rows, int &cols)
{
    //input amount of rows and columns in the array
    cin >> rows;
    cin >> cols;
    
    int **array = new int *[rows];
    
    for(int i = 0; i < rows; i++)
    {
        array[i] = new int[cols];
    }
    
    //input the integers into the array
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }
    
    return array;
}
void prntDat(const int * const *array, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(j == cols - 1)
            {
             cout << array[i][j]; 
             break;
            }
            cout << array[i][j] << " ";
            
        }
        
        cout << endl;
    }
    
}
void destroy(int **array, int rows, int cols)
{
    //delete the rows first 
    for(int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    //deletes columns
    delete[] array;
}
int sum(const int * const *array, int rows, int cols)
{
    int count = 0;
    
   
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            count = count + array[i][j];
        }
    }
    //returns sum
    return count;
    
}