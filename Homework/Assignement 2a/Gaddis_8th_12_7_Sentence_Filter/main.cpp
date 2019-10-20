#include<fstream>
#include<iostream>
#include<cctype>

using namespace std;

int main()
{
    const int SIZE = 81;
    char file1[SIZE];
    char file2[SIZE];
    ifstream inFile;
    fstream outFile;
    char ch;
   
    
    cout << "Read into the first file" << endl;; 
    cin >> file1;
    
     inFile.open(file1);
    
     //test if file opens correctly
     if(!inFile)
     {
         cout << "The file " << file1 << " failed to open";
         exit(0);
     }
     
     cout << "Read out into the second file" << endl;
     cin >> file2;
     
     outFile.open(file2, ios::out);
     inFile.get(ch);
     while(!inFile.eof())
     {
         outFile.put(tolower(ch));
         inFile.get(ch);
     }
     inFile.close();
     outFile.close();
     
     return 0;
}
