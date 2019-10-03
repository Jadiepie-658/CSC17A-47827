/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}
int  read(char array[][COLMAX],int &rowDet)
{
       int colDet = 0; 
       
    cin.ignore(1024, '\n');
    
    for (int count=0; count < rowDet; count++) {
        
        cin.getline(array[count], COLMAX);
        int length=strlen(array[count]);
        
        if (length > colDet){
         colDet=length;
        }
    }
    return colDet;

}
void sort(char array[][COLMAX], int rows, int, const char replace[], const char with[]) { //Sort by row
   int i, j;
    int min;
    char temp[COLMAX];
    for(i = 0; i < rows - 1; i++)
    {
    min = i;
        for(j = i + 1; j < rows; j++)
        {
            if(strcmp(array[j], array[min], replace, with) > 0)
            {
min = j;
            }
           
                 
        
        } 
        if(min != i){
        strcpy(temp, array[i]);
        strcpy(array[i], array[min]);
        strcpy(array[min], temp);
        }
       
    }
}

int strcmp(char first[], char second[], const char replace[], const char with[]) { 
    //Replace sort order
    char copy1[COLMAX];
    
       for (int count=0; copy1[count]=='\0';count++) {
           
        copy1[count] = first[count];
    }
    char copy2[COLMAX];
    for (int count=0; copy2[count]=='\0';count++) {
        
        copy2[count] = second[count];
      
    }
     int copy1Len = strlen(first);
    int copy2Len = strlen(second);
    int repLen = strlen(replace);
    
    for(int i = 0; i < copy1Len && i < copy2Len; i++)
    {
        for(int j = 0; j < repLen && copy1[i] == replace[j] && copy2[i] == replace[j]; j++)
    {
    if(copy1[i] == replace[j] && copy2[i] == replace[j])
    {
        copy1[i] = with[j];
        copy2[i] = with[j];
    }
    }
}

    
    return strcmp(copy1, copy2);
}

void print(const char array[][COLMAX], int rows, int cols){
    for (int count=0;count<rows;count++){
        cout<<array[count]<<endl;
    }
}