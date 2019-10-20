#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int LENGTH = 4;

struct Corp
{
    static string Division[LENGTH];
    float quarter[LENGTH];
    float quartlySales;
};

string Corp :: Division[LENGTH] = {"East", "West", "North", "South"};

int main()
{
    Corp sales;
    
    fstream File("salesFigure.txt", ios::out | ios::binary);
    if(!File)
    {
        cout << "Failed to open file";
        return 0;
    }
    
    cout << "Enter the quarterly sales figure for each of the four divisions" << endl;
    
    for(int i = 0; i < LENGTH; i++)
    {
        cout << sales.Division[i] << " Division: ";
        
        for(int j = 0; j < LENGTH; j++)
        {
            do
            {
                cout << "Quarter " << j + 1 << ": ";
                cin >> sales.quartlySales;
                
                if(sales.quartlySales < 0)
                    cout << "Invalid sales figure" << endl;
            }while(sales.quartlySales < 0);
            sales.quarter[i] = sales.quartlySales;
        }
        
        File.write(reinterpret_cast<char *>(&sales), sizeof(sales));
    }
    File.close();
    return 0;
}