/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int>&even, vector<int>&odd)
{
    int n;
    int size;
    cout << "Input the number of integers to input." << endl;
    cin >> size;
    
    cout << "Input each number." << endl;
    for(int i = 0; i < size; i++)
    {
        
        cin >> n;
        
        if(n%2 == 0) //checks even numbers
        {
            even.push_back(n);
        }
        else
        {
            odd.push_back(n);
        }
    }
}

void prntVec(vector<int>even, vector<int>odd, int n)
{
    cout << endl << setw(9) << "Vector" << setw(11) << "Even" << setw(12) << "Odd" << endl;
    int i, j;
    while( i < even.size() && j < odd.size())
    {
        cout << setw(n) << even[i] << setw(n) << odd[j] << endl;
        i++;
        j++;
    }
    
    while(i < even.size())
    {
        cout << setw(n) << even[i] << endl;
        i++;
    }
    while(j < odd.size())
    {
        cout << setw(n) << odd[j] << endl;
        j++;
    }
}
void copy(vector<int>even, vector<int>odd,int array[][COLMAX])
{
    int i, j;
    for(i = 0, j = 0; i < even.size(); i++)
    {
        array[i][j] = even[i];
    }
    for(i = 0, j = 1; i < odd.size(); i++)
    {
        array[i][j] = odd[i];
    }
}
void prntAry(const int array[][COLMAX],int evenSize,int oddSize,int n)
{
    cout << setw(n) << "Array" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    int i, j;
    
    while(i < evenSize && j < oddSize)
    {
        cout << setw(n) << array[i][0] << setw(n) << array[j][1] << endl;
        i++;
                j++;
    }
    
    while(i < evenSize)
    {
        cout << setw(n) << array[i][0] << endl;
        i++;
    }
    while(j < oddSize)
    {
        cout << setw(n) << array[j][1] << endl;
        j++;
    }
}