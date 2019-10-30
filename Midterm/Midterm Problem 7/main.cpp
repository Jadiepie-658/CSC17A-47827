//Prime numbers Problem
//Jade Braun


#include<iostream>
#include<string>

using namespace std;

struct Prime
{
    unsigned short prime;
   unsigned char power;
};
struct Primes
{
    Prime *prime;
    unsigned char nPrimes;
};

Primes *factor(int);
void prntPrm(Primes *);
int main()
{
    
    int number;
    cout << "Enter a number to print the primes and their powers (NO DECIMALS): " << endl;
            cin >> number;
            prntPrm(factor(number));
            
           
            return 0;
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