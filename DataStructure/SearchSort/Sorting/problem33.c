#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* A and B Two Sorted array
* Shift all element of B to A ( A contains required space)
*/

void mergeSortedList(int a[], int m, int b[], int n){


    int count = m+n-1;

    int i=m-1, j=n-1;
    for(;count>=0;){

            // i>=0 to avoid under flow
            if(a[i]>b[j] && i>=0){
                    printf("a %d:%d ",i,a[i]);
                a[count--]=a[i];
                i--;
            }
            else{
                    printf("b %d: %d " ,j,b[j]);
                a[count--]=b[j];
                j--;
                //When all element of B is shifted to A, Break the loop.
                if(j<0){
                        printf("Loop Breaks\n");
                    break;
                }
            }

    }

    if(j>0 && i<0){
        a[count--]=b[j--];
    }
}

void printingArray(int a[], int length)
{
    int i;
    printf("\n****Array*****\n");
    for(i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    printf("\n**************\n");
}


int main(){

  //  int a[10]= {6,8,9,10,14,15};
  //  int b[4] = {1,11,13,16};

   // mergeSortedList(a,6,b,4);

   // printingArray(a,10);


}
