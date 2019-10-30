//Mode problem

#include<iostream>
using namespace std;

struct Array
{
    int size;
    int *data;
};
struct Stats
{
    float avg;
    float median;
    Array *mode;
    int modFreq;
};
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

//Execution begins here
int main(int argc, char*argv[]) {
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
    
    //Exit stage right
    return 0;
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