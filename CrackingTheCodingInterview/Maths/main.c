#include <stdio.h>
#include <stdlib.h>


int setValue(int a[], int n){

    int i;
    for(i = 1;i<=n;i++){
        a[i] = 1;
    }
}

int getNextPrimeNumber(int a[],int max, int last){

    int i;
    for(i=last+1;i<=max;i++){
        if(a[i]==1){
            return i;
        }
    }
    return -1;
}

int markPrimeNumber(int a[], int max, int prime){

    int i;
    for(i=prime*prime;i<=max;i+=prime){
        a[i]=0;
    }
}

int GeneratePrimeNumbersList(int a[],int max){

    setValue(a,max);
    int i,last,next;
    last=2;

    while(last<=max){
        markPrimeNumber(a,max,last);
        next = getNextPrimeNumber(a,max,last);
        if(next==-1)
            break;
        last = next;
    }


    for(i=1;i<=max;i++){
        printf("%2d : %2d\n",i,a[i]);
    }

}
int main()
{

    int n=20;
    int *a = malloc(sizeof(int)*(n+1));
    GeneratePrimeNumbersList(a,n);
    return 0;u77l
}
