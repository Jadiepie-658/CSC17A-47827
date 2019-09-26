#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    
    int val1 = *a;
    int val2 = *b;
    
    *a =  val1 + val2;
   
    if(val1 > val2) //to create an absolute value marker over b
    {
        *b = val1 - val2;
    }//if b is greater than val it subtracts b with val
    else
    {//these ensure b will always come out positive
        *b = val2 - val1;
    } 
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}


