/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jade Braun
 *
 * Created on October 29, 2019, 4:28 PM
 */
#include <cstdlib>
#include<iostream>
#include<string>
#include "Structs.h"

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//function I created
float median(int, int *);
float mean(int, int *);
int *mode(int, int *, int &, int &);
int encryption(int);
int decryption(int);
bool valid(int);
bool isValid(int);
Primes *factor(int);
void prntPrm(Primes *);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int inN;
    do {
        Menu();
        inN = getN();
        switch (inN) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            case 7: problem7();
            break;
            default: def(inN);
        }
    } while(inN < 9 && inN > 0);
    
}
void Menu() {
    cout << "\nMenu" << endl;
    cout << "Type 1 for problem 1" << endl;
    cout << "Type 2 for problem 2" << endl;
    cout << "Type 3 for problem 3" << endl;
    cout << "Type 4 for problem 4" << endl;
    cout << "Type 5 for problem 5" << endl;
    cout << "Type 6 for problem 6" << endl;
    cout << "Type 7 for problem 7" << endl;
    cout << "Type anything else to exit \n" << endl;
}

int getN() {
    int inN;
    cin>>inN;
    return inN;
}
void def(int inN) {
    cout << "You typed " << inN << " to exit the program" << endl;
}
void problem1()
{
    Customer *cust = new Customer;
    string name, address;
    int checks, depo, acc; //number of checks, deposits, and account number
    float balance, sum = 0, diff = 0, total = 0, amt;
   
    cout << "Please enter your name. " << endl;
    cin.ignore();
    getline(cin, name); 
    cust->name = name; //pointer to the structure variable
    
    cout << "Please enter your address " << endl;
    getline(cin, address);
    cust ->address = address; //pointer to the structure variable
            

    cout << "Please enter your 5 digit account number: " << endl;
    cin >> acc;
    //doesn't accept the account number 00000
    while(!isValid(acc))
    {
        cout << "Invalid account number. Please enter a 5 digit account number: ";
        cin >> acc;
    }
    cust->account = acc;
    
    cout << "Enter the account's starting balance: ";
    cin >> balance;
    cust->amount = balance;
    sum = sum + balance;
    
    cout << "How many checks did you write this month?" << endl;
            cin >> checks;
    
    for(int i = 0; i < checks; i++)
    {
        cout << "Enter the amount for check #" << i + 1 << endl;
        cin >> amt;
        cust->totalChecks[i] = amt;
        
        diff = diff + amt;
    }
  
    cout << "How many deposits would you like to make?" << endl;
    cin >> depo;
    
    for(int i = 0; i < depo; i++)
    {
        cout << "Enter the amounts for deposit #" << i+1 << endl;
        cin >> amt;
        cust->totalDepo[i] = amt;
        sum = sum + amt;
    }
    cout << endl;
    total = sum - diff;
    
    if(total < 0)
    { cout << "You have broken our terms of service of always having the minimum of"
                " 20 dollars in your account, you have been charged with a 20 dollar fee" << endl;    
    total = total - 20;
    }
   

    
    cout << "---------------------------------" << endl;
    cout << "Name: " << cust->name << endl;
    cout << "Address: " << cust->address << endl;
    cout << "Account number: " << cust->account << endl;
    cout << "Beginning balance: $" << cust->amount << endl;
    cout << "Total of checks: $" << diff << endl;
    cout << "Total of deposits: $" << sum << endl;
    cout << "---------------------------------" << endl;

    

    cout << "Your new balance is: $" << total << endl;


}



bool isValid(int num)
{
    int count = 0;
    while(num > 0)
    {
        count ++;
        num = num / 10;
    }
    if(count == 5)
        return true;
    else 
        return false;
}


void problem2()
{
    
}
void problem3()
{
     //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size - 1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
     
    Stats *stats=new Stats;
    stats->mode=new Array;
    
    stats->mode->size;
    int nModes;
    
    stats->mode->data=new int[nModes];
    stats->modFreq;
    stats -> mode -> data = mode(array -> size, array -> data,
            stats -> modFreq, stats -> mode -> size);
    stats -> median = median(array -> size, array -> data);
    stats -> avg = mean(array -> size, array -> data);
    return stats;
}

float mean(int size, int *array)
{
    int total = 0;
    float mean = 0.0;
    for(int i = 0; i < size; i++)
    {
        total = total + array[i];
    }
    mean =(float)(total) / size;
    
    return mean;
}

float median(int size, int *array)
{
    float med = 0.0;
    //even or odd function
    if(size % 2 == 0)
    {
        med = array[(size / 2)] + array[((size / 2) - 1)];
        med = med /2.0;
        
    }
    else
    {
        med = array[size / 2];
    }
    return med;
}

int *mode(int size, int *array, int &frequency, int &nMod)
{
    int *modes;
    int freq = 1;
    int nModes = 0;
    
    int current = 1;
    for(int i = 1; i < size; i++)
    {
        if(array[i] == array[i - 1])
        {
            current++;
            if(current == freq)
            {
                nModes++;
            }
            if(current > freq)
            {
                freq = current;
                nModes = 1;
            }
        }
        else current = 1;
    }
   
    int count = 0;
    modes = new int[nModes];
    for(int i = 0; i < nModes; i++)
    {
        modes[i] = -1;
    }
    int curr = 1;
    for(int i = 1; i < size; i++)
    {
        if(array[i] == array[i - 1])
        {
            curr++;
            if(curr == freq)
            {
                modes[count] = array[i];
                count++;
            }
        }
        else 
            curr = 1;
       
    }
    frequency = freq;
    nMod = nModes;
    return modes;
    
}
void problem4()
{
    cout << "In problem #4: " << endl << endl;
    
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
      
}
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
                   << (base3 + 3)%8 << (base4 + 3)%8 << endl;
           
     
      
    
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

void problem5()
{
    cout << "Short: 15, overflows at 16"<< endl;
    cout << "Int: 31, overflows at 32" << endl;
    cout << "Long: 63, overflows at 64" << endl;
    cout << "Float: 34, overflows at 35" << endl;
    cout << "Double: 170, overflows at 171" << endl;
    cout << "Signed: 31, overflows at 32" << endl;
    cout << "Unsigned: 32, overflows at 33" << endl;
    
/*{float facto;
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
*/

}

void problem6()
{
    cout << "In problem #6 " << endl << endl;
    cout << "------------------------------------" << endl;
    cout << "base 10 \t base 2 \t base 8 \t base 16 \t floating point representation" << endl;
    cout << "2.875 \t\t 10.111 \t 2.7 \t        2.E \t\t 40380000" << endl << endl;
    cout << ".1796875 \t .0010111 \t .134 \t\t.2E \t\t 3E380000" << endl << endl;
    cout << "-2.875 \t\t 01.000001 \t -2.7 \t        4.1 \t\t C0380000" << endl << endl;
    cout << "-.1796875 \t .11010001 \t -.134 \t\t.D1 \t\t BE380000" << endl << endl;
    cout << "------------------------------------" << endl;
    
    cout << "Part C: " << endl;
    cout << "59999901 in decimal is 5404237626343424" << endl;
            cout << "59999902 in decimal is 5404238163214336" << endl;
            cout << "A66667FE in decimal is 2791729142" << endl;
}
void problem7()
{
     int number;
    cout << "Enter a number to print the primes and their powers (NO DECIMALS): " << endl;
            cin >> number;
            prntPrm(factor(number));
}
Primes *factor(int num)
{
    //malloc() returns a pointer to uninitialized memory block allocated by the function
    Primes* primes = (Primes*)malloc(sizeof(Primes));
    primes->prime = (Prime*)malloc(sizeof(Prime) * 100);
    Prime prim;
    int i = 2;
    unsigned char count = '0';
    unsigned char nPrimes = '0';
    while(num > 2)
    {
        if(num % i == 0)
        {
            
            count++;
            num = num / i;
            
      
        }
        else 
        {
            if(count > '0')
            {
                
                prim.prime = i;
               prim.power = count;
                primes->prime[nPrimes - '0'] = prim;
                nPrimes++;
            }
            i++;
            count = '0';
        }
    }
    if(count > '0')
    {
        prim.prime = (short)i;
       prim.power = count;
        primes->prime[nPrimes - '0'] = prim;
        nPrimes++;
    }
    primes->nPrimes = nPrimes - 1;
    
}

void prntPrm(Primes *primes)
{
    int nPrimes = (int)primes->nPrimes;
    Prime prim;
    int i;
    
    for(i = 0; i < nPrimes - '0'; i++)
    {
        prim = primes->prime[i];
       
        
        cout << prim.prime << "^" << prim.power << ", ";
    }
    prim = primes->prime[i];
    cout << prim.prime << "^" << prim.power << ", ";
}