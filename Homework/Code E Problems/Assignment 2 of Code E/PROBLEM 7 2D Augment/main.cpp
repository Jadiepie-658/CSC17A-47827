#include <iostream>

using namespace std;

int **getData(int &, int &);
void printDat(const int * const *, int, int);
int **augment(const int * const *, int, int);
void destroy(int **, int);

int main() {

    int row;
    int col;
    int size;
    int **array;
    int **aug;

    array = getData(row, col);

    printDat(array, row, col);

    aug = augment(array, row, col);
    cout << aug;
    
    destroy(array, row);

    return 0;
}

int **getData(int &rows, int &cols) {
    //input rows and columns
    cin >> rows >> cols;

    int **array = new int *[rows];

    for (int i = 0; i < rows; i++) {
        array[i] = new int [cols];
    }

    //input the integers into the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> array[i][j];
        }
    }
    return array;

}

void printDat(const int * const *array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == cols - 1) {
                cout << array[i][j];
                break;
            }
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

}

int **augment(const int * const *array, int rows, int cols) {
    
    //clears space in array to hold zeros
    int row2 = rows + 1;
    int col2 = cols + 1;

    int **augs = new int *[row2];
    
    for(int i = 0; i < row2; i++)
    {
        augs[i] = new int[col2];
    }
    
     
   
    for(int i = 0; i < rows + 3; i++)
    {
        augs[0][i] = 0; //assigns zeros to rows
    } 
    
  
    for(int j = 1; j < cols; j++)
    {
        augs[j][0] = 0; //assigns zeros to cols
    } 
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            augs[i + 1][j + 1] = array[i][j]; //copying the array elements
        }
    }
    
    for(int j = 0; j < row2; j++)
    {
        for(int i = 0; i < row2 + 1; i++)
        {
            //fixing the formatting
            if(j == rows && i == cols)
            {
                cout << augs[j][i];
                break;
            }
            if(i == row2)
            {
                cout << augs[i][j];
                cout << endl; 
                break;
            }
            cout << augs[j][i] << " ";
        }
    }
    
    return augs;
}

void destroy(int **array, int rows) {
    
    for (int i = 0; i < rows; i++) {
        delete [] array[i];
    }

    delete[] array;
}
