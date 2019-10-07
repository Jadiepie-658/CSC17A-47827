#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  
   int n,q; //n number of variable length arrays
   // q is the number of queries asked
    cin >>n >>q;
   int ** Vectors = new int *[n];
   //creating a 2D vector array
   int j;
    for (int i=0;i<n;i++)
    {   
        cin>>j;
        Vectors[i] = new int [j]; 
        //creating columns of array
        
        for (int y=0;y<j;y++)
            cin>>Vectors[i][y];
    }
    int q1,q2;
    for (int i=0;i<q;i++)
    {
        cin >>q1 >> q2;
        cout<<Vectors[q1][q2]<<endl;

     }

   
    return 0;
}




