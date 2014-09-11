#include <stdio.h>
#include <stdlib.h>

#define N 10

int findMax(int a[], int size){

    int ans=0, i;
    for(i=0;i<size;i++){
        if(ans<a[i]){
            ans = a[i];
        }
    }
    return ans;
}

int printingArray(int a[], int length)
{   int i;
    printf("\n****Array*****\n");
    for(i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    printf("\n**************\n");
}

int countSort(int a[], int size, int exp){

    int c[N];
    int * b = malloc(size*sizeof(int));
    int i,j;

    for(i=0;i<N;i++){
            c[i]=0;
    }

    for(i=0;i<size;i++){
        c[(a[i]/exp)%10] = c[(a[i]/exp)%10] +1;
        b[i] = 0;
    }

    for(i=1;i<N;i++){
        c[i]= c[i]+c[i-1];
    }
   // printingArray(c,N);

    for(i=size-1;i>=0;i--){
        b[c[(a[i]/exp)%10] - 1] = a[i];
        c[(a[i]/exp)%10] = c[(a[i]/exp)%10] - 1;
    }

    for(i=0;i<size;i++){
        a[i] = b[i];
    }
    free(b);
    printingArray(a,size);
}

int radixSort(int a[], int size){

    int m= findMax (a,size);
    int exp;
    for(exp = 1;m/exp>0;exp = exp*10){
        countSort(a,size,exp);
    }
}

int main()
{

    int a[8] = {25,36,16,13,9,5};
    radixSort(a,8);
    return 0;
}
