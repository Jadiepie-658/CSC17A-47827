#include<iostream>
#include<string>
#include<string.h>


using namespace std;

struct Customer {
    string name, address;
    int account;
    float totalChecks[100];
    float totalDepo[100];
    float amount;
};
bool isValid(int);
int main(int argc, char** argv) {

    Customer *cust = new Customer;
    string name, address;
    int checks, depo, acc; //number of checks, deposits, and account number
    float balance, sum = 0, diff = 0, total = 0, amt;
    char choice;
   
    
   

    cout << "Please enter your name. " << endl;
    getline(cin, name); 
    cust->name = name; //pointer to the structure variable
    
    cout << "Please enter your address " << endl;
    getline(cin, address);
    cust ->address = address; //pointer to the structure variable
            

    cout << "Please enter your 5 digit account number: " << endl;
    cin >> acc;
    
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


    return 0;
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