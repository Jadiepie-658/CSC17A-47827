//Factorials
//Jade Braun

#include<iostream>
using namespace std;
int main()
{
    float facto;
do 
{
    
    cout << "Enter a number to get its factorial: ";
            cin >> facto;
            for(int i = facto - 1; i > 0; i--)
            {
                facto *=i;
            }
            cout << "Factorial: " << facto << endl;
            
}while(facto != -1);


}