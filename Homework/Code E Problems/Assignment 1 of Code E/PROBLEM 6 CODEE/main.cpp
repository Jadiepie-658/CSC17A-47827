//System Libraries Here
#include <iostream>//cin,cout
#include <vector> //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 2; //Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy1(vector<int>&, vector<int>&, int [][COLMAX]);
void prntVec(vector<int>, vector<int>, int); //int n is the format setw(n)
void prntAry(const int [][COLMAX], int, int, int);

//Program Execution Begins Here

int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW = 80; //No more than 80 rows
    int arr[ROW][COLMAX]; //Really, just an 80x2 array, even vs. odd
    vector<int> even(0), odd(0); //Declare even,odd vectors

    //Input data and place even in one vector odd in the other
    read(even, odd);

    //Now output the content of the vectors
    // setw(10)
    prntVec(even, odd, 10); //Input even, odd vectors with setw(10);

    //Copy the vectors into the 2 dimensional array
    copy1(even, odd, arr);

    //Now output the content of the array
    // setw(10)
    prntAry(arr, even.size(), odd.size(), 10); //Same format as even/odd vectors

    //Exit
    return 0;
}

void read(vector<int>&even, vector<int>&odd) {
    int n;
    cout << "Input the number of integers to input." <<endl;
    cin>>n;
    
    cout << "Input each number." << endl;
    for (int i = 0; i < n; i++) {
        int arr;
        cin>>arr;
        
        if (arr % 2 == 0) {
            even.push_back(arr);
        } else {
            odd.push_back(arr);
        }
    }
}

void prntVec(vector<int>even, vector<int>odd, int n) {
    
    int size = 0;
    if(even.size() > odd.size())
    {
        size = even.size();
        
    }
    else
    {
        size = odd.size();
    }

   cout  << setw(n) << "Vector" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(n * 2);
        if(i < even.size())
        {
            cout << even.at(i); 
        }
        else
        cout << " ";
        
        cout << setw(n);
        
        if(i < odd.size())
        {
            cout << odd.at(i);
        }
        else 
        cout << " ";
        
        cout << endl;
      
}
}

void copy1(vector<int>&even, vector<int>&odd, int arr[][COLMAX]) {
int size = 0;

if(even.size() > odd.size())
    {
        size = even.size();
        
    }
    else
    {
        size = odd.size();
    }
  
  for(int i = 0; i < size; i ++)
  {
      for(int j = 0; j <= 1; j++)
      {
          switch(j)
          {
              case 0:
              if(i < even.size()){
              arr[i][j] = even.at(i);
              }
              else
              arr[i][j] = -1;
              break;
              
              case 1:
              if(i < odd.size()){
              arr[i][j] = odd.at(i);
              }
              else
              arr[i][j] = -1;
              break;
              
              default:
              break;
          }
      }
  }
}

void prntAry(const int arr[][COLMAX], int evenSize, int oddSize, int n) {
    
    int size = 0;
     if(evenSize > oddSize)
    {
        size = evenSize;
        
    }
    else
    {
        size = oddSize;
    }
        cout << setw(n) << "Array" << setw(n) << "Even" << setw(n) << "Odd" << endl;
   
     for (int i = 0; i < size; i++) {
    cout << setw(n * 2);
    for (int j = 0; j <= 1; j++) {
        if (arr[i][j] != -1) {
            cout << arr[i][j];
        }
            else
                cout << " ";

                    cout << setw(n);
          
        }
    cout << endl;    
    }
    
}

