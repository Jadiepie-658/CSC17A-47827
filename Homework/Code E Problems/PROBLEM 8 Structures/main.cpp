#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


struct MovieData{
    
    string title;
    string director;
    string year;
    string runTime;
};


void movieDat(MovieData [],int &);
void printMovie(MovieData [],int);



int main() {
    
    int size=10;
    MovieData movies[size];
    
   
    movieDat(movies,size);
   
  
    printMovie(movies,size);
    

    return 0;
}


void movieDat(MovieData movies[],int &size){
    
        cout << "This program reviews structures" << endl
         << "Input how many movies, the Title of the Movie, Director, Year "
            "Released, and the Running Time in (minutes)." << endl;
    
    cin >> size;
    
    cin.ignore(); 
    //without cin.ignore() it won't ignore the amount of characters you specify, 
    //up to the character you specify as a breakpoint
    
     for (int i=0; i < size; i++){
        
        
        //used getline because it was easier to figure out for me because
        //my cin inputs were getting skipped and the program was failing
         
     
        getline(cin,movies[i].title);
 
     
        getline(cin,movies[i].director);
     
       
        getline(cin,movies[i].year);
    
  
        getline(cin,movies[i].runTime);
    
        
    }
    
}



void printMovie(MovieData mov[], int size){
    
    
    
    for (int i=0; i < size; i++){      
    
    cout << endl;  
        
    cout << "Title:     " << mov[i].title << endl;
 
    cout << "Director:  " << mov[i].director << endl;
    
    cout << "Year:      " << mov[i].year << endl;
    
    cout << "Length:    " << mov[i].runTime << endl;
    
    cin.ignore();
  }
    
    
    
}