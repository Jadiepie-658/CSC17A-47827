/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jade Braun
 */

#include<iostream>
using namespace std;

/*
 * 
 */
int encryption(int);
int decryption(int);
bool valid(int);
int main(int argc, char** argv) {

    int a;
    char choice;
    
    cout << "Please choose whether you want to encrypt a number or decrypt (E or D)" << endl;
       cin >> choice;
    if(choice == 'E' || choice == 'e')
    {
    encryption(a);
    }
    if(choice == 'D' || choice == 'd')
    {
    decryption(a);
    }
      
    return 0;
}
//warning the while loop will break if you enter a char as an input
int encryption(int num)
{
   
    int number;
    bool error = false;
    
    do
    {
    cout << "Enter the number you want to encrypt" << endl;
    cin >> number;
    
    error = valid(number);
    if(error){
    cout << "You entered an invalid integer" << endl;
    }
    }while(error);
    int base1, base2, base3, base4;
    
   
        base1 = number / 1000;
        base2 = number / 100 - 10*base1;
        base4 = number%10;
        base3 = (number %100 - base4) / 10;
        
        
        cout << "Encrypted integer: " << (base1 + 5)%8 << (base2 + 5)%8 <<(base3 + 5)%8
                << (base4 + 5)%8 << endl;
        
       
}

int decryption(int a)
    {
    int number;
    bool error = false;
    do
       {
       cout << "Enter the number you want to decrypt" << endl;
       cin >> number;
       
       error = valid(number);
           if(error){
           cout << "You entered an invalid integer" << endl;
           }
    }while(error);
       int base1, base2, base3, base4;
       
       
           base1 = number / 1000;
           base2 = number / 100 - 10*base1;
           base4 = number%10;
           base3 = (number%100 - base4) /10;
           
           cout << "Decrypted integer is: " << (base1 + 3)%8 << (base2 + 3)%8
                   << (base3 + 3)%8 << (base4 + 3)%8;
           
     
      
    
}

bool valid(int check)
{
    int base1, base2, base3, base4;
    base1 = check / 1000;
    base2 = (check%1000) / 100;
    base3 = ((check %1000)%100)/10;
    base4 = ((check%1000)%100)%10;
    //checks for integers with 8's and 9's in it
    if(check < 1000 || check > 7777) 
        return true;
    else if(base1 > 7 || base2 > 7 || base3 > 7 || base4 > 7)
        return true;
    else 
        return false;
}